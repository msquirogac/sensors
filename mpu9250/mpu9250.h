#include "mpu9250_api.h"
#include "mpu9250_types.h"
#include <stddef.h>

extern void MPU9250_Read(uint8_t Address, uint8_t *Buffer, size_t NumBytes);
extern void MPU9250_Write(uint8_t Address, uint8_t *Buffer, size_t NumBytes);
extern void MPU9250_Delay(uint32_t Delay);

//*************************************************************************************//

void MPU9250_Init(MPU9250_HandleTypeDef *mpu9250);
void MPU9250_InitGyroscope(MPU9250_HandleTypeDef *mpu9250);
void MPU9250_InitAccelerometer(MPU9250_HandleTypeDef *mpu9250);
void MPU9250_InitMagnetometer(MPU9250_HandleTypeDef *mpu9250);
void MPU9250_Reset(MPU9250_HandleTypeDef *mpu9250);

//*************************************************************************************//

uint8_t MPU9250_GetID(MPU9250_HandleTypeDef *mpu9250);
uint8_t MPU9250_GetMagnetID(MPU9250_HandleTypeDef *mpu9250);

//*************************************************************************************//

void MPU9250_GetTemperature(MPU9250_HandleTypeDef *mpu9250, int32_t *adcvalue);
void MPU9250_GetGyroscope(MPU9250_HandleTypeDef *mpu9250, int32_t *adcvalue);
void MPU9250_GetAccelerometer(MPU9250_HandleTypeDef *mpu9250, int32_t *adcvalue);
void MPU9250_GetMagnetometer(MPU9250_HandleTypeDef *mpu9250, int32_t *adcvalue);