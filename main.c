#define F_CPU 8000000
#include <util/delay.h>
#define  F_CPU      8000000
#include "util/delay.h"
#include "RC_Car_Button.h"
//#include "UTILS.h"



int main(void)
{
	DIO_Init();
	while(1)
	{

		if(DIO_ReadPin(BT_F) == LOW)
		{
			car_Forward();
			while(DIO_ReadPin(BT_F)== LOW);
		}
		else if(DIO_ReadPin(BT_B)== LOW)
		{
			car_Backward();
			while(DIO_ReadPin(BT_B)== LOW);
		}
		else if(DIO_ReadPin(BT_RR)== LOW)
		{
			car_RotatRight();
			while(DIO_ReadPin(BT_RR)== LOW);
		}
		else if(DIO_ReadPin(BT_RL)== LOW)
		{
			car_RotatLeft();
			while(DIO_ReadPin(BT_RL)== LOW);
		}
		else
		{
			car_Stop();
		}
	}
}

