#include "Project.h"
#include "stm32f3xx_hal.h"
#include "stm32f3xx_hal_i2c.h"
#include "stm32f3xx_hal_def.h"
#include "main.h"
#include <stdint.h>
#include <stddef.h>

#ifndef RTC_MANAGER_H
#define RTC_MANAGER_H

#define RTC_I2C_ADDRESS 0xDE


HAL_StatusTypeDef rtcReadRAM(uint8_t* data);
HAL_StatusTypeDef rtcWriteRAM(uint8_t* data);
HAL_StatusTypeDef rtcReadTime(uint8_t* data);
HAL_StatusTypeDef rtcWriteTime(uint8_t* data);
HAL_StatusTypeDef rtcStart();
HAL_StatusTypeDef rtcSetSQWV();

#endif
