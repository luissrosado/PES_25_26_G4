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
