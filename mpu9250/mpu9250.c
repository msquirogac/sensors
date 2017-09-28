#include "mpu9250.h"

void MPU9250_Init(MPU9250_HandleTypeDef *mpu9250)
{
	MPU9250_ReadHandler read = mpu9250->HAL.Read;
	MPU9250_WriteHandler write = mpu9250->HAL.Write;
	MPU9250_InitTypeDef *init = &mpu9250->Init;
	uint8_t tmpreg;
}

void MPU9250_InitGyroscope(MPU9250_HandleTypeDef *mpu9250)
{
	MPU9250_ReadHandler read = mpu9250->HAL.Read;
	MPU9250_WriteHandler write = mpu9250->HAL.Write;
	MPU9250G_InitTypeDef *init = &mpu9250->InitGyro;
	uint8_t tmpreg;
	read(MPU9250_PWR_MGMT_2, &tmpreg, 1);
	tmpreg = (uint8_t)(((~init->Enable_Axis) & 0x07) | (tmpreg & 0x38));
	write(MPU9250_PWR_MGMT_2, &tmpreg, 1);
	tmpreg = (uint8_t)(init->DLPF_Config);
	write(MPU9250_CONFIG, &tmpreg, 1);
	tmpreg = (uint8_t)(init->Full_Scale);
	write(MPU9250_GYRO_CONFIG, &tmpreg, 1);
}

void MPU9250_InitAccelerometer(MPU9250_HandleTypeDef *mpu9250)
{
	MPU9250_ReadHandler read = mpu9250->HAL.Read;
	MPU9250_WriteHandler write = mpu9250->HAL.Write;
	MPU9250A_InitTypeDef *init = &mpu9250->InitAccel;
	uint8_t tmpreg;
	read(MPU9250_PWR_MGMT_2, &tmpreg, 1);
	tmpreg = (uint8_t)(((~init->Enable_Axis) & 0x38) | (tmpreg & 0x07));
	write(MPU9250_PWR_MGMT_2, &tmpreg, 1);
	tmpreg = (uint8_t)(init->Full_Scale);
	write(MPU9250_ACCEL_CONFIG, &tmpreg, 1);
	tmpreg = (uint8_t)(init->DLPF_Config);
	write(MPU9250_ACCEL_CONFIG2, &tmpreg, 1);
}

void MPU9250_InitMagnetometer(MPU9250_HandleTypeDef *mpu9250)
{
	MPU9250_WriteHandler write = mpu9250->HAL.Write;
	MPU9250_DelayHandler delay = mpu9250->HAL.Delay;
	MPU9250M_InitTypeDef *init = &mpu9250->InitMagnet;
	uint8_t tmpreg[4];

	tmpreg[0] = 0x20;
	write(MPU9250_USER_CTRL, tmpreg, 1);

	tmpreg[0] = AK8963_I2C_ADDR;
	tmpreg[1] = AK8963_CNTL2;
	tmpreg[2] = 0x01;
	tmpreg[3] = 0x80;
	write(MPU9250_I2C_SLV4_ADDR, tmpreg, 4);
	delay(1);

	tmpreg[0] = AK8963_I2C_ADDR;
	tmpreg[1] = AK8963_CNTL1;
	tmpreg[2] = (uint8_t)(init->Full_Resolution | init->Working_Mode);
	tmpreg[3] = 0x80;
	write(MPU9250_I2C_SLV4_ADDR, tmpreg, 4);
	delay(1);

	tmpreg[0] = AK8963_I2C_ADDR | MPU9250_READ_FLAG;
	tmpreg[1] = AK8963_HXL;
	tmpreg[2] = 0x87;
	write(MPU9250_I2C_SLV0_ADDR, tmpreg, 3);
	delay(1);
}

void MPU9250_Reset(MPU9250_HandleTypeDef *mpu9250)
{
	MPU9250_WriteHandler write = mpu9250->HAL.Write;
	uint8_t tmpreg = MPU9250_H_RESET;
	write(MPU9250_PWR_MGMT_1, &tmpreg, 1);
}

//*************************************************************************************//

uint8_t MPU9250_GetID(MPU9250_HandleTypeDef *mpu9250)
{
	MPU9250_ReadHandler read = mpu9250->HAL.Read;
	uint8_t tmpreg;
	read(MPU9250_WHO_AM_I, &tmpreg, 1);
	return tmpreg;
}

uint8_t MPU9250_GetMagnetID(MPU9250_HandleTypeDef *mpu9250)
{
	MPU9250_ReadHandler read = mpu9250->HAL.Read;
	MPU9250_WriteHandler write = mpu9250->HAL.Write;
	MPU9250_DelayHandler delay = mpu9250->HAL.Delay;
	uint8_t tmpreg[3];
	tmpreg[0] = AK8963_I2C_ADDR | MPU9250_READ_FLAG;
	tmpreg[1] = AK8963_WIA;
	tmpreg[2] = 0x81;
	write(MPU9250_I2C_SLV1_ADDR, tmpreg, 3);
	delay(1);

	read(MPU9250_EXT_SENS_DATA_07, tmpreg, 1);
	tmpreg[1] = 0x00;
	write(MPU9250_I2C_SLV1_CTRL, tmpreg + 1, 1);
	return tmpreg[0];
}

//*************************************************************************************//

void MPU9250_GetTemperature(MPU9250_HandleTypeDef *mpu9250, int32_t *adcvalue)
{
	MPU9250_ReadHandler read = mpu9250->HAL.Read;
	uint8_t tmpreg[2];
	read(MPU9250_TEMP_OUT_H, tmpreg, 2);
	adcvalue[0] = (int16_t)(((uint16_t)tmpreg[0] << 8) | tmpreg[1]);
}

void MPU9250_GetGyroscope(MPU9250_HandleTypeDef *mpu9250, int32_t *adcvalue)
{
	MPU9250_ReadHandler read = mpu9250->HAL.Read;
	uint8_t tmpreg[6];
	read(MPU9250_GYRO_XOUT_H, tmpreg, 6);
	adcvalue[0] = (int16_t)(((uint16_t)tmpreg[0] << 8) | tmpreg[1]);
	adcvalue[1] = (int16_t)(((uint16_t)tmpreg[2] << 8) | tmpreg[3]);
	adcvalue[2] = (int16_t)(((uint16_t)tmpreg[4] << 8) | tmpreg[5]);
}

void MPU9250_GetAccelerometer(MPU9250_HandleTypeDef *mpu9250, int32_t *adcvalue)
{
	MPU9250_ReadHandler read = mpu9250->HAL.Read;
	uint8_t tmpreg[6];
	read(MPU9250_ACCEL_XOUT_H, tmpreg, 6);
	adcvalue[0] = (int16_t)(((uint16_t)tmpreg[0] << 8) | tmpreg[1]);
	adcvalue[1] = (int16_t)(((uint16_t)tmpreg[2] << 8) | tmpreg[3]);
	adcvalue[2] = (int16_t)(((uint16_t)tmpreg[4] << 8) | tmpreg[5]);
}

void MPU9250_GetMagnetometer(MPU9250_HandleTypeDef *mpu9250, int32_t *adcvalue)
{
	MPU9250_ReadHandler read = mpu9250->HAL.Read;
	uint8_t tmpreg[6];
	read(MPU9250_EXT_SENS_DATA_00, tmpreg, 6);
	adcvalue[0] = (int16_t)(((uint16_t)tmpreg[1] << 8) | tmpreg[0]);
	adcvalue[1] = (int16_t)(((uint16_t)tmpreg[3] << 8) | tmpreg[2]);
	adcvalue[2] = (int16_t)(((uint16_t)tmpreg[5] << 8) | tmpreg[4]);
}