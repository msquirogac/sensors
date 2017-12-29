#ifndef __BMP280_H
#define __BMP280_H

#include "bmp280_api.h"
#include "bmp280_types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void BMP280_Init(BMP280_HandleTypeDef *hsensor);
void BMP280_Reset(BMP280_HandleTypeDef *hsensor);
void BMP280_GetCalibParams(BMP280_HandleTypeDef *hsensor);

//*************************************************************************************//

uint8_t BMP280_GetID(BMP280_HandleTypeDef *hsensor);
uint8_t BMP280_GetStatus(BMP280_HandleTypeDef *hsensor);
int32_t BMP280_GetTemperature(BMP280_HandleTypeDef *hsensor);
int32_t BMP280_GetPressure(BMP280_HandleTypeDef *hsensor);

//*************************************************************************************//

int32_t BMP280_CalculateTemperature(BMP280_HandleTypeDef *hsensor, int32_t adcvalue);
int32_t BMP280_CalculatePressure(BMP280_HandleTypeDef *hsensor, int32_t adcvalue);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __BMP280_H */