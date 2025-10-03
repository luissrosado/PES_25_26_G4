/*
 * File:   common.c
 * Author: João Duarte
 *         Gonçalo Antunes
 *         Gonçalo Batalha
 *
 */


#include "common.h"
#include "../../PIC24_Lib/PIC24FJ256GA702_lib.X/PIC24FJ256GA702_lib.h"
#include "ldr.h"
#include "SPI_Slave.h"
#include "axl.h"


#define LED_PIN RB5
#define LDR_PIN AN1
#define LDR_SEL 0x0001  // Indicates the ADC what's the LDR pin


uint8_t AXL_flag = 0;
volatile LIS axl;

// Timer 1 Interrupt Function
void T1_ISR(void){
    toggleDigitalPin(LED_PIN);
    AD1CON1bits.ASAM = 1;           // Start ADC Conversion
    AXL_flag = 1;
    
    IFS0bits.T1IF = 0;
    return;
}

void setup(void){
    // Insert your setup code here, to run once:
    
    // Setup Pin RB3 to a digital output
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, HIGH);
    
    // Setup SPI Slave for the Bridge
    pinMode(RB12, INPUT);
    pinMode(RB13, INPUT);
    pinMode(RB14, OUTPUT);
    pinMode(RB15, INPUT);
    setupSPI1Slave(SPI1_SCLK_RPIN, SPI1_CS_RPIN, SPI1_MISO_RPIN, SPI1_MOSI_RPIN);
    
    // Setup SPI Master for the Accelerometer
    pinMode(RB2, INPUT);
    pinMode(RB6, OUTPUT);
    pinMode(RB7, OUTPUT);
    pinMode(RB3, OUTPUT);
    setupSPI2Master(SPI2_SCLK_RPIN, SPI2_CS_RPIN, SPI2_MISO_RPIN, SPI2_MOSI_RPIN);
    
    pinMode(LDR_PIN, INPUT);
    setupADC(
        0x0070,             // SSRC = 111, internal counter ends sampling and starts conversion
        0x0004,             // Interrupt flag set after 2 samples
        0x0F00,             // Sample time = 15 Tad, Tad = Tcy
        LDR_SEL,             // Select AN1 (RA1) as input channel
        0,                  // Disable channel scanning
        1                   // Enable 12-bit mode
    );
    LDR.threshold = LDR_THRESHOLD;
    
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
    setupTimer1(0x8030, 10);      // Enables timer with 256 Prescaler and the FRC
    
    // Config the Accelerometer Module
    LISconfig();
    
    // Interrupt flags setup
    setupInterrupt(ADC1_INTERRUPT, 7);
    setupInterrupt(T1_INTERRUPT, 6);
    setupInterrupt(SPI1_RX_INTERRUPT, 5);
    //setupInterrupt(SPI2_RX_INTERRUPT, 5);
    
    ENABLE_INTERRUPTS;
    
    
    return;
}

void loop(void){
    // Insert your loop code here, to run repeatedly:
    Idle();
    if(AXL_flag != 0){
        readAXL(&axl);
        AXL_flag = 0;
    }
    
    return;
}
