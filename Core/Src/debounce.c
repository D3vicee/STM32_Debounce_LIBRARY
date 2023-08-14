/*
 * debounce.c
 *
 *  Created on: Aug 14, 2023
 *      Author: D3vice
 */
#include "main.h"

uint16_t ms_counter = 0, but_state = 0, but_count= 0 ;

void Debounce(GPIO_TypeDef* BUT_GPIOx, uint16_t BUT_GPIO_Pin, uint8_t BUT_debounce_time )
{
	if( HAL_GPIO_ReadPin( BUT_GPIOx,  BUT_GPIO_Pin)== GPIO_PIN_SET && but_state == 0){
		ms_counter++;
		if(ms_counter >= BUT_debounce_time){
			but_state = 1;
			but_count++;
		}
	}
	else if(HAL_GPIO_ReadPin( BUT_GPIOx,  BUT_GPIO_Pin)== GPIO_PIN_RESET && but_state == 1){
		ms_counter = 0;
		but_state = 0;
	}
}
