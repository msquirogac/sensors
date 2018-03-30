#include "bmp280.h"
#include <math.h>

void BMP280_Init(BMP280_HandleTypeDef *hsensor)
{
  BMP280_WriteHandler write = hsensor->HAL.Write;
  BMP280_InitTypeDef *init = &hsensor->Init;
  uint8_t tmpreg;
  tmpreg = init->TempOSR | init->PressOSR | init->Mode;
  write(BMP280_REG_CTRL_MEAS, &tmpreg, 1);
  tmpreg = init->Standby | init->Filter | init->SPIMode;
  write(BMP280_REG_CONFIG, &tmpreg, 1);
  BMP280_GetCalibParams(hsensor);
}

void BMP280_Reset(BMP280_HandleTypeDef *hsensor)
{
  BMP280_WriteHandler write = hsensor->HAL.Write;
  uint8_t tmpreg = BMP280_RESET;
  write(BMP280_REG_RESET, &tmpreg, 1);
}

void BMP280_GetCalibParams(BMP280_HandleTypeDef *hsensor)
{
  BMP280_ReadHandler read = hsensor->HAL.Read;
  BMP280_CParamsTypeDef *cparams = &hsensor->CParams;
  read(BMP280_REG_CALIB_00, (uint8_t *)&cparams->dig_T1, 2);
  read(BMP280_REG_CALIB_02, (uint8_t *)&cparams->dig_T2, 2);
  read(BMP280_REG_CALIB_04, (uint8_t *)&cparams->dig_T3, 2);
  read(BMP280_REG_CALIB_06, (uint8_t *)&cparams->dig_P1, 2);
  read(BMP280_REG_CALIB_08, (uint8_t *)&cparams->dig_P2, 2);
  read(BMP280_REG_CALIB_10, (uint8_t *)&cparams->dig_P3, 2);
  read(BMP280_REG_CALIB_12, (uint8_t *)&cparams->dig_P4, 2);
  read(BMP280_REG_CALIB_14, (uint8_t *)&cparams->dig_P5, 2);
  read(BMP280_REG_CALIB_16, (uint8_t *)&cparams->dig_P6, 2);
  read(BMP280_REG_CALIB_18, (uint8_t *)&cparams->dig_P7, 2);
  read(BMP280_REG_CALIB_20, (uint8_t *)&cparams->dig_P8, 2);
  read(BMP280_REG_CALIB_22, (uint8_t *)&cparams->dig_P9, 2);
}

//*************************************************************************************//

uint8_t BMP280_GetID(BMP280_HandleTypeDef *hsensor)
{
  BMP280_ReadHandler read = hsensor->HAL.Read;
  uint8_t tmpreg;
  read(BMP280_REG_ID, &tmpreg, 1);
  return tmpreg;
}

uint8_t BMP280_GetStatus(BMP280_HandleTypeDef *hsensor)
{
  BMP280_ReadHandler read = hsensor->HAL.Read;
  uint8_t tmpreg;
  read(BMP280_REG_STATUS, &tmpreg, 1);
  return tmpreg;
}

int32_t BMP280_GetTemperature(BMP280_HandleTypeDef *hsensor)
{
  BMP280_ReadHandler read = hsensor->HAL.Read;
  int32_t adcvalue;
  uint8_t tmpreg[3];
  read(BMP280_REG_TEMP_MSB, tmpreg, 3);
  adcvalue = tmpreg[0];
  adcvalue = (adcvalue << 8) | tmpreg[1];
  adcvalue = (adcvalue << 8) | tmpreg[2];
  adcvalue = (adcvalue >> 4);
  return adcvalue;
}

int32_t BMP280_GetPressure(BMP280_HandleTypeDef *hsensor)
{
  BMP280_ReadHandler read = hsensor->HAL.Read;
  int32_t adcvalue;
  uint8_t tmpreg[3];
  read(BMP280_REG_PRESS_MSB, tmpreg, 3);
  adcvalue = tmpreg[0];
  adcvalue = (adcvalue << 8) | tmpreg[1];
  adcvalue = (adcvalue << 8) | tmpreg[2];
  adcvalue = (adcvalue >> 4);
  return adcvalue;
}

//*************************************************************************************//

int32_t BMP280_CalculateTemperature(BMP280_HandleTypeDef *hsensor, int32_t adcvalue)
{
  BMP280_CParamsTypeDef *cparams = &hsensor->CParams;
  BMP280_IntVarsTypeDef *intvars = &hsensor->IntVars;
  int32_t var1, var2, t, tfine;
  var1 = (((adcvalue >> 3) - ((int32_t)cparams->dig_T1 << 1)) * ((int32_t)cparams->dig_T2)) >> 11;
  var2 = (((((adcvalue >> 4) - ((int32_t)cparams->dig_T1)) * ((adcvalue >> 4) - ((int32_t)cparams->dig_T1))) >> 12) * ((int32_t)cparams->dig_T3)) >> 14;
  tfine = var1 + var2;
  t = (tfine * 5 + 128) >> 8;
  intvars->TFine = tfine;
  return (int32_t)t;
}

int32_t BMP280_CalculatePressure(BMP280_HandleTypeDef *hsensor, int32_t adcvalue)
{
  BMP280_CParamsTypeDef *cparams = &hsensor->CParams;
  BMP280_IntVarsTypeDef *intvars = &hsensor->IntVars;
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