/*
 * File:   common.c
 * Author: João Duarte
 *
 * Created on September 9, 2025, 11:38 PM
 */

#include <p24FJ256GA702.h>

#include "common.h"
#include "../../PIC24_Lib/PIC24FJ256GA702_lib.X/PIC24FJ256GA702_lib.h"

#define LED_PIN RB15

void T1_ISR(void){
    IFS0bits.T1IF = 0;
    
    //toggleDigitalPin(LED_PIN);
    
    return;
}

void setup(void){
    // Insert your setup code here, to run once:
    setupOsc(
        0x0000,
        0x0000,
        0x0000,
        0x0000,
        0x0000
    );
    setupTimer1(0x8030, 3000);
    
    // Setup Pin RA0 to a digital output
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, HIGH);
    
    
    // Interrupt flags
    setupInterrupt(T1_INTERRUPT, 6);
    ENABLE_INTERRUPTS;
    
    return;
}

void loop(void){
    // Insert your loop code here, to run repeatedly:
    // Using idle, the internal clock keeps working and so does Timer1
    //Idle();
    digitalWrite(LED_PIN, HIGH);
    // Using sleep, the internal clock stops working and so does Timer1
    // Unless it is using an external clock
    //Sleep();
    
    return;
}
