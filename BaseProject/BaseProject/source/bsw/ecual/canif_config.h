#ifndef _CANIF_CONF_H_
#define _CANIF_CONF_H_


#include "stdint.h"
#include "mcan.h"
#include "chip.h"

   typedef enum
   {
      CAN_TX = 0,
      CAN_RX = 1,
   }MCan_DirType;

   typedef struct
   {
      uint32_t CanId;
      MCan_IdType CanIdType;
      MCan_DlcType CanDlc;
      uint8_t* CanSdu;
      uint8_t* CanSduRam;
      uint8_t u8CanDedBuf;
   }CanIf_PduType;

   typedef struct
   {
      uint8_t CanMsgIdNumber;
      MCan_DirType MCanDir;
      CanIf_PduType CanPdu;
   }CanIf_MessageConfigType;

   typedef struct
   {
      uint8_t CanNumberOfMsgs;
      CanIf_MessageConfigType *CanIfMessageConfig;
   }CanIf_MsgObjType;



extern CanIf_MsgObjType CanMsgObj;

#endif