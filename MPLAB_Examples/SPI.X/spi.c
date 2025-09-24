/*
 * File:   spi.c
 * Author: gbata
 *
 * Created on 17 de Setembro de 2025, 17:29
 */


#include "spi.h"
#include "common.h"

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
    
    SPI1BUFL = *data;
    return;
}
void spi1_read(int16_t *data){
    data = SPI1BUFL;
    return;
}
uint16_t spi1_transfer(uint16_t dataOut) {
    while (SPI1STATLbits.SPITBF);   // Espera que o buffer TX fique livre
    SPI1BUFL = dataOut;             // Envia 16 bits, o HIGH BYTE e o address, o low byte é os dados po addr
    while (!SPI1STATLbits.SPIRBF);  // Espera receção
    return SPI1BUFL;                // Retorna dado recebido
}

void chip_select(){
    digitalWrite(RB3, LOW);
    return;
}

void chip_deselect(){
    digitalWrite(RB3, HIGH);
    return;
}

void spi2PinConfig(){
    RPOR0bits.RP0R =10;
    RPOR0bits.RP1R =11;
    RPINR22bits.SDI2R = 2; //RP2 supposedly
}
