#include "ubx.h"

void UBX_CalculateCRC(uint8_t *Checksum, uint8_t NewByte)
{
  Checksum[0] = Checksum[0] + NewByte;
  Checksum[1] = Checksum[1] + Checksum[0];
}

uint8_t UBX_ReceiveMessage(UBX_DataPacket_TypeDef *UBX_Packet, uint8_t NewByte)
{
  uint8_t Status = 0;
  switch(UBX_Packet->Ctrl.RecvState)
  {
    case 0:
    {
      if(NewByte == 0xB5)
        UBX_Packet->Ctrl.RecvState = 1;
    }
    break;
    case 1:
    {
      if(NewByte == 0x62)
        UBX_Packet->Ctrl.RecvState = 2;
      else
        UBX_Packet->Ctrl.RecvState = 0;
    }
    break;
    case 2:
    {
      UBX_Packet->Ctrl.Checksum[0] = 0;
      UBX_Packet->Ctrl.Checksum[1] = 0;
      UBX_CalculateCRC(UBX_Packet->Ctrl.Checksum, NewByte);
      UBX_Packet->Class = NewByte;
      UBX_Packet->Ctrl.RecvState = 3;
    }
    break;
    case 3:
    {
      UBX_CalculateCRC(UBX_Packet->Ctrl.Checksum, NewByte);
      UBX_Packet->Id = NewByte;
      UBX_Packet->Ctrl.RecvState = 4;
    }
    break;
    case 4:
    {
      UBX_CalculateCRC(UBX_Packet->Ctrl.Checksum, NewByte);
      UBX_Packet->Length = NewByte;
      UBX_Packet->Ctrl.RecvState = 5;
    }
    break;
    case 5:
    {
      UBX_CalculateCRC(UBX_Packet->Ctrl.Checksum, NewByte);
      UBX_Packet->Length += (NewByte << 8);
      UBX_Packet->Ctrl.Idx = 0;
      UBX_Packet->Ctrl.RecvState = 6;
    }
    break;
    case 6:
    {
      UBX_CalculateCRC(UBX_Packet->Ctrl.Checksum, NewByte);
      UBX_Packet->Payload._buffer[UBX_Packet->Ctrl.Idx] = NewByte;
      UBX_Packet->Ctrl.Idx++;

      if(UBX_Packet->Ctrl.Idx >= UBX_BUFFER_SIZE)
        UBX_Packet->Ctrl.RecvState = 0;
      else if(UBX_Packet->Ctrl.Idx >= UBX_Packet->Length)
        UBX_Packet->Ctrl.RecvState = 7;
    }
    break;
    case 7:
    {
      UBX_Packet->Checksum[0] = NewByte;
      UBX_Packet->Ctrl.RecvState = 8;
    }
    break;
    case 8:
    {
      UBX_Packet->Checksum[1] = NewByte;
      if((UBX_Packet->Checksum[0] == UBX_Packet->Ctrl.Checksum[0]) && (UBX_Packet->Checksum[1] == UBX_Packet->Ctrl.Checksum[1]))
        Status = 1;
      UBX_Packet->Ctrl.RecvState = 0;
    }
    break;
    default:
      UBX_Packet->Ctrl.RecvState = 0;
  }
  return Status;
}

uint8_t UBX_ParseMessage(UBX_DataPacket_TypeDef *UBX_Packet, UBX_Data_TypeDef *UBX_Data)
{
  uint8_t Status = UBX_Packet->Id;
  if(UBX_Packet->Class == NAV_Type)
  {
    switch(UBX_Packet->Id)
    {
      case NAV_POSECEF_Type:
      {
        UBX_Data->Info.PAcc = UBX_Packet->Payload.NAV_POSECEF.pAcc * 1E-2;
        UBX_Data->Data.Position.ECEF.AxisX = UBX_Packet->Payload.NAV_POSECEF.ecefX * 1E-2;
        UBX_Data->Data.Position.ECEF.AxisY = UBX_Packet->Payload.NAV_POSECEF.ecefY * 1E-2;
        UBX_Data->Data.Position.ECEF.AxisZ = UBX_Packet->Payload.NAV_POSECEF.ecefZ * 1E-2;
      }
      break;
      case NAV_POSLLH_Type:
      {
        UBX_Data->Info.HAcc = UBX_Packet->Payload.NAV_POSLLH.hAcc * 1E-3;
        UBX_Data->Info.VAcc = UBX_Packet->Payload.NAV_POSLLH.vAcc * 1E-3;
        UBX_Data->Data.Position.LLA.longitude = UBX_Packet->Payload.NAV_POSLLH.lon * 1E-7;
        UBX_Data->Data.Position.LLA.latitude = UBX_Packet->Payload.NAV_POSLLH.lat * 1E-7;
        UBX_Data->Data.Position.LLA.altitude = UBX_Packet->Payload.NAV_POSLLH.height * 1E-3;
        UBX_Data->Data.altitudeMSL = UBX_Packet->Payload.NAV_POSLLH.hMSL * 1E-3;
        UBX_Data->Data.geoidSep = (UBX_Packet->Payload.NAV_POSLLH.height - UBX_Packet->Payload.NAV_POSLLH.hMSL) * 1E-3;
      }
      break;
      case NAV_STATUS_Type:
      {
        UBX_Data->Info.ttff = UBX_Packet->Payload.NAV_STATUS.ttff;
        UBX_Data->Info.msss = UBX_Packet->Payload.NAV_STATUS.msss;
      }
      break;
      case NAV_DOP_Type:
      {
        UBX_Data->Info.PDOP = UBX_Packet->Payload.NAV_DOP.pDOP * 1E-2;
        UBX_Data->Info.VDOP = UBX_Packet->Payload.NAV_DOP.vDOP * 1E-2;
        UBX_Data->Info.HDOP = UBX_Packet->Payload.NAV_DOP.hDOP * 1E-2;
      }
      break;
      case NAV_SOL_Type:
      {
        UBX_Data->Info.fix = UBX_Packet->Payload.NAV_SOL.gpsFix;
        UBX_Data->Info.numSV = UBX_Packet->Payload.NAV_SOL.numSV;
        UBX_Data->Info.PAcc = UBX_Packet->Payload.NAV_SOL.pAcc * 1E-2;
        UBX_Data->Info.SAcc = UBX_Packet->Payload.NAV_SOL.sAcc * 1E-2;
        UBX_Data->Data.Position.ECEF.AxisX = UBX_Packet->Payload.NAV_SOL.ecefX * 1E-2;
        UBX_Data->Data.Position.ECEF.AxisY = UBX_Packet->Payload.NAV_SOL.ecefY * 1E-2;
        UBX_Data->Data.Position.ECEF.AxisZ = UBX_Packet->Payload.NAV_SOL.ecefZ * 1E-2;
        UBX_Data->Data.Velocity.ECEF.AxisX = UBX_Packet->Payload.NAV_SOL.ecefVX * 1E-2;
        UBX_Data->Data.Velocity.ECEF.AxisY = UBX_Packet->Payload.NAV_SOL.ecefVY * 1E-2;
        UBX_Data->Data.Velocity.ECEF.AxisZ = UBX_Packet->Payload.NAV_SOL.ecefVZ * 1E-2;
      }
      break;
      case NAV_PVT_Type:
      {
        UBX_Data->Info.fix = UBX_Packet->Payload.NAV_PVT.fixType;
        UBX_Data->Info.numSV = UBX_Packet->Payload.NAV_PVT.numSV;
        UBX_Data->Info.HAcc = UBX_Packet->Payload.NAV_PVT.hAcc * 1E-3;
        UBX_Data->Info.VAcc = UBX_Packet->Payload.NAV_PVT.vAcc * 1E-3;
        UBX_Data->Info.SAcc = UBX_Packet->Payload.NAV_PVT.sAcc * 1E-3;
        UBX_Data->Info.HeadAcc = UBX_Packet->Payload.NAV_PVT.headAcc * 1E-5;
        UBX_Data->Data.Position.LLA.longitude = UBX_Packet->Payload.NAV_PVT.lon * 1E-7;
        UBX_Data->Data.Position.LLA.latitude = UBX_Packet->Payload.NAV_PVT.lat * 1E-7;
        UBX_Data->Data.Position.LLA.altitude = UBX_Packet->Payload.NAV_PVT.height * 1E-3;
        UBX_Data->Data.Velocity.NED.AxisX = UBX_Packet->Payload.NAV_PVT.velN * 1E-3;
        UBX_Data->Data.Velocity.NED.AxisY = UBX_Packet->Payload.NAV_PVT.velE * 1E-3;
        UBX_Data->Data.Velocity.NED.AxisZ = UBX_Packet->Payload.NAV_PVT.velD * 1E-3;
        UBX_Data->Data.altitudeMSL = UBX_Packet->Payload.NAV_PVT.hMSL * 1E-3;
        UBX_Data->Data.geoidSep = (UBX_Packet->Payload.NAV_PVT.height - UBX_Packet->Payload.NAV_PVT.hMSL) * 1E-3;
        UBX_Data->Data.Velocity.LLA.GroundSpeed = UBX_Packet->Payload.NAV_PVT.gSpeed * 1E-3;
        UBX_Data->Data.Velocity.LLA.Heading = UBX_Packet->Payload.NAV_PVT.headMot * 1E-5;
      }
      break;
      case NAV_VELNED_Type:
      {
        UBX_Data->Info.SAcc = UBX_Packet->Payload.NAV_VELNED.sAcc * 1E-2;
        UBX_Data->Info.CAcc = UBX_Packet->Payload.NAV_VELNED.cAcc * 1E-5;
        UBX_Data->Data.Velocity.NED.AxisX = UBX_Packet->Payload.NAV_VELNED.velN * 1E-2;
        UBX_Data->Data.Velocity.NED.AxisY = UBX_Packet->Payload.NAV_VELNED.velE * 1E-2;
        UBX_Data->Data.Velocity.NED.AxisZ = UBX_Packet->Payload.NAV_VELNED.velD * 1E-2;
        UBX_Data->Data.Velocity.LLA.Speed = UBX_Packet->Payload.NAV_VELNED.speed * 1E-2;
        UBX_Data->Data.Velocity.LLA.GroundSpeed = UBX_Packet->Payload.NAV_VELNED.gSpeed * 1E-2;
        UBX_Data->Data.Velocity.LLA.Heading = UBX_Packet->Payload.NAV_VELNED.heading * 1E-5;
      }
      break;
      default:
        Status = 0;
    }
  }
  return Status;
}