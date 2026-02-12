#include <LPC21xx.h>
#include "types.h"
#include "pin_function_defines.h"
#include "pin_connect_block.h"

#define EINTO_VIC_CHNO 14
#define EINTO_STATUS_LED 16
#define EINTO_PIN_0_1 PIN_FUNC4

void einto_isr(void) __irq;
u32 i_flag=0;
void Enable_int(void)
{
	//cfg EINTO status led pin as gpio output
	//IODIR1|=1<<EINTO_STATUS_LED;
	//cfg p0.1 pin as EINTO input pin
	cfgPortFunc(0,1,EINTO_PIN_0_1);
	//cfg VIC peripheral for EINTO
	//cfg EINTO as irq type,def all are anyway irq
	//VICINTSelect=0;
	//Enable EINTO via VIC
	VICIntEnable=1<<EINTO_VIC_CHNO;
	//cfg EINTO as v.irq,highest priority 0
	VICVectCntl0=(1<<5)|EINTO_VIC_CHNO;
	//load einto_isr addr in hardware lut sfr for v.irq
	VICVectAddr0=(u32)einto_isr;
	//cfg External interrupt peripheral
	//Enable EINTO,def all eints are any enable
	//EXTINT=0;
	//cfg EINTO for edge triggering
	EXTMODE=1<<0;
	//cfg EINTO for falling edge triggering,def FE anyway
	//EXTPOLAR=0
	//enter regular operations
}
void einto_isr(void) __irq
{
	//einto isr user activity begins
	//toggle EINTO status led upon interrupt fired/raised
	//IOPIN1^=1<<EINTO_STATUS_LED;
	i_flag=1;
	  
	//einto isr user activity ends
	//clear EINTO status in external interrupt perpheral
	EXTINT=1<<0;
	//clear EINTO status in peripheral
	VICVectAddr=0;
}
