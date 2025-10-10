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

// Pragmas for WDT
#pragma config FWDTEN = OFF     // Controlled by software
#pragma config WINDIS = OFF
#pragma config WDTPS  = 0b1100  // = 4096
#pragma config FWPSA  = 0b0     // 5-bit
#pragma config WDTCLK = SYSCLK  // Use system clock



#define TMR1_LED_PIN RB5
#define WDT_LED_PIN  RB8

#define WDT_TIMEOUT RCONbits.WDTO
#define WDT_ENABLE  RCONbits.SWDTEN

uint8_t wdt_test = 0;
#define TEST_THRESHOLD 5

// Timer 1 Interrupt Function
void T1_ISR(void){
    toggleDigitalPin(TMR1_LED_PIN);
    wdt_test += 1;
    
    IFS0bits.T1IF = 0;
    return;
}

void setup(void){
    // Insert your setup code here, to run once:
    
    // Setup Pin for TMR1 LED to a digital output
    pinMode(TMR1_LED_PIN, OUTPUT);
    digitalWrite(TMR1_LED_PIN, HIGH);
    
    // Setup Pin for WDT LED to a digital output
    pinMode(WDT_LED_PIN, OUTPUT);
    digitalWrite(WDT_LED_PIN, HIGH);
    
    
    // Setup Oscillator with the FRC = 8 MHz
    // OSCDIV = 0x0005 means frequency = 8 MHz / 10 = 0.8 MHz
    setupOsc(
        0x0000,
        0x0000,
        0x0000,
        0x0005,
        0x0000
    );
    
    // Timer period = (PR1 + 1) * Prescaler / Fcy = 1 second
    // Fcy = 0.8/2 = 0.4 MHz
    // Prescaler = 256
    // PR1 = Timer period * Fcy / Prescaler + 1 = 1562.6 = 1563
    setupTimer1(0x8030, 1563);      // Enables timer with 256 Prescaler and the FRC
    
    setupInterrupt(T1_INTERRUPT, 7);
    ENABLE_INTERRUPTS;
    
    // Enable the watchdog timer
    WDT_ENABLE = 1; // Enable WDT
    
    return;
}

void loop(void){
    // Insert your loop code here, to run repeatedly:
    
    // If the WDT triggered the reset, toggle the informative LED:
    if (WDT_TIMEOUT == 1){
        digitalWrite(WDT_LED_PIN, LOW);
    }
    
    // Reset the WDT
    if(wdt_test == TEST_THRESHOLD){
        while(1);
    }
    ClrWdt();
    
    
    Idle();
    return;
}
