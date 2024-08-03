#include "I2C_Services.h"


TWI_CheckTrans_type TWI_SendByte(u8 SlaveAddress , u8 data)
{
	//Start Condition 
	TWI_Start();
	//Check Condition of Start
	if(TWI_GetStatus() != TWI_START)
	    return BUS_BUSY ;
	//Select Slave Address
	//3l4an al data 7 bits bas we al bit al 8 deh bt3at al read/write
	TWI_Write((SlaveAddress<<1)|W) ; 
	//Check ACK
	if(TWI_GetStatus() != TWI_MT_SLV_ACK)
	    return WRONG_SLAVE ;
	//Send Data 
	TWI_Write(data);
	//Check ACK
	if(TWI_GetStatus() != TWI_MT_DATA_ACK)
	    return NACK_DATA ;
	
	TWI_Stop();	
	return DONE ;
}
TWI_CheckTrans_type TWI_SendString(u8 SlaveAddress , u8* str) 
{
	//Start Condition
	TWI_Start();
	//Check Condition of Start
	if(TWI_GetStatus() != TWI_START)
	    return BUS_BUSY ;
	//Select Slave Address
	//3l4an al data 7 bits bas we al bit al 8 deh bt3at al read/write
	TWI_Write((SlaveAddress<<1)|W) ;
	//Check ACK
	if(TWI_GetStatus() != TWI_MT_SLV_ACK)
	    return WRONG_SLAVE ; 	
	for(u8 i= 0 ; str[i] ; i++)
	{
		TWI_Write(str[i]);
		//Check ACK
		if(TWI_GetStatus() != TWI_MT_DATA_ACK)
		return NACK_DATA ;	
	}
	
	TWI_Stop();
	return DONE ;
}