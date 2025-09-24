/*
 * File:   LIS3DH.c
 * Author: gbata
 *
 * Created on 19 de Setembro de 2025, 15:33
 */


#include "LIS3DH.h"
#include "spi.h"

int8_t who_am(){
    //int8_t tx= 0x0F;
    int16_t rx, tx=0x0F00;      //High byte e addr, low byte é dummy data pa enviar
    chip_select();
    rx=spi1_transfer(tx);
    chip_deselect();
    if(rx==WHO_AM_I){
        return 0;
    }else{
        return -1;
    }
}

void LISconfig(){
    int16_t tx;
    tx = (CTRL_REG0<<8 | 0x90) | WRITE; // pull up disable on SD0 line
    chip_select();
    spi1_transfer(tx);
    chip_deselect();
    tx = (CTRL_REG1<<8 | 0x47); // 50hz output data rate (ODR)
    chip_select();
    spi1_transfer(tx);
    chip_deselect();
    tx = (CTRL_REG4<<8 | 0x00); // full scale +-2g (~20 m/s2)
    chip_select();
    spi1_transfer(tx);
    chip_deselect();
    return;
}

void accel(LIS *accel){
    int16_t tx;
    tx |= READ;
    accel->accelX=spi1_transfer(tx);
    return;
}
