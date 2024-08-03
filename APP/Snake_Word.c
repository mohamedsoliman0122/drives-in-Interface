#include "Snake_Wordh.h"

void Snake_Word(void)
{
	u8 i = 0 , length = 0 , str[]= "Play Game :)";
	DIO_Init();
	LCD_Init();
	//To get Length of the string
	while(str[length])
	{
		length++;
	}
	while(1)
	{
		//to begin with the End of the word  in LCD line 0
		//we begin i = 1 to Escape the null when we make str + length -i
		for(i= 1 ; i < length ; i++)
		{
			LCD_Clear();
			LCD_GoToWriteString(0,0,str+length-i);
			_delay_ms(500);
		}
		//Shift the word to the end of LCD line 0 -> its length from 0 to 15
		//we begin i = 1 to Escape the null when we make str + length -i
		for(i = 0 ; i < 16 ; i++)
		{
			LCD_Clear();
			LCD_GoToWriteString(0,i,str);
			_delay_ms(500);
		}
		//to begin with the End of the word  in LCD line 1
		for(i = 1 ; i< length ; i++)
		{
			LCD_Clear();
			LCD_GoToWriteString(1,0,str+length-i);
			_delay_ms(500);
		}
		//Shift the word to the end of LCD line 1 -> its length from 0 to 15
		for(i = 0 ; i < 16 ; i++)
		{
			LCD_Clear();
			LCD_GoToWriteString(1,i,str);
			_delay_ms(500);
		}
	}
}



/*
//Another Solution
for(i=length ; i > 1 ; i--)
{
	LCD_Clear();
	LCD_WriteString(str+i-1);
	_delay_ms(500);
}
for(i=0 ; i<16 ; i++)
{
	LCD_Clear();
	LCD_GoToWriteString(0,i,str);
	_delay_ms(500);
}
for(i=length ; i > 1 ; i--)
{
	LCD_Clear();
	LCD_GoTo(1,0);
	LCD_WriteString(str+i-1);
	_delay_ms(500);
}
for(i=0 ; i<16 ; i++)
{
	LCD_Clear();
	LCD_GoToWriteString(1,i,str);
	_delay_ms(500);
}
*/