#ifndef __HMC5983_H
#define __HMC5983_H

#include "hmc5983_api.h"
#include "hmc5983_types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void HMC5983_Init(HMC5983_HandleTypeDef *hmc5983);

//*************************************************************************************//

uint8_t HMC5983_GetID(HMC5983_HandleTypeDef *hmc5983);
uint8_t HMC5983_GetStatus(HMC5983_HandleTypeDef *hmc5983);

//*************************************************************************************//

void HMC5983_GetMagnetometer(HMC5983_HandleTypeDef *hmc5983, int16_t *adcvalue);
void HMC5983_GetTemperature(HMC5983_HandleTypeDef *hmc5983, int16_t *adcvalue);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __HMC5983_H */