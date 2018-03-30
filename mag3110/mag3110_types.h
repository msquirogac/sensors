#ifndef __MAG3110_TYPES_H
#define __MAG3110_TYPES_H

#include <stddef.h>
#include <stdint.h>

typedef void (*MAG3110_ReadHandler)(uint8_t Address, uint8_t* Buffer, size_t NumBytes);
typedef void (*MAG3110_WriteHandler)(uint8_t Address, uint8_t* Buffer, size_t NumBytes);

typedef struct
{
  uint8_t ADC_Rate;        /* Output data rate */
  uint8_t Average_Sample;  /* Select number of samples averaged */
  uint8_t Fast_Read;       /* Fast Read */
  uint8_t Trigger_Mode;    /* Trigger immediate measurement */
  uint8_t Working_Mode;    /* Operating mode */
} MAG3110_InitTypeDef;

typedef struct
{
  const MAG3110_ReadHandler Read;
  const MAG3110_WriteHandler Write;
} MAG3110_HalTypeDef;

typedef struct
{
  MAG3110_InitTypeDef Init;
  MAG3110_HalTypeDef HAL;
} MAG3110_HandleTypeDef;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __MAG3110_TYPES_H */