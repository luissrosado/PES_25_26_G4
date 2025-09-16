/*
 * File:   common.c
 * Author: João Duarte
 *
 * Created on September 9, 2025, 11:38 PM
 */

#include <p24FJ256GA702.h>

#include "common.h"
#include "../../PIC24_Lib/PIC24FJ256GA702_lib.X/PIC24FJ256GA702_lib.h"

void T1_ISR(void){
    uint16_t *IFS_vec[8] = {&IFS0, &IFS1, &IFS2, &IFS3, &IFS4, &IFS5, &IFS6, &IFS7};
    SET_BIT_ON_REG(*IFS_vec[T1_INTERRUPT.ifs_iec_id], T1_INTERRUPT.ifs_iec_bit, 0); // Set interrupt flag to 0
    
    toggleDigitalPin(RB3);
    
    return;
}

void setup(void){
    // Insert your setup code here, to run once:
    setupSOsc(
        0x0000,
        0x0000,
        0x0000,
        0x0000,
        0x0000
    );
    setupTimer1(0x8030, 3000);
    
    // Setup Pin RB3 to a digital output
    pinMode(RB3, OUTPUT);
    digitalWrite(RB3, LOW);
    
    
    // Interrupt flags
    setupInterrupt(T1_INTERRUPT, 6);
    ENABLE_INTERRUPTS;
    
    return;
}

void loop(void){
    // Insert your loop code here, to run repeatedly:
    // Using idle, the internal clock keeps working and so does Timer1
    Idle();
    // Using sleep, the internal clock stops working and so does Timer1
    // Unless it is using an external clock
    //Sleep();
    
    return;
}
