#ifndef __LCD_H__
#define __LCD_H__
#include "types.h"
void Init_LCD(void);
void CmdLCD(u8 CmdByte);
void CharLCD(u8 asciVal);
void WriteLCD(u8 bye);
void StrLCD(s8 *);
void U32LCD(u32);
void S32LCD(s32);
void F32LCD(f32,u32);
void BuildCGRAM(u8 *,u8);
#endif
