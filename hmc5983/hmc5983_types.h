#ifndef __HMC5983_TYPES_H
#define __HMC5983_TYPES_H

#include <stddef.h>
#include <stdint.h>

typedef void (*HMC5983_ReadHandler)(uint8_t Address, uint8_t *Buffer, size_t NumBytes);
typedef void (*HMC5983_WriteHandler)(uint8_t Address, uint8_t *Buffer, size_t NumBytes);

typedef struct
{
	uint8_t Temperature_Sensor; /* Temperature sensor enable/disable */
	uint8_t Average_Sample;			/* Select number of samples averaged */
	uint8_t Output_DataRate;		/* OUT data rate */
	uint8_t Working_Mode;				/* Operating mode */
	uint8_t Full_Scale;					/* Full Scale selection */
} HMC5983_InitTypeDef;

typedef struct
{
	const HMC5983_ReadHandler Read;
	const HMC5983_WriteHandler Write;
} HMC5983_HalTypeDef;

typedef struct
{
	HMC5983_InitTypeDef Init;
	HMC5983_HalTypeDef HAL;
} HMC5983_HandleTypeDef;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __HMC5983_TYPES_H */