#ifndef __SPI__
#define __SPI__


#include "stm32f10x.h"                 

void SPI_Config(void);
uint8_t SPI_SendByte(uint8_t byte);


#endif