#include<LPC21xx.h>
#include "types.h"
#include "lcd.h"
#include "kpm.h"
#include "delay.h"
#include "edit.h"
extern u32 depass;
extern u32 curpass;
extern u32 ONH,ONM,OFFH,OFFM;
u32 newpass,key,i=0,*num=0;
void edit_password()
{
	CmdLCD(0x01);
	curpass=0;
	StrLCD("enter old pass");
	delay_ms(500);
	password(&curpass);
	if(curpass==depass)
	{
	    curpass=0;
		CmdLCD(0x01);
		StrLCD("enter new pass");
		password(&curpass);
		if(curpass!=depass)
		{
			newpass=curpass;
			CmdLCD(0x01);
			StrLCD("cnfm new pass");
			password(&curpass);
			if(curpass==newpass)
			{
				depass=newpass;
				CmdLCD(0x01);
				StrLCD("password updated");
			}
			else
			{
				CmdLCD(0x01);
				StrLCD("pass not same");
			}
			delay_s(2);
			CmdLCD(0x01);
		  
		  }
		  else
		  {
		  	CmdLCD(0x01);
			StrLCD("   NEW & OLD   ");
			CmdLCD(0xc0);
			StrLCD("  PASS ARE SAME ");
		  }
		  delay_s(2);
			CmdLCD(0x01);
		}
		else
		{
			CmdLCD(0x01);
			 StrLCD("incorrect pass");
		}
}

void edit_menu(void)
{
	u32 key,i;
	CmdLCD(0x01);
	StrLCD("enter password");
      password(&curpass);
				if(curpass==depass)
				{ 
					CmdLCD(0x01);
					StrLCD("validating");
					for(i=11;i<16;i++)
					{
						CharLCD('.');
						delay_ms(60);
				}
				CmdLCD(0x01);
				StrLCD("valid password");
	CmdLCD(0x01);
		StrLCD("MENU");
		delay_ms(2000);
		CmdLCD(0x01);
	while(1)
	{
	 CmdLCD(0x80);
		StrLCD("1.ERTC 2.CHNGPASS");
		CmdLCD(0xc0);
		StrLCD("3.EDTime 4.Exit");
		key=keyScan();
		delay_ms(100);
		while(ColScan()==0);
		switch(key)
		{
			case '1':edit_rtc();
			        break;
			case '2':edit_password();
			        break;
			case '3':edit_time();
			       break;
			case '4':CmdLCD(0x01);
		         StrLCD("Exit menu");
				 delay_ms(1000);
				 CmdLCD(0x01);
			      return;
			default:CmdLCD(0x01);
			StrLCD("invalid option");
			         break;
		}
		//CmdLCD(0x01);
		//StrLCD("Exit menu");
	}
	}
}
void edit_rtc()
{
	u32 key;
	CmdLCD(0x01);
	StrLCD("Edit RTC Time");
	delay_ms(2000);
	CmdLCD(0x01);
	//StrLCD("HH:MM:SS");
	while(1)
	{
		CmdLCD(0x80);
		StrLCD("1.H 2.M 3.S 4.D");
		CmdLCD(0xc0);
		delay_ms(900);
		StrLCD("5.Da 6.M 7.Y 8.E");
		delay_ms(900);
	//	CmdLCD(0x01);
	//	CmdLCD(0x80);
		//StrLCD("6.Month 7.Year");
		CmdLCD(0xc0);
		key=keyScan();
		delay_ms(100);
		while(ColScan()==0);
		switch(key)
		{
			case '1':edit_hour();
			         break;
			case '2':edit_minute();
			         break;
			case '3':edit_second();
			         break;
			case '4':edit_day();
			         break;
			case '5':edit_date();
			         break;
			case '6':edit_month();
			         break;
			case '7':edit_year();
			        break;
			case '8':CmdLCD(0x01);
			         StrLCD("Exit Menu");
			         delay_s(1);
					 CmdLCD(0x01);
			         return;
			default:CmdLCD(0x01);
			StrLCD("invalid option");
			         break;
		}
	}
}
void edit_hour()
{
	u32 hh;
	input:CmdLCD(0x01);
	StrLCD("Enter hour(0-23)");
	CmdLCD(0xc0);
	Readnum(&hh);
	if(hh>23)
	{
	 goto input;
	}
	HOUR=hh;
	CmdLCD(0x01);
	StrLCD("Hour updated");
	delay_ms(900);
}
void edit_minute()
{
	u32 mm;
	input1:CmdLCD(0x01);
	StrLCD("Enter Minute");
	CmdLCD(0xc0);
	Readnum(&mm);
	if(mm>59)
	{
	goto input1;
	}
	MIN=mm;
	CmdLCD(0x01);
	StrLCD("Minute updated");
	delay_ms(900);
}
void edit_second()
{
	u32 ss;
	input2:CmdLCD(0x01);
	StrLCD("Enter second");
	CmdLCD(0xc0);
	Readnum(&ss);
	if(ss>59)
	{
	goto input2;
	}
	SEC=ss;
	CmdLCD(0x01);
	StrLCD("Second updated");
	delay_ms(900);
}
void edit_day()
{
	u32 day;
	input3:CmdLCD(0x01);
	StrLCD("Enter Day");
	CmdLCD(0xc0);
	Readnum(&day);
	if(day>6)
	{
	goto input3;
	}
	DOW=day;
	CmdLCD(0x01);
	StrLCD("Day updated");
	delay_ms(900);
}
void edit_date()
{
	u32 date;
	input4:CmdLCD(0x01);
	StrLCD("Enter Date");
	CmdLCD(0xc0);
	Readnum(&date);
	if(date>30)
	{
	goto input4;
	}
	DOM=date;
	CmdLCD(0x01);
	StrLCD("Day updated");
	delay_ms(900);
}
void edit_month()
{
	u32 mm;
	input5:CmdLCD(0x01);
	StrLCD("Enter Month");
	CmdLCD(0xc0);
	Readnum(&mm);
	if(mm>11)
	{
	goto input5;
	}
	MONTH=mm;
	CmdLCD(0x01);
	StrLCD("Month updated");
}
void edit_year()
{
	u32 yy;
	input6:CmdLCD(0x01);
	StrLCD("Enter Year");
	CmdLCD(0xc0);
	Readnum(&yy);
	if(yy>4095)//based on DATA SHEET
	{
	goto input6;
	}
	YEAR=yy;
	CmdLCD(0x01);
	StrLCD("Year updated");
	delay_ms(900);
}
void edit_time()
{
	u32 key;
	while(1)
	{
		CmdLCD(0x01);
		StrLCD("1.StartTime");
		CmdLCD(0xc0);
		StrLCD("2.EndTime 3.Exit");
		key=keyScan();
		while(ColScan()==0);
		switch(key)
		{
			case '1':set_start_time();
			         break;
			case '2':set_end_time();
			         break;
			case '3':CmdLCD(0x01);
			         StrLCD("Exit");
			         delay_s(1);
					 CmdLCD(0x01);
			        return;
			default:CmdLCD(0x01);
			        StrLCD("Invalid");
			         delay_ms(500);
		}
	}
}
void set_start_time()
{
	u32 hh,mm;
	input7:CmdLCD(0x01);
	StrLCD("Start Hour");
	CmdLCD(0xc0);
	Readnum(&hh);
	if(hh>23)
	{
		goto input7;
	}
	input8:CmdLCD(0x01);
	StrLCD("Start Min");
	CmdLCD(0xc0);
	Readnum(&mm);
	if(mm>59)
	{
		goto input8;
	}
	if(key=='B')
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
	ONH=hh;
	ONM=mm;
	CmdLCD(0x01);
	StrLCD("Updated");
	delay_ms(800);
}
void set_end_time()
{
	u32 hh,mm;
	input9:CmdLCD(0x01);
	StrLCD("End Hour");
	CmdLCD(0xc0);
	Readnum(&hh);
	if(hh>23)
	{
		goto input9;
	}
	input10:CmdLCD(0x01);
	StrLCD("End Min");
	CmdLCD(0xc0);
	Readnum(&mm);
	if(mm>59)
	{
		goto input10;
	}
	if(key=='B')
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
	OFFH=hh;
	OFFM=mm;
	CmdLCD(0x01);
	StrLCD("Updated");
	delay_ms(800);
}
	