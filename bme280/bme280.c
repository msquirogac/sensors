#include "bme280.h"
#include <math.h>

void BME280_Init(BME280_HandleTypeDef *hsensor)
{
  BME280_WriteHandler write = hsensor->HAL.Write;
  BME280_InitTypeDef *init = &hsensor->Init;
  uint8_t tmpreg;
  tmpreg = init->HumidOSR;
  write(BME280_REG_CTRL_HUM, &tmpreg, 1);
  tmpreg = init->TempOSR | init->PressOSR | init->Mode;
  write(BME280_REG_CTRL_MEAS, &tmpreg, 1);
  tmpreg = init->Standby | init->Filter | init->SPIMode;
  write(BME280_REG_CONFIG, &tmpreg, 1);
  BME280_GetCalibParams(hsensor);
}

void BME280_Reset(BME280_HandleTypeDef *hsensor)
{
  BME280_WriteHandler write = hsensor->HAL.Write;
  uint8_t tmpreg = BME280_RESET;
  write(BME280_REG_RESET, &tmpreg, 1);
}

void BME280_GetCalibParams(BME280_HandleTypeDef *hsensor)
{
  BME280_ReadHandler read = hsensor->HAL.Read;
  BME280_CParamsTypeDef *cparams = &hsensor->CParams;
  read(BME280_REG_CALIB_00, (uint8_t *)&cparams->dig_T1, 2);
  read(BME280_REG_CALIB_02, (uint8_t *)&cparams->dig_T2, 2);
  read(BME280_REG_CALIB_04, (uint8_t *)&cparams->dig_T3, 2);
  read(BME280_REG_CALIB_06, (uint8_t *)&cparams->dig_P1, 2);
  read(BME280_REG_CALIB_08, (uint8_t *)&cparams->dig_P2, 2);
  read(BME280_REG_CALIB_10, (uint8_t *)&cparams->dig_P3, 2);
  read(BME280_REG_CALIB_12, (uint8_t *)&cparams->dig_P4, 2);
  read(BME280_REG_CALIB_14, (uint8_t *)&cparams->dig_P5, 2);
  read(BME280_REG_CALIB_16, (uint8_t *)&cparams->dig_P6, 2);
  read(BME280_REG_CALIB_18, (uint8_t *)&cparams->dig_P7, 2);
  read(BME280_REG_CALIB_20, (uint8_t *)&cparams->dig_P8, 2);
  read(BME280_REG_CALIB_22, (uint8_t *)&cparams->dig_P9, 2);

  int8_t tmp[3];
  int16_t dig_H4, dig_H5;
  read(BME280_REG_CALIB_25, (uint8_t *)&cparams->dig_H1, 1);
  read(BME280_REG_CALIB_26, (uint8_t *)&cparams->dig_H2, 2);
  read(BME280_REG_CALIB_28, (uint8_t *)&cparams->dig_H3, 1);
  read(BME280_REG_CALIB_29, tmp, 3);
  dig_H4 = tmp[0];
  dig_H4 = (dig_H4 << 4) | (tmp[1] & 0x0F);
  dig_H5 = tmp[2];
  dig_H5 = (dig_H5 << 8) | (tmp[1] & 0xF0);
  dig_H5 = (dig_H5 >> 4);
  cparams->dig_H4 = dig_H4;
  cparams->dig_H5 = dig_H5;
  read(BME280_REG_CALIB_32, (uint8_t *)&cparams->dig_H6, 1);
}

//*************************************************************************************//

uint8_t BME280_GetID(BME280_HandleTypeDef *hsensor)
{
  BME280_ReadHandler read = hsensor->HAL.Read;
  uint8_t tmpreg;
  read(BME280_REG_ID, &tmpreg, 1);
  return tmpreg;
}

uint8_t BME280_GetStatus(BME280_HandleTypeDef *hsensor)
{
  BME280_ReadHandler read = hsensor->HAL.Read;
  uint8_t tmpreg;
  read(BME280_REG_STATUS, &tmpreg, 1);
  return tmpreg;
}

int32_t BME280_GetTemperature(BME280_HandleTypeDef *hsensor)
{
  BME280_ReadHandler read = hsensor->HAL.Read;
  int32_t adcvalue;
  uint8_t tmpreg[3];
  read(BME280_REG_TEMP_MSB, tmpreg, 3);
  adcvalue = tmpreg[0];
  adcvalue = (adcvalue << 8) | tmpreg[1];
  adcvalue = (adcvalue << 8) | tmpreg[2];
  adcvalue = (adcvalue >> 4);
  return adcvalue;
}

int32_t BME280_GetPressure(BME280_HandleTypeDef *hsensor)
{
  BME280_ReadHandler read = hsensor->HAL.Read;
  int32_t adcvalue;
  uint8_t tmpreg[3];
  read(BME280_REG_PRESS_MSB, tmpreg, 3);
  adcvalue = tmpreg[0];
  adcvalue = (adcvalue << 8) | tmpreg[1];
  adcvalue = (adcvalue << 8) | tmpreg[2];
  adcvalue = (adcvalue >> 4);
  return adcvalue;
}

int32_t BME280_GetHumidity(BME280_HandleTypeDef *hsensor)
{
  BME280_ReadHandler read = hsensor->HAL.Read;
  int32_t adcvalue;
  uint8_t tmpreg[3];
  read(BME280_REG_HUM_MSB, tmpreg, 2);
  adcvalue = tmpreg[0];
  adcvalue = (adcvalue << 8) | tmpreg[1];
  return adcvalue;
}

//*************************************************************************************//

int32_t BME280_CalculateTemperature(BME280_HandleTypeDef *hsensor, int32_t adcvalue)
{
  BME280_CParamsTypeDef *cparams = &hsensor->CParams;
  BME280_IntVarsTypeDef *intvars = &hsensor->IntVars;
  int32_t var1, var2, t, tfine;
  var1 = (((adcvalue >> 3) - ((int32_t)cparams->dig_T1 << 1)) * ((int32_t)cparams->dig_T2)) >> 11;
  var2 = (((((adcvalue >> 4) - ((int32_t)cparams->dig_T1)) * ((adcvalue >> 4) - ((int32_t)cparams->dig_T1))) >> 12) * ((int32_t)cparams->dig_T3)) >> 14;
  tfine = var1 + var2;
  t = (tfine * 5 + 128) >> 8;
  intvars->TFine = tfine;
  return (int32_t)t;
}

int32_t BME280_CalculatePressure(BME280_HandleTypeDef *hsensor, int32_t adcvalue)
{
  BME280_CParamsTypeDef *cparams = &hsensor->CParams;
  BME280_IntVarsTypeDef *intvars = &hsensor->IntVars;
  int64_t var1, var2, p;
  var1 = ((int64_t)intvars->TFine) - 128000;
  var2 = var1 * var1 * (int64_t)cparams->dig_P6;
  var2 = var2 + ((var1 * (int64_t)cparams->dig_P5) << 17);
  var2 = var2 + (((int64_t)cparams->dig_P4) << 35);
  var1 = ((var1 * var1 * (int64_t)cparams->dig_P3) >> 8) + ((var1 * (int64_t)cparams->dig_P2) << 12);
  var1 = (((((int64_t)1) << 47) + var1)) * ((int64_t)cparams->dig_P1) >> 33;
  if(var1 == 0)
  {
    return 0;
  }
  p = 1048576 - adcvalue;
  p = (((p << 31) - var2) * 3125) / var1;
  var1 = (((int64_t)cparams->dig_P9) * (p >> 13) * (p >> 13)) >> 25;
  var2 = (((int64_t)cparams->dig_P8) * p) >> 19;
  p = ((p + var1 + var2) >> 8) + (((int64_t)cparams->dig_P7) << 4);
  return (int32_t)p;
}

int32_t BME280_CalculateHumidity(BME280_HandleTypeDef *hsensor, int32_t adcvalue)
{
  BME280_CParamsTypeDef *cparams = &hsensor->CParams;
  BME280_IntVarsTypeDef *intvars = &hsensor->IntVars;
  int32_t var1;
  var1 = intvars->TFine - (int32_t)76800;
  var1 = (((((adcvalue << 14) - (((int32_t)cparams->dig_H4) << 20) - (((int32_t)cparams->dig_H5) * var1)) + ((int32_t)16384)) >> 15) * (((((((var1 * ((int32_t)cparams->dig_H6)) >> 10) * (((var1 * ((int32_t)cparams->dig_H3)) >> 11) + ((int32_t)32768))) >> 10) + ((int32_t)2097152)) * ((int32_t)cparams->dig_H2) + 8192) >> 14));
  var1 = (var1 - (((((var1 >> 15) * (var1 >> 15)) >> 7) * ((int32_t)cparams->dig_H1)) >> 4));
  var1 = (var1 < 0 ? 0 : var1);
  var1 = (var1 > 419430400 ? 419430400 : var1);
  return (uint32_t)(var1 >> 12);
}