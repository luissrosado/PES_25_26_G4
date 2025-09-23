/*
 * File:   LIS3DH.c
 * Author: gbata
 *
 * Created on 19 de Setembro de 2025, 15:33
 */


#include "LIS3DH.h"
#include "spi.h"

int8_t who_am_i(){
    int8_t *data= 0x0F;
    int16_t tx;
    spi1_write(data);
    spi1_read(&tx);
    if(tx==WHO_AM_I){
        return 0;
    }else{
        return -1;
    }
}


