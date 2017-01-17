#include "stm32f10x_conf.h"
#include "stm32f10x.h"
#include "SPI.h"

u8 SPI_Exchange_Data(SPI_TypeDef* SPIx, u8 data){
    /* ȷ�����ͼĴ����ѿ� */
    while(SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_TXE) == RESET);

    SPI_I2S_SendData(SPIx, data);

    /* ������ϣ�ͬʱ���յ�����*/
    while(SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_RXNE) == RESET);

    return SPI_I2S_ReceiveData(SPIx);
}