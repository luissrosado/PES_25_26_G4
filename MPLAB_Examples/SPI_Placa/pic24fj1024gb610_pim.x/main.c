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
    SPI1CON1Lbits.SPIEN = 0;  

    // Clear interrupt flag and disable SPI interrupt
    IFS0bits.SPI1IF = 0;   
    IEC0bits.SPI1IE = 0;   

    // Configure SPI1CON1 register
    SPI1CON1bits.DISSCK = 0;    // Enable generation of SCK
    SPI1CON1bits.DISSDO = 0;    // Enable generation of SDO
    SPI1CON1bits.MODE16 = 1;    // 8-bit mode
    SPI1CON1bits.SMP = 0;       // Sample at middle of data output time
    SPI1CON1bits.CKP = 0;       // Clock idle state low
    SPI1CON1bits.CKE = 1;       // Data changes on falling edge of SCK
    //SPI1CON1bits.SPRE = 4;      // Secondary prescaler 4:1
    //SPI1CON1bits.PPRE = 2;      // Primary prescaler 4:1 -> F_SCK = 1 MHz (if FCY = 16 MHz)
    SPI1CON1bits.MSTEN = 1;     // Enable master mode

    // Fully disable frame mode
    SPI1CON2 = 0;
    SPI1BRGL = 3;              // 16MHz / 8 = 2 MHz

    SPI1CON1Lbits.SPIEN = 1;  // Enable SPI
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
        printf("\fOLEEEEEEEE");

        // Check for slave acknowledgment
        if(response == 0x00AA)
        {
            printf("\nSLAVE OK");
        }

        __delay_ms(500);
    }

    return 0;
}
