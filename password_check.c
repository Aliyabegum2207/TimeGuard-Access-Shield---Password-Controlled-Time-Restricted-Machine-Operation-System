#include<LPC21xx.h>
#include "lcd.h"
#include "LCD_defines.h"
#include "kpm.h"
#include "types.h"
#include "delay.h"
void password(u32 *num)
{
	u32 key=0,i=0;
	*num=0;
	while(1)
	{
	  key=keyScan();
	  if(key>='0'&&key<='9')
      {
	   *num=(*num*10)+(key-48);
       CmdLCD(0xc0+i);
       CharLCD(key);
      delay_ms(50);
       CmdLCD(0xc0+i);
       CharLCD('*');
        i++;
        while(ColScan()==0);
       }
       else if(key=='D')
       {
         while(ColScan()==0);
        break;
        }
        else if(key=='B')
        {
            while (ColScan() == 0);

            if (i > 0)         
            {
                i--;            
                *num = *num / 10;  

                CmdLCD(0xC0 + i);
                CharLCD(' ');      
                CmdLCD(0xC0 + i);
            }
        }
		else if(key=='A')
		{			   
		CmdLCD(13);
		}

    }
}
main()
{
	u32 curpass=123;
	u32 entered_pass=0;
	u32 key;
	Init_LCD();
	key=keyScan(); 
	while(ColScan()==0);
	while(1)
	{	   
	//key=keyScan();
	 if(key=='A')
	 {
	 CmdLCD(0x01);
	 StrLCD("enter password:");
	 password(&entered_pass);

	 if(entered_pass==curpass)
	{
	  StrLCD("password correct!");
	}
	else
	{
	  StrLCD("invalid password");
	}
    }
		//while(ColScan()==0);
	}
	//while(ColScan()==0);
}
