#ifndef __LSM303C_H
#define __LSM303C_H

#include "lsm303c_api.h"
#include "lsm303c_types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void LSM303C_Init(LSM303C_HandleTypeDef *hsensor);
void LSM303C_Reset(LSM303C_HandleTypeDef *hsensor);

//*************************************************************************************//

uint8_t LSM303C_GetID(LSM303C_HandleTypeDef *hsensor);
uint8_t LSM303C_GetStatus(LSM303C_HandleTypeDef *hsensor);

//*************************************************************************************//

void LSM303C_GetMagnetometer(LSM303C_HandleTypeDef *hsensor, int16_t *adcvalue);
void LSM303C_GetTemperature(LSM303C_HandleTypeDef *hsensor, int16_t *adcvalue);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __LSM303C_H */