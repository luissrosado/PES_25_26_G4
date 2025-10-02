/*
 * File:   spi.c
 * Author: gbata
 *
 * Created on 17 de Setembro de 2025, 17:29
 */


#include "spi.h"
#include "common.h"

void spi_config_master(){
    PMD1bits.SPI2MD=0;      // ligar power module spi2
    SPI2CON1Hbits.AUDEN=0; //DISABLE AUDIO SPI
    SPI2CON1Lbits.SPISIDL=0; //Continues to operate in CPU Idle mode
    SPI2CON1Lbits.DISSDO=0;
    SPI2CON1Lbits.MODE32=0;     /*ENABLE 16BIT TRANSFER*/
    SPI2CON1Lbits.MODE16=1;
    SPI2CON1Lbits.SMP=0;    //SAMPLE ATE MIDDLE OF TIME
    SPI2CON1Lbits.CKE=0;    //IDLE TO LOW TO TRANSMIT
    SPI2CON1Lbits.CKP=1;    //IDLE HIGH
    SPI2CON1Lbits.MSTEN=1;
    SPI2CON1Lbits.DISSDI=0;
    SPI2CON1Lbits.DISSCK=0;
    SPI2CON1Lbits.SPIFE=1;
    SPI2CON1Lbits.ENHBUF=0;
    SPI2CON2Lbits.WLENGTH=0b01111;
    SPI2BRGL=7;
    spi2PinConfig();
    return;
}

void spi2_enable(){
    SPI2CON1Lbits.SPIEN=1; //enable spi2
}
void spi2_disable(){
    SPI2CON1Lbits.SPIEN=0; //enable spi2
}

void spi2_write(int16_t *data){
    
    SPI2BUFL = *data;
    return;
}
void spi2_read(int16_t *data){
    data = SPI2BUFL;
    return;
}
uint16_t spi2_transfer(uint16_t dataOut) {
    while (SPI2STATLbits.SPITBF);   // Espera que o buffer TX fique livre
    SPI2BUFL = dataOut;             // Envia 16 bits, o HIGH BYTE e o address, o low byte é os dados po addr
    while (!SPI2STATLbits.SPIRBF);  // Espera receção
    return SPI2BUFL;                // Retorna dado recebido
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
    RPOR3bits.RP6R =10;
    RPOR3bits.RP7R =11;
    RPINR22bits.SDI2R = 2; //RP2 supposedly
}
