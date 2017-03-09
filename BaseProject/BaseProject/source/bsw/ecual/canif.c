

#include "canif.h"
#include "board.h"
#include "chip.h"

#define _MCAN_DBG_

uint8_t  * MCAN_ConfigTxDedBuffer( 
  const MCan_ConfigType * mcanConfig, 
  uint8_t buffer, 
  uint32_t id, 
  MCan_IdType idType, 
  MCan_DlcType dlc );


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

  /* Allocate message configurations and buffers */ 
  
  uint8_t i;
  uint8_t txbuf, rxbuf; 
  CanIf_MessageConfigType *ptrMsgConfig;
  for( i = 0 ; i < CanIfMsgConfig.CanNumberOfMsgs ; i++ ){

    ptrMsgConfig = &(CanIfMsgConfig.CanIfMessageConfig[i]);

    if( ptrMsgConfig->MCanDir == CAN_TX ){
      ptrMsgConfig->CanPdu.CanSdu = (uint8_t *)MCAN_ConfigTxDedBuffer( mcan_config, txbuf++, ptrMsgConfig->CanPdu.CanId, ptrMsgConfig->CanPdu.CanIdType, ptrMsgConfig->CanPdu.CanDlc );

      /* If Buffer allocation gives an error continues to the next register */
      if( !ptrMsgConfig->CanPdu.CanSdu ){
        txbuf--;
        continue;
      }
    }
    else{
      /* TODO - Need to add code for buffer reception */

    }
  }
}


void CanIf_Transmit(uint8_t CanChannelId, uint8_t MsgId){

}