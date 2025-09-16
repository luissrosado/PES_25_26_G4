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

int ldrValue;                // Variable to store LDR ADC value

void setup(void){
    // Insert your setup code here, to run once:
    
    // Enable ADC1 module
    SET_BIT_ON_REG(PMD1, 0, 0);
    
    ANSB = 0x0002;               // Set RB2/AN2 as analog pin
    AD1CON1 = 0x0070;            // SSRC = 111, internal counter ends sampling and starts conversion
    AD1CHS  = 0x0002;            // Select AN2 (RB2) as input channel
    AD1CSSL = 0;                 // Disable channel scanning
    AD1CON3 = 0x0F00;            // Sample time = 15 Tad, Tad = Tcy
    AD1CON2 = 0x0004;            // Interrupt flag set after 2 samples
    AD1CON1bits.ADON = 1;        // Turn ADC module ON
    
    return;
}

void loop(void){
    // Insert your loop code here, to run repeatedly:
    
    IFS0bits.AD1IF = 0;      // Clear ADC interrupt flag
    AD1CON1bits.ASAM = 1;    // Start auto-sampling and conversion

    while (!IFS0bits.AD1IF); // Wait until 2 samples are completed

    AD1CON1bits.ASAM = 0;    // Stop sampling/conversion

    // Retrieve two samples from ADC buffer
    ldrValue  = ADC1BUF0;                
    ldrValue += *((&ADC1BUF0) + 1);

    // Proper averaging of 2 samples
    ldrValue = ldrValue >> 1;   // Divide by 2

    // At this point, ldrValue holds the averaged LDR sensor reading (0?1023 for 10-bit ADC)
    Nop();
    
    return;
}
