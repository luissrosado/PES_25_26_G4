/*
 * File:   LIS3DH.c
 * Author: gbata
 *
 * Created on 19 de Setembro de 2025, 15:33
 */

#define FCY 1000000
#include <libpic30.h>

#include "LIS3DH.h"
#include "spi.h"

int8_t who_am(){
    //int8_t tx= 0x0F;
    int16_t rx, tx=0x0F00;      //High byte e addr, low byte é dummy data pa enviar
    tx |=READ;
    chip_select();
    rx=spi2_transfer(tx);
    chip_deselect();
    if(rx==WHO_AM_I){
        digitalWrite(RB5, HIGH);
        return 0;        
    }else{
        return 1;
    }
}

// TER EM ATENÇÃO O PMD, HABILITAR O POWER DO SPI

void LISconfig(){
    int16_t tx;
    tx = (CTRL_REG0<<8 | 0x90) | WRITE; // pull up disable on SD0 line
    chip_select();
    spi2_transfer(tx);
    chip_deselect();
    tx = (CTRL_REG1<<8 | 0x47); // 50hz output data rate (ODR)
    chip_select();
    spi2_transfer(tx);
    chip_deselect();
    tx = (CTRL_REG4<<8 | 0x00); // full scale +-2g (~20 m/s2)
    chip_select();
    spi2_transfer(tx);
    chip_deselect();
    return;
}

void accel(LIS *accel){ //saida dos valores não esta convertido, fazer conversao apos enviar devboard (multiplicar por 39)
    int16_t accx_l=0x2800, tx;
    int8_t accL, accH;      //valores LOW e HIGH byte da accelaracao respetivamente
    tx = accx_l | READ;
    chip_select();
    __delay_ms(100);
    accL=spi2_transfer(tx);
    chip_deselect();
    tx+=0x0100;   
    chip_select();
    accH=spi2_transfer(tx);
    chip_deselect();
    accel->accelX = ((int16_t)accH << 8) | accL;
    tx+=0x0100;
    chip_select();
    accL=spi2_transfer(tx);
    chip_deselect();
    tx+=0x0100;
    chip_select();
    accH=spi2_transfer(tx);
    chip_deselect();
    accel->accelY = ((int16_t)accH << 8) | accL;
    tx+=0x0100;
    chip_select();
    accL=spi2_transfer(tx);
    chip_deselect();
    tx+=0x0100;
    chip_select();
    accH=spi2_transfer(tx);
    chip_deselect();
    accel->accelZ = ((int16_t)accH << 8) | accL;
    return;
}
