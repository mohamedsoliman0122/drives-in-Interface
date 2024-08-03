#include "LCD.h"

#if LCD_MODE == _8_BIT
static void LCD_WriteCommand(u8 command)
{
	DIO_WritePin(LCD_RS,LOW);
	DIO_WritePort(LCD_PORT,command);
	DIO_WritePin(LCD_EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_EN,LOW);
	_delay_ms(1);
}
static void LCD_WriteData(u8 data)
{
	DIO_WritePin(LCD_RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(LCD_EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_EN,LOW);
	_delay_ms(1);
}
void LCD_Init()
{
	_delay_ms(50);
	LCD_WriteCommand(0x38); // 2 Line , 5*7 ;
    LCD_WriteCommand(0x0C); // NO Cursor ->0x0C  / for Cursor -> On&Blink-> 0x0F ,Cursor On -> 0x0E ;
	LCD_WriteCommand(0x01); // Clear Screen ;
	_delay_ms(1);
	LCD_WriteCommand(0x06); // Increase DDRAM Address , No Shift  ;
}

#elif LCD_MODE == _4_BIT
static void LCD_WriteCommand(u8 command)
{
	DIO_WritePin(LCD_RS,LOW);
	DIO_WritePin(D7,READ_BIT(command,7));
	DIO_WritePin(D6,READ_BIT(command,6));
	DIO_WritePin(D5,READ_BIT(command,5));
	DIO_WritePin(D4,READ_BIT(command,4));
	DIO_WritePin(LCD_EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(command,3));
	DIO_WritePin(D6,READ_BIT(command,2));
	DIO_WritePin(D5,READ_BIT(command,1));
	DIO_WritePin(D4,READ_BIT(command,0));
	DIO_WritePin(LCD_EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_EN,LOW);
	_delay_ms(1);	
}
static void LCD_WriteData(u8 data)
{
	DIO_WritePin(LCD_RS,HIGH);
	DIO_WritePin(D7,READ_BIT(data,7));
	DIO_WritePin(D6,READ_BIT(data,6));
	DIO_WritePin(D5,READ_BIT(data,5));
	DIO_WritePin(D4,READ_BIT(data,4));
	DIO_WritePin(LCD_EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(data,3));
	DIO_WritePin(D6,READ_BIT(data,2));
	DIO_WritePin(D5,READ_BIT(data,1));
	DIO_WritePin(D4,READ_BIT(data,0));
	DIO_WritePin(LCD_EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_EN,LOW);
	_delay_ms(1);
}
void LCD_Init()
{
	_delay_ms(50);
	LCD_WriteCommand(0x02); // 2 Line , 5*7 ;
	LCD_WriteCommand(0x28); // 2 Line , 5*7 ;
	LCD_WriteCommand(0x0c); // NO Cursor ->0x0c  / for Cursor -> On&Blink-> 0x0F ,Cursor On -> 0x0E ;
	LCD_WriteCommand(0x01); // Clear Screen ;
	_delay_ms(1);
	LCD_WriteCommand(0x06); // Increase DDRAM Address , No Shift  ;
}
#endif


/***********************************************************************************************/
void LCD_Clear(void)
{
	LCD_WriteCommand(0x01); // Clear Screen ;
}

void LCD_WriteChar(u8 ch)
{
	LCD_WriteData(ch);
}

void LCD_WriteString(u8 *str)
{
	u8 i ;
	for(i =0 ; str[i] ; i++)
	{
		LCD_WriteData(str[i]);
	}
}

void LCD_WriteNumber(s64 num)
{
	u8 rem , str[20] ,i = 0  ;
	if(num == 0)
	{
		LCD_WriteData('0');
		return ;
	}
    if(num < 0)
	{
		num = num * (-1);
		LCD_WriteChar('-');
	}
	while(num > 0)
	{
		rem=num%10;
		str[i] =rem + '0' ;
		num=num/10;
		i++;
	}
    for(s8 j = i-1 ; j>= 0 ; j--)
	{
	  LCD_WriteChar(str[j]);
	}
}

void LCD_WriteNumbe_4D(u16 num)
{
	LCD_WriteChar(((num%10000)/1000)+'0');
	LCD_WriteChar(((num%1000)/100)+'0');
	LCD_WriteChar(((num%100)/10)+'0');
	LCD_WriteChar(((num%10)/1)+'0');
}

void LCD_WriteBinaryNumber(u64 num)
{
	s8 i , flag = 0 ;
	for(i= 63 ; i >= 0 ; i--)
	{
		if((num>>i) & 1)
		{
			LCD_WriteChar('1');
			flag=1 ;
		}
		else
		{
			if(flag == 1)
			{
				LCD_WriteChar('0');
			}
		}
	}
}

void LCD_WriteBinaryNumberWithZero(u8 num)
{
	s8 i ;
	for(i= 7 ; i >= 0 ; i--)
	{
		if((num>>i) & 1)
		{
			LCD_WriteChar('1');
			
		}
		else
		{

			LCD_WriteChar('0');
		}
	}
}

void LCD_WriteHexNumber(u8 num)
{
	u8 Hnibble = num >> 4 ;
	u8 Lnibble = num & 0x0F ;
	u8  HexArray[]={'0','1','2','3',
		            '4','5','6','7',
		            '8','9','A','B',
		            'C','D','E','F'
	               };
	//LCD_WriteChar('0');
	//LCD_WriteChar('x');
	LCD_WriteChar(HexArray[Hnibble]);
	LCD_WriteChar(HexArray[Lnibble]);
}

void LCD_WriteHexu64Number(u64 num)
{
	u8 static flag = 0 ;
	u8 nibble ,hex =60 ;
	u8  HexArray[]={'0','1','2','3',
		            '4','5','6','7',
		            '8','9','A','B',
	             	'C','D','E','F'
                   	};
	
	for(u8 i = 0 ; i < 16 ; i++ ,hex-=4)
	{
		nibble = (num >> hex) & 0x0f ;
		if(nibble > 0)
		{
			flag = 1 ;
		}
		if(flag == 1)
		{
			LCD_WriteChar(HexArray[nibble]);
		}
	}
	flag = 0 ;
}

void LCD_GoTo(u8 line ,u8 cell)
{
	if(line == 0)
	{
		LCD_WriteCommand(0x80|cell);
	}
	else if (line == 1)
	{
		LCD_WriteCommand((0x80+0x40)|cell);
	}
}

void LCD_GoToClear(u8 line,u8 cell,u8 numOfCells)
{
	u8 i ;
	LCD_GoTo(line,cell);
	for(i = 0 ; i < numOfCells ; i++)
	{
		LCD_WriteChar(' ');
	}
}

void LCD_GoToWriteString(u8 line , u8 cell , u8 *str)
{
	LCD_GoTo(line,cell);
	LCD_WriteString(str);	
}

void LCD_GoToWriteNumber(u8 line , u8 cell , s64 num)
{
	LCD_GoTo(line,cell);
	LCD_WriteNumber(num);
}

void LCD_GoToWriteBinaryNumber(u8 line , u8 cell , u64 num)
{
	LCD_GoTo(line,cell);
	LCD_WriteBinaryNumber(num);
}

void LCD_GoToWriteHexNumber(u8 line , u8 cell , u8 num)
{
	LCD_GoTo(line,cell);
	LCD_WriteHexNumber(num);
}

void LCD_GoToWriteChar(u8 line , u8 cell , u8 ch)
{
	LCD_GoTo(line,cell);
	LCD_WriteData(ch);
}

void LCD_Create_Character(u8 *pattern, u8 address)
{
	u8 iLoop;
	
	LCD_WriteCommand(0x40+(address*8)); //Send The Address Of CGRAM
	for(iLoop = 0 ; iLoop < 8 ;iLoop++)
	{
		LCD_WriteData(pattern[iLoop]);//Pass The Bytes Of Pattern On LCD
	}
	LCD_WriteCommand(0x80); //GoTo the address Of DDRAM After Finished
}

void LCD_GoToWriteHexu64Number(u8 line , u8 cell , u64 num)
{
	LCD_GoTo(line,cell);
	LCD_WriteHexu64Number(num);
}

/*
//function for signed number only
void LCD_WriteUnSignedNumber(u64 num)
{
	u64 rem , reversed = 0 , digits_counter = 0 ;
	if(num == 0)
	{
		LCD_WriteData(num + '0');
	}
	else
	{
		while(num > 0)
		{
			rem=num%10;
			num=num/10;
			reversed= (reversed * 10) + rem ;
			digits_counter ++ ;
		}
		while(digits_counter)
		{
			rem = reversed  % 10 ;
			reversed = reversed / 10 ;
			LCD_WriteData(rem + '0');
			digits_counter -- ;
		}
	}
}
*/
/*
another solution
void LCD_WriteNumbe_4D(u16 num)
{
	u8 rem , str[5] ={0}  ;
	s8 i =0;
	for(i =0 ; i < 4 ;i++)
	{
		rem=num%10;
		str[i]=rem+'0';
		num=num/10;
	}
	for(i=4 ; i >= 0 ;i--)
	{
		LCD_WriteChar(str[i]);
	}
}
*/
/*
another solution
void LCD_WriteHexNumber(u8 num)
{
	u8 Hnibble = num >> 4 ;
	u8 Lnibble = num && 0x0f ;
	if(Hnibble <= 9)
	{
		LCD_WriteChar(Hnibble + '0');
	}
	else
	{
		LCD_WriteChar(Hnibble - 10 +'A');
	}
	if(Lnibble <= 9)
	{
		LCD_WriteChar(Lnibble + '0');
	}
	else
	{
		LCD_WriteChar(Lnibble - 10 +'A');
	}

}
another solution
void LCD_WriteHexNumber(u8 num)
{
	s8 i ,value_1 = 8 ,value_2 = 8 , Hex_1 = 0, Hex_2 =0;
	LCD_WriteChar('0');
	LCD_WriteChar('x');
	for(i= 7 ; i >= 0 ; i--)
	{
		if(i > 3)
		{
			if((num>>i) & 1)
			{
				Hex_1 = Hex_1 + value_1 ;
			}
			value_1 = value_1 / 2 ;
		}
		else
		{
			if((num>>i) & 1)
			{
				Hex_2 = Hex_2 + value_2 ;
			}
			value_2 = value_2 / 2 ;
		}
	}
	switch(Hex_1)
	{
		case 10 :
		LCD_WriteChar('A');
		break;
		case 11 :
		LCD_WriteChar('B');
		break;
		case 12 :
		LCD_WriteChar('C');
		break;
		case 13 :
		LCD_WriteChar('D');
		break;
		case 14 :
		LCD_WriteChar('E');
		break;
		case 15 :
		LCD_WriteChar('F');
		break;
		default:
		LCD_WriteChar(Hex_1 +'0');
	}
	switch(Hex_2)
	{
		case 10 :
		LCD_WriteChar('A');
		break;
		case 11 :
		LCD_WriteChar('B');
		break;
		case 12 :
		LCD_WriteChar('C');
		break;
		case 13 :
		LCD_WriteChar('D');
		break;
		case 14 :
		LCD_WriteChar('E');
		break;
		case 15 :
		LCD_WriteChar('F');
		break;
		default:
		LCD_WriteChar(Hex_2 +'0');
	}

}
*/
