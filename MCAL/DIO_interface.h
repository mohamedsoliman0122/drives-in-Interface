
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_TYPES.h"
#include "MEMMAP.h"
#include "UTILS.h"

typedef enum{
	PINA0=0,
	PINA1=1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS
}DIO_Pin_type;


typedef enum{
	OUTPUT,
	INFREE,
	INPULL
	}DIO_PinStatus_type;

typedef enum{
	PA=0,
	PB,
	PC,
	PD
}DIO_Port_type;


typedef enum{
	LOW=0,
	HIGH
}DIO_PinVoltage_type;
 

extern void DIO_WritePin(DIO_Pin_type pin,DIO_PinVoltage_type volt);

extern DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin);

extern void DIO_WritePort(DIO_Port_type port,u8 value);

extern void DIO_ToggelPin(DIO_Pin_type pin);

extern u8 DIO_ReadPort(DIO_Port_type port);

void DIO_Init(void);

#endif /* DIO_INTERFACE_H_ */