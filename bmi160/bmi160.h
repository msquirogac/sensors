#ifndef __BMI160_H
#define __BMI160_H

#include "bmi160_api.h"
#include "bmi160_types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void BMI160_Init(BMI160_HandleTypeDef *hsensor);
void BMI160_InitGyroscope(BMI160_HandleTypeDef *hsensor);
void BMI160_InitAccelerometer(BMI160_HandleTypeDef *hsensor);
void BMI160_Reset(BMI160_HandleTypeDef *hsensor);

//*************************************************************************************//

uint8_t BMI160_GetID(BMI160_HandleTypeDef *hsensor);
uint8_t BMI160_GetStatus(BMI160_HandleTypeDef *hsensor);

//*************************************************************************************//

void BMI160_GetGyroscope(BMI160_HandleTypeDef *hsensor, int16_t *adcvalue);
void BMI160_GetAccelerometer(BMI160_HandleTypeDef *hsensor, int16_t *adcvalue);
void BMI160_GetTemperature(BMI160_HandleTypeDef *hsensor, int16_t *adcvalue);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __BMI160_H */