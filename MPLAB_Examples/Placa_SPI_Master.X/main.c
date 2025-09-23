#include "placa_config.h"

// ===== SPI1 Setup =====
void init_spi1(void)
{
    SPI1CON1Lbits.SPIEN = 0;   // Disable SPI before configuring

    // Disable interrupts
    IEC0bits.SPI1IE = 0;
    IFS0bits.SPI1IF = 0;

    // SPI configuration
    SPI1CON1bits.DISSCK = 0;   // Enable internal SPI clock
    SPI1CON1bits.DISSDO = 0;   // Enable SDO
    SPI1CON1bits.MODE16 = 1;   // 16-bit communication
    SPI1CON1bits.SMP = 0;      // Sample in middle of output time
    SPI1CON1bits.CKP = 0;      // Clock idle state = low
    SPI1CON1bits.CKE = 1;      // Data changes on falling edge
    SPI1CON1bits.MSTEN = 1;    // Master mode enabled

    // Baud rate: Fcy / (2 * (BRG+1))
    SPI1BRGL = 4;              // Example: ~4 MHz if Fcy = 40 MHz

    SPI1CON2 = 0;              // Disable framed mode

    // Pin mapping
    RPINR20bits.SDI1R = 26;    // SDI (MISO) -> RP26
    RPOR9bits.RP19R   = 7;     // SDO (MOSI) -> RP19
    RPOR10bits.RP21R  = 8;     // SCK -> RP21

    // Chip Select pin (RB1)
    ANSELBbits.ANSB1 = 0;      // Set RB1 as digital
    TRISBbits.TRISB1 = 0;      // Configure as output
    LATBbits.LATB1   = 1;      // Set high (not selected by default)

    SPI1CON1Lbits.SPIEN = 1;   // Enable SPI module
}

// ===== SPI Transfer (single 16-bit word) =====
uint16_t SPI1_Transfer16(uint16_t data)
{
    uint16_t rx;

    LATBbits.LATB1 = 0;        // Assert CS (active low)
    __delay_us(5);             // Small delay for setup

    SPI1BUFL = data;           // Write data to transmit buffer
    while (!SPI1STATLbits.SPIRBF); // Wait until data is received
    rx = SPI1BUFL;             // Read received data

    LATBbits.LATB1 = 1;        // De-assert CS (inactive high)
    return rx;
}

// ===== Main Program =====
int main(void)
{
    uint16_t command = 0x0055;
    uint16_t response;

    init_spi1();        // Initialize SPI1

    while(1)
    {
        // Send command over SPI
        response = SPI1_Transfer16(command);

        // Check if slave acknowledged
        if(response == 0x00AA)
        {
          Nop();
        }
        
        __delay_ms(500);  // Delay between SPI transfers
    }

    return 0;
}
