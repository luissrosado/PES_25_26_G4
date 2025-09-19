/*
 * File:   spi.c
 * Author: gbata
 *
 * Created on 17 de Setembro de 2025, 17:29
 */


#include "spi.h"

void spi_config_master(){
    SPI1CON1Hbits.AUDEN=0; //DISABLE AUDIO SPI
    SPI1CON1Lbits.SPISIDL=0; //Continues to operate in CPU Idle mode
    SPI1CON1Lbits.DISSDO=0;
    SPI1CON1Lbits.MODE32=0;     /*ENABLE 16BIT TRANSFER*/
    SPI1CON1Lbits.MODE16=1;
    SPI1CON1Lbits.SMP=0;    //SAMPLE ATE MIDDLE OF TIME
    SPI1CON1Lbits.CKE=0;    //IDLE TO LOW TO TRANSMIT
    SPI1CON1Lbits.CKP=1;    //IDLE HIGH
    SPI1CON1Lbits.MSTEN=1;
    SPI1CON1Lbits.DISSDI=0;
    SPI1CON1Lbits.DISSCK=0;
    SPI1CON1Lbits.SPIFE=1;
    SPI1CON1Lbits.ENHBUF=0;
    SPI1CON2Lbits.WLENGTH=0b01111;
    return;
}

void spi1_enable(){
    SPI1CON1Lbits.SPIEN=1; //enable spi1
}
void spi1_disable(){
    SPI1CON1Lbits.SPIEN=0; //enable spi1
}

void spi1_write(int16_t *data){
    SPI1BUFL = &data;
    return;
}
