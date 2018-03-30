#include "valtitude.h"
#include <math.h>

float VALT_CalculateAltitude(float Pressure, float PressureZero)
{
  return ((1.0f - powf(Pressure / PressureZero, 0.19026318875f)) * 44330.7692308f);
}

float VALT_CalculateAltitude2(float Pressure, float PressureZero, float Temperature0)
{
  return ((1.0f - powf(Pressure / PressureZero, 0.19026318875f)) * (Temperature0 + 273.15f) / 0.0065f);
}

float VALT_CalculateSeaLevelPressure(float Pressure, float Altitude)
{
  return (Pressure / powf(1.0f - (Altitude / 44330.7692308f), 5.255781f));
}