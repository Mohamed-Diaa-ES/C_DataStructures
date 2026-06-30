#include "LCD_Config.h"
#include "LCD_Private.h"
#include <stdint.h>
#include <util/delay.h>
#include "LCD_Interface.h"

static uint8_t LinesOfDisplay[NumOfRows] = Rows_Addresses_Array;

void hLCD_Init(void)
{
    mDIO_SetDirectionForPin(LCD_Group, Data_Pin4, Output);
    mDIO_SetDirectionForPin(LCD_Group, Data_Pin5, Output);
    mDIO_SetDirectionForPin(LCD_Group, Data_Pin6, Output);
    mDIO_SetDirectionForPin(LCD_Group, Data_Pin7, Output);
    mDIO_SetDirectionForPin(LCD_Group, RS_Pin, Output);
    mDIO_SetDirectionForPin(LCD_Group, EN_Pin, Output);

    _delay_ms(POWER_ON_WAIT);
    hLCD_SendCommand(Function_Set_Command_1);
    hLCD_SendCommand(Function_Set_Command_2);
    _delay_us(FUNCTION_SET_WAIT);
    hLCD_SendCommand(Display_Control_1);
    hLCD_SendCommand(Display_Control_2);
    _delay_us(DISPLAY_CONTROL_WAIT);
    hLCD_SendCommand(Display_Clear_1);
    hLCD_SendCommand(Display_Clear_2);
    _delay_ms(DISPLAY_CLEAR_WAIT);
    hLCD_SendCommand(Entry_Mode_Set_1);
    hLCD_SendCommand(Entry_Mode_Set_2);
    _delay_ms(MILLI_Second);
}

void hLCD_SendCommand(uint8_t Command)
{
    mDIO_WritePin(LCD_Group, RS_Pin, Low);

    LCD_Port_Output &= LowerBitMaskDeletion;
    LCD_Port_Output |= Upper_Nibble_Masking(Command);

    mDIO_WritePin(LCD_Group, EN_Pin, High);
    _delay_ms(Enable_Pulse_Wait);
    mDIO_WritePin(LCD_Group, EN_Pin, Low);

    mDIO_WritePin(LCD_Group, RS_Pin, Low);

    LCD_Port_Output &= LowerBitMaskDeletion;
    LCD_Port_Output |= Lower_Nibble_Masking(Command);

    mDIO_WritePin(LCD_Group, EN_Pin, High);
    _delay_ms(Enable_Pulse_Wait);
    mDIO_WritePin(LCD_Group, EN_Pin, Low);
}

void hLCD_Clear(uint8_t ClearLine)
{
    hLCD_SetCursor(ClearLine, 0); // Start of the line
    hLCD_WriteString(Clear_Line_String);
}

void hLCD_SetCursor(uint8_t Line, uint8_t Digits)
{
    uint8_t DDRAM_Address = 0;
    switch (Line)
    {
    case 1:
        DDRAM_Address = Row_1_Start + Digits;
        break;
    case 2:
        DDRAM_Address = Row_2_Start + Digits;
        break;
    default:
        /* Default to Line 1 if an invalid line is passed */
        DDRAM_Address = Row_1_Start + Digits;
        break;
    }
    hLCD_SendCommand(DDRAM_Address);
    _delay_ms(1);
}

void hLCD_WriteChar(char Character)
{
    mDIO_WritePin(LCD_Group, RS_Pin, High);

    LCD_Port_Output &= LowerBitMaskDeletion;
    LCD_Port_Output |= Upper_Nibble_Masking(Character);

    mDIO_WritePin(LCD_Group, EN_Pin, High);
    _delay_ms(Enable_Pulse_Wait);
    mDIO_WritePin(LCD_Group, EN_Pin, Low);

    mDIO_WritePin(LCD_Group, RS_Pin, High);

    LCD_Port_Output &= LowerBitMaskDeletion;
    LCD_Port_Output |= Lower_Nibble_Masking(Character);

    mDIO_WritePin(LCD_Group, EN_Pin, High);
    _delay_ms(Enable_Pulse_Wait);
    mDIO_WritePin(LCD_Group, EN_Pin, Low);
}

void hLCD_WriteString(const char *str)
{
    if (str != Null)
    {
        uint8_t index = 0;
        while (str[index] != NullChar)
        {
            hLCD_WriteChar(str[index]);
            index++;
        }
    }
}

void hLCD_WriteNumber(int32_t Number)
{
    if (Number == 0)
    {
        hLCD_WriteChar('0');
        return;
    }
    else if (Number < 0)
    {
        Number *= -1;
        hLCD_WriteChar('-');
    }

    uint8_t NumArr[10];
    uint8_t index = 0;
    while (index < 10)
    {
        NumArr[index] = Number % 10;
        NumArr[index] += '0';
        Number /= 10;
        index++;
        if (Number == 0)
        {
            break;
        }
    }

    while (index--)
    {
        hLCD_WriteChar(NumArr[index]);
        _delay_ms(2); // Reduced from 20ms to speed up display refresh
    }
}


void hLCD_DisplayTask(uint8_t TaskNum, uint8_t priority, const char* taskName)
{

    hLCD_Clear(1);
    hLCD_Clear(2);

    hLCD_SetCursor(1, 0);
    hLCD_WriteString("ID:");
    hLCD_WriteNumber(TaskNum);
    hLCD_WriteString(" Prio:");
    hLCD_WriteNumber(priority);

    hLCD_SetCursor(2, 0);
    if (taskName != Null) 
    {
        hLCD_WriteString(taskName);
    }else
    {
         hLCD_WriteString("SIKE!!");
    }
}