#ifndef __MAG3110_H
#define __MAG3110_H

#include "mag3110_api.h"
#include "mag3110_types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void MAG3110_Init(MAG3110_HandleTypeDef *mag3110);
void MAG3110_Reset(MAG3110_HandleTypeDef *mag3110);

//*************************************************************************************//

uint8_t MAG3110_GetID(MAG3110_HandleTypeDef *mag3110);
uint8_t MAG3110_GetStatus(MAG3110_HandleTypeDef *mag3110);

//*************************************************************************************//

void MAG3110_GetMagnetometer(MAG3110_HandleTypeDef *mag3110, int16_t *adcvalue);
void MAG3110_GetTemperature(MAG3110_HandleTypeDef *mag3110, int16_t *adcvalue);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __MAG3110_H */