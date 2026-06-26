
#ifndef _LCD_CONFIG_H_
#define _LCD_CONFIG_H_
#include "LCD_Private.h"
#include "../../Mcal/DIO/DIO_Interface.h"

/** * @def Clear_Line_String 
 * @brief String used to clear a line on the LCD.
 */
#define  Clear_Line_String "                " // 16 spaces for 16x2 display

/** * @def LCD_Group 
 * @brief Defines the group used for LCD control.
 */
#define LCD_Group GroupA // Changed to GroupA to match PA2-PA7

/** * @def Upper_Nibble_Masking 
 * @brief Extracts the upper nibble (4 bits) from a register (aligned to pins 4-7).
 */
#define Upper_Nibble_Masking(Reg) ((Reg)&0xF0)

/** * @def Lower_Nibble_Masking 
 * @brief Extracts the lower nibble (4 bits) from a register (shifted to pins 4-7).
 */
#define Lower_Nibble_Masking(Reg) ((Reg<<4)&0xF0)

/** * @def NumOfRows 
 * @brief Total number of display rows.
 */
#define NumOfRows 2 // Adjusted for 16x2 LCD

/** * @def Rows_Addresses_Array 
 * @brief Array of starting addresses for each LCD row.
 */
#define Rows_Addresses_Array {Row_1_Start,Row_2_Start} // Adjusted for 2 rows

/** * @def Array_Num_Of_Digits 
 * @brief Maximum number of digits for a 32-bit unsigned integer.
 */
#define Array_Num_Of_Digits 10 

/** * @def LowerBitMaskDeletion
 * @brief Mask to clear the upper 4 bits (Pins 4-7) where data is connected.
 */
#define LowerBitMaskDeletion 0x0F // Clears upper nibble while preserving lower nibble

#endif