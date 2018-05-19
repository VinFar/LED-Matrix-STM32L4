/*
 * matrix_draw.c
 *
 *  Created on: 17.05.2018
 *      Author: root
 */

#include "main.h"
#include "gpio.h"
#include "matrix.h"
#include "matrix_draw.h"
#include "stm32l432xx.h"

int8_t matrix_update() {

	for (int k = 0; k < 16; k++) {
		OE_LOW;
		LAT_LOW;
		for (int f = 0; f < 64; f++) {
			GPIOA->ODR = disp[k][f];
			CLK_HIGH;	//Create rising edge
			CLK_LOW;
		}
		OE_HIGH;
		LAT_HIGH;

	}
	return 0;

}


void matrix_drawPixel(int8_t x,int8_t y,int8_t color){

	if(y>15){
		disp[y][x] = (disp[y][x] & MASK_FOR_UPPER_DATA) | (color << 3);
	}else{
		disp[y][x] = (disp[y][x] & MASK_FOR_LOWER_DATA) | color;
	}


}


