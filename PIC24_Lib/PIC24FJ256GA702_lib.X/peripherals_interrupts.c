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
    volatile uint16_t *IFS_vec[8] = {&IFS0, &IFS1, &IFS2, &IFS3, &IFS4, &IFS5, &IFS6, &IFS7};
    volatile uint16_t *IEC_vec[8] = {&IEC0, &IEC1, &IEC2, &IEC3, &IEC4, &IEC5, &IEC6, &IEC7};
    volatile uint16_t *IPC_vec[30] = {&IPC0, &IPC1, &IPC2, &IPC3, &IPC4, &IPC5, &IPC6, &IPC7, 
                            &IPC8, &IPC9, &IPC10, &IPC11, &IPC12, &IPC13, &IPC14, &IPC15, 
                            &IPC16, &IPC17, &IPC18, &IPC19, &IPC20, &IPC21, &IPC22, &IPC23, 
                            &IPC24, &IPC25, &IPC26, &IPC27, &IPC28, &IPC29
    };
    
    if (priority > 0b00000111){
        priority = 0b00000111;
    }
    
    SET_BIT_ON_REG(*IFS_vec[spec_inter.ifs_iec_id], spec_inter.ifs_iec_bit, 0); // Set interrupt flag to 0
    SET_BIT_ON_REG(*IEC_vec[spec_inter.ifs_iec_id], spec_inter.ifs_iec_bit, 1); // Enable the interrupt
    // Set the priority on the register
    SET_BIT_ON_REG(*IPC_vec[spec_inter.ipc_id], spec_inter.ipc_bit, priority & 0x04);
    SET_BIT_ON_REG(*IPC_vec[spec_inter.ipc_id], spec_inter.ipc_bit - 1, priority & 0x02);
    SET_BIT_ON_REG(*IPC_vec[spec_inter.ipc_id], spec_inter.ipc_bit - 2, priority & 0x01);
    
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
