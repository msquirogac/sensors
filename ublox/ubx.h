#include "ubx_types.h"
#include "ubx_types2.h"

void UBX_CalculateCRC(uint8_t *Checksum, uint8_t NewByte);

uint8_t UBX_ReceiveMessage(UBX_DataPacket_TypeDef *UBX_Packet, uint8_t NewByte);
uint8_t UBX_ParseMessage(UBX_DataPacket_TypeDef *UBX_Packet, UBX_Data_TypeDef *UBX_Data);