#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#define FCY 16000000UL     // System frequency
#include <libpic30.h>      // For __delay_ms()

#include "bsp/lcd.h"       // LCD driver

/**
 * @brief Initialize SPI1 as Master in 16-bit mode
 */
void setupSOsc(
    uint16_t osccon,
    uint16_t osctun,
    uint16_t clkdiv,
    uint16_t oscdiv,
    uint16_t oscfdiv
){
    OSCCON  = osccon;
    OSCTUN  = osctun;
    CLKDIV  = clkdiv;
    OSCDIV  = oscdiv;
    OSCFDIV = oscfdiv;
    
    return;
}

void SPI1_Init(void)
{
    uint16_t dummy;

    // Disable SPI module before configuration
    SPI1CON1Lbits.SPIEN = 0;

    // Disable and clear interrupt flag (not using interrupts here)
    IFS0bits.SPI1IF = 0;
    IEC0bits.SPI1IE = 0;

    // Clear receive buffer (drain any unread data)
    while (SPI1STATLbits.SPIRBF)
        dummy = SPI1BUFL;

    // Clear overflow flag
    SPI1STATLbits.SPIROV = 0;

    // Configure SPI1CON1 register
    SPI1CON1bits.DISSCK = 0;    // Enable internal SCK generation
    SPI1CON1bits.DISSDO = 0;    // Enable SDO pin
    SPI1CON1bits.MODE16 = 1;    // 16-bit mode (not 8-bit!)
    SPI1CON1bits.SMP = 0;       // Sample at middle of data output time
    SPI1CON1bits.CKP = 0;       // Idle state for clock is low
    SPI1CON1bits.CKE = 1;       // Transmit data on rising edge, change on falling edge
    SPI1CON1bits.MSTEN = 1;     // Master mode enabled

    // Disable frame mode completely
    SPI1CON2 = 0;

    // Set baud rate (F_SCK = FCY / (2 * (SPI1BRGL+1)))
    // With FCY=16 MHz and BRGL=3 -> F_SCK ? 2 MHz
    SPI1BRGL = 3;

    // Enable SPI module
    SPI1CON1Lbits.SPIEN = 1;
}


/**s
 * @brief Send and receive 16-bit data over SPI1
 */
uint16_t SPI1_Transfer16(uint16_t data)
{
    SPI1BUFL = data;                      // Load data into buffer
    while(!SPI1STATLbits.SPIRBF);         // Wait until receive complete
    return SPI1BUFL;                      // Read received 16-bit data
}

/**
 * @brief Main program
 */
int main(void)
{
    uint16_t command = 0x0055;
    uint16_t response;
    
    setupSOsc(0x0000, 0x0000, 0x0000, 0x0000, 0x0000);

    // Initialize SPI and LCD
    SPI1_Init();
    LCD_Initialize();

    while(1)
    {
        response = SPI1_Transfer16(command);  // Send command and receive response

        // Show message on LCD
        printf("\fFUNCIONAAAAA MALUCO");

        // Check for slave acknowledgment
        if(response == 0x00AA)
        {
            printf("\nSLAVE OK");
        }

        __delay_ms(500);
    }

    return 0;
}
