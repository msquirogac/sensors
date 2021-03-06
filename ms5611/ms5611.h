#ifndef __MS5611_H
#define __MS5611_H

#include "ms5611_api.h"
#include "ms5611_types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void MS5611_Init(MS5611_HandleTypeDef *hsensor);
void MS5611_Reset(MS5611_HandleTypeDef *hsensor);
void MS5611_GetCalibParams(MS5611_HandleTypeDef *hsensor);

//*************************************************************************************//

void MS5611_RequestTemperature(MS5611_HandleTypeDef *hsensor);
void MS5611_RequestPressure(MS5611_HandleTypeDef *hsensor);
uint32_t MS5611_GetADC(MS5611_HandleTypeDef *hsensor);

//*************************************************************************************//

int32_t MS5611_CalculateTemperature(MS5611_HandleTypeDef *hsensor, uint32_t adcvalue);
int32_t MS5611_CalculatePressure(MS5611_HandleTypeDef *hsensor, uint32_t adcvalue);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /*__MS5611_H */