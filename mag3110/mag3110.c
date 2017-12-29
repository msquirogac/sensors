#include "mag3110.h"

void MAG3110_Init(MAG3110_HandleTypeDef *hsensor)
{
	MAG3110_WriteHandler write = hsensor->HAL.Write;
	MAG3110_InitTypeDef *init = &hsensor->Init;
	uint8_t tmpreg;
	tmpreg = (uint8_t)(MAG3110_AUTO_MRST_ENABLE);
	write(MAG3110_CTRL_REG2, &tmpreg, 1);
	tmpreg = (uint8_t)(init->ADC_Rate | init->Average_Sample | init->Fast_Read | init->Trigger_Mode | init->Working_Mode);
	write(MAG3110_CTRL_REG1, &tmpreg, 1);
}

void MAG3110_Reset(MAG3110_HandleTypeDef *hsensor)
{
	MAG3110_WriteHandler write = hsensor->HAL.Write;
	uint8_t tmpreg = MAG3110_MAG_RST;
	write(MAG3110_CTRL_REG2, &tmpreg, 1);
}

//*************************************************************************************//

uint8_t MAG3110_GetID(MAG3110_HandleTypeDef *hsensor)
{
	MAG3110_ReadHandler read = hsensor->HAL.Read;
	uint8_t tmpreg;
	read(MAG3110_WHO_AM_I, &tmpreg, 1);
	return tmpreg;
}

uint8_t MAG3110_GetStatus(MAG3110_HandleTypeDef *hsensor)
{
	MAG3110_ReadHandler read = hsensor->HAL.Read;
	uint8_t tmpreg;
	read(MAG3110_DR_STATUS, &tmpreg, 1);
	return tmpreg;
}

//*************************************************************************************//

void MAG3110_GetMagnetometer(MAG3110_HandleTypeDef *hsensor, int16_t *adcvalue)
{
	MAG3110_ReadHandler read = hsensor->HAL.Read;
	uint8_t tmpreg[6];
	read(MAG3110_OUT_X_MSB, tmpreg, 6);
	adcvalue[0] = (int16_t)(((uint16_t)tmpreg[0] << 8) | tmpreg[1]);
	adcvalue[1] = (int16_t)(((uint16_t)tmpreg[2] << 8) | tmpreg[3]);
	adcvalue[2] = (int16_t)(((uint16_t)tmpreg[4] << 8) | tmpreg[5]);
}

void MAG3110_GetTemperature(MAG3110_HandleTypeDef *hsensor, int16_t *adcvalue)
{
	MAG3110_ReadHandler read = hsensor->HAL.Read;
	uint8_t tmpreg[2];
	read(MAG3110_DIE_TEMP, tmpreg, 1);
	adcvalue[0] = (int16_t)tmpreg[0];
}