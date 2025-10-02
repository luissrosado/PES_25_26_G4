/*
 * File:   SPI.c
 * Author: João Duarte
 *
 * Created on 24 September 2025, 22:33
 */


#include "xc.h"
#include "SPI.h"
#include "ldr.h"
#include "../../PIC24_Lib/PIC24FJ256GA702_lib.X/PIC24FJ256GA702_lib.h"


#define USE_LDR 1
#define USE_AXL 1

// SPI 1 Interrupt Function
void SPI1_RX_ISR(void){
    uint16_t received = SPI1BUFL;
    
    switch (received){
    #if USE_LDR
        case CMD_LDR_VAL:
            SPI1BUFL = LDR.value;
            
            break;
            
        case CMD_LDR_CNT:
            SPI1BUFL = LDR.count;
            
            break;
    #endif
            
    #if USE_AXL
        // TEMP AXL
        case CMD_AXL_X:
            SPI1BUFL = 0x1001;
            
            break;
            
        case CMD_AXL_Y:
            SPI1BUFL = 0x1002;
            
            break;
            
        case CMD_AXL_Z:
            SPI1BUFL = 0x1004;
            
            break;
    #endif
            
            
        case CMD_ERROR:
            SPI1BUFL = ERR_REPLY_TO_BOARD;
            
            break;
            
        default:
            SPI1BUFL = STD_REPLY_TO_BOARD;
            
    }
  
    if (SPI1STATLbits.SPIROV) {
        volatile uint8_t dump = SPI1BUFL;
        (void)dump;
        SPI1STATLbits.SPIROV = 0;
    }
    
    IFS3bits.SPI1RXIF = 0;
    return;
}
