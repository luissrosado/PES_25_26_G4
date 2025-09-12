/*
 * File:   common.c
 * Author: João Duarte
 *
 * Created on September 9, 2025, 11:38 PM
 */

#include <p24FJ256GA702.h>

#include "common.h"


void __attribute__((__interrupt__, auto_psv)) _T1Interrupt(void){
    IFS0bits.T1IF = 0;
    
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
    setupTimer1(0x8030, 65000);
    
    // Setup Pin RB3 to a digital output
    pinMode(RB3, OUTPUT, DIGITAL);
    digitalWrite(RB3, 0);
    
    
    // Interrupt flags
    IFS0bits.T1IF = 0;      // Clear Interrupt Flag
    IPC0bits.T1IP = 6;      // Timer1 Priority Value
    IEC0bits.T1IE = 1;      // Enable Timer1's Interrupt
    INTCON2bits.GIE = 1;    // Enable Every Interrupt Flag    
    
    return;
}

void loop(void){
    // Insert your loop code here, to run repeatedly:
    
    return;
}
