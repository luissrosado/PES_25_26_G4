/*
 * File:   common.c
 * Author: Jo�o Duarte
 *         Gon�alo Antunes
 *         Gon�alo Batalha
 *
 * Created on September 9, 2025, 11:38 PM
 */


#include "common.h"
#include "../../PIC24_Lib/PIC24FJ256GA702_lib.X/PIC24FJ256GA702_lib.h"

#include "SPI_Pins.h"

void SPI1_RX_ISR(void){
    uint16_t received = SPI1BUFL;
    
    if (received == CMD_FROM_MASTER) {
        toggleDigitalPin(RA0);
        SPI1BUFL = RESPONSE_TO_SEND;  // Queue response for next transfer
    }
  
    if (SPI1STATLbits.SPIROV) {
        volatile uint8_t dump = SPI1BUFL;
        (void)dump;
        SPI1STATLbits.SPIROV = 0;
    }
    
    IFS3bits.SPI1RXIF = 0;
    return;
}

void setup(void){
    // Setup Oscillator with the FRC = 8 MHz
    // OSCDIV = 0x0005 means frequency = 8 MHz / 10 = 0.8 MHz
    setupOsc(
        0x0000,
        0x0000,
        0x0000,
        0x0005,
        0x0000
    );
    
    // Setup Pin RA0 to a digital output
    pinMode(RA0, OUTPUT);
    digitalWrite(RA0, LOW);
    
    // Insert your setup code here, to run once:
    pinMode(RB12, INPUT);
    pinMode(RB13, INPUT);
    pinMode(RB14, INPUT);
    pinMode(RB15, OUTPUT);
    setupSPI1Slave(SPI1_SCLK_RPIN, SPI1_CS_RPIN, SPI1_MISO_RPIN, SPI1_MOSI_RPIN);
    //setupInterrupt(SPI1_GEN_INTERRUPT, 7);
    
    ENABLE_INTERRUPTS;
    
    return;
}

void loop(void){
    // Insert your loop code here, to run repeatedly:
    
    return;
}
