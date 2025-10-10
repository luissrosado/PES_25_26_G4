/*
 * File:   GPIO.c
 * Author: João Duarte
 *         Gonçalo Antunes
 *         Gonçalo Batalha
 *
 */


#include "xc.h"
#include "GPIO.h"

void pinMode(struct pin_t pin, uint8_t mode){
    switch(pin.a_b){
        case A_PIN:
            SET_BIT_ON_REG(TRISA, pin.pinNum, mode);
            SET_BIT_ON_REG(ANSELA, pin.pinNum, pin.pinType);
            break;
        
        case B_PIN:
            SET_BIT_ON_REG(TRISB, pin.pinNum, mode);
            SET_BIT_ON_REG(ANSELB, pin.pinNum, pin.pinType);
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
