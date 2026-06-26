
#include <stdint.h>
#include "../../Common/Macros.h"
#include "DIO_Private.h"
#include "DIO_Config.h"
#include "../ATmega128_Registers.h"

void mDIO_SetDirectionForPin(uint8_t GroupName, uint8_t PinNumber, uint8_t DirectionState);
void mDIO_SetDirectionForPin(uint8_t GroupName, uint8_t PinNumber, uint8_t DirectionState);
void mDIO_WritePin(uint8_t GroupName, uint8_t PinNumber, uint8_t OutputValue);
void mDIO_TogglePin(uint8_t GroupName, uint8_t PinNumber);
void mDIO_ReadPin(uint8_t GroupName, uint8_t PinNumber, uint8_t *InputValue);
void mDIO_SetDirectionForGroup(uint8_t GroupName, uint8_t DirectionState);
void mDIO_WriteGroup(uint8_t GroupName, uint8_t OutputValue);
void mDIO_ReadGroup(uint8_t GroupName, uint8_t *InputValue);
