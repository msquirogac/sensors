#ifndef __BMI160_TYPES_H
#define __BMI160_TYPES_H

#include <stddef.h>
#include <stdint.h>

typedef void (*BMI160_ReadHandler)(uint8_t Address, uint8_t *Buffer, size_t NumBytes);
typedef void (*BMI160_WriteHandler)(uint8_t Address, uint8_t *Buffer, size_t NumBytes);
typedef void (*BMI160_DelayHandler)(uint32_t Delay);

typedef struct
{
} BMI160_InitTypeDef;

typedef struct
{
	uint8_t ODR;
	uint8_t OSR;
	uint8_t Range;
} BMI160G_InitTypeDef;

typedef struct
{
	uint8_t US;
	uint8_t ODR;
	uint8_t OSR;
	uint8_t Range;
} BMI160A_InitTypeDef;

typedef struct
{
	const BMI160_ReadHandler Read;
	const BMI160_WriteHandler Write;
	const BMI160_DelayHandler Delay;
} BMI160_HalTypeDef;

typedef struct
{
	BMI160_InitTypeDef Init;
	BMI160G_InitTypeDef InitGyro;
	BMI160A_InitTypeDef InitAccel;
	BMI160_HalTypeDef HAL;
} BMI160_HandleTypeDef;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __BMI160_TYPES_H */