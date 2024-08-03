#include "Motor_cfg.h"
#include "Motor_Interface.h"
#include "Motor_Private.h"

 const DIO_Pin_type MotorPinsArray[NUMBER_OF_MOTORS][NUMBERS_OF_PIN_PER_MOTOR]={
	                      /*IN1  IN2*/
	 /* MOTOR 1*/       { EN1_M1,EN2_M1},
	 /* MOTOR 2*/       { EN1_M2,EN2_M2},
	 /* MOTOR 3*/       { EN1_M3,EN2_M3},
	 /* MOTOR 4*/       { EN1_M4,EN2_M4}
 };