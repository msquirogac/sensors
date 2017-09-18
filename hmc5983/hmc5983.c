#include "hmc5983.h"

void HMC5983_Init(HMC5983_HandleTypeDef *hmc5983)
{
	HMC5983_InitTypeDef *init = &hmc5983->Init;
	uint8_t tmpreg;
	tmpreg = (uint8_t)(init->Temperature_Sensor | init->Average_Sample | init->Output_DataRate);
	HMC5983_Write(HMC5983_CRA, &tmpreg, 1);
	tmpreg = (uint8_t)(init->Full_Scale);
	HMC5983_Write(HMC5983_CRB, &tmpreg, 1);
	tmpreg = (uint8_t)(init->Working_Mode);
	HMC5983_Write(HMC5983_MR, &tmpreg, 1);
}

//*************************************************************************************//

uint8_t HMC5983_GetID(HMC5983_HandleTypeDef *hmc5983)
{
	uint8_t tmpreg;
	HMC5983_Read(HMC5983_IRA, &tmpreg, 1);
	return tmpreg;
}

uint8_t HMC5983_GetStatus(HMC5983_HandleTypeDef *hmc5983)
{
	uint8_t tmpreg;
	HMC5983_Read(HMC5983_SR, &tmpreg, 1);
	return tmpreg;
}

//*************************************************************************************//

void HMC5983_GetMagnetometer(HMC5983_HandleTypeDef *hmc5983, int32_t *adcvalue)
{
	uint8_t tmpreg[6];
	int16_t rawdata[3];
	HMC5983_Read(HMC5983_DXRA, tmpreg, 6);
	for(size_t i = 0; i < 3; i++)
	{
		rawdata[i] = (int16_t)(((uint16_t)tmpreg[2 * i] << 8) | tmpreg[2 * i + 1]);
	}
	adcvalue[0] = (int32_t)rawdata[0];
	adcvalue[1] = (int32_t)rawdata[2];
	adcvalue[2] = (int32_t)rawdata[1];
}

void HMC5983_GetTemperature(HMC5983_HandleTypeDef *hmc5983, int32_t *adcvalue)
{
	uint8_t tmpreg[2];
	int16_t rawdata[1];
	HMC5983_Read(HMC5983_TEMPH, tmpreg, 2);
	rawdata[0] = (int16_t)(((uint16_t)tmpreg[0] << 8) | tmpreg[1]);
	adcvalue[0] = (int32_t)rawdata[0];
}