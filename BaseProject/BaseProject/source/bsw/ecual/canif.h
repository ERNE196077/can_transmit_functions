#ifndef _CANIF_H_
#define _CANIF_H_
   
#include "canif_config.h"


extern CanIf_MsgObjType CanMsgObj;



void CanIf_Init(uint8_t CanChannelId, CanIf_MsgObjType CanIfMsgConfig);

void CanIf_Transmit(uint8_t CanChannelId, uint8_t MsgId);


#endif



