#include<LPC21xx.h>
#include "lcd.h"
#include "kpm.h"
#include "delay.h"
#include "types.h"
#include "edit.h"
#include "rtc.h"
#define DEVICE 19
extern u32 i_flag;u32 k_flag;
u32 curpass,depass=1234;
u32 ONH=9,ONM=15,OFFH=12,OFFM=15;
u32 h,mi,s,da,dat,mn,y;
void Enable_int(void);
main()
{
	u32 i;
	Init_KPM();
	Init_LCD();
	RTC_Init();
	Enable_int();
	IODIR0|=15<<DEVICE;
	while(1)
	{
		
		 		GetRTCTimeInfo(&h,&mi,&s);
					DisplayRTCTime(h,mi,s);
					GetRTCDateInfo(&dat,&mn,&y);
					DisplayRTCDate(dat,mn,y);
					GetRTCDay(&da);
					DisplayRTCDay(da);
			 //if(ColScan()==0);
		 
		if(ColScan()==0)
		{
		      CmdLCD(0x01);
	          StrLCD("enter password");
			 password(&curpass);
				if(curpass==depass)
				{ 
					while(ColScan()==0);
					CmdLCD(0x01);
					StrLCD("validating");
					//while(ColScan()==0);
					for(i=11;i<16;i++)
					{
						CharLCD('.');
						delay_ms(60);
				}
				CmdLCD(0x01);
				StrLCD("valid password");
				if((HOUR>=ONH)&&(HOUR<=OFFH))
				{
					if((MIN>=ONM)&&(MIN<=OFFM))
					{ 
					IOPIN0=IOPIN0&~(15<<DEVICE)|(0x00<<DEVICE);
					}
				}
		}
		if(i_flag==1)
		{
		i_flag=0;
		edit_menu();
		}
	}
}																		
}
