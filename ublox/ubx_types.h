#include "stdint.h"

#define UBX_BUFFER_SIZE UINT8_MAX

typedef struct _NAV_POSECEF
{
  uint32_t iTOW;
  int32_t ecefX;
  int32_t ecefY;
  int32_t ecefZ;
  uint32_t pAcc;
} UBX_NAV_POSECEF_Typedef;

typedef struct _NAV_POSLLH
{
  uint32_t iTOW;
  int32_t lon;
  int32_t lat;
  int32_t height;
  int32_t hMSL;
  uint32_t hAcc;
  uint32_t vAcc;
} UBX_NAV_POSLLH_Typedef;

typedef struct _NAV_DOP
{
  uint32_t iTOW;
  uint16_t gDOP;
  uint16_t pDOP;
  uint16_t tDOP;
  uint16_t vDOP;
  uint16_t hDOP;
  uint16_t nDOP;
  uint16_t eDOP;
} UBX_NAV_DOP_Typedef;

typedef struct _NAV_STATUS
{
  uint32_t iTOW;
  uint8_t gpsFix;
  int8_t flags;
  int8_t fixStat;
  int8_t flags2;
  uint32_t ttff;
  uint32_t msss;
} UBX_NAV_STATUS_Typedef;

typedef struct _NAV_SOL
{
  uint32_t iTOW;
  int32_t fTOW;
  int16_t week;
  uint8_t gpsFix;
  uint8_t flags;
  int32_t ecefX;
  int32_t ecefY;
  int32_t ecefZ;
  uint32_t pAcc;
  int32_t ecefVX;
  int32_t ecefVY;
  int32_t ecefVZ;
  uint32_t sAcc;
  uint16_t pDOP;
  uint8_t reserved1;
  uint8_t numSV;
  uint8_t reserved2[4];
} UBX_NAV_SOL_Typedef;

typedef struct _NAV_PVT
{
  uint32_t iTOW;
  uint16_t year;
  uint8_t month;
  uint8_t day;
  uint8_t hour;
  uint8_t min;
  uint8_t sec;
  uint8_t valid;
  uint32_t tAcc;
  int32_t nano;
  uint8_t fixType;
  uint8_t flags;
  uint8_t reserved1;
  uint8_t numSV;
  int32_t lon;
  int32_t lat;
  int32_t height;
  int32_t hMSL;
  uint32_t hAcc;
  uint32_t vAcc;
  int32_t velN;
  int32_t velE;
  int32_t velD;
  int32_t gSpeed;
  int32_t headMot;
  uint32_t sAcc;
  uint32_t headAcc;
  uint16_t pDOP;
  uint8_t reserved2[6];
  int32_t headVeh;
  uint8_t reserved3[4];
} UBX_NAV_PVT_Typedef;

typedef struct _NAV_VELNED
{
  uint32_t iTOW;
  int32_t velN;
  int32_t velE;
  int32_t velD;
  uint32_t speed;
  uint32_t gSpeed;
  int32_t heading;
  uint32_t sAcc;
  uint32_t cAcc;
} UBX_NAV_VELNED_Typedef;

//*************************************************************************************//

typedef enum __attribute__((__packed__))
{
  NULL_Type = 0x00,
  NAV_Type = 0x01,
  RXM_Type = 0x02,
  INF_Type = 0x04,
  ACK_Type = 0x05,
  CFG_Type = 0x06,
  UPD_Type = 0x09,
  MON_Type = 0x0A,
  AID_Type = 0x0B,
  TIM_Type = 0x0D,
  MGA_Type = 0x13,
  LOG_Type = 0x21
}
UBX_PACKET_CLASS;

typedef enum __attribute__((__packed__))
{
  NAV_NULL_Type = 0x00,
  NAV_POSECEF_Type = 0x01,
  NAV_POSLLH_Type = 0x02,
  NAV_STATUS_Type = 0x03,
  NAV_DOP_Type = 0x04,
  NAV_SOL_Type = 0x06,
  NAV_PVT_Type = 0x07,
  NAV_VELNED_Type = 0x12
}
UBX_PACKET_NAV_ID;

typedef union
{
  uint8_t _buffer[UBX_BUFFER_SIZE];

  UBX_NAV_POSECEF_Typedef NAV_POSECEF;
  UBX_NAV_POSLLH_Typedef NAV_POSLLH;
  UBX_NAV_DOP_Typedef NAV_DOP;
  UBX_NAV_STATUS_Typedef NAV_STATUS;
  UBX_NAV_SOL_Typedef NAV_SOL;
  UBX_NAV_PVT_Typedef NAV_PVT;
  UBX_NAV_VELNED_Typedef NAV_VELNED;
} UBX_PayloadFormat_Typedef;

typedef struct
{
  UBX_PACKET_CLASS Class;
  uint8_t Id;
  uint16_t Length;
  UBX_PayloadFormat_Typedef Payload;
  uint8_t Checksum[2];

  struct
  {
    uint32_t Idx;
    uint8_t RecvState;
    uint8_t Checksum[2];
  } Ctrl;
} UBX_DataPacket_TypeDef;