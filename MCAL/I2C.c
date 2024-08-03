#include "I2C.h"

void TWI_Init(void)
{
	//TWI Initialization
	//Bit Rate : 400.000 kHz (m7taga tet3adel
	TWBR = 72 ;
	//I2C Bus Slave Address : 0x1 
	//General Call Recognition : Off
	TWAR = 0x02;
	//Generate Acknowledge Pulse : On
	//I2C Interrupt : Off
	TWCR = 0x44 ;
	TWSR = 0x00 ;
	TWSR &=(~((1<<TWPS1) | (1<<TWPS0))) ;	
	//momkan 3adii tet3ml btre2t al set we clear 
}

void TWI_Start(void)
{
	//Send Start Condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN) ;
	// Wait for TWINT Flag Set in TWCR Register
	while(!(TWCR & (1<<TWINT)));
}

void TWI_Stop(void)
{
	//Send Stop Condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO) ;
}

void TWI_Write(u8 data)
{
	//put data in TWI Register
	TWDR = data ;
	//send data
	TWCR = (1<<TWINT) | (1<<TWEN) ;
	//wait for TWINT Flag set in TWCR Register
	while(!(TWCR & ( 1 << TWINT )));
}

u8 TWI_ReadACK(void)
{
	TWCR = (1 << TWINT) | (1<<TWEN) | (1<<TWEA) ; // Enable Ack
	//wait for TWINT Flag set in TWCR Register
	while(!(TWCR & ( 1 << TWINT )));
	//Read Data 
	return TWDR ;
}

u8 TWI_ReadNACK(void)
{
	TWCR = (1 << TWINT) | (1<<TWEN) ;
	//wait for TWINT Flag set in TWCR Register
	while(!(TWCR & ( 1 << TWINT )));
	//Read Data
	return TWDR ;	
}

u8 TWI_GetStatus(void)
{
	u8 status ;
	status = TWSR & 0xF8 ;
	return status ;	
}