#ifndef I2C_SERVICES_H_
#define I2C_SERVICES_H_
#include "I2C.h"

typedef enum{
	BUS_BUSY,
	WRONG_SLAVE,
	NACK_DATA,
	DONE
}TWI_CheckTrans_type;

TWI_CheckTrans_type TWI_SendByte(u8 SlaveAddress , u8 data);

TWI_CheckTrans_type TWI_SendString(u8 SlaveAddress , u8* str); 








#endif /* I2C_SERVICES_H_ */