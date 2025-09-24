/*
 * File:   main.c
 * Author: João Duarte
 *
 * Created on 24 September 2025, 02:14
 */


#include "xc.h"
#include "../../PIC24_Lib/PIC24FJ256GA702_lib.X/PIC24FJ256GA702_lib.h"

#define CMD_FROM_MASTER  0x0055
#define RESPONSE_TO_SEND 0x00AA


static void SPI1_Init_Slave(void)
{
    // 1) Make SPI pins DIGITAL and set directions
    ANSBbits.ANSB12 = 0;  // RB12 SS1   (in)
    ANSBbits.ANSB13 = 0;  // RB13 SCK1  (in)
    ANSBbits.ANSB14 = 0;  // RB14 SDI1  (in)
    ANSBbits.ANSB15 = 0;  // RB15 SDO1  (out)

    TRISBbits.TRISB12 = 1; // SS  in
    TRISBbits.TRISB13 = 1; // SCK in
    TRISBbits.TRISB14 = 1; // SDI in
    TRISBbits.TRISB15 = 0; // SDO out

    // 2) PPS mapping
    __builtin_write_OSCCONL(OSCCON & 0xBF);
    RPINR20bits.SDI1R = 14;   // SDI1 <- RP12 (RB12)
    RPOR7bits.RP15R   = 7;    // SDO1 -> RP13 (RB13) func=7
    RPINR20bits.SCK1R = 13;   // SCK1 <- RP14 (RB14)
    RPINR21bits.SS1R  = 12;   // SS1  <- RP15 (RB15)
    __builtin_write_OSCCONL(OSCCON | 0x40);

    // 3) Stop/reset SPI, clear RX buffer, clear ENHBUF if you want standard buffer
    SPI1CON1Lbits.SPIEN = 0;      // stop SPI
    SPI1CON1L = 0;
    SPI1CON1H = 0;
    SPI1CON2L = 0;
    SPI1CON2 = 0;
    // Standard buffer mode (ENHBUF = 0 by default in SPI1CON1L<0>)

    volatile uint16_t dump;
    while (SPI1STATLbits.SPIRBF) dump = SPI1BUFL; // clear RX
    SPI1STATLbits.SPIROV = 0;

    // Mask register: enable ?RX buffer full? to generate an interrupt event
    SPI1IMSKLbits.SPIRBFEN = 1;

    // Clear + enable interrupt
    IFS3bits.SPI1RXIF = 0;
    IPC14bits.SPI1RXIP = 5;   // priority
    IEC3bits.SPI1RXIE = 1;                    // clear overflow

    // 5) Configure Slave mode + SS sync enabled
    SPI1CON1Lbits.MSTEN  = 0; // slave
    SPI1CON1Lbits.SSEN   = 1; // SS must be low to shift & generate interrupts
    SPI1CON1Lbits.CKP    = 0; // idle clock low
    SPI1CON1Lbits.CKE    = 1; // data changes active->idle (mode 0,0 with SMP=0)
    SPI1CON1Lbits.SMP    = 0; // sample in middle
    
    // 16-bit
    SPI1CON1Lbits.MODE16 = 1;
    SPI1CON1Lbits.MODE32 = 0;

    // 6) Enable SPI
    SPI1CON1Lbits.SPIEN = 1;

    // 8) Prime first TX byte so the first received byte clocks out something valid
    SPI1BUFL = RESPONSE_TO_SEND;
}

// ---- SPI1 RX ISR: fires once per received byte ----
void __attribute__((__interrupt__, no_auto_psv)) _SPI1RXInterrupt(void)
{
    // Read received byte (clears SPIRBF)
    uint16_t b = SPI1BUFL;

    // Queue the response byte for this position
    if (b == CMD_FROM_MASTER){
        SPI1BUFL = RESPONSE_TO_SEND;
        toggleDigitalPin(RA0);
    }

    // Clear RX flag and any overflow
    IFS3bits.SPI1RXIF = 0;  // clear flag
    if (SPI1STATLbits.SPIROV) {
        volatile uint8_t dump = SPI1BUFL;
        (void)dump;
        SPI1STATLbits.SPIROV = 0;
    }
}


int main(void) {
    SPI1_Init_Slave();
    
    pinMode(RA0, OUTPUT);
    digitalWrite(RA0, HIGH);
    
    while(1);
    
    return 0;
}
