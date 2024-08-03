#include "DIO_interface.h"
#include "DIO_private.h"

void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type statuc)
{
	DIO_Port_type port=pin/8;
	u8 pin_num=pin%8;
	 switch(statuc)
	 {
		 case OUTPUT:
		 switch(port)
		 {
			 case PA:
			 SET_BIT(DDRA,pin_num);
			 CLR_BIT(PORTA,pin_num);
			 break;
			 case PB:
			 SET_BIT(DDRB,pin_num);
			 CLR_BIT(PORTB,pin_num);
			 break;
			 case PC:
			 SET_BIT(DDRC,pin_num);
			 CLR_BIT(PORTC,pin_num);
			 break;
			 case PD:
			 SET_BIT(DDRD,pin_num);
			 CLR_BIT(PORTD,pin_num);
			 break;
		 }
		 break;
		 
		 case INFREE:
		 switch(port)
		 {
			 case PA:
			 CLR_BIT(DDRA,pin_num);
			 CLR_BIT(PORTA,pin_num);
			 break;
			 case PB:
			 CLR_BIT(DDRB,pin_num);
			 CLR_BIT(PORTB,pin_num);
			 break;
			 case PC:
			 CLR_BIT(DDRC,pin_num);
			 CLR_BIT(PORTC,pin_num);
			 break;
			 case PD:
			 CLR_BIT(DDRD,pin_num);
			 CLR_BIT(PORTD,pin_num);
			 break;
		 }
		 break;
		 
		 case INPULL:
		 switch(port)
		 {
			 case PA:
			 CLR_BIT(DDRA,pin_num);
			 SET_BIT(PORTA,pin_num);
			 break;
			 case PB:
			 CLR_BIT(DDRB,pin_num);
			 SET_BIT(PORTB,pin_num);
			 break;
			 case PC:
			 CLR_BIT(DDRC,pin_num);
			 SET_BIT(PORTC,pin_num);
			 break;
			 case PD:
			 CLR_BIT(DDRD,pin_num);
			 SET_BIT (PORTD,pin_num);
			 break;
		 }
		 break;
	 } 
}



void DIO_WritePin(DIO_Pin_type pin,DIO_PinVoltage_type volt)
{
	DIO_Port_type port=pin/8;
	u8 pin_num=pin%8;
	if (volt==HIGH)
	{
		switch(port)
		{
			case PA:
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT (PORTD,pin_num);
			break;
		}
	}
	else if(volt==LOW)
	{
		switch(port)
		{
			case PA:
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT (PORTD,pin_num);
			break;
		}
	}
}

DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin)
{
	DIO_PinVoltage_type volt=LOW;
	DIO_Port_type port=pin/8;
	u8 pin_num=pin%8;
	
	switch(port)
	{
		case PA:
		volt=(DIO_PinVoltage_type)READ_BIT(PINA,pin_num);
		break;
		
		case PB:
		volt=(DIO_PinVoltage_type)SET_BIT(PINB,pin_num);
		break;
		
		case PC:
		volt=(DIO_PinVoltage_type)SET_BIT(PINC,pin_num);
		break;
		
		case PD:
		volt=(DIO_PinVoltage_type)SET_BIT (PIND,pin_num);
		break;
	}
	return volt;
}

void DIO_TogglPin(DIO_Pin_type pin)
{
	DIO_Port_type port = pin / 8  ;
	u8 pin_num = pin % 8 ;
	switch(port)
	{
		case PA :
		TOG_BIT(PORTA,pin_num);
		break;
		case PB :
		TOG_BIT(PORTB,pin_num);
		break;
		case PC :
		TOG_BIT(PORTC,pin_num);
		break;
		case PD :
		TOG_BIT(PORTD,pin_num);
		break;
	}
}

void DIO_WritePort(DIO_Port_type port ,u8 value)
{
	switch(port)
	{
		case PA :
		PORTA = value ;
		break;
		case PB :
		PORTB = value ;
		break;
		case PC :
		PORTC = value ;
		break;
		case PD :
		PORTD = value ;
		break;
	}
}

u8 DIO_ReadPort(DIO_Port_type port)
{
	u8 data  = 0 ;
	switch(port)
	{
		case PA :
		data = PORTA ;
		break;
		case PB :
		data = PORTB ;
		break;
		case PC :
		data = PORTC ;
		break;
		case PD :
		data = PORTD ;
		break;
	}
	return data ;
}

void DIO_Init(void)
{
	DIO_Pin_type i = PINA0 ;
	for(i = PINA0 ; i< TOTAL_PINS ; i++)
	{
		DIO_InitPin(i,PinsStatusArray[i]);
	}
}