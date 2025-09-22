/*
 * File:   common.c
 * Author: João Duarte
 *         Gonçalo Antunes
 *         Gonçalo Batalha
 *
 * Created on September 9, 2025, 11:38 PM
 */


#include "common.h"
#include "../../PIC24_Lib/PIC24FJ256GA702_lib.X/PIC24FJ256GA702_lib.h"
#include "ldr.h"

volatile LDR_Registers_t LDR = {
    .value = 0,
    .threshold = LDR_THRESHOLD,
    .count = 0
};

void ADC1_ISR(void){
    uint16_t ldrValue;
    AD1CON1bits.ASAM = 0;       // Stop Conversion
    
    // Calculate the value according to 2 samples
    ldrValue = (ADC1BUF0 + *((&ADC1BUF0) + 1)) >> 1;
    
    // Store value in global variable
    LDR.value = ldrValue;
    
    ADC_check(&LDR);
    
    IFS0bits.AD1IF = 0;
    return;
}

void T1_ISR(void){
    toggleDigitalPin(RA0);
    AD1CON1bits.ASAM = 1;           // Start ADC Conversion
    
    IFS0bits.T1IF = 0;
    return;
}

void setup(void){
    // Insert your setup code here, to run once:
    
    // Setup Pin RB3 to a digital output
    pinMode(RA0, OUTPUT);
    digitalWrite(RA0, LOW);
    
    pinMode(AN2, INPUT);
    setupADC(
        0x0070,             // SSRC = 111, internal counter ends sampling and starts conversion
        0x0004,             // Interrupt flag set after 2 samples
        0x0F00,             // Sample time = 15 Tad, Tad = Tcy
        0x0002,             // Select AN2 (RB2) as input channel
        0,                  // Disable channel scanning
        1                   // Enable 12-bit mode
    );
    
    // Setup Oscillator with the FRC = 8 MHz
    // OSCDIV = 0x0005 means frequency = 8 MHz / 10 = 0.8 MHz
    setupOsc(
        0x0000,
        0x0000,
        0x0000,
        0x0005,
        0x0000
    );
    
    // Timer period = (PR1 + 1) * Prescaler / Fcy = 10 seconds
    // Fcy = 0.8/2 = 0.4 MHz
    // Prescaler = 256
    // PR1 = Timer period * Fcy / Prescaler + 1 = 15626
    setupTimer1(0x8030, 15626);      // Enables timer with 256 Prescaler and the FRC
    
    // Interrupt flags setup
    setupInterrupt(ADC1_INTERRUPT, 6);
    setupInterrupt(T1_INTERRUPT, 6);
    ENABLE_INTERRUPTS;
    
    
    return;
}

void loop(void){
    // Insert your loop code here, to run repeatedly:
    Idle();
    
    return;
}
