#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H

#include "stm32f10x.h"
#include "TIM.h"

#define LED_PIN GPIO_Pin_13
#define LED_PORT GPIOC

void GPIO_Config(void);
void Debug(void);

#endif