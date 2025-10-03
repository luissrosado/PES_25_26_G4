/*
 * File:   peripherals_interrupts.c
 * Author: João Duarte
 *
 * Created on 16 September 2025, 20:36
 */


#include "xc.h"

#include "peripherals_interrupts.h"

void setupTimer1(uint16_t t1con, uint16_t pr1){
    // Enable Timer1 module
    PMD1bits.T1MD = 0;
    
    // Set it up
    T1CON = t1con;
    PR1 = pr1;
    
    // Reset the timer
    TMR1 = 0;
    
    return;
}

void setupADC(
    uint16_t ad1con1,
    uint16_t ad1con2,
    uint16_t ad1con3,
    uint16_t ad1chs,
    uint16_t ad1cssl,
    uint16_t bit_mode
) {
    PMD1bits.AD1MD = 0;         // Enable ADC1
    
    AD1CON1 = ad1con1;
    AD1CON2 = ad1con2;
    AD1CON3 = ad1con3;
    
    AD1CHS  = ad1chs;
    AD1CSSL = ad1cssl;
    AD1CON1bits.MODE12 = bit_mode;     // Choose bit operation mode
    
    AD1CON1bits.ADON = 1;       // Turn ADC module ON
    
    return;
}


void setupInterrupt(struct interrupt_t spec_inter, uint8_t priority){    
    if (priority > 0b00000111){
        priority = 0b00000111;
    }
    
    SET_BIT_ON_REG(*(spec_inter.ifs_addr), spec_inter.ifs_iec_bit, 0); // Set interrupt flag to 0
    
    // Set the priority on the register
    SET_BIT_ON_REG(*(spec_inter.ipc_addr), spec_inter.ipc_bit, priority & 0x04);
    SET_BIT_ON_REG(*(spec_inter.ipc_addr), spec_inter.ipc_bit - 1, priority & 0x02);
    SET_BIT_ON_REG(*(spec_inter.ipc_addr), spec_inter.ipc_bit - 2, priority & 0x01);
    
    SET_BIT_ON_REG(*(spec_inter.iec_addr), spec_inter.ifs_iec_bit, 1); // Enable the interrupt
    
    return;
}



void setupOsc(
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


void setupSPI1Slave(uint16_t SCLK_Pin, uint16_t CS_Pin, uint16_t MISO_Pin, uint16_t MOSI_Pin){
    // Enable the SPI1 Module
    PMD1bits.SPI1MD = 0;
    //SET_BIT_ON_REG(PMD1, 3, 0);
    
    IEC3bits.SPI1RXIE = 0;
    IFS3bits.SPI1RXIF = 0;
    
    IEC0bits.SPI1TXIE = 0;
    IFS0bits.SPI1TXIF = 0;
    
    SPI1CON1Lbits.SPIEN   = 0; // Disable SPI1 before config
    SPI1CON1Lbits.SPISIDL = 0; // Enable SPI1 during idle
    
    SPI1CON1L = 0;
    SPI1CON1H = 0;
    SPI1CON2L = 0;
    SPI1CON2 = 0;
    
    RPINR20bits.SDI1R = MOSI_Pin;  // SDI1 input  (MOSI)
    RPOR7bits.RP14R = 0b00111;     // SDO1 output (MISO)    // HAS TO BE SETUP MANUALLY
    RPINR20bits.SCK1R = SCLK_Pin;  // SCK1 input
    RPINR21bits.SS1R  = CS_Pin;    // SS1 input
    
    volatile uint16_t dump;
    while (SPI1STATLbits.SPIRBF) dump = SPI1BUFL; // clear RX
    SPI1STATLbits.SPIROV = 0;   // Clear overflow

    // Use Standard Buffer mode (clear ENHBUF) unless you want enhanced
    SPI1CON1Lbits.ENHBUF = 0;   // Standard buffer
    
    SPI1IMSKLbits.SPIRBFEN = 1; // Enable Interrupt Event by Full Receive Buffer

    SPI1CON1Lbits.MSTEN = 0;    // 0 = Slave mode
    SPI1CON1Lbits.SSEN  = 1;    // Enable Slave Select pin
    SPI1CON1Lbits.CKP   = 0;    // Idle clock is low
    SPI1CON1Lbits.CKE   = 1;    // Data changes on transition from active to idle clock state
    SPI1CON1Lbits.SMP   = 0;    // Input data sampled in the middle
    SPI1CON1Lbits.MODE32 = 0;
    SPI1CON1Lbits.MODE16 = 1;
    
    SPI1CON1Lbits.SPIEN  = 1;   // Enable SPI1
    
    return;
}

void setupSPI2Master(uint16_t SCLK_Pin, uint16_t CS_Pin, uint16_t MISO_Pin, uint16_t MOSI_Pin){
    // Enable the SPI2 Module
    PMD1bits.SPI2MD = 0;
    
    IEC3bits.SPI2RXIE = 0;
    IFS3bits.SPI2RXIF = 0;
    
    SPI2CON1Lbits.SPIEN   = 0; // Disable SPI2 before config
    SPI2CON1Lbits.SPISIDL = 0; // Enable SPI2 during idle
    
    SPI2CON1L = 0;
    SPI2CON1H = 0;
    SPI2CON2L = 0;
    SPI2CON2 = 0;
    
    RPINR22bits.SDI2R = MISO_Pin;   // MDI2 input  (MISO)
    RPOR3bits.RP6R    = 10;         // MDO2 output (MOSI)   // HAS TO BE SETUP MANUALLY
    RPOR3bits.RP7R    = 11;         // SCK2 output          // HAS TO BE SETUP MANUALLY
    RPOR1bits.RP3R    = 12;         // SS2  output          // HAS TO BE SETUP MANUALLY
    
    volatile uint16_t dump;
    while (SPI2STATLbits.SPIRBF) dump = SPI1BUFL; // clear RX
    SPI2STATLbits.SPIROV = 0;   // Clear overflow

    // Use Standard Buffer mode (clear ENHBUF) unless you want enhanced
    SPI2CON1Lbits.ENHBUF = 0;   // Standard buffer
    
    SPI2IMSKLbits.SPIRBFEN = 1; // Enable Interrupt Event by Full Receive Buffer

    SPI2CON1Lbits.MSTEN = 1;    // 1 = Master mode
    SPI2CON1Lbits.CKP   = 1;    // Idle clock is low
    SPI2CON1Lbits.CKE   = 0;    // Data changes on transition from active to idle clock state
    SPI2CON1Lbits.SMP   = 0;    // Input data sampled in the middle
    SPI2CON1Lbits.MODE32 = 0;
    SPI2CON1Lbits.MODE16 = 1;
    
    SPI2CON1Lbits.SPIEN  = 1;   // Enable SPI2
}