#ifndef __BME280_TYPES_H
#define __BME280_TYPES_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef void (*BME280_ReadHandler)(uint8_t Address, uint8_t *Buffer, size_t NumBytes);
typedef void (*BME280_WriteHandler)(uint8_t Address, uint8_t *Buffer, size_t NumBytes);

typedef struct
{
  const BME280_ReadHandler Read;
  const BME280_WriteHandler Write;
} BME280_HalTypeDef;

typedef struct
{
  uint8_t HumidOSR;
  uint8_t TempOSR;
  uint8_t PressOSR;
  uint8_t Mode;
  uint8_t Standby;
  uint8_t Filter;
  uint8_t SPIMode;
} BME280_InitTypeDef;

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
  uint8_t dig_H1;
  int16_t dig_H2;
  uint8_t dig_H3;
  int16_t dig_H4;
  int16_t dig_H5;
  int8_t  dig_H6;
} BME280_CParamsTypeDef;

typedef struct
{
  int32_t TFine;
} BME280_IntVarsTypeDef;

typedef struct
{
  BME280_HalTypeDef HAL;
  BME280_InitTypeDef Init;
  BME280_CParamsTypeDef CParams;
  BME280_IntVarsTypeDef IntVars;
} BME280_HandleTypeDef;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __BME280_TYPES_H */