/*
 * File:   ldr.c
 * Author: João Duarte
 *
 * Created on 22 September 2025, 00:21
 */


#include "xc.h"
#include "ldr.h"


void ADC_check(LDR_Registers_t* ldr){
    // If the ldr value is bigger than the threshold it counts
    if (ldr->value > ldr->threshold) {
        ldr->count++;
    }
    
    return;
}