/* ---------------------------------------------------------------------------- */
/*                  Atmel Microcontroller Software Support                      */
/*                       SAM Software Package License                           */
/* ---------------------------------------------------------------------------- */
/* Copyright (c) 2014, Atmel Corporation                                        */
/*                                                                              */
/* All rights reserved.                                                         */
/*                                                                              */
/* Redistribution and use in source and binary forms, with or without           */
/* modification, are permitted provided that the following condition is met:    */
/*                                                                              */
/* - Redistributions of source code must retain the above copyright notice,     */
/* this list of conditions and the disclaimer below.                            */
/*                                                                              */
/* Atmel's name may not be used to endorse or promote products derived from     */
/* this software without specific prior written permission.                     */
/*                                                                              */
/* DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR   */
/* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE   */
/* DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,      */
/* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT */
/* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  */
/* OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF    */
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING         */
/* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, */
/* EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                           */
/* ---------------------------------------------------------------------------- */

INPUT (C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\dbg_console.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\board_lowlevel.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\board_memories.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\MemAlloc.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\exceptions.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\pio.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\mpu.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\pmc.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\uart.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\wdt.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\pio_it.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\supc.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\tc.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\xdma_hardware_interface.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\xdmac.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\xdmad.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\mcan.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\syscalls.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\system_sam.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\timetick.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\app_scheduler.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\Tasks.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\cannm.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\led.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\canif.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\canif_config.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\main.o 
C:\Task4_Team4\BaseProject\BaseProject\workspace\Debug\startup_sam.o)

/*------------------------------------------------------------------------------
 *      Linker script for running in internal FLASH on the ATSAMV71Q21
 *----------------------------------------------------------------------------*/

OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
SEARCH_DIR(.)

/* Memory Spaces Definitions */
MEMORY
{
  rom (rx)  :      ORIGIN = 0x00400000, LENGTH = 0x00200000
  ram (rwx) :      ORIGIN = 0x20400000, LENGTH = 0x00050000
  ram_heap (rwx) : ORIGIN = 0x20450000, LENGTH = 0x00010000
  sdram(rwx): ORIGIN = 0x70000000, LENGTH = 0x00200000
}

/* The stack size used by the application. NOTE: you need to adjust according to your application. */
STACK_SIZE = DEFINED(STACK_SIZE) ? STACK_SIZE : 0x2000;

/* The heapsize used by the application. NOTE: you need to adjust according to your application. */
HEAP_SIZE = DEFINED(HEAP_SIZE) ? HEAP_SIZE : 0x1000;

MY_HEAP_SIZE = DEFINED(MY_HEAP_SIZE) ? MY_HEAP_SIZE : 0x10000;

INCLUDE ..\source\infrastructure\toolset\gcc\sam_flash.ld
INCLUDE ..\source\infrastructure\toolset\gcc\sam_sdram.ld
