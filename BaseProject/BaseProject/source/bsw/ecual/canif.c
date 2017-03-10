

#include "canif.h"
#include "board.h"
#include "chip.h"

#define _CANIF_DBG_


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

  /* If not empty save CAN messages configuration to use in the module */
  if ( CanIfMsgConfig.CanNumberOfMsgs )
  CanInternMsgConfig = &CanIfMsgConfig;

  /* Initialize MCAN driver */
  MCAN_Init(mcan_config);
  #ifdef _CANIF_DBG_
  printf( "\n\r-- MCAN driver Initialized!!! --\n\r" ) ;
  #endif

  /* Enable MCAN Channel */
  MCAN_Enable(mcan_config);
  #ifdef _CANIF_DBG_
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
  
  CanIf_MessageConfigType *ptrMsgConfig;

  int i;
  for (i = 0; i < CanInternMsgConfig.CanNumberOfMsgs; i++){
    if(MsgId == CanInternMsgConfig.CanIfMessageConfig[i]->CanMsgIdNumber ){
      ptrMsgConfig = CanInternMsgConfig.CanIfMessageConfig[i];
      break;
    }
  }

  /* If the message id was not found OR data buffer pointer is null exit */
  if (!ptrMsgConfig ){
    #ifdef _CANIF_DBG_
    printf( "\n\r-- CANIF::ERROR Message id does not exist. --\n\r" ) ;
    #endif
    return;
  }

  if (!ptrMsgConfig->CanPdu.CanSdu){
    #ifdef _CANIF_DBG_
    printf( "\n\r-- CANIF::ERROR TX buffer for message 0x%x not allocated. --\n\r", MsgId ) ;
    #endif
    return;
  }

  /* TODO - Need funtion to write data into the buffer, using test data */
  uint8_t *ptrTxBuf = ptrMsgConfig->CanPdu.CanSdu;
  for (i = 0; i < ptrMsgConfig->CanPdu.CanDlc; ++i)
  {
    *ptrTxBuf++ = 0x8 ;
  }
  








}