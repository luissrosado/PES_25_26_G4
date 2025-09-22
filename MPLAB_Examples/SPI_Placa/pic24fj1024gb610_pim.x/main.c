#include "config.h"

// SPI1 Initialization
void spi_init(void)
{
    SPI1CON1Lbits.SPIEN = 0;       // Disable SPI peripheral
    IFS0bits.SPI1IF = 0;           // Clear SPI interrupt flag
    IEC0bits.SPI1IE = 0;           // Disable SPI interrupt

    SPI1CON1bits.DISSCK = 0;       // Enable SCK generation
    SPI1CON1bits.DISSDO = 0;       // Enable SDO output
    SPI1CON1bits.MODE16 = 1;       // 16-bit mode
    SPI1CON1bits.SMP = 0;          // Sample at middle of data
    SPI1CON1bits.CKP = 0;          // Idle clock low
    SPI1CON1bits.CKE = 1;          // Data changes on falling edge
    SPI1CON1bits.MSTEN = 1;        // Master mode
    SPI1BRGL = 4;                  // SPI baud rate = FCY/(2*(BRG+1)) ~ 400 kHz

    SPI1CON2 = 0;                   // Disable framed SPI mode

    // Pin remapping
    RPINR20bits.SDI1R = 26;         // MISO -> RP26 (P11)
    RPOR9bits.RP19R = 7;            // MOSI -> RP19 (P12)
    RPOR10bits.RP21R = 8;           // SCK -> RP21 (P10)

    // Chip Select RB1 (P24)
    ANSELBbits.ANSB1 = 0;
    TRISBbits.TRISB1 = 0;
    LATBbits.LATB1 = 1;             // Set CS high

    SPI1CON1Lbits.SPIEN = 1;        // Enable SPI
}

// SPI Communication
void spi_com(uint16_t *data, uint16_t *rx_data, uint16_t length)
{
    LATBbits.LATB1 = 0;             // Select slave
    __delay_ms(1);                  // Short delay for CS setup

    for (uint16_t i = 0; i < length; i++)
    {
        SPI1BUFL = data[i];          // Transmit
        while (!SPI1STATLbits.SPIRBF); // Wait for receive
        rx_data[i] = SPI1BUFL;       // Read received
    }

    LATBbits.LATB1 = 1;             // Deselect slave
}

int main(void)
{
    // Initialize SPI
    spi_init();

    uint16_t tx_data[4] = {0x1234, 0x4567, 0x1234, 0x4567};
    uint16_t rx_data[4];

    while (1)
    {
        __delay_ms(1000);
        spi_com(tx_data, rx_data, 4);
        __delay_ms(1000);
    }

    return 0;
}
