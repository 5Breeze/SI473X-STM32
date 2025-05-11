#ifndef _SI4735_HAL_H_
#define _SI4735_HAL_H_

#define BUFFERLEN 32
#define MAX_DELAY_TIME 1000

#define GPIO_SI473X GPIOB
#define GPIO_SI473X_PIN GPIO_PIN_5

#define GPIO_SI473X_MUTE GPIOB
#define GPIO_SI473X_PIN_MUTE GPIO_PIN_9

#include "stm32f0xx_hal.h"
#include "stdbool.h"
#include "string.h"

extern I2C_HandleTypeDef hi2c1;

	void i2cWrite(uint8_t *data, size_t len, uint16_t dev_addr);
	void i2cWriteTo(uint8_t *data, size_t len, uint16_t dev_addr, uint16_t to);
	void i2cRead(uint8_t *data, size_t len, uint16_t dev_addr);
	void i2cReadFrom(uint8_t *data, size_t len, uint16_t dev_addr, uint16_t from);
	uint32_t _millis(void);
#endif // _SI4735_HAL_H_