#ifndef LCD_H_
#define LCD_H_

#define  F_CPU      8000000
#include "util/delay.h"
#include "DIO_Interface.h"


#define  _4_BIT     1
#define  _8_BIT     2


/******************************** PIN_CONFIG ********************************/
/********* SELECT_MODE *********/
#define LCD_MODE           _4_BIT
/*******************************/
#define LCD_RS             PINA1
#define LCD_EN             PINA2
/********** _4_BIT ************/
#define D4                 PINA3
#define D5                 PINA4
#define D6                 PINA5
#define D7                 PINA6

/********** _8_BIT ************/
#define LCD_PORT           PA
/***************************************************************************/

void LCD_Init(void);

void LCD_Clear(void);

void LCD_WriteString(u8 *str);

void LCD_Create_Character(u8 *pattern, u8 address);

void LCD_WriteChar(u8 ch);

void LCD_WriteNumber(s64 num);

void LCD_WriteNumbe_4D(u16 num);

void LCD_WriteBinaryNumber(u64 num);

void LCD_WriteBinaryNumberWithZero(u8 num);

void LCD_WriteHexNumber(u8 num);

void LCD_WriteHexu64Number(u64 num);

void LCD_GoTo(u8 line ,u8 cell);

void LCD_GoToClear(u8 line,u8 cell,u8 numOfCells);

void LCD_GoToWriteString(u8 line , u8 cell , u8 *str) ;

void LCD_GoToWriteNumber(u8 line , u8 cell , s64 num) ;

void LCD_GoToWriteBinaryNumber(u8 line , u8 cell , u64 num);

void LCD_GoToWriteHexNumber(u8 line , u8 cell , u8 num);

void LCD_GoToWriteChar(u8 line , u8 cell , u8 ch);

void LCD_GoToWriteHexu64Number(u8 line , u8 cell , u64 num);

#endif /* LCD_H_ */