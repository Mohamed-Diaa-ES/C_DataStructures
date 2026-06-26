#include <stdint.h>
#include <util/delay.h>

#include "Mcal/DIO/DIO_Interface.h"
#include "HAL/LCD_128/LCD_Interface.h"

int main(void)
{
    
    hLCD_Init();

  
    hLCD_SetCursor(1, 0); 
    hLCD_WriteString("Welcome to the world Boy!");
    hLCD_SetCursor(2, 0); 
    hLCD_WriteString("pls Work Sa3ed :-)");

   
    
    while(1);
   

}