#ifndef _SI4735_HAL_H_
#define _SI4735_HAL_H_

#define BUFFERLEN 32
#define MAX_DELAY_TIME 1000

#define GPIO_SI473X GPIO_A
#define GPIO_SI473X_PIN GPIO_PIN_4

#include "main.h"
#include "stm32f0xx_hal.h"
#include "stdbool.h"
#include "string.h"

extern I2C_HandleTypeDef hi2c1;

static uint8_t I2C_rxBuffer[BUFFERLEN];
static uint8_t I2C_txBuffer[BUFFERLEN];

static uint8_t tx_buffer_size = 0;
static uint8_t rx_buffer_size = 0;

static uint16_t SI473X_DevAddress;

#endif // _SI4735_HAL_H_