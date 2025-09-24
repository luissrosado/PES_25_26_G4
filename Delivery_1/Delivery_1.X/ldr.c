/*
 * File:   ldr.c
 * Author: João Duarte
 *
 * Created on 22 September 2025, 00:21
 */


#include "xc.h"
#include "ldr.h"


volatile LDR_Registers_t LDR = {
    .value = 0,
    .threshold = LDR_THRESHOLD,
    .count = 0
};

// ADC 1 Interrupt Function
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


void ADC_check(LDR_Registers_t* ldr){
    // If the ldr value is bigger than the threshold it counts
    if (ldr->value > ldr->threshold) {
        ldr->count++;
    }
    
    return;
}