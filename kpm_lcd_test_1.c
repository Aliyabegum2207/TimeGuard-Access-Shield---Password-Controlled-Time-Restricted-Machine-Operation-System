#include "kpm.h"
#include "lcd_defines.h"
#include "lcd.h"
#include "delay.h"
u32 key;
main()
{
	Init_LCD();
	Init_KPM();
	StrLCD("KPM TEST");
	while(1)
	{
		key=keyScan();
		//key=keyScan();
		//key=keyScan();
		delay_ms(200);
		CmdLCD(GOTO_LINE2_POSO);
		StrLCD("  ");
		CmdLCD(GOTO_LINE2_POSO);
		U32LCD(key);
		while(ColScan()==0);
	}
}
