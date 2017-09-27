#include "hmc5983_api.h"
#include "hmc5983_types.h"

void HMC5983_Init(HMC5983_HandleTypeDef *hmc5983);

//*************************************************************************************//

uint8_t HMC5983_GetID(HMC5983_HandleTypeDef *hmc5983);
uint8_t HMC5983_GetStatus(HMC5983_HandleTypeDef *hmc5983);

//*************************************************************************************//

void HMC5983_GetMagnetometer(HMC5983_HandleTypeDef *hmc5983, int32_t *adcvalue);
void HMC5983_GetTemperature(HMC5983_HandleTypeDef *hmc5983, int32_t *adcvalue);