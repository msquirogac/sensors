#include "lsm303c.h"

void LSM303C_Init(LSM303C_HandleTypeDef *hsensor)
{
	LSM303C_WriteHandler write = hsensor->HAL.Write;
  LSM303C_DelayHandler delay = hsensor->HAL.Delay;
  LSM303C_InitTypeDef *init = &hsensor->Init;
	uint8_t tmpreg;
	tmpreg = (uint8_t)(init->Temp | init->OMXY | init->ODR);
	write(LSM303C_M_CTRL_REG1, &tmpreg, 1);
  delay(1);
	tmpreg = (uint8_t)(init->FS);
	write(LSM303C_M_CTRL_REG2, &tmpreg, 1);
  delay(1);
	tmpreg = (uint8_t)(init->CM);
	write(LSM303C_M_CTRL_REG3, &tmpreg, 1);
  delay(1);
	tmpreg = (uint8_t)(init->OMZ);
	write(LSM303C_M_CTRL_REG4, &tmpreg, 1);
  delay(1);
}

void LSM303C_Reset(LSM303C_HandleTypeDef *hsensor)
{
  LSM303C_WriteHandler write = hsensor->HAL.Write;
  uint8_t tmpreg;
	tmpreg = (uint8_t)(LSM303C_MAG_REBOOT | LSM303C_MAG_SOFT_RST);
	write(LSM303C_M_CTRL_REG2, &tmpreg, 1);
}

//*************************************************************************************//

uint8_t LSM303C_GetID(LSM303C_HandleTypeDef *hsensor)
{
	LSM303C_ReadHandler read = hsensor->HAL.Read;
	uint8_t tmpreg;
	read(LSM303C_M_WHO_AM_I, &tmpreg, 1);
	return tmpreg;
}

uint8_t LSM303C_GetStatus(LSM303C_HandleTypeDef *hsensor)
{
	LSM303C_ReadHandler read = hsensor->HAL.Read;
	uint8_t tmpreg;
	read(LSM303C_M_STATUS_REG, &tmpreg, 1);
	return tmpreg;
}

//*************************************************************************************//

void LSM303C_GetMagnetometer(LSM303C_HandleTypeDef *hsensor, int16_t *adcvalue)
{
	LSM303C_ReadHandler read = hsensor->HAL.Read;
	uint8_t tmpreg[6];
	read(LSM303C_M_OUT_X_L, tmpreg, 6);
	adcvalue[0] = (int16_t)(((uint16_t)tmpreg[1] << 8) | tmpreg[0]);
	adcvalue[1] = (int16_t)(((uint16_t)tmpreg[3] << 8) | tmpreg[2]);
	adcvalue[2] = (int16_t)(((uint16_t)tmpreg[5] << 8) | tmpreg[4]);
}

void LSM303C_GetTemperature(LSM303C_HandleTypeDef *hsensor, int16_t *adcvalue)
{
}