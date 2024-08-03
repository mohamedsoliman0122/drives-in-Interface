#include "MemMap.h"
#include "Utils.h"
#include "StdTypes.h"
#define  F_CPU      8000000
#include "util/delay.h"
#include "DIO_Interface.h"

/*********************  PIN CONFIG *******************/
#define SEGMANT_PORT      PORTA
#define SEGMANT_EN_PORT   PORTC
#define S1_EN               6 
#define S2_EN               7
/*****************************************************/
static u8 segmant_num [] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7D,0x07,0x7f,0x6f};

void segmant_Display(u8 num)
{
	SEGMANT_PORT = segmant_num[num] ;
}
void segmant_Display_BCD(u8 num)
{
	u8 x = num % 10 ;
	u8 y = num / 10 ;
	SEGMANT_PORT = y|x<<4 ;
}
void segmant_Display_MUX(u8 num)
{
	u8 x = num % 10 ;
	u8 y = num / 10 ;
	
	SET_BIT(SEGMANT_EN_PORT,S1_EN);
	SEGMANT_PORT = segmant_num[x];
	CLR_BIT(SEGMANT_EN_PORT,S2_EN);
	_delay_ms(1);
	SET_BIT(SEGMANT_EN_PORT,S2_EN);
	SEGMANT_PORT = segmant_num[y];
	CLR_BIT(SEGMANT_EN_PORT,S1_EN);
	_delay_ms(1);
}