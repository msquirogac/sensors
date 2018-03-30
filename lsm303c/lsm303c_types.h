#ifndef __LSM303C_TYPES_H
#define __LSM303C_TYPES_H

#include <stddef.h>
#include <stdint.h>

typedef void (*LSM303C_ReadHandler)(uint8_t Address, uint8_t *Buffer, size_t NumBytes);
typedef void (*LSM303C_WriteHandler)(uint8_t Address, uint8_t *Buffer, size_t NumBytes);
typedef void (*LSM303C_DelayHandler)(uint32_t Delay);

typedef struct
{
  uint8_t Temp;
  uint8_t ODR;
  uint8_t FS;
  uint8_t OMXY;
  uint8_t OMZ;
  uint8_t CM;
} LSM303C_InitTypeDef;

typedef struct
{
  const LSM303C_ReadHandler Read;
  const LSM303C_WriteHandler Write;
  const LSM303C_DelayHandler Delay;
} LSM303C_HalTypeDef;

typedef struct
{
  LSM303C_InitTypeDef Init;
  LSM303C_HalTypeDef HAL;
} LSM303C_HandleTypeDef;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __LSM303C_TYPES_H */