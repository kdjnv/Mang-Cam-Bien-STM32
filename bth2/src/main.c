#include "stm32f10x.h"
#include "Delay_Tim.h"
#include "GPIO.h"
#include "DHT11.h"

//DE CHECK GIA TRI DOC DUOC CHI CO THE DEBUG

float Temp = 1;
float Humi = 1;
DHT11_Name DHT11;


int main(){
	SystemInit();
	DHT11_Init(&DHT11, GPIOC, GPIO_Pin_14);
	GPIO_Config();
	TIM2_Config();
	while(1){
		Temp = DHT11_ReadTemp(&DHT11);
		Humi = DHT11_ReadHumi(&DHT11);
		delay_ms(500);
	}
}
