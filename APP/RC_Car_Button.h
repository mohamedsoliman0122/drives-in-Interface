


#ifndef RC_CAR_BUTTON_H_
#define RC_CAR_BUTTON_H_

#include "DIO_Interface.h"
#include "Motor_cfg.h"
#include "Motor_Interface.h"

#define  F_R    M1
#define  F_L    M2
#define  B_R    M3
#define  B_L    M4

#define  BT_F   PIND0
#define  BT_B   PIND1
#define  BT_RR  PIND2
#define  BT_RL  PIND3
#define  BT_ST  PIND4



void car_Forward(void);

void car_Backward(void);

void car_RotatLeft(void);

void car_RotatRight(void);

void car_Stop(void);




#endif /* RC_CAR_BUTTON_H_ */