#include "bmp280_api.h"
#include "bmp280_types.h"
#include <stddef.h>

extern void BMP280_Read(uint8_t Address, uint8_t *Buffer, size_t NumBytes);
extern void BMP280_Write(uint8_t Address, uint8_t *Buffer, size_t NumBytes);

//*************************************************************************************//

void BMP280_Init(BMP280_HandleTypeDef *bmp280);
void BMP280_Reset(BMP280_HandleTypeDef *bmp280);
void BMP280_GetCalibParams(BMP280_HandleTypeDef *bmp280);

//*************************************************************************************//

uint8_t BMP280_GetID(BMP280_HandleTypeDef *bmp280);
uint8_t BMP280_GetStatus(BMP280_HandleTypeDef *bmp280);
int32_t BMP280_GetTemperature(BMP280_HandleTypeDef *bmp280);
int32_t BMP280_GetPressure(BMP280_HandleTypeDef *bmp280);

//*************************************************************************************//

int32_t BMP280_CalculateTemperature(BMP280_HandleTypeDef *bmp280, int32_t adcvalue);
int32_t BMP280_CalculatePressure(BMP280_HandleTypeDef *bmp280, int32_t adcvalue);