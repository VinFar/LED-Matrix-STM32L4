/**
 ******************************************************************************
 * File Name          : gpio.h
 * Description        : This file contains all the functions prototypes for
 *                      the gpio
 ******************************************************************************
 * This notice applies to any and all portions of this file
 * that are not between comment pairs USER CODE BEGIN and
 * USER CODE END. Other portions of this file, whether
 * inserted by the user or by software development tools
 * are owned by their respective copyright owners.
 *
 * Copyright (c) 2018 STMicroelectronics International N.V.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted, provided that the following conditions are met:
 *
 * 1. Redistribution of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of STMicroelectronics nor the names of other
 *    contributors to this software may be used to endorse or promote products
 *    derived from this software without specific written permission.
 * 4. This software, including modifications and/or derivative works of this
 *    software, must execute solely and exclusively on microcontroller or
 *    microprocessor devices manufactured by or for STMicroelectronics.
 * 5. Redistribution and use of this software other than as permitted under
 *    this license is void and will automatically terminate your rights under
 *    this license.
 *
 * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
 * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT
 * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __gpio_H
#define __gpio_H
#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"
#include "main.h"

/* USER CODE BEGIN Includes */

#define PIN_R1 GPIO_PIN_0
#define PIN_G1 GPIO_PIN_1
#define PIN_B1 GPIO_PIN_2
#define PIN_R2 GPIO_PIN_3
#define PIN_B2 GPIO_PIN_4
#define PIN_G2 GPIO_PIN_5
#define PIN_LAT GPIO_PIN_6
#define PIN_A GPIO_PIN_7
#define PIN_B GPIO_PIN_8
#define PIN_C GPIO_PIN_11
#define PIN_D GPIO_PIN_12
#define PIN_OE GPIO_PIN_0
#define PIN_CLK GPIO_PIN_1

#define BANK_R1 GPIOA
#define BANK_G1 GPIOA
#define BANK_B1 GPIOA
#define BANK_R2 GPIOA
#define BANK_B2 GPIOA
#define BANK_G2 GPIOA
#define BANK_LAT GPIOA
#define BANK_A GPIOA
#define BANK_B GPIOA
#define BANK_C GPIOA
#define BANK_D GPIOA
#define BANK_OE GPIOB
#define BANK_CLK GPIOB

#define LAT_HIGH BANK_LAT->BSRR = PIN_LAT
#define LAT_LOW BANK_LAT->BSRR = PIN_LAT<<16

#define OE_HIGH BANK_OE->BSRR = PIN_OE
#define OE_LOW BANK_OE->BSRR = PIN_OE<< 16

#define R1_HIGH BANK_R1->BSRR = PIN_R1
#define R1_LOW BANK_R1->BSRR = PIN_R1<< 16

#define B1_HIGH BANK_B1->BSRR = PIN_B1
#define B1_LOW BANK_B1->BSRR = PIN_B1<< 16

#define G1_HIGH BANK_G1->BSRR = PIN_G1
#define G1_LOW BANK_G1->BSRR = PIN_G1<< 16

#define R2_HIGH BANK_R2->BSRR = PIN_R2
#define R2_LOW BANK_R2->BSRR = PIN_R2<< 16

#define B2_HIGH BANK_B2->BSRR = PIN_B2
#define B2_LOW BANK_B2->BSRR = PIN_B2<< 16

#define G2_HIGH BANK_G2->BSRR = PIN_G2
#define G2_LOW BANK_G2->BSRR = PIN_G2<< 16

#define ALL_HIGH R1_HIGH; R2_HIGH; B1_HIGH; B2_HIGH; G1_HIGH; G2_HIGH
#define ALL_LOW R1_LOW; R2_LOW; B1_LOW; B2_LOW; G1_LOW; G2_LOW


#define CLK_HIGH BANK_CLK->BSRR = PIN_CLK
#define CLK_LOW BANK_CLK->BSRR = PIN_CLK<< 16

#define A_HIGH BANK_A->BSRR = PIN_A
#define A_LOW BANK_A->BSRR = PIN_A<< 16

#define B_HIGH BANK_B->BSRR = PIN_B
#define B_LOW BANK_B->BSRR = PIN_B<< 16

#define C_HIGH BANK_C->BSRR = PIN_C
#define C_LOW BANK_C->BSRR = PIN_C<< 16

#define D_HIGH BANK_D->BSRR = PIN_D
#define D_LOW BANK_D->BSRR = PIN_D<< 16



/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
