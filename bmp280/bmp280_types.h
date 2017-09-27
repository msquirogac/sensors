#ifndef __BMP280_TYPES
#define __BMP280_TYPES

#include <stddef.h>
#include <stdint.h>

typedef void (*BMP280_ReadHandler)(uint8_t Address, uint8_t *Buffer, size_t NumBytes);
typedef void (*BMP280_WriteHandler)(uint8_t Address, uint8_t *Buffer, size_t NumBytes);

typedef struct
{
	uint8_t TempOSR;
	uint8_t PressOSR;
	uint8_t Mode;
	uint8_t Standby;
	uint8_t Filter;
	uint8_t SPIMode;
} BMP280_InitTypeDef;

typedef struct
{
	uint16_t dig_T1;
	int16_t dig_T2;
	int16_t dig_T3;
	uint16_t dig_P1;
	int16_t dig_P2;
	int16_t dig_P3;
	int16_t dig_P4;
	int16_t dig_P5;
	int16_t dig_P6;
	int16_t dig_P7;
	int16_t dig_P8;
	int16_t dig_P9;
} BMP280_CParamsTypeDef;

typedef struct
{
	int32_t TFine;
} BMP280_IntVarsTypeDef;

typedef struct
{
	const BMP280_ReadHandler Read;
	const BMP280_WriteHandler Write;
} BMP280_HalTypeDef;

typedef struct
{
	BMP280_InitTypeDef Init;
	BMP280_CParamsTypeDef CParams;
	BMP280_IntVarsTypeDef IntVars;
	BMP280_HalTypeDef HAL;
} BMP280_HandleTypeDef;

#endif