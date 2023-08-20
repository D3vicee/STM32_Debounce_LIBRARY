/*
 * debounce.c
 *
 *  Created on: Aug 14, 2023
 *      Author: D3vice
 */
#include "main.h"
#define NUMBEROFBUTTONS				10

uint16_t BUTS_STATE[NUMBEROFBUTTONS] = {0}, BUTS_COUNT[NUMBEROFBUTTONS]= {0};

uint16_t ms_counter = 0, BUT_STATE = 0, BUT_COUNT= 0 ;

void Debounce(GPIO_TypeDef* BUT_GPIOx, uint16_t BUT_GPIO_Pin, uint8_t BUT_debounce_time )
{
	if( HAL_GPIO_ReadPin( BUT_GPIOx,  BUT_GPIO_Pin)== GPIO_PIN_SET && BUT_STATE == 0){
		ms_counter++;
		if(ms_counter >= BUT_debounce_time){
			BUT_STATE = 1;
			BUT_COUNT++;
		}
	}
	else if(HAL_GPIO_ReadPin( BUT_GPIOx,  BUT_GPIO_Pin)== GPIO_PIN_RESET && BUT_STATE == 1){
		ms_counter = 0;
		BUT_STATE = 0;
	}
}

void Multiple_Debounce(GPIO_TypeDef* BUT_GPIOx, uint16_t BUT_GPIO_Pin, uint16_t BUT_index, uint8_t BUT_debounce_time )
{
	if( HAL_GPIO_ReadPin( BUT_GPIOx,  BUT_GPIO_Pin)== GPIO_PIN_SET && BUTS_STATE[BUT_index] == 0){
		ms_counter++;
		if(ms_counter >= BUT_debounce_time){
			BUTS_STATE[BUT_index] = 1;
			BUTS_COUNT[BUT_index]++;
		}
	}
	else if(HAL_GPIO_ReadPin( BUT_GPIOx,  BUT_GPIO_Pin)== GPIO_PIN_RESET && BUTS_STATE[BUT_index] == 1){
		ms_counter = 0;
		BUTS_STATE[BUT_index] = 0;
	}
}
