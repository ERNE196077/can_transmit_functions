/*
 * Tasks.c
 *
 * Created: 6/21/2016 7:25:43 PM
 *  Author: Francisco Martinez
 */ 

#include "Tasks.h"
#include "led.h"
#include "canif.h"

int var = 0;

void vfnTsk_1ms(void)
{

}

void vfnTsk_2msA(void)
{
	
}

void vfnTsk_2msB(void)
{
	
}

void vfnTsk_10ms(void)
{

}

void vfnTsk_50ms(void)
{

}

void vfnTsk_100ms(void)
{
  	  if(!var){
  	var++;
  	CanIf_Init(1, CanMsgObj);
  }else{
    CanIf_Transmit(1,3);
  }		

  
}

