#include <xc.h>
#include <stdio.h>
#include "placa_config.h"
#include "io_mapping.h"

#include "bsp/lcd.h"
#include "bsp/timer_1ms.h"
#include "bsp/rtcc.h"
#include "bsp/leds.h"

// ===========================
// UART Initialization
// ===========================
void SerialInit() {
    U1BRG = 103; // Baud rate 9600, Fcy = 4MHz
    U1MODEbits.PDSEL = 0; // 8 bits, no parity
    U1MODEbits.STSEL = 0; // 1 stop bit
    U1MODEbits.UEN = 0;   // Only U1TX and U1RX
    U1MODEbits.BRGH = 0;  // Standard speed

    RPOR8bits.RP17R = 3;     // U1TX -> RP17
    RPINR18bits.U1RXR = 10;  // U1RX -> RP10

    U1MODEbits.UARTEN = 1; // Enable UART
    U1STAbits.UTXEN = 1;   // Enable transmission
}

// ===========================
// Send a char via UART
// ===========================
void SerialSendChar(char c) {
    while (U1STAbits.UTXBF); // Wait until buffer is free
    U1TXREG = c;
}

// ===========================
// Send a string via UART
// ===========================
void SerialSendString(const char *str) {
    while (*str) {
        SerialSendChar(*str++);
    }
}

// ===========================
// Read a char from UART (blocking)
// ===========================
char SerialReadChar(void) {
    while (!U1STAbits.URXDA); // Wait until data available
    return U1RXREG;
}

// ===========================
// Example sensor values
// ===========================
int X = 10, Y = 20, Z = -5;
int TEMP = 24;
int ACC_COUNTER = 12;
int TEMP_COUNTER = 3;
int ACC_THRESH = 30;
int TEMP_THRESH = 40;

// ===========================
// Helper: Send all values in CSV
// ===========================
void SendAllValues() {
    char buffer[128];
    sprintf(buffer,
        "X=%d,Y=%d,Z=%d,TEMP=%d,ACC_COUNTER=%d,TEMP_COUNTER=%d,ACC_THRESH=%d,TEMP_THRESH=%d\r\n",
        X, Y, Z, TEMP, ACC_COUNTER, TEMP_COUNTER, ACC_THRESH, TEMP_THRESH
    );
    SerialSendString(buffer);
}

// ===========================
// Main function
// ===========================
int main(void) {
    SYS_Initialize();
    SerialInit();
    LCD_Initialize();
    printf("\f"); // Clear LCD

    char buffer[64];

    while (1) {
        char cmd = SerialReadChar(); // read 1 byte command

        // Show received command on LCD
        printf("\f"); 
        printf("CMD: %d\n", (unsigned char)cmd);

        switch (cmd) {
            case 0: // START ? envia todos os valores em CSV
                SendAllValues();
                break;

            case 1: // TOGGLE_SYSTEM
                printf("\f");
                printf("SYSTEM TOGGLED\n");
                SerialSendString("SYSTEM TOGGLED\r\n");
                break;

            case 2: // ACC_VALUES
                X = 15; 
                Y = 2; 
                Z = -1;
                sprintf(buffer, "X=%d,Y=%d,Z=%d\r\n", X, Y, Z);
                SerialSendString(buffer);
                break;

            case 3: // ACC_COUNTER
                sprintf(buffer, "ACC_COUNTER=%d\r\n", ACC_COUNTER);
                SerialSendString(buffer);
                break;

            case 4: // TEMP
                TEMP = 30;
                sprintf(buffer, "TEMP=%d\r\n", TEMP);
                SerialSendString(buffer);
                break;

            case 5: // TEMP_COUNTER
                TEMP_COUNTER=7;
                sprintf(buffer, "TEMP_COUNTER=%d\r\n", TEMP_COUNTER);
                SerialSendString(buffer);
                break;

            case 6: // READ_ACC_THRESH
                sprintf(buffer, "ACC_THRESH=%d\r\n", ACC_THRESH);
                SerialSendString(buffer);
                break;

            case 7: // SET_ACC_THRESH
            {
                char newVal = SerialReadChar();
                ACC_THRESH = (int)newVal;
                sprintf(buffer, "ACC_THRESH=%d\r\n", ACC_THRESH);
                SerialSendString(buffer);
            }
            break;

            case 8: // READ_TEMP_THRESH
                sprintf(buffer, "TEMP_THRESH=%d\r\n", TEMP_THRESH);
                SerialSendString(buffer);
                break;

            case 9: // SET_TEMP_THRESH
            {
                char newVal = SerialReadChar();
                TEMP_THRESH = (int)newVal;
                Nop();
                sprintf(buffer, "TEMP_THRESH=%d\r\n", TEMP_THRESH);
                SerialSendString(buffer);
            }
            break;

            default:
                SerialSendString("UNKNOWN CMD\r\n");
                break;
        }
    }
}
