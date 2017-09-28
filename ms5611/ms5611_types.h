#ifndef __MS5611_TYPES_H
#define __MS5611_TYPES_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef void (*MS5611_CommandHandler)(uint8_t Command, uint8_t *Buffer, size_t NumBytes);

typedef struct
{
	uint8_t OSRSelectPress;
	uint8_t OSRSelectTemp;
} MS5611_InitTypeDef;

typedef struct
{
	uint16_t C1_SENS_T1;
	uint16_t C2_OFF_T1;
	uint16_t C3_TCS;
	uint16_t C4_TCO;
	uint16_t C5_TREF;
	uint16_t C6_TEMPSENS;
} MS5611_CParamsTypeDef;

typedef struct
{
	int32_t dTemperature;
	int64_t OffsetAtTemp;
	int64_t SensitivityAtTemp;
	int64_t OffsetAtTemp2;
	int64_t SensitivityAtTemp2;
} MS5611_IntVarsTypeDef;

typedef struct
{
	const MS5611_CommandHandler Command;
} MS5611_HalTypeDef;

typedef struct
{
	MS5611_InitTypeDef Init;
	MS5611_CParamsTypeDef CParams;
	MS5611_IntVarsTypeDef IntVars;
	MS5611_HalTypeDef HAL;
} MS5611_HandleTypeDef;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __MS5611_TYPES_H */