#include "SI4735_HAL.h"

void delayMicroseconds(uint32_t us)
{
    uint32_t i;
    for (i = 0; i < us; i++)
    {
        __NOP();
    }
}

HAL_StatusTypeDef SI473X_requestFrom(uint8_t deviceAddress, uint8_t size)
{
    HAL_StatusTypeDef status;
    memset(I2C_rxBuffer, '\0', BUFFERLEN);
    tx_buffer_size = 0; // reset tx buffer size
    status = HAL_I2C_Master_Receive(&hi2c1, (deviceAddress << 1) | 1, I2C_rxBuffer, size, MAX_DELAY_TIME);
    return status;
}

uint8_t SI473X_read()
{
    return I2C_rxBuffer[tx_buffer_size++];
}

void SI473X_beginTransmission(uint8_t deviceAddress)
{
    tx_buffer_size = 0; // reset rx buffer size
    memset(I2C_txBuffer, '\0', BUFFERLEN);
    SI473X_DevAddress = deviceAddress;
}

void SI473X_write(uint8_t data)
{
    I2C_txBuffer[rx_buffer_size++] = data;
}
void SI473X_write_string(uint8_t* data,uint8_t size)
{
		tx_buffer_size = size;
		memcpy(I2C_txBuffer,data,size);
}
HAL_StatusTypeDef SI473X_endTransmission()
{
    HAL_StatusTypeDef status;
    status = HAL_I2C_Master_Transmit(&hi2c1, SI473X_DevAddress << 1, I2C_txBuffer, rx_buffer_size, MAX_DELAY_TIME);
    return status;
}


uint32_t millis(void)
{
//you need to implement this function
//	uint32_t time_us;

//	time_us = htim2.Instance->CNT;
//	time_us1 = time_us;

//	return time_us + tim2_cnt * 40000;
	return 4000;
}
