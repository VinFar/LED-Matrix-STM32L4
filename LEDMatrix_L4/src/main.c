#include "main.h"
#include "stm32l4xx_hal.h"
#include "cmsis_os.h"
#include "spi.h"
#include "gpio.h"
#include <string.h>
#include "matrix.h"
#include "matrix_draw.h"

void SystemClock_Config(void);
void MX_FREERTOS_Init(void);



uint16_t disp[16][64];

int main(void) {

	HAL_Init();

	SystemClock_Config();

	MX_GPIO_Init();

//  MX_FREERTOS_Init();

	/* Start scheduler */
//  osKernelStart();
	OE_HIGH;
	LAT_LOW;
	R1_HIGH;
	CLK_HIGH;

	A_LOW;
	B_LOW;
	C_LOW;
	D_LOW;

	int i = 0;

	ALL_LOW
	;
	R1_HIGH;
	R2_HIGH;
	memset(&disp, 0, DISP_SIZE);

	memset(&disp[0][0], 0, ROW_SIZE);


	for (int k = 0; k < 16; k++) {
		memset(&disp[k][0], ((k & 0b01100) << 9) | ((k & 0b0011) << 7),
				ROW_SIZE);
	}

	while (1) {

		delayUS_ASM(1000);

		matrix_update();

		asm("nop");
	}

}


void SystemClock_Config(void) {

RCC_OscInitTypeDef RCC_OscInitStruct;
RCC_ClkInitTypeDef RCC_ClkInitStruct;

RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
RCC_OscInitStruct.HSIState = RCC_HSI_ON;
RCC_OscInitStruct.HSICalibrationValue = 16;
RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
RCC_OscInitStruct.PLL.PLLM = 2;
RCC_OscInitStruct.PLL.PLLN = 20;
RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
	_Error_Handler(__FILE__, __LINE__);
}

RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
		| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK) {
	_Error_Handler(__FILE__, __LINE__);
}

if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK) {
	_Error_Handler(__FILE__, __LINE__);
}

HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq() / 1000);

HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

HAL_NVIC_SetPriority(SysTick_IRQn, 15, 0);
}


void _Error_Handler(char * file, int line) {
/* USER CODE BEGIN Error_Handler_Debug */
/* User can add his own implementation to report the HAL error return state */
while (1) {
}
}

#ifdef USE_FULL_ASSERT

void assert_failed(uint8_t* file, uint32_t line)
{

}

#endif

