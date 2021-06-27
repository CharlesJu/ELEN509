#include "RTC_manager.h"

extern I2C_HandleTypeDef hi2c1;

HAL_StatusTypeDef rtcReadRAM(uint8_t* data){
  return HAL_I2C_Mem_Read(&hi2c1, RTC_I2C_ADDRESS, 0x20, 
                          I2C_MEMADD_SIZE_8BIT, data, 8, 1000);
}

HAL_StatusTypeDef rtcWriteRAM(uint8_t* data){
  return HAL_I2C_Mem_Write(&hi2c1, RTC_I2C_ADDRESS, 0x20, 
                           I2C_MEMADD_SIZE_8BIT, data, 8, 1000);
}

HAL_StatusTypeDef rtcReadTime(uint8_t* data){
  return HAL_I2C_Mem_Read(&hi2c1, RTC_I2C_ADDRESS, 0x00, 
                          I2C_MEMADD_SIZE_8BIT, data, 8, 1000);
}

HAL_StatusTypeDef rtcWriteTime(uint8_t* data){
  return HAL_I2C_Mem_Write(&hi2c1, RTC_I2C_ADDRESS, 0x00, 
                           I2C_MEMADD_SIZE_8BIT, data, 8, 1000);
}

HAL_StatusTypeDef rtcStart(){
  
  // place a 0x08 in the [0] location
  uint8_t rtcData = 0x08;
  if(HAL_I2C_Mem_Write(&hi2c1, RTC_I2C_ADDRESS, 0x07, 
                    I2C_MEMADD_SIZE_8BIT, &rtcData, 1, 1000) == HAL_OK)
    return HAL_ERROR;
  
  
  // place a 0x80 in the [4] location
  rtcData = 0x80;
  if(HAL_I2C_Mem_Write(&hi2c1, RTC_I2C_ADDRESS, 0x00, 
                    I2C_MEMADD_SIZE_8BIT, &rtcData, 1, 1000) != HAL_OK)
     return HAL_ERROR;
  return HAL_OK;
}

HAL_StatusTypeDef rtcSetSQWV(){
  uint8_t rtcData = 0x4C;
  return HAL_I2C_Mem_Write(&hi2c1, RTC_I2C_ADDRESS, 0x07, 
                    I2C_MEMADD_SIZE_8BIT, &rtcData, 1, 1000); 
}
