#include "ms5611_api.h"
#include "ms5611_types.h"

void MS5611_Init(MS5611_HandleTypeDef *ms5611);
void MS5611_Reset(MS5611_HandleTypeDef *ms5611);
void MS5611_GetCalibParams(MS5611_HandleTypeDef *ms5611);

//*************************************************************************************//

void MS5611_RequestTemperature(MS5611_HandleTypeDef *ms5611);
void MS5611_RequestPressure(MS5611_HandleTypeDef *ms5611);
uint32_t MS5611_GetADC(MS5611_HandleTypeDef *ms5611);

//*************************************************************************************//

int32_t MS5611_CalculateTemperature(MS5611_HandleTypeDef *ms5611, uint32_t adcvalue);
int32_t MS5611_CalculatePressure(MS5611_HandleTypeDef *ms5611, uint32_t adcvalue);