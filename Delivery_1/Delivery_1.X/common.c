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
#include "SPI.h"



#define LED_PIN RB5
#define LDR_PIN AN1
#define LDR_SEL 0x0001  // Indicates the ADC what's the LDR pin


// Timer 1 Interrupt Function
void T1_ISR(void){
    toggleDigitalPin(LED_PIN);
    AD1CON1bits.ASAM = 1;           // Start ADC Conversion
    
    IFS0bits.T1IF = 0;
    return;
}

void setup(void){
    // Insert your setup code here, to run once:
    
    // Setup Pin RB3 to a digital output
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, HIGH);
    
    // Insert your setup code here, to run once:
    pinMode(RB12, INPUT);
    pinMode(RB13, INPUT);
    pinMode(RB14, OUTPUT);
    pinMode(RB15, INPUT);
    setupSPI1Slave(SPI1_SCLK_RPIN, SPI1_CS_RPIN, SPI1_MISO_RPIN, SPI1_MOSI_RPIN);
    
    pinMode(LDR_PIN, INPUT);
    setupADC(
        0x0070,             // SSRC = 111, internal counter ends sampling and starts conversion
        0x0004,             // Interrupt flag set after 2 samples
        0x0F00,             // Sample time = 15 Tad, Tad = Tcy
        LDR_SEL,             // Select AN1 (RA1) as input channel
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
