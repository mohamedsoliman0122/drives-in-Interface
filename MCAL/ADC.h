#ifndef ADC_H_
#define ADC_H_

#define  F_CPU      8000000
#include "util/delay.h"
#include "Utils.h"
#include "MemMap.h"
#include "StdTypes.h"

typedef enum{
	ADC_AREF=0,
	ADC_VCC,
	ADC_V256=3
	}ADC_Vref_type;
typedef enum{
	CH_0 = 0,
	CH_1 ,
	CH_2 ,
	CH_3 , 
	CH_4 ,
	CH_5 ,
	CH_6 ,
	CH_7
	}ADC_Channel_type;
typedef enum{
	ADC_SCALER_1=0,
	ADC_SCALER_4=2,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128
	}ADC_Scaler_type;
typedef enum{
	ADC_INT
}ADC_InterruptSource_type;	

void ADC_Init(ADC_Vref_type vref,ADC_Scaler_type scaler);

/*
// i make Enable in initialization function
//if you want to use this functions remove Enable from initialization function
void ADC_Enable(void);
void ADC_Disable(void);
*/

u16 ADC_Read(ADC_Channel_type ch);

u16 ADC_GetVolt(ADC_Channel_type ch);

void ADC_StartConversion(ADC_Channel_type ch);

u16 ADC_GetRead(void);

u8 ADC_GetReadPeriodicCheck(u16 *pdata);
/*************************** Enable/Disable INT Functions **************************/
void ADC_InterruptEnable(void);
void ADC_InterruptDisable(void);
/**************************************** Call Back Functions ************************************/
void ADC_SetCallBack(ADC_InterruptSource_type Interrupt,void(*Local_fptr)(void));

#endif /* ADC_H_ */