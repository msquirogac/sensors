#include "stdint.h"

typedef struct
{
  float geoidSep;
  float altitudeMSL;
  struct
  {
    struct
    {
      double latitude;
      double longitude;
      float altitude;
    } LLA;
    struct
    {
      double AxisX;
      double AxisY;
      double AxisZ;
    } ECEF;
  } Position;
  struct
  {
    struct
    {
      float Speed;
      float GroundSpeed;
      float Heading;
    } LLA;
    struct
    {
      float AxisX;
      float AxisY;
      float AxisZ;
    } ECEF;
    struct
    {
      float AxisX;
      float AxisY;
      float AxisZ;
    } NED;
  } Velocity;
} UBX_NavData_TypeDef;

typedef struct
{
  int8_t fix;
  uint32_t ttff;
  uint32_t msss;
  uint8_t numSV;
  float PDOP;
  float VDOP;
  float HDOP;
  float PAcc;
  float CAcc;
  float HAcc;
  float VAcc;
  float SAcc;
  float HeadAcc;
} UBX_NavInfo_TypeDef;

typedef struct
{
  UBX_NavData_TypeDef Data;
  UBX_NavInfo_TypeDef Info;
} UBX_Data_TypeDef;