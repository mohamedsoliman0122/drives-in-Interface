#ifndef UART_FUNCTIONMESSAGECONTROL_H_
#define UART_FUNCTIONMESSAGECONTROL_H_
#define  F_CPU      8000000
#include "util/delay.h"
#include "UART.h"
#include "UART_Services.h"
#include "DIO_Interface.h"
#include "LCD.h"
#include "SERVO.h"

#define MSG_NUM           4

typedef enum
{
	NOT_WORK= 0,
	WORKED = 1
}FunctionStatus_type;
typedef enum
{
	NOT_MATCH = 0,
	MATCHED = 1
}StringCompare_type;

u16 String_Len(u8* str);

StringCompare_type String_Compare(u8* new_str,u8* msg);

FunctionStatus_type String_SeparateBySpace(u8* str,u8* new_str,u8* num);

StringCompare_type ArrayOfString_LinearSearch(u8** StrOfMsgs,u8 size,u8* new_str ,u8* msg_id );

void SERVO_Move(u8 Angle);

void LCD_Write(u8 num);

void LED_Off(u8 LED);

void LED_On(u8 LED);

void UART_MessageControl_Init(void);

void UART_MessageControl(void);


#endif /* UART_FUNCTIONMESSAGECONTROL_H_ */