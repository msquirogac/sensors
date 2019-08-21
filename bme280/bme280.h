#ifndef __BME280_H
#define __BME280_H

#include "bme280_api.h"
#include "bme280_types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void BME280_Init(BME280_HandleTypeDef *hsensor);
void BME280_Reset(BME280_HandleTypeDef *hsensor);
void BME280_GetCalibParams(BME280_HandleTypeDef *hsensor);

//*************************************************************************************//

uint8_t BME280_GetID(BME280_HandleTypeDef *hsensor);
uint8_t BME280_GetStatus(BME280_HandleTypeDef *hsensor);
int32_t BME280_GetTemperature(BME280_HandleTypeDef *hsensor);
int32_t BME280_GetPressure(BME280_HandleTypeDef *hsensor);
int32_t BME280_GetHumidity(BME280_HandleTypeDef *hsensor);

//*************************************************************************************//

int32_t BME280_CalculateTemperature(BME280_HandleTypeDef *hsensor, int32_t adcvalue);
int32_t BME280_CalculatePressure(BME280_HandleTypeDef *hsensor, int32_t adcvalue);
int32_t BME280_CalculateHumidity(BME280_HandleTypeDef *hsensor, int32_t adcvalue);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __BME280_H */