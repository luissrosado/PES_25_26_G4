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

#include "SPI_Pins.h"

void SPI1_GEN_ISR(void){
    uint8_t received = SPI1BUFL; // Read received byte
    
    if (received == CMD_FROM_MASTER) {
        SPI1BUFL = RESPONSE_TO_SEND;  // Queue response for next transfer
    }
    
    return;
}

void setup(void){
    // Insert your setup code here, to run once:
    setupSPI1Slave(SPI1_SCLK_RPIN, SPI1_CS_RPIN, SPI1_MISO_RPIN, SPI1_MOSI_RPIN);
    
    
    // Setup Oscillator with the FRC = 8 MHz
    // OSCDIV = 0x0005 means frequency = 8 MHz / 10 = 0.8 MHz
    setupOsc(
        0x0000,
        0x0000,
        0x0000,
        0x0005,
        0x0000
    );
    
    return;
}

void loop(void){
    // Insert your loop code here, to run repeatedly:
    
    return;
}
