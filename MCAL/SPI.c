#include "SPI.h"

void SPI_Init(MasterSlave_type mode)
{
	//master or slave 
	if(mode== Master)
	{
		SET_BIT(SPCR,MSTR);
	}
	else
	{
		CLR_BIT(SPCR,MSTR); 
	}
	//Clock
	//->defult prescaler /4 -> 2MHz
	CLR_BIT(SPCR,SPR0);
	CLR_BIT(SPCR,SPR1);
	CLR_BIT(SPCR,SPI2X);
	
	/*data order -> default most bit send first*/
	
	//Enable SPI
	SET_BIT(SPCR,SPE);
}

u8 SPI_SendReceive(u8 data)
{
	SPDR = data	;
	while (!READ_BIT(SPSR,SPIF));
	return SPDR ;
}

void SPI_Send(u8 data)
{
	SPDR = data	;
}

u8 SPI_ReceivePeriodic(u8* data)
{
	if(READ_BIT(SPSR,SPIF))
	{
		*data=SPDR ;
		 return 1 ;
	}
    return 0;
}

u8 SPI_Receive(void)
{
	return SPDR ;
}
/*************************** Enable/Disable Functions **************************/
void SPI_InterruptEnable(void)
{
	SET_BIT(SPSR,SPIF);
}
void SPI_InterruptDisable(void)
{
	CLR_BIT(SPSR,SPIF);
}
/*************************** Pointer to Functions to be assigned to ISR **************************/
//we make it static to not be edited by any one in another files
//concept of setter and getter
static void (*Fptr_SPI_INT)(void) = NULLPTR;
/**************************************** Call Back Functions ************************************/
void SPI_SetCallBack(void(*Local_fptr)(void))
{
	Fptr_SPI_INT=Local_fptr;
}
/********************************************** ISR **********************************************/
ISR(SPI_STC_vect)
{
	if(Fptr_SPI_INT != NULLPTR)
	{
		Fptr_SPI_INT();
	}
}