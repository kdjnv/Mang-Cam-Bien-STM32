#ifndef __UART_H
#define __UART_H

#include "stm32f10x.h"

void UART1_config(void);
void UART_SendChar(char c);
void UART_SendString(char *str);
void USART1_Send_Hex(uint8_t num);

#endif
