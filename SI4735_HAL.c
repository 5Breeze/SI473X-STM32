#include "SI4735_HAL.h"

	void i2cWrite(uint8_t *data, size_t len, uint16_t dev_addr)
	{
		HAL_I2C_Master_Transmit(&hi2c1, dev_addr << 1, data, len, MAX_DELAY_TIME);
	}
	void i2cWriteTo(uint8_t *data, size_t len, uint16_t dev_addr, uint16_t to)
	{
		HAL_I2C_Mem_Write(&hi2c1, dev_addr << 1, to, 1, data, len, MAX_DELAY_TIME);
	}
	void i2cRead(uint8_t *data, size_t len, uint16_t dev_addr)
	{
		HAL_I2C_Master_Receive(&hi2c1, dev_addr << 1, data, len, MAX_DELAY_TIME);
	}
	void i2cReadFrom(uint8_t *data, size_t len, uint16_t dev_addr, uint16_t from)
	{
		HAL_I2C_Mem_Read(&hi2c1, dev_addr << 1, from, 1, data, len, MAX_DELAY_TIME);
	}
	uint32_t _millis()
	{
		return HAL_GetTick();
	}