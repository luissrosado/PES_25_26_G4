/*
 * File:   common.c
 * Author: João Duarte
 *         Gonçalo Antunes
 *         Gonçalo Batalha
 *
 * Created on September 9, 2025, 11:38 PM
 */


#include "common.h"
#include "ldr.h"
#include "../../PIC24_Lib/PIC24FJ256GA702_lib.X/PIC24FJ256GA702_lib.h"

int ldrValue;                // Variable to store LDR ADC value

void setup(void){
    // Insert your setup code here, to run once:
    
    // Enable ADC1 module
    SET_BIT_ON_REG(PMD1, 0, 0);
    
    ADC_setup();
    
    return;
}

void loop(void){
    // Insert your loop code here, to run repeatedly:
    
    ADC_read();
    ADC_check();

    // At this point, ldrValue holds the averaged LDR sensor reading (0?1023 for 10-bit ADC)
    Nop();
    
    return;
}
