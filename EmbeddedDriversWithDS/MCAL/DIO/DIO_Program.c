#include <stdint.h>
#include "../ATmega128_Registers.h"
#include "../../Common/Macros.h"

#include "DIO_Private.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"

void mDIO_SetDirectionForPin(uint8_t GroupName,uint8_t PinNumber,uint8_t DirectionState)
{
    if(PinNumber>=0 && PinNumber<=7)
    {   
        if(DirectionState==Input)
        {
            switch (GroupName)
            {
            case GroupA:
                ClearBit(DDRA_Reg,PinNumber);
                break;
            case GroupB:
                ClearBit(DDRB_Reg,PinNumber);
                break;
            case GroupC:
                ClearBit(DDRC_Reg,PinNumber);
                break;
            case GroupD:
                ClearBit(DDRD_Reg,PinNumber);
                break;
            case GroupE:
                ClearBit(DDRE_Reg,PinNumber);
                break;
            case GroupF:
                ClearBit(DDRF_Reg,PinNumber);
                break;
            case GroupG:
                ClearBit(DDRG_Reg,PinNumber);
                break;
            
            default:

                break;
            }
            
        }
        else if(DirectionState==Output)
        {
            switch (GroupName)
            {
            case GroupA:
                SetBit(DDRA_Reg,PinNumber);
                break;
            case GroupB:
                SetBit(DDRB_Reg,PinNumber);
                break;
            case GroupC:
                SetBit(DDRC_Reg,PinNumber);
                break;
            case GroupD:
                SetBit(DDRD_Reg,PinNumber);
                break;
            case GroupE:
                SetBit(DDRE_Reg,PinNumber);
                break;
            case GroupF:
                SetBit(DDRF_Reg,PinNumber);
                break;
            case GroupG:
                SetBit(DDRG_Reg,PinNumber);
                break;
            
            default:
              
                break;
            }        
        }
        else
        {

        }

    }
    else 
    {
    }

}

void mDIO_SetDirectionForGroup(uint8_t GroupName,uint8_t DirectionState)
{
    if(DirectionState>=0X00 && DirectionState<=0XFF)
    {
        switch (GroupName)
        {
        case GroupA:
            DDRA_Reg=DirectionState;
            break;
        case GroupB:
            DDRB_Reg=DirectionState;
            break;
        case GroupC:
            DDRC_Reg=DirectionState;
            break;
        case GroupD:
            DDRD_Reg=DirectionState;
            break;
        case GroupE:
            DDRE_Reg=DirectionState;
            break;
        case GroupF:
            DDRF_Reg=DirectionState;
            break;
        case GroupG:
            DDRG_Reg=DirectionState;
            break;
        
        default:
   
            break;
        }
    }    
}

void mDIO_WritePin(uint8_t GroupName,uint8_t PinNumber,uint8_t OutputValue)
{
    if (PinNumber>=0 && PinNumber<=7)
    {
        if (OutputValue==Low)
        {
            switch (GroupName)
            {
            case GroupA:
                ClearBit(PORTA_Reg,PinNumber);
                break;
            case GroupB:
                ClearBit(PORTB_Reg,PinNumber);
                break;
            case GroupC:
                ClearBit(PORTC_Reg,PinNumber);
                break;
            case GroupD:
                ClearBit(PORTD_Reg,PinNumber);
                break;
            case GroupE:
                ClearBit(PORTE_Reg,PinNumber);
                break;
            case GroupF:
                ClearBit(PORTF_Reg,PinNumber);
                break;
            case GroupG:
                ClearBit(PORTG_Reg,PinNumber);
                break;
            default:
            
                break;
            }
        }
        else if (OutputValue==High)
        {
            switch (GroupName)
            {
            case GroupA:
                SetBit(PORTA_Reg,PinNumber);
                break;
            case GroupB:
                SetBit(PORTB_Reg,PinNumber);
                break;
            case GroupC:
                SetBit(PORTC_Reg,PinNumber);
                break;
            case GroupD:
                SetBit(PORTD_Reg,PinNumber);
                break;
            case GroupE:
                SetBit(PORTE_Reg,PinNumber);
                break;
            case GroupF:
                SetBit(PORTF_Reg,PinNumber);
                break;
            case GroupG:
                SetBit(PORTG_Reg,PinNumber);
                break;
            default:
            
                break;
            }        
        }
        else
        {
        }
        
    }
    else
    {

    }
}

void mDIO_WriteGroup(uint8_t GroupName,uint8_t OutputValue)
{
    if(OutputValue>=0x00 && OutputValue<=0XFF)
    {
        switch (GroupName)
        {
        case GroupA:
            PORTA_Reg=OutputValue;
            break;
        case GroupB:
            PORTB_Reg=OutputValue;
            break;
        case GroupC:
            PORTC_Reg=OutputValue;
            break;
        case GroupD:
            PORTD_Reg=OutputValue;
            break;
        case GroupE:
            PORTE_Reg=OutputValue;
            break;
        case GroupF:
            PORTF_Reg=OutputValue;
            break;
        case GroupG:
            PORTG_Reg=OutputValue;
            break;

        
        default:
        
            break;
        }
    }
    else
    {
   

    }
}

void mDIO_TogglePin(uint8_t GroupName,uint8_t PinNumber)
{
    if(PinNumber>=0 && PinNumber<=7)
    {
        switch (GroupName)
        {
        case GroupA:
            ToggleBit(PORTA_Reg,PinNumber);
            break;
        case GroupB:
            ToggleBit(PORTB_Reg,PinNumber);
            break;
        case GroupC:
            ToggleBit(PORTC_Reg,PinNumber);
            break;
        case GroupD:
            ToggleBit(PORTD_Reg,PinNumber);
            break;
        case GroupE:
            ToggleBit(PORTE_Reg,PinNumber);
            break;
        case GroupF:
            ToggleBit(PORTF_Reg,PinNumber);
            break;
        case GroupG:
            ToggleBit(PORTG_Reg,PinNumber);
            break;
        
        default:
        
            break;
        }
    }
    else
    {
   
    }
    
}

void mDIO_ReadPin(uint8_t GroupName,uint8_t PinNumber,uint8_t * InputValue)
{
    if(InputValue!=Null)
    {
        if(PinNumber>=0 && PinNumber<=7)
        {
            switch (GroupName)
            {
            case GroupA:
                *InputValue=GetBit(PINA_Reg,PinNumber);
                break;
            case GroupB:
                *InputValue=GetBit(PINB_Reg,PinNumber);
                break;
            case GroupC:
                *InputValue=GetBit(PINC_Reg,PinNumber);
                break;
            case GroupD:
                *InputValue=GetBit(PIND_Reg,PinNumber);
                break;
            case GroupE:
                *InputValue=GetBit(PINE_Reg,PinNumber);
                break;
            case GroupF:
                *InputValue=GetBit(PINF_Reg,PinNumber);
                break;
            case GroupG:
                *InputValue=GetBit(PING_Reg,PinNumber);
                break;
            
            default:
           
                break;
            }
        }
    }
    else
    {
    
    }
}

void mDIO_ReadGroup(uint8_t GroupName,uint8_t *InputValue)
{
    if(InputValue!=Null)
    {
        switch (GroupName)
        {
        case GroupA:
            *InputValue=PINA_Reg;
            break;
        case GroupB:
            *InputValue=PINB_Reg;
            break;
        case GroupC:
            *InputValue=PINC_Reg;
            break;
        case GroupD:
            *InputValue=PIND_Reg;
            break;
        case GroupE:
            *InputValue=PINE_Reg;
            break;
        case GroupF:
            *InputValue=PINF_Reg;
            break;
        case GroupG:
            *InputValue=PING_Reg;
            break;
        
        default:
            break;
        }
    }
    else
    {

    }
}