#ifndef __MPU9250_H
#define __MPU9250_H

#include "mpu9250_api.h"
#include "mpu9250_types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void MPU9250_Init(MPU9250_HandleTypeDef *mpu9250);
void MPU9250_InitGyroscope(MPU9250_HandleTypeDef *mpu9250);
void MPU9250_InitAccelerometer(MPU9250_HandleTypeDef *mpu9250);
void MPU9250_InitMagnetometer(MPU9250_HandleTypeDef *mpu9250);
void MPU9250_Reset(MPU9250_HandleTypeDef *mpu9250);

//*************************************************************************************//

uint8_t MPU9250_GetID(MPU9250_HandleTypeDef *mpu9250);
uint8_t MPU9250_GetMagnetID(MPU9250_HandleTypeDef *mpu9250);

//*************************************************************************************//

void MPU9250_GetTemperature(MPU9250_HandleTypeDef *mpu9250, int16_t *adcvalue);
void MPU9250_GetGyroscope(MPU9250_HandleTypeDef *mpu9250, int16_t *adcvalue);
void MPU9250_GetAccelerometer(MPU9250_HandleTypeDef *mpu9250, int16_t *adcvalue);
void MPU9250_GetMagnetometer(MPU9250_HandleTypeDef *mpu9250, int16_t *adcvalue);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __MPU9250_H */