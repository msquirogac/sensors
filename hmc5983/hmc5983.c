#include "hmc5983.h"

void HMC5983_Init(HMC5983_HandleTypeDef *hsensor)
{
	HMC5983_WriteHandler write = hsensor->HAL.Write;
	HMC5983_InitTypeDef *init = &hsensor->Init;
	uint8_t tmpreg;
	tmpreg = (uint8_t)(init->Temperature_Sensor | init->Average_Sample | init->Output_DataRate);
	write(HMC5983_CRA, &tmpreg, 1);
	tmpreg = (uint8_t)(init->Full_Scale);
	write(HMC5983_CRB, &tmpreg, 1);
	tmpreg = (uint8_t)(init->Working_Mode);
	write(HMC5983_MR, &tmpreg, 1);
}

//*************************************************************************************//

uint8_t HMC5983_GetID(HMC5983_HandleTypeDef *hsensor)
{
	HMC5983_ReadHandler read = hsensor->HAL.Read;
	uint8_t tmpreg;
	read(HMC5983_IRA, &tmpreg, 1);
	return tmpreg;
}

uint8_t HMC5983_GetStatus(HMC5983_HandleTypeDef *hsensor)
{
	HMC5983_ReadHandler read = hsensor->HAL.Read;
	uint8_t tmpreg;
	read(HMC5983_SR, &tmpreg, 1);
	return tmpreg;
}

//*************************************************************************************//

void HMC5983_GetMagnetometer(HMC5983_HandleTypeDef *hsensor, int16_t *adcvalue)
{
	HMC5983_ReadHandler read = hsensor->HAL.Read;
	uint8_t tmpreg[6];
	read(HMC5983_DXRA, tmpreg, 6);
	adcvalue[0] = (int16_t)(((uint16_t)tmpreg[0] << 8) | tmpreg[1]);
	adcvalue[1] = (int16_t)(((uint16_t)tmpreg[4] << 8) | tmpreg[5]);
	adcvalue[2] = (int16_t)(((uint16_t)tmpreg[2] << 8) | tmpreg[3]);
}

void HMC5983_GetTemperature(HMC5983_HandleTypeDef *hsensor, int16_t *adcvalue)
{
	HMC5983_ReadHandler read = hsensor->HAL.Read;
	uint8_t tmpreg[2];
	read(HMC5983_TEMPH, tmpreg, 2);
	adcvalue[0] = (int16_t)(((uint16_t)tmpreg[0] << 8) | tmpreg[1]);
}