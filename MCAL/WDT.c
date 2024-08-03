#include "WDT.h"


void WDT_Set(TimeOut_type time)
{
	u8 wdt_value = 0x08 ;//WDE SET And WDTOE CLEARD 
	wdt_value |=time ;
	//al mafrod a3mel critical section  34an mafe4 INT y2t3nii fe al satren dol
	//lazm da kolo ytktb fe nafs al cycle
	WDTCR |= (1<<WDTOE) | (1<<WDE) ;  
	WDTCR = wdt_value ;
}
void WDT_Stop(void)
{
	WDTCR = (1<<WDTOE) | (1<<WDE) ;
	  
	WDTCR = 0;
}