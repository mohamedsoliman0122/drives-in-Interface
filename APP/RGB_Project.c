#include "RGB_Project.h"

// 133 Element                
static u8 colors[NO_OF_COLORS][RGB]={
//  Red Green Blue	
	{ 0 , 0 , 0 },//Black
	{254,254,254},//White
	{254, 0 , 0 },//Red
	{ 0 ,254, 0 },//Lime
	{ 0 , 0 ,254},//Blue
	{254,254, 0 },//Yellow
	{ 0 ,254,254},//Cyan / Aqua
	{254, 0 ,254},//Magenta / Fuchsia
	{191,191,191},//Silver
	{127,127,127},//Gray
	{127, 0 , 0 },//Maroon
	{127,127, 0 },//Olive
	{ 0 ,127, 0 },//Green
	{127, 0 ,127},//Purple
	{ 0 ,127,127},//Teal
	{ 0 , 0 ,127},//Navy
/****     1     ****/
	{254,254,254},//white
	{223,223,223},//	
	{191,191,191},//
	{159,159,159},//
	{127,127,127},//
	{ 95, 95, 95},//
	{ 63, 63, 63},//
	{ 31, 31, 31},//
	{ 0 , 0 , 0 },//Black
/****     2     ****/
	{ 50, 0 , 24},//
	{101, 0 , 50},//
	{152, 0 , 75},//
	{203, 0 ,101},//
	{254, 0 ,126},//
	{254, 50,152},//
	{254,101,178},//
	{254,152,203},//
	{254,203,228},//
/****     3     ****/
	{254,203,254},//
	{254,152,254},//
	{254,101,254},//
	{254, 50,254},//
	{254, 0 ,254},//
	{203, 0 ,203},//
	{152, 0 ,152},//
	{101, 0 ,101},//
	{ 50, 0 , 50},//
/****     4     ****/
	{ 24, 0 , 50},//
	{ 50, 0 ,101},//
	{ 75, 0 ,152},//
	{101, 0 ,203},//
	{126, 0 ,254},//
	{152, 50,254},//
	{177,101,254},//
	{203,152,254},//
	{228,203,254},//
/****     5     ****/
	{203,203,254},//
	{152,152,254},//
	{101,101,254},//
	{ 50, 50,254},//
	{ 0 , 0 ,254},//
	{ 0 , 0 ,203},//
	{ 0 , 0 ,152},//
	{ 0 , 0 ,101},//
	{ 0 , 0 , 50},//
/****     6     ****/
	{ 0 , 24, 50},//
	{ 0 , 50,101},//
	{ 0 , 75,152},//
	{ 0 ,101,203},//
	{ 0 ,127,254},//
	{ 50,152,254},//
	{101,177,254},//
	{152,203,254},//
	{203,228,254},//
/****     7     ****/
	{203,254,254},//
	{152,254,254},//
	{101,254,254},//
	{ 50,254,254},//
	{ 0 ,254,254},//
	{ 0 ,203,203},//
	{ 0 ,152,152},//
	{ 0 ,101,101},//
	{ 0 , 50, 50},//
/****     8     ****/
	{ 0 , 50, 24},//
	{ 0 ,101, 50},//
	{ 0 ,152, 75},//
	{ 0 ,203,101},//
	{ 0 ,254,127},//
	{ 50,254,152},//
	{101,254,177},//
	{152,254,203},//
	{203,254,228},//
/****     9     ****/
	{203,254,203},//
	{152,254,152},//
	{101,254,101},//
	{ 50,254, 50},//
	{ 0 ,254, 0 },//
	{ 0 ,203, 0 },//
	{ 0 ,152, 0 },//
	{ 0 ,101, 0 },//
	{ 0 , 50, 0 },//
/****     10    ****/
	{ 24, 50, 0 },//
	{ 50,101, 0 },//
	{ 75,152, 0 },//
	{101,203, 0 },//
	{127,254, 0 },//
	{152,254, 50},//
	{177,254,101},//
	{203,254,152},//
	{228,254,203},//
/****     11    ****/
	{254,254,203},//
	{254,254,152},//
	{254,254,101},//
	{254,254, 50},//
	{254,254, 0 },//
	{203,203, 0 },//
	{152,152, 0 },//
	{101,101, 0 },//
	{ 50, 50, 0 },//
/****     12    ****/
	{ 50, 24, 0 },//
	{101, 50, 0 },//
	{152, 75, 0 },//
	{203,101, 0 },//
	{254,127, 0 },//
	{254,152, 50},//
	{254,177,101},//
	{254,203,152},//
	{254,228,203},//
/****     13    ****/
	{254,203,203},//
	{254,152,152},//
	{254,101,101},//
	{254, 50, 50},//
	{254, 0 , 0 },//
	{203, 0 , 0 },//
	{152, 0 , 0 },//
	{101, 0 , 0 },//
	{ 50, 0 , 0 } //
};

void RGB_Init(void)
{
	TIMER0_Init(TIMER0_FASTPWM_MODE,TIMER0_SCALER_8);
	TIMER1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8);
	Timer1_ICR1_Set(255);
	TIMER0_OC_Mode(OC0_NON_INVERTING);
	TIMER1_OCRA1_Mode(OCRA_NON_INVERTING);
	TIMER1_OCRB1_Mode(OCRB_NON_INVERTING);
}

void Set_Color(u8 color)
{
	Timer0_OC_Set(colors[color][RED]);
	Timer1_OCA_Set(colors[color][GREEN]);
	Timer1_OCB_Set(colors[color][BLUE]);
}

void RGB_NormalMode(void)
{
	u64 num=0 ;
	u8  key = NO_KEY, sel_mode_flag = 0 ;
	LCD_GoToWriteString(0,0,"   Welcome to   ");
	LCD_GoToWriteString(1,0,"  Normal Mode   ");
	_delay_ms(2000);
	LCD_Clear();
	LCD_GoToWriteString(0,0,"Color Range From");
	LCD_GoToWriteString(1,0," (0)To(132) only");
	_delay_ms(2000);
	LCD_GoToWriteString(0,0,"Press 3 Times on");
	LCD_GoToWriteString(1,0," C to go back :)");
	_delay_ms(2000);
	LCD_Clear();
	while(1)
	{
		LCD_GoToWriteString(0,0,"   NormalMode");
		key = KEYPAD_GetKey();
		if(key != NO_KEY)
		{
			if((key >= '0' && key <= '9'))
			{
				num = num * 10 + (key -'0') ;
				LCD_GoToWriteNumber(1,0,num);
			}
			else if (key == 'C')
			{
				LCD_GoToWriteString(1,0,"   ");
				num = 0 ;
				sel_mode_flag ++ ;
			}
			else if (key == '=')
			{
				if(num > 132)
				{
					LCD_GoToWriteString(0,0,"Wrong Num Range");
					LCD_GoToWriteString(1,0,"Range (0)To(132)");
					_delay_ms(1000);
					LCD_Clear();
				}
				else
				{
					Set_Color(num);
				}
				num = 0 ;
				LCD_GoToWriteString(1,0,"   ");
				sel_mode_flag = 0 ;
			}
			if( sel_mode_flag > 2 )
			{
				Set_Color(0);
				return;
			}
		}
	}
}

void ShowRoom_Mode(void)
{
	u8  key = NO_KEY, sel_mode_flag = 0, color = 16 ,flag= 0 ;
	LCD_GoToWriteString(0,0,"   Welcome to   ");
	LCD_GoToWriteString(1,0,"  ShowRoom Mode ");
	_delay_ms(2000);
	LCD_Clear();
	LCD_GoToWriteString(0,0,"Press 3 Times on");
	LCD_GoToWriteString(1,0,"C to go back :)");
	_delay_ms(2000);
	LCD_Clear();
	while(1)
	{
		LCD_GoToWriteString(0,0,"  ShowRoomMode");
		Set_Color(color);
		
		for(u8 i = 0 ; i < 10 ; i++)
		{
			key = KEYPAD_GetKey();
			if(key != NO_KEY)
			{
				if(key == 'C')
				{
					sel_mode_flag++;
				}
				if(sel_mode_flag > 2)
				{
					Set_Color(0);
					return ;
				}
			}
			_delay_ms(50);
		}
		if(flag == 0)
		{
			color ++ ;
			if(color > 132)
			{
				flag = 1 ;
			}
		}
		else if(flag == 1)
		{
			color -- ;
			if(color < 16)
			{
				flag = 0 ;
			}
		}
	}
}

u8 SelectMode()
{
	u8 	key, value ;
	while(1)
	{
		key = KEYPAD_GetKey();
		LCD_GoToWriteString(0,0,"(1) NormalMode");
		LCD_GoToWriteString(1,0,"(2) ShowRoomMode");
		if(key != NO_KEY)
		{
			value = key - '0';
			LCD_Clear();
			LCD_GoToWriteChar(0,0,key);
			if(value == NORMAL_MODE || value == SHOWROOM_MODE)
			{
				return value;
			}
			else
			{
				LCD_Clear();
				LCD_GoToWriteString(0,0,"  Wrong Choice");
				LCD_GoToWriteString(1,0,"   Try Again");
				_delay_ms(1000);
			}
		}
	}
}


/*
void ShowRoom_Mode(void)
{
	u8  key = NO_KEY, sel_mode_flag = 0, flag = 0, R= 254,G = 0, B=0 ;
	LCD_GoToWriteString(0,0,"   Welcome to   ");
	LCD_GoToWriteString(1,0,"  ShowRoom Mode ");
	_delay_ms(3000);
	LCD_Clear();
	LCD_GoToWriteString(0,0,"Press 3 Times on");
	LCD_GoToWriteString(1,0,"C to go back :)");
	_delay_ms(3000);
	LCD_Clear();
	while(1)
	{
		LCD_GoToWriteString(0,0,"  ShowRoomMode");
		key = KEYPAD_GetKey();
		if(key != NO_KEY)
		{
			if(key == 'C')
			{
				sel_mode_flag++;
			}
			if(sel_mode_flag > 2)
			{
				Timer0_OC_Set(0);
				Timer1_OCA_Set(0);
				Timer1_OCB_Set(0);
				return ;
			}
		}
		if(flag == 0)
		{
			Timer0_OC_Set(R--);
			Timer1_OCA_Set(G++);
			Timer1_OCB_Set(0);
			_delay_ms(50);
			if(R == 0)
			{
				flag = 1;
				R = 0 ;
				G = 254;
				B = 0;
			}
		}
		else if (flag == 1)
		{
			Timer0_OC_Set(0);
			Timer1_OCA_Set(G--);
			Timer1_OCB_Set(B++);
			_delay_ms(50);
			if(G == 0)
			{
				flag = 2;
				R = 0 ;
				G = 0;
				B = 254;
			}
		}
		else if (flag == 2)
		{
			Timer0_OC_Set(R++);
			Timer1_OCA_Set(0);
			Timer1_OCB_Set(B--);
			_delay_ms(50);
			if(B == 0)
			{
				flag = 0;
				R = 254 ;
				G = 0;
				B = 0;
			}
		}
	}
}*/