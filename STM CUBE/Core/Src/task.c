/*
 * task.c
 *
 *  Created on: Nov 22, 2022
 *      Author: Welcome
 */

#include "task.h"

void blink_led1(){//tasks running periodically in 0.5 second
	HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);
}

void blink_led2(){//tasks running periodically in 1 second
	HAL_GPIO_TogglePin(LED2_GPIO_Port,LED2_Pin);
}

void blink_led3(){//tasks running periodically in 1.5 second
	HAL_GPIO_TogglePin(LED3_GPIO_Port,LED3_Pin);
}

void blink_led4(){//tasks running periodically in 2 second
	HAL_GPIO_TogglePin(LED4_GPIO_Port,LED4_Pin);
}

//one-shot task
void blink_led5(){
	HAL_GPIO_TogglePin(LED5_GPIO_Port,LED5_Pin);
}

