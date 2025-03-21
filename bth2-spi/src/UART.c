#include "UART.h"

void UART1_config(void){
	
	USART_InitTypeDef USART_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
  USART_InitStruct.USART_BaudRate = 9600; 
  USART_InitStruct.USART_WordLength = USART_WordLength_8b; 
  USART_InitStruct.USART_StopBits = USART_StopBits_1; 
  USART_InitStruct.USART_Parity = USART_Parity_No;
  USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStruct.USART_Mode = USART_Mode_Tx; 
	USART_Init(USART1, &USART_InitStruct);
	USART_Cmd(USART1, ENABLE);
}




void UART_SendChar(char c){
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
    USART_SendData(USART1, c);
}

void UART_SendString(char *str){
    while (*str){
        UART_SendChar(*str++);
    }
}

void USART1_Send_Hex(uint8_t num)
{
    uint8_t temp;
    temp = num >> 4;
    if(temp > 9) {
        temp += 0x37;
    } else {
        temp += 0x30;
    }
    UART_SendChar(temp);
    temp = num & 0x0F;
    if(temp > 9) {
        temp += 0x37;
    } else {
        temp += 0x30;
    }
    UART_SendChar(temp);
}

