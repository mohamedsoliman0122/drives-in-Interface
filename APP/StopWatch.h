#ifndef STOPWATCH_H_
#define STOPWATCH_H_

#define  F_CPU      8000000
#include "util/delay.h"
#include "StdTypes.h"
#include "DIO_Interface.h"
#include "segmant.h"

#define But1        PIND2
#define But2        PIND3
#define But3        PIND4
#define Buzzer      PINC5


void StopWatch_Init(void);

void StopWatch_Prog(void);



#endif /* STOPWATCH_H_ */