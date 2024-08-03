
#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#include "DIO_interface.h"

extern const DIO_PinStatus_type PinsStatusArray[TOTAL_PINS];

static void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status);


#endif /* DIO_PRIVATE_H_ */