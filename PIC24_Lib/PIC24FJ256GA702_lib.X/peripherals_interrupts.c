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
    SET_BIT_ON_REG(PMD1, 11, 0);
    
    // Set it up
    T1CON = t1con;
    PR1 = pr1;
    
    // Reset the timer
    TMR1 = 0;
    
    return;
}

void setupInterrupt(struct interrupt_t spec_inter, uint8_t priority){    
    if (priority > 0b00000111){
        priority = 0b00000111;
    }
    
    SET_BIT_ON_REG(*(spec_inter.ifs_addr), spec_inter.ifs_iec_bit, 0); // Set interrupt flag to 0
    SET_BIT_ON_REG(*(spec_inter.iec_addr), spec_inter.ifs_iec_bit, 1); // Enable the interrupt
    // Set the priority on the register
    SET_BIT_ON_REG(*(spec_inter.ipc_addr), spec_inter.ipc_bit, priority & 0x04);
    SET_BIT_ON_REG(*(spec_inter.ipc_addr), spec_inter.ipc_bit - 1, priority & 0x02);
    SET_BIT_ON_REG(*(spec_inter.ipc_addr), spec_inter.ipc_bit - 2, priority & 0x01);
    
}

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

void setupSPI1Slave(uint16_t SCLK_Pin, uint16_t CS_Pin, uint16_t MISO_Pin, uint16_t MOSI_Pin){
    // Enable the SPI1 Module
    SET_BIT_ON_REG(PMD1, 3, 0);
    
    
    RPINR20bits.SDI1R = MISO_Pin;  // SDI1 input (MISO)
    RPOR7bits.RP14R = 0b00111;     // SDO1 output (MOSI)
    RPINR20bits.SCK1R = SCLK_Pin;  // SCK1 input
    RPINR21bits.SS1R  = CS_Pin;    // SS1 input
    
    SPI1CON1Lbits.SPIEN = 0;  // Disable SPI1 before config
    
    // Setup as 16-bit communication, 16-bit FIFO
    SPI1CON1Hbits.AUDEN  = 0;
    SPI1CON1Lbits.MODE32 = 0;
    SPI1CON1Lbits.MODE16 = 1;

    SPI1CON1Lbits.MSTEN = 0;  // 0 = Slave mode
    SPI1CON1Lbits.SMP   = 0;  // Input data sampled in the middle
    SPI1CON1Lbits.CKE   = 1;  // Data changes on transition from active to idle clock state
    SPI1CON1Lbits.CKP   = 0;  // Idle clock is low
    SPI1CON1Lbits.SSEN  = 1;  // Enable Slave Select pin

    SPI1STATLbits.SPIROV = 0; // Clear overflow
    SPI1CON1Lbits.SPIEN  = 1; // Enable SPI1

    // === Configure SPI Interrupt ===
    IFS0bits.SPI1IF = 0; // Clear interrupt flag
    IEC0bits.SPI1IE = 1; // Enable SPI interrupt
    
    return;
}
