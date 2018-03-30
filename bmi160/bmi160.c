#include "bmi160.h"

void BMI160_Init(BMI160_HandleTypeDef *hsensor)
{
  BMI160_WriteHandler write = hsensor->HAL.Write;
  BMI160_DelayHandler delay = hsensor->HAL.Delay;
  uint8_t tmpreg;
  tmpreg = (uint8_t)(BMI160_GYRO_NORMAL);
  write(BMI160_CMD, &tmpreg, 1);
  delay(100);
  tmpreg = (uint8_t)(BMI160_ACCEL_NORMAL);
  write(BMI160_CMD, &tmpreg, 1);
  delay(100);
}

void BMI160_InitGyroscope(BMI160_HandleTypeDef *hsensor)
{
  BMI160_WriteHandler write = hsensor->HAL.Write;
  BMI160G_InitTypeDef *init = &hsensor->InitGyro;
  uint8_t tmpreg;
  tmpreg = (uint8_t)(init->ODR | init->OSR);
  write(BMI160_GYR_CONF, &tmpreg, 1);
  tmpreg = (uint8_t)(init->Range);
  write(BMI160_GYR_RANGE, &tmpreg, 1);
}

void BMI160_InitAccelerometer(BMI160_HandleTypeDef *hsensor)
{
  BMI160_WriteHandler write = hsensor->HAL.Write;
  BMI160A_InitTypeDef *init = &hsensor->InitAccel;
  uint8_t tmpreg;
  tmpreg = (uint8_t)(init->US | init->ODR | init->OSR);
  write(BMI160_ACC_CONF, &tmpreg, 1);
  tmpreg = (uint8_t)(init->Range);
  write(BMI160_ACC_RANGE, &tmpreg, 1);
}

void BMI160_Reset(BMI160_HandleTypeDef *hsensor)
{
}

//*************************************************************************************//

uint8_t BMI160_GetID(BMI160_HandleTypeDef *hsensor)
{
  BMI160_ReadHandler read = hsensor->HAL.Read;
  uint8_t tmpreg;
  read(BMI160_CHIP_ID, &tmpreg, 1);
  return tmpreg;
}

uint8_t BMI160_GetStatus(BMI160_HandleTypeDef *hsensor)
{
  BMI160_ReadHandler read = hsensor->HAL.Read;
  uint8_t tmpreg;
  read(BMI160_STATUS, &tmpreg, 1);
  return tmpreg;
}

//*************************************************************************************//

void BMI160_GetGyroscope(BMI160_HandleTypeDef *hsensor, int16_t *adcvalue)
{
  BMI160_ReadHandler read = hsensor->HAL.Read;
  uint8_t tmpreg[6];
  read(BMI160_DATA_8, tmpreg, 6);
  adcvalue[0] = (int16_t)(((uint16_t)tmpreg[1] << 8) | tmpreg[0]);
  adcvalue[1] = (int16_t)(((uint16_t)tmpreg[3] << 8) | tmpreg[2]);
  adcvalue[2] = (int16_t)(((uint16_t)tmpreg[5] << 8) | tmpreg[4]);
}

void BMI160_GetAccelerometer(BMI160_HandleTypeDef *hsensor, int16_t *adcvalue)
{
  BMI160_ReadHandler read = hsensor->HAL.Read;
  uint8_t tmpreg[6];
  read(BMI160_DATA_14, tmpreg, 6);
  adcvalue[0] = (int16_t)(((uint16_t)tmpreg[1] << 8) | tmpreg[0]);
  adcvalue[1] = (int16_t)(((uint16_t)tmpreg[3] << 8) | tmpreg[2]);
  adcvalue[2] = (int16_t)(((uint16_t)tmpreg[5] << 8) | tmpreg[4]);
}

void BMI160_GetTemperature(BMI160_HandleTypeDef *hsensor, int16_t *adcvalue)
{
  BMI160_ReadHandler read = hsensor->HAL.Read;
  uint8_t tmpreg[2];
  read(BMI160_TEMPERATURE_0, tmpreg, 2);
  adcvalue[0] = (int16_t)(((uint16_t)tmpreg[1] << 8) | tmpreg[0]);
}