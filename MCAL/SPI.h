#ifndef SPI_H_
#define SPI_H_

#include "MemMap.h"
#include "Utils.h"
#include "StdTypes.h"

typedef enum{
	Master,
	Slave
	}MasterSlave_type;
	
void SPI_Init(MasterSlave_type mode);

u8 SPI_SendReceive(u8 data);

void SPI_Send(u8 data) ;

u8 SPI_ReceivePeriodic(u8* data);

u8 SPI_Receive(void);

void SPI_SetCallBack(void(*Local_fptr)(void));

void SPI_InterruptEnable(void);

void SPI_InterruptDisable(void);



#endif /* SPI_H_ */