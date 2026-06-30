#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_

/**
 * @addtogroup Hal
 * @{
 * @addtogroup LCD_Display
 * @{
 */

#include <stdint.h>
#include "LCD_Config.h"
#include "LCD_Private.h"
#include "../../Common/Macros.h"
#include "../../Mcal/DIO/DIO_Interface.h"


void hLCD_Init(void);

void hLCD_Clear(uint8_t ClearLine);

void hLCD_SetCursor(uint8_t Line, uint8_t Digits);

void hLCD_WriteChar(char Character);

void hLCD_WriteString(const char *str);

void hLCD_WriteNumber(int32_t Number);

void hLCD_SendCommand(uint8_t Command);

void hLCD_DisplayTask(uint8_t TaskNum, uint8_t priority, const char* taskName);// the new one to display the tasks 

/**
 * @}
 * @}
 */

#endif