
#ifndef DEAD_MAN_H_
#define DEAD_MAN_H_
//#include "DIO_Interface.h"
#include "LCD.h"

   //Dead Man Pattern
   //Hex value to create The pattern -> Arrow
   extern u8 const pattern1[];
   //Hex value to create The pattern -> Man
   extern u8 const pattern2[];
   //Hex value to create The pattern -> Man With Arrow
   extern u8 const pattern3[];
   //Hex value to create The pattern -> Half Man 1
   extern u8 const pattern4[];
   //Hex value to create The pattern -> Half Man 2
   extern u8 const pattern5[];
   
   //Arabic Sentens Pattern
   //Hex value to create The pattern -> ?
   extern u8 const pattern6[];
   //Hex value to create The pattern -> ?
   extern u8 const pattern7[];
   //Hex value to create The pattern -> ?
   extern u8 const pattern8[];
   //Hex value to create The pattern -> ?
   extern u8 const pattern9[];
   //Hex value to create The pattern -> ?
   extern u8 const pattern10[];
   //Hex value to create The pattern -> ?
   extern u8 const pattern11[];
   //Hex value to create The pattern -> ?
   extern u8 const pattern12[];
   //Hex value to create The pattern -> ?
   extern u8 const pattern13[];

void Dead_Man_ConfigPattern(void);

void ArabicWord_ConfigPattern(void);

void Write_ArabicWord_Pattern(void);




#endif /* DREAM_MAN_H_ */