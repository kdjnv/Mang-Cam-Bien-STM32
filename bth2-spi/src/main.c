#include "TIM.h"
#include "GPIO.h"
#include "UART.h"
#include "SPI.h"
#include "RFID.h"
#include "stdio.h"



int main(){
	
	
	SystemInit();
	GPIO_Config();
	UART1_config();
	TIM2_Config();
	SPI_Config();
	RFID_Init();
	
	
	UART_SendString("RFID System Initialized.\r\n");
	
	while(1){
		RFID_Debug_ReadCard();
		Debug();
	}
}