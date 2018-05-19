/*
 * matrix.h
 *
 *  Created on: 17.05.2018
 *      Author: root
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "stm32l432xx.h"

extern uint16_t disp[16][64];

/*
 * 	Bit:	12 11 10 9  8  7  6  5  4  3  2  1  0
 * 	Pin:	A  B  X  X  C  D  X  R2 G2 B2 R1 G1 B1
 *						         (lower)  (upper)
 *
 *
 */

#define DISP_SIZE sizeof(disp)
#define ROW_SIZE (sizeof(disp)/64)


#endif /* MATRIX_H_ */
