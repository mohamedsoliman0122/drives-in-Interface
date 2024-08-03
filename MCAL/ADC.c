
#include "ADC.h"

void ADC_Init(ADC_Vref_type vref,ADC_Scaler_type scaler)
{	
	//Vref
	switch (vref)
	{
	 case ADC_AREF:
	 CLR_BIT(ADMUX,REFS1);
	 CLR_BIT(ADMUX,REFS0);
	 break;
	 case ADC_VCC:
	 CLR_BIT(ADMUX,REFS1);
	 SET_BIT(ADMUX,REFS0);
	 break;
	 case ADC_V256:
	 SET_BIT(ADMUX,REFS1);
	 SET_BIT(ADMUX,REFS0);
	 break;
	}
	//prescaler (clock)
     ADCSRA = ADCSRA  & 0xf8  ; //11111000
	 scaler = scaler  & 0x07  ; //00000111
	 ADCSRA = ADCSRA  | scaler; 
	 //Adjust Read to the Right
	 CLR_BIT(ADMUX,ADLAR);
	//ADC Enable
	SET_BIT(ADCSRA,ADEN);	
}

u16 ADC_Read(ADC_Channel_type ch)
{
	//Select Channel
	ADMUX = ADMUX & 0xE0 ; //0b11100000
	ADMUX = ADMUX | ch   ;
	//start conversion
	SET_BIT(ADCSRA,ADSC);
	//wait until conversion end
	while(READ_BIT(ADCSRA,ADSC));// pooling busy wait
	//reading
	return ADC ;
	//we make casting in MemMap instead of this solution
	//u16 ADC = ADLAR |( u16) ADCH << 8
}

u16 ADC_GetVolt(ADC_Channel_type ch)
{  
	 u16 adc = ADC_Read(ch) ;
	 //                   read       v_in 5 *1000 mili volt    no.of probabilities of 1 bits 
	 u16 v_out = (((u32 ) adc      *  5000)                     / 1024 ) ;
	 return v_out ; 
}

static u8 read_flag = 1 ;

void ADC_StartConversion(ADC_Channel_type ch)
{
	if(read_flag == 1)
	{
		//Select Channel
		ADMUX = ADMUX & 0xe0 ; //0b11100000
		ADMUX = ADMUX | ch   ;
		//start conversion
		SET_BIT(ADCSRA,ADSC);
		//wait until conversion end
		read_flag = 0 ;
	}
	
}

u16 ADC_GetRead(void)
{
	//wait until conversion end
	while(READ_BIT(ADCSRA,ADSC));// pooling busy wait
	read_flag = 1 ;
	//reading
	return ADC ;
	//we make casting in MemMap instead of this solution
	//u16 ADC = ADLAR |( u16) ADCH << 8
}
	
u8 ADC_GetReadPeriodicCheck(u16 *pdata)
{
	if(READ_BIT(ADCSRA,ADSC) == 0)
	{
		*pdata = ADC ;
		read_flag = 1 ;
		return 1 ;
	}
	else
	{
		return 0 ;
	}
}

/*************************** Enable/Disable INT Functions **************************/
void ADC_InterruptEnable(void)
{
	SET_BIT(ADCSRA,ADIE);
}
void ADC_InterruptDisable(void)
{
	CLR_BIT(ADCSRA,ADIE);
}
/*************************** Pointer to Functions to be assigned to ISR **************************/
//we make it static to not be edited by any one in another files
//concept of setter and getter
static void (*Fptr_ADC_INT)(void) = NULLPTR;
/**************************************** Call Back Functions ************************************/
void ADC_SetCallBack(ADC_InterruptSource_type Interrupt,void(*Local_fptr)(void))
{
	Fptr_ADC_INT=Local_fptr;
}
/********************************************** ISR **********************************************/
ISR(ADC_vect)
{
	if(Fptr_ADC_INT != NULLPTR)
	{
		Fptr_ADC_INT();
	}
}



















/*
// i make Enable in initialization function 
//if you want to use this functions remove Enable from initialization function
void ADC_Enable(void)
{   //ADC Enable
	SET_BIT(ADCSRA,ADEN);
}

void ADC_Disable(void)
{   //ADC Enable
	CLR_BIT(ADCSRA,ADEN);
}
*/