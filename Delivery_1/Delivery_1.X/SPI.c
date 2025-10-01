/*
 * File:   SPI.c
 * Author: João Duarte
 *
 * Created on 24 September 2025, 22:33
 */


#include "xc.h"
#include "SPI.h"

<<<<<<< Updated upstream
=======
extern LDR_Registers_t LDR;
#define USE_LDR 1
>>>>>>> Stashed changes

// SPI 1 Interrupt Function
void SPI1_RX_ISR(void){
    uint16_t received = SPI1BUFL;
    
    if (received == CMD_FROM_BOARD) {
<<<<<<< Updated upstream
        SPI1BUFL = REPLY_TO_BOARD;  // Queue response for next transfer
=======
    #if USE_LDR 
        if (!LDR.value){
            SPI1BUFL = LDR.value;  // Queue response for next transfer
        } else{
            SPI1BUFL = REPLY_TO_BOARD;
        }
    #else 
        SPI1BUFL = REPLY_TO_BOARD;
    #endif
>>>>>>> Stashed changes
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
