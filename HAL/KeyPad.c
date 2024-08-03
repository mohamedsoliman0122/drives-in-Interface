#include "KeyPad.h"

u8 KEYPAD_GetKey()
{
	u8 row , col , key = NO_KEY ;
	DIO_WritePin(FIRST_OUTPUT,HIGH);
	DIO_WritePin(FIRST_OUTPUT+1,HIGH);
	DIO_WritePin(FIRST_OUTPUT+2,HIGH);
	DIO_WritePin(FIRST_OUTPUT+3,HIGH);
	for(row= 0 ; row < ROWS ;row ++)
	{
		DIO_WritePin(FIRST_OUTPUT+row,LOW);
		for(col = 0 ; col < COLS ; col++)
		{
			if(DIO_ReadPin(FIRST_INPUT+col)== LOW)
			{
				key = KeysArray[row][col];
				while(DIO_ReadPin(FIRST_INPUT+col) == LOW);
			}
		}
		DIO_WritePin(FIRST_OUTPUT+row,HIGH);
	}
	return key ;
}
