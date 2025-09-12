/*
 * File:   PIC24FJ256GA702_lib.c
 * Author: João Duarte
 *         Gonçalo Antunes
 *         Gonçalo Batalha
 *
 * Created on 11 September 2025, 19:55
 */


#include "xc.h"

#include "PIC24FJ256GA702_lib.h"
#include <libpic30.h>

void pinMode(struct pin_t pin, uint8_t mode, uint8_t AnaOrDigi){
    switch(pin.a_b){
        case A_PIN:
            SET_BIT_ON_REG(TRISA, pin.pinNum, mode);
            SET_BIT_ON_REG(ANSELA, pin.pinNum, AnaOrDigi);
            break;
        
        case B_PIN:
            SET_BIT_ON_REG(TRISB, pin.pinNum, mode);
            SET_BIT_ON_REG(ANSELB, pin.pinNum, AnaOrDigi);
            break;
        
        default:
            break;
    }
    
    return;
}

void digitalWrite(struct pin_t pin, uint8_t toWrite){
    switch(pin.a_b){
        case A_PIN:
            SET_BIT_ON_REG(LATA, pin.pinNum, toWrite);
            break;
        
        case B_PIN:
            SET_BIT_ON_REG(LATB, pin.pinNum, toWrite);
            break;
        
        default:
            break;
    }
    
    return;
}

void toggleDigitalPin(struct pin_t pin){
    switch(pin.a_b){
        case A_PIN:
            SET_BIT_ON_REG(LATA, pin.pinNum, !READ_BIT_ON_REG(LATA, pin.pinNum));
            break;
            
        case B_PIN:
            SET_BIT_ON_REG(LATB, pin.pinNum, !READ_BIT_ON_REG(LATB, pin.pinNum));
            break;
            
        default:
            break;
    }
            
    return;
}

void setupTimer1(uint16_t t1con, uint16_t pr1){
    T1CON = t1con;
    PR1 = pr1;
    
    // Reset the timer
    TMR1 = 0;
    
    return;
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
