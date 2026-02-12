#include "lcd_defines.h"
#include "lcd.h"
#include "delay.h"
cu8 CgramLUT[]=
{
	/*swastik custom character data for ascii 0*/
	0x1d,0x05,0x05,0x1f,0x14,0x14,0x17,0x00
		/*add more custom character data for ascii 1-7 */
};
main()
{
	Init_LCD();
	CharLCD('A');
	//CmdLCD(GOTO_LINE2_POSO);
	StrLCD("ALIYA BEGUM");
    delay_ms(1000);
	CmdLCD(GOTO_LINE2_POSO);
	U32LCD(1234567890);
	delay_ms(2000);
	CmdLCD(CLEAR_LCD);
	S32LCD(-783839492);
	CmdLCD(GOTO_LINE2_POSO);
	F32LCD(-123.456777,6);
	delay_ms(2000);
	CmdLCD(CLEAR_LCD);
	
	BuildCGRAM((u8*)CgramLUT,8);
	CharLCD('0');
	CharLCD(0);
	while(1);
}
