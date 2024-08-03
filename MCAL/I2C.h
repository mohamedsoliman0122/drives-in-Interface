#ifndef I2C_H_
#define I2C_H_

#include "MemMap.h"
#include "StdTypes.h"
#include "Utils.h"


#define TWI_MT_ARB_LOST       0x38
#define TWI_MR_ARB_LOST       0x38
#define TWI_START             0x08
#define TWI_REP_START         0x10
#define TWI_MT_SLV_ACK        0x18
#define TWI_MT_DATA_ACK       0x28
#define TWI_MR_DATA_NOT_ACK   0x58
#define TWI_MT_DATA_NOT_ACK   0x30
#define TWI_MR_SLV_NOT_ACK    0x48
#define TWI_MT_SLV_NOT_ACK    0x20
#define TWI_MR_DATA_ACK       0x50
#define TWI_MR_SLV_ACK        0x40

#define W  0
#define R  0


void TWI_Init(void);

void TWI_Start(void);

void TWI_Stop(void);

void TWI_Write(u8 data);

u8 TWI_ReadACK(void);

u8 TWI_ReadNACK(void);

u8 TWI_GetStatus(void);

#endif /* I2C_H_ */