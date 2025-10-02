/*
 * File:   ldr.c
 * Author: João Duarte
 *
 * Created on 22 September 2025, 00:21
 */


#include "xc.h"
#include "ldr.h"
#include "../../PIC24_Lib/PIC24FJ256GA702_lib.X/PIC24FJ256GA702_lib.h"


volatile LDR_Registers_t LDR;

// ADC 1 Interrupt Function
void ADC1_ISR(void){
    uint16_t ldrValue;
    AD1CON1bits.ASAM = 0;       // Stop Conversion
    
    uint16_t s0 = ADC1BUF0;
    uint16_t s1 = ADC1BUF1;               // read second sample if configured
    ldrValue = (uint16_t)(((uint32_t)s0 + (uint32_t)s1) >> 1);
    
    
    // Calculate the value according to 2 samples
    //ldrValue = (ADC1BUF0 + ADC1BUF1) >> 1;
    
    // Store value in global variable
    LDR.value = ldrValue;
    
    ADC_check(&LDR);
    
    
    IFS0bits.AD1IF = 0;
    return;
}


void ADC_check(LDR_Registers_t* ldr){
    // If the ldr value is bigger than the threshold it counts
    if (ldr->value < ldr->threshold) {
        ldr->count++;
    }
    
    return;
}