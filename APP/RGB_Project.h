#ifndef RGB_PROJECT_H_
#define RGB_PROJECT_H_

#define  F_CPU      8000000
#include "util/delay.h"
#include "DIO_Interface.h"
#include "LCD.h"
#include "Timers.h"
#include "KeyPad.h"

#define NO_OF_COLORS         133
#define RGB                   3
#define RED                   0
#define GREEN                 1
#define BLUE                  2

#define NORMAL_MODE           1
#define SHOWROOM_MODE         2

void RGB_Init(void);

void Set_Color(u8 color);

void RGB_NormalMode(void);

void ShowRoom_Mode(void);

u8 SelectMode(void);

#endif /* RGB_PROJECT_H_ */