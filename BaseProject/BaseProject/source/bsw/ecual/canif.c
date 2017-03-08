

#include "canif.h"
#include "board.h"
#include "chip.h"

#define _MCAN_DBG_

static const CanIf_MsgObjType *CanInternMsgConfig;

void CanIf_Init(uint8_t CanChannelId, CanIf_MsgObjType CanIfMsgConfig){
  const MCan_ConfigType *mcan_config;

  	/* Check if Channel received is whithin the two available, if not, do nothing */
	switch (CanChannelId){
		case 0:
			mcan_config = &mcan0Config;
		break;
		case 1:
			mcan_config = &mcan1Config;
		break;
		default:
			return;
		break;	
	}

  /* Save CAN messages configuration to use in the module */
  CanInternMsgConfig = &CanIfMsgConfig;

  /* Initialize MCAN driver */
  MCAN_Init(mcan_config);
  #ifdef _MCAN_DBG_
  printf( "\n\r-- MCAN driver Initialized!!! --\n\r" ) ;
  #endif

  /* Enable MCAN Channel */
  MCAN_Enable(mcan_config);
  #ifdef _MCAN_DBG_
  printf( "\n\r-- MCAN Enabled!!! --\n\r" ) ;
  #endif

}


void CanIf_Transmit(uint8_t CanChannelId, uint8_t MsgId){

}