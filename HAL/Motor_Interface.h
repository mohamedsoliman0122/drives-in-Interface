

#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_

#include "DIO_Interface.h"



typedef enum{
	M1,
	M2,
	M3,
	M4
}MOTOR_type;


void MOTOR_CW  (MOTOR_type motor);

void MOTOR_CCW (MOTOR_type motor);

void MOTOR_Stop(MOTOR_type motor);








#endif /* MOTOR_INTERFACE_H_ */