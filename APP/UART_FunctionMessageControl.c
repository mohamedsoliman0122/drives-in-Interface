#include "UART_FunctionMessageControl.h"

static *StrOfMsgs[4] ={"LEDON","LEDOFF","LCD","SERVO"};
static void(*msg_fun[4])(u8 num) ={LED_On,LED_Off,LCD_Write,SERVO_Move};
	
static	u8 str[10], new_str[10];
static	u8 msg_id= 0 ;
static 	u16 num = 0 ;


u16 String_Len(u8*str)
{
	u16 i;
	for(i=0; str[i]; i++);
	return i;
}

StringCompare_type String_Compare(u8*new_str,u8*msg)
{
	u16 i;
	StringCompare_type status = NOT_MATCH ;
	u16 l1=String_Len(new_str);
	u16 l2=String_Len(msg);
	if(l1!=l2)
	{
		status = NOT_MATCH ;
	}
	else
	{
		for(i= 0 ; i < l1; i++)
		{
			if(new_str[i] != msg[i])
			{
				status = NOT_MATCH ;
				break ;
			}
			status = MATCHED ;
		}	
	}
	return status ;
}

FunctionStatus_type String_SeparateBySpace(u8*str,u8*new_str,u8*num)
{
	u8 space_flag = 0, num_flag = 0 ;
	u16 i= 0, j= 0 ;
	FunctionStatus_type status = NOT_WORK ;
	for(i= 0 ; str[i] ; i++)
	{
		if( str[i] >= 'A' && str[i] <= 'z')
		{
			new_str[i]=str[i];
		}
		else if((str[i] == ' ' ))
		{
			space_flag = 1 ;
			new_str[i]= 0 ;
			for(j = i ; str[j]; j++)
			{
				if ((str[j] >= '0') && (str[j] <= '9'))
				{
					num_flag = 1 ;
					*num= *num * 10 +(str[j] - '0');
				}
			}
			if((space_flag == 1) && (num_flag == 1))
			{
				status = WORKED;
			}
			else
			{
				status = NOT_WORK ;
			}
			return status ;
		}
	}
}

StringCompare_type ArrayOfString_LinearSearch(u8**StrOfMsgs,u8 size,u8 *new_str ,u8*msg_id )
{
	u16 i;
	for( i=0 ; i<size ; i++)
	{	
		if( String_Compare(StrOfMsgs[i] , new_str) == MATCHED)
		{
			*msg_id = i ;
			return MATCHED;
		}
	}
	return NOT_MATCH ;
}

void LED_On(u8 LED)
{
	DIO_WritePin(LED,HIGH);
}

void LED_Off(u8 LED)
{
	DIO_WritePin(LED,LOW);
}

void LCD_Write(u8 num)
{
	LCD_GoToWriteNumber(1,0,num);	
}

void SERVO_Move(u8 Angle)
{
	SERVO_SetAngleTimer1_OCRA(Angle);
}

void UART_MessageControl_Init(void)
{
	DIO_Init();
	LCD_Init();
	UART_Init();
	SERVO_Init_Timer1(TIMER1A_ICR_TOP);
	LCD_GoToWriteString(0,0," Enter Message");
}

void UART_MessageControl(void)
{
	UART_ReceiveString_BusyWait_Synch(str);
	LCD_Clear();
	LCD_GoToWriteString(0,0,str);
	if(String_SeparateBySpace(str,new_str,&num) == WORKED)
	{
		if(ArrayOfString_LinearSearch(StrOfMsgs,MSG_NUM,new_str,&msg_id)== MATCHED)
		{
			LCD_GoToWriteString(0,9,"MSG_ID");
			LCD_GoToWriteNumber(0,15,msg_id);
			msg_fun[msg_id](num);
		}
		else
		{
			LCD_GoToWriteString(0,0,"Wrong Operation");
			_delay_ms(300);
			LCD_GoToWriteString(0,0,"  Enter Message");
		}
	}
	else
	{
		LCD_GoToWriteString(0,0,"Wrong Operation");
		_delay_ms(300);
		LCD_GoToWriteString(0,0,"  Enter Message");
	}
	num = 0 ;
	msg_id = 0 ;
}
