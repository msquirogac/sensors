#include "ms5611.h"
#include <math.h>

void MS5611_Init(MS5611_HandleTypeDef *ms5611)
{
	MS5611_GetCalibParams(ms5611);
}

void MS5611_Reset(MS5611_HandleTypeDef *ms5611)
{
	MS5611_SendCommand(MS5611_CMD_RESET, 0x00, 0);
}

void MS5611_GetCalibParams(MS5611_HandleTypeDef *ms5611)
{
	MS5611_CParamsTypeDef *cparams = &ms5611->CParams;
	uint8_t data[2];
	MS5611_SendCommand(MS5611_CMD_PROM_READ + 0x02, data, 2);
	cparams->C1_SENS_T1 = (data[0] << 8) | (data[1] << 0);
	MS5611_SendCommand(MS5611_CMD_PROM_READ + 0x04, data, 2);
	cparams->C2_OFF_T1 = (data[0] << 8) | (data[1] << 0);
	MS5611_SendCommand(MS5611_CMD_PROM_READ + 0x06, data, 2);
	cparams->C3_TCS = (data[0] << 8) | (data[1] << 0);
	MS5611_SendCommand(MS5611_CMD_PROM_READ + 0x07, data, 2);
	cparams->C4_TCO = (data[0] << 8) | (data[1] << 0);
	MS5611_SendCommand(MS5611_CMD_PROM_READ + 0x0A, data, 2);
	cparams->C5_TREF = (data[0] << 8) | (data[1] << 0);
	MS5611_SendCommand(MS5611_CMD_PROM_READ + 0x0C, data, 2);
	cparams->C6_TEMPSENS = (data[0] << 8) | (data[1] << 0);
}

//*************************************************************************************//

void MS5611_RequestTemperature(MS5611_HandleTypeDef *ms5611)
{
	MS5611_InitTypeDef *init = &ms5611->Init;
	MS5611_SendCommand(MS5611_CMD_ADC_CONV + MS5611_CMD_ADC_D2 + init->OSRSelectTemp, 0x00, 0);
}

void MS5611_RequestPressure(MS5611_HandleTypeDef *ms5611)
{
	MS5611_InitTypeDef *init = &ms5611->Init;
	MS5611_SendCommand(MS5611_CMD_ADC_CONV + MS5611_CMD_ADC_D1 + init->OSRSelectPress, 0x00, 0);
}

uint32_t MS5611_GetADC(MS5611_HandleTypeDef *ms5611)
{
	uint32_t adcvalue;
	uint8_t data[3];
	MS5611_SendCommand(MS5611_CMD_ADC_READ, data, 3);
	adcvalue = (data[0] << 16) | (data[1] << 8) | (data[2] << 0);
	return adcvalue;
}

//*************************************************************************************//

int32_t MS5611_CalculateTemperature(MS5611_HandleTypeDef *ms5611, uint32_t adcvalue)
{
	MS5611_CParamsTypeDef *cparams = &ms5611->CParams;
	MS5611_IntVarsTypeDef *intvars = &ms5611->IntVars;
	int32_t temperature;
	intvars->dTemperature = adcvalue - (int32_t)(cparams->C5_TREF << 8);
	temperature = 2000 + (int32_t)(((int64_t)intvars->dTemperature * cparams->C6_TEMPSENS) >> 23);
	return temperature;
}

int32_t MS5611_CalculatePressure(MS5611_HandleTypeDef *ms5611, uint32_t adcvalue)
{
	MS5611_CParamsTypeDef *cparams = &ms5611->CParams;
	MS5611_IntVarsTypeDef *intvars = &ms5611->IntVars;
	int32_t pressure;
	intvars->OffsetAtTemp = ((uint32_t)cparams->C2_OFF_T1 << 16) + (((int64_t)intvars->dTemperature * cparams->C4_TCO) >> 7);
	intvars->SensitivityAtTemp = ((uint32_t)cparams->C1_SENS_T1 << 15) + (((int64_t)intvars->dTemperature * cparams->C3_TCS) >> 8);
	pressure = (((((int64_t)adcvalue * intvars->SensitivityAtTemp) >> 21) - intvars->OffsetAtTemp) >> 15);
	return pressure;
}