#include "spi.h"

void SPI_Config(void)
{
	SPI_InitTypeDef   SPI_InitStructure;
	RCC_APB1PeriphClockCmd (RCC_APB1Periph_SPI2, ENABLE);

	// Configure SPI2
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_16;
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStructure.SPI_CRCPolynomial = 7;
	SPI_Init(SPI2, &SPI_InitStructure);
	
	SPI_Cmd(SPI2, ENABLE);
}

uint8_t SPI_SendByte(uint8_t byte)
{
    // Wait until transmit buffer is empty
    while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET);
    // Send byte to SPI2
    SPI_I2S_SendData(SPI2, byte);
    // Wait to receive a byte
    while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET);
    // Return the byte read from the SPI bus
    return SPI_I2S_ReceiveData(SPI2);
}
