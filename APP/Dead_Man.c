#include "Dead_Man.h"
    //Dead Man Pattern
    //Hex value to create The pattern -> Arrow
    u8 const pattern1[]={0x00,0x04,0x02,0x1F,0x02,0x04,0x00,0x00};
    //Hex value to create The pattern -> Man
    u8 const pattern2[]={0x04,0x0A,0x04,0x0E,0x15,0x04,0x0A,0x0A};
    //Hex value to create The pattern -> Man With Arrow
    u8 const pattern3[]={0x04,0x0E,0x06,0x1F,0x17,0x04,0x0A,0x0A};
    //Hex value to create The pattern -> Half Man 1
    u8 const pattern4[]={0x00,0x00,0x08,0x06,0x01,0x06,0x08,0x00};
    //Hex value to create The pattern -> Half Man 2
    u8 const pattern5[]={0x00,0x00,0x10,0x0A,0x0D,0x0A,0x10,0x00};
    
    //Arabic Sentens Pattern
    //Hex value to create The pattern -> ?
    u8 const pattern6[]={0x05,0x00,0x07,0x05,0x05,0xFF,0x00,0x00};
    //Hex value to create The pattern -> ?
    u8 const pattern7[]={0x00,0x00,0x03,0x05,0x09,0xFF,0x00,0x00};
    //Hex value to create The pattern -> ?
    u8 const pattern8[]={0x00,0x14,0x00,0x1C,0x1C,0x07,0x00,0x00};
    //Hex value to create The pattern -> ?
    u8 const pattern9[]={0x00,0x00,0x06,0x01,0x1F,0x00,0x00,0x00};
    //Hex value to create The pattern -> ?
    u8 const pattern10[]={0x00,0x00,0x04,0x00,0x03,0x02,0x0C,0x00};
    //Hex value to create The pattern -> ?
    u8 const pattern11[]={0x00,0x05,0x05,0x05,0x1F,0x00,0x05,0x00};
    //Hex value to create The pattern -> ?
    u8 const pattern12[]={0x04,0x00,0x0A,0x0A,0x1F,0x00,0x00,0x00};
    //Hex value to create The pattern -> ?
    u8 const pattern13[]={0x14,0x00,0x1C,0x1C,0x07,0x00,0x00,0x00};

void Dead_Man_ConfigPattern(void)
{
	LCD_Create_Character(pattern1,1);
	LCD_Create_Character(pattern2,2);
	LCD_Create_Character(pattern3,3);
	LCD_Create_Character(pattern4,4);
	LCD_Create_Character(pattern5,5);
}
void ArabicWord_ConfigPattern(void)
{
	LCD_Create_Character(pattern6,0);
	LCD_Create_Character(pattern7,1);
	LCD_Create_Character(pattern8,2);
	LCD_Create_Character(pattern9,3);
	LCD_Create_Character(pattern10,4);
	LCD_Create_Character(pattern11,5);
	LCD_Create_Character(pattern12,6);
	LCD_Create_Character(pattern13,7);
}
void Write_ArabicWord_Pattern(void)
{
	LCD_GoToWriteChar(0,8,0);
	LCD_GoToWriteChar(0,7,1);
	LCD_GoToWriteChar(0,6,2);
	LCD_GoToWriteChar(1,9,3);
	LCD_GoToWriteChar(1,8,4);
	LCD_GoToWriteChar(1,7,5);
	LCD_GoToWriteChar(1,6,6);
	LCD_GoToWriteChar(1,5,7);
}