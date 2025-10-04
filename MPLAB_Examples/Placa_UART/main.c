#include <xc.h>
#include <stdio.h>
#include "placa_config.h"
#include "io_mapping.h"

#include "bsp/lcd.h"
#include "bsp/timer_1ms.h"
#include "bsp/rtcc.h"
#include "bsp/leds.h"

uint8_t FirstByte;
uint8_t LastByte;

// Configuração UART
void UART_Config(void) {
    U1MODEbits.UARTEN = 0;
    U1BRG = BRGVAL;
    U1MODEbits.PDSEL = 0; // 8 bits, sem paridade
    U1MODEbits.STSEL = 0; // 1 stop bit
    U1MODEbits.BRGH = 0;
    U1STAbits.UTXEN = 1;
    U1STAbits.URXEN = 1;

    RPOR8bits.RP17R = 3;  // U1TX
    RPINR18bits.U1RXR = 10; // U1RX

    __delay_ms(200);
}

// Envia 1 byte
void UART_SendByte(uint8_t data) {
    while (U1STAbits.UTXBF);
    U1TXREG = data;
}

// Envia 16 bits como 2 bytes
void UART_Send16(uint16_t data) {
    UART_SendByte((data >> 8) & 0xFF); // byte alto
    UART_SendByte(data & 0xFF);        // byte baixo
}

// Recebe 2 bytes e retorna como uint16_t
uint16_t UART_Receive16(void) {
    while(!U1STAbits.URXDA);
    uint8_t high = U1RXREG;
    while(!U1STAbits.URXDA);
    uint8_t low = U1RXREG;
    return (high << 8) | low;
}

// ===== Main Program =====
int main(void)
{
    int16_t command = 0xAAAA;
    uint16_t response;

    // Inicializa periféricos básicos da placa
    SYS_Initialize();
    
    UART_Config();

    // Limpa tela do LCD
    printf("\f");
    printf("Starting UART...\r\n");
    
    BUTTON_Enable(BUTTON_S3);
    LED_Enable(LED_D3);
    
    __delay_ms(10000);
    
    printf("\f");

    while(1)
    {
        // Escreve no LCD antes da transmissão
        printf("S: 0x%04X\r\n", command);

        // Envia comando
        UART_Send16(command);

        // Recebe resposta
        response = UART_Receive16();

        // Mostra resposta no LCD
        printf("R: 0x%04X\r\n", response);

        // Controle de LED baseado na resposta
        if(response == 0x00AA) {
            LED_On(LED_BLINK_ALIVE);
        } else {
            LED_Off(LED_BLINK_ALIVE);
        }

        // Controle de LED pelo botão
        if(BUTTON_IsPressed(BUTTON_S3)) {
            LED_On(LED_D3);
        } else {
            LED_Off(LED_D3);
        }

        __delay_ms(500);
    }

    return 0;
}
