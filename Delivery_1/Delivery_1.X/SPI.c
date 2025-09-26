/*
 * File:   SPI.c
 * Author: João Duarte
 *
 * Created on 24 September 2025, 22:33
 */


#include "xc.h"
#include "SPI.h"
#include "../../PIC24_Lib/PIC24FJ256GA702_lib.X/PIC24FJ256GA702_lib.h"
#include "ldr.h"

extern LDR_Registers_t LDR;

// SPI 1 Interrupt Function
void SPI1_RX_ISR(void){
    uint16_t received = SPI1BUFL;
    
    if (received == CMD_FROM_BOARD) {
        if (!LDR.value){
            SPI1BUFL = LDR.value;  // Queue response for next transfer
        } else{
            SPI1BUFL = REPLY_TO_BOARD;
        }
    } else{
        SPI1BUFL = 0x0FF0;
    }
  
    if (SPI1STATLbits.SPIROV) {
        volatile uint8_t dump = SPI1BUFL;
        (void)dump;
        SPI1STATLbits.SPIROV = 0;
    }
    
    IFS3bits.SPI1RXIF = 0;
    return;
}
