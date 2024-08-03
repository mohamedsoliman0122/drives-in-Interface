#include "Sensors.h"
/******************* LDR ************************/
u16 LDR_GetLightIntinisty()
{
	u16 light = ADC_GetVolt(LDR_CH);
	return light ;
}

void LDR_StartConversion()
{
	ADC_StartConversion(LDR_CH);
}

u16 LDR_GetReadLightIntinisty()
{
	u16 adc = ADC_GetRead();
	u16 light = (((u32 ) adc *  5000) / 1024 ) ;
	return light ;
}

u8 LDR_GetReadLightIntinisty_PeriodicCheck(u16 *pdata)
{
	u16 light ;
	if( ADC_GetReadPeriodicCheck(&light))
	{
			*pdata =(((u32 ) light * 5000) / 1024 ) ;
			return 1 ;
	}
	else
	{
		return 0 ;
	}
}

/******************* TEMP ***********************/
u16 LM35_GetTemp()
{
	u16 temp ;
	u16 volt = ADC_GetVolt(LM35_CH);
	temp = volt ;
	//the reading contain more zero digit to present 0.0 digits 
	//if reading == 10 ==> 100  , 10.5 ==> 105
	return temp ;
}

void LM35_StartConversion()
{
	ADC_StartConversion(LM35_CH);
}

u16 LM35_GetReadTemp()
{
	u16 adc = ADC_GetRead();
	//the reading contain more zero digit to present 0.0 digits
	//if reading == 10 ==> 100  , 10.5 ==> 105
	u16 temp = (((u32 ) adc *  5000) / 1024 ) / 10 ;
	return temp ;
}

u8 LM35_GetReadTemp_PeriodicCheck(u16 *pdata)
{
	u16 temp ;
	if( ADC_GetReadPeriodicCheck(&temp))
	{
		*pdata =(((u32 ) temp * 5000) / 1024 ) / 10 ;
		return 1 ;
	}
	else
	{
		return 0 ;
	}
}

/******************* POT ************************/
u8 POT_GetPercent()
{
	u16 adc = ADC_Read(POT_CH); 
	u8 per  = ((u32)100 * adc ) /1023 ; 
	return per ;
}

void POT_StartConversion()
{
	ADC_StartConversion(POT_CH);
}

u8 POT_GetReadPrecent()
{
	u16 adc = ADC_GetRead();
	u8 per  = ((u32)100 * adc ) /1023 ;
	return per ;
}

u8 POT_GetReadPercent_PeriodicCheck(u8 *pdata)
{
	u16 perc ;
	if( ADC_GetReadPeriodicCheck(&perc))
	{
		*pdata = ((u32)100 * perc ) /1023 ;
		return 1 ;
	}
	else
	{
		return 0 ;
	}
}

/******************* Pres ***********************/
u16 MPX4115_GetPressure()
{
	u16 pre ;
	u16 adc = ADC_Read(MPX4115_CH);
	pre = ((((u32)adc - 55) * 1000) / 921) + 150;
	//the reading contain more zero digit to present 0.0 digits
	//if reading == 10 ==> 100  , 10.5 ==> 105
	return pre ;
}

void MPX4115_StartConversion()
{
	ADC_StartConversion(MPX4115_CH);
}

u16 MPX4115_GetReadPressure()
{
	u16 adc = ADC_GetRead();
	u16 pre = ((((u32)adc - 55) * 1000) / 921) + 150;
	return pre ;
}

u8 MPX4115_GetReadPressure_PeriodicCheck(u16 *pdata)
{
	u16 pre ;
	if( ADC_GetReadPeriodicCheck(&pre))
	{
		*pdata = ((((u32) pre - 55) * 1000) / 921) + 150;
		return 1 ;
	}
	else
	{
		return 0 ;
	}
}

u8 MPX4115_GetReadPressurePercent()
{
	u16 adc = ADC_GetRead();
	u16 pre = ((((u32)adc - 55) * 1000)  / 921) + 150 ;
	u16 percent = ((u32) 100  * pre ) / 1150 ;
	return percent ;
}

u8 MPX4115_GetReadPressurePercent_PeriodicCheck(u16 *pdata)
{
	u16 pre  , percent ;
	if( ADC_GetReadPeriodicCheck(&pre))
	{
		percent = ((((u32) pre - 55) * 1000) / 921) + 150;
		*pdata = ((u32) 100  * percent ) / 1150 ;
		return 1 ;
	}
	else
	{
		return 0 ;
	}
}
