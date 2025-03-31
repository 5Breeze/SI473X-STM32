#ifndef _SI4735_HAL_H_
#define _SI4735_HAL_H_

#define BUFFERLEN 32
#define MAX_DELAY_TIME 1000

#define GPIO_SI473X GPIOA
#define GPIO_SI473X_PIN GPIO_PIN_4

#define GPIO_SI473X_MUTE GPIOA
#define GPIO_SI473X_PIN_MUTE GPIO_PIN_4

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


void delayMicroseconds(uint32_t us);
HAL_StatusTypeDef SI473X_requestFrom(uint8_t deviceAddress, uint8_t size);
uint8_t SI473X_read();
void SI473X_beginTransmission(uint8_t deviceAddress);
void SI473X_write(uint8_t data);
HAL_StatusTypeDef SI473X_endTransmission();
void SI473X_write_string(uint8_t* data,uint8_t size);
uint32_t millis(void);
#endif // _SI4735_HAL_H_