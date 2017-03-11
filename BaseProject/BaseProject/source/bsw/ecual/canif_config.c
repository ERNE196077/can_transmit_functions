
#include "canif_config.h"
#include "cannm.h"




CanIf_MessageConfigType CanTxMsg[] =
{
   { 0, CAN_TX, { 0x1A0, CAN_STD_ID, CAN_DLC_3, (uint8_t *)&u8CANData0, (uint8_t *)0, 255 } },
   { 1, CAN_TX, { 0x123456A0, CAN_EXT_ID, CAN_DLC_6, (uint8_t *)&u8CANData1, (uint8_t *)0, 255 } },
   { 2, CAN_TX, { 0x1B0, CAN_STD_ID, CAN_DLC_7, (uint8_t *)&u8CANData2, (uint8_t *)0, 255 } },
   { 3, CAN_TX, { 0x123456B0, CAN_EXT_ID, CAN_DLC_8, (uint8_t *)&u8CANData3, (uint8_t *)0, 255 } }
};

CanIf_MsgObjType CanMsgObj =
{
sizeof(CanTxMsg)/sizeof(CanIf_MessageConfigType),
CanTxMsg
};


