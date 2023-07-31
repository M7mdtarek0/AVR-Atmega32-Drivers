/*
 * Gpt.c
 *
 *  Created on: Feb 24, 2023
 *      Author: Mohamed Tarek
 */


#include "Types.h"
#include "Registers.h"
#include "Macros.h"
#include "Interrupts.h"
#include "Gpt.h"

void (*Gpt_Callback_TIM0_COMP ) (void) = NULL_PTR;
void (*Gpt_Callback_TIM0_OVF  ) (void) = NULL_PTR;
void (*Gpt_Callback_TIM1A_COMP) (void) = NULL_PTR;
void (*Gpt_Callback_TIM1B_COMP) (void) = NULL_PTR;
void (*Gpt_Callback_TIM1_OVF  ) (void) = NULL_PTR;
void (*Gpt_Callback_TIM1_CAPT ) (void) = NULL_PTR;
void (*Gpt_Callback_TIM2_OVF  ) (void) = NULL_PTR;
void (*Gpt_Callback_TIM2_COMP ) (void) = NULL_PTR;

ISR(VECTOR_TIM0_COMP) {
    if (NULL_PTR != Gpt_Callback_TIM0_COMP) {
        Gpt_Callback_TIM0_COMP();
    }
}

ISR(VECTOR_TIM0_OVF) {
    if (NULL_PTR != Gpt_Callback_TIM0_OVF) {
        Gpt_Callback_TIM0_OVF();
    }
}



ISR(VECTOR_TIM1_COMPA) {
    if (NULL_PTR != Gpt_Callback_TIM1A_COMP) {
        Gpt_Callback_TIM1A_COMP();
    }
}

ISR(VECTOR_TIM1_COMPB) {
    if (NULL_PTR != Gpt_Callback_TIM1B_COMP) {
        Gpt_Callback_TIM1B_COMP();
    }
}

ISR(VECTOR_TIM1_OVF) {
    if (NULL_PTR != Gpt_Callback_TIM1_OVF) {
        Gpt_Callback_TIM1_OVF();
    }
}

ISR(VECTOR_TIM2_COMP) {
    if (NULL_PTR != Gpt_Callback_TIM2_COMP) {
        Gpt_Callback_TIM2_COMP();
    }
}

ISR(VECTOR_TIM2_OVF) {
    if (NULL_PTR != Gpt_Callback_TIM2_OVF) {
        Gpt_Callback_TIM2_OVF();
    }
}


void Gpt_Init(Gpt_ChannelType channel, const Gpt_ConfigType* config) {
    switch (channel)
    {
    case GPT_CHANNEL_TIM0:
    {
        switch (config->mode)
        {
        case GPT_MODE_NORMAL:
            CLR_BIT(TCCR0, 3);
            CLR_BIT(TCCR0, 6);
            break;
        case GPT_MODE_CTC:
        	SET_BIT(TCCR0, 3);
        	CLR_BIT(TCCR0, 6);
        default:
            break;
        }
        switch (config->compareMode)
        {
        case GPT_COMP_OUT_MODE_DISCONNECTED:
            CLR_BIT(TCCR0, 4);
            CLR_BIT(TCCR0, 5);
            break;
        case GPT_COMP_OUT_MODE_TOGGLE:
            SET_BIT(TCCR0, 4);
            CLR_BIT(TCCR0, 5);
            break;
        case GPT_COMP_OUT_MODE_CLEAR:
            CLR_BIT(TCCR0, 4);
            SET_BIT(TCCR0, 5);
            break;
        case GPT_COMP_OUT_MODE_SET:
            SET_BIT(TCCR0, 4);
            SET_BIT(TCCR0, 5);
            break;
        default:
            break;
        }
        break;
    }
    case GPT_CHANNEL_TIM1:
    {
        switch (config->mode)
        {
        case GPT_MODE_NORMAL:
            CLR_BIT(TCCR1A, 0);
            CLR_BIT(TCCR1A, 1);
            CLR_BIT(TCCR1B, 3);
            CLR_BIT(TCCR1B, 4);
            break;
        case GPT_MODE_CTC:
            CLR_BIT(TCCR1A, 0);
            CLR_BIT(TCCR1A, 1);
            SET_BIT(TCCR1B, 3);
            CLR_BIT(TCCR1B, 4);
        default:
            break;
        }
        switch (config->compareMode)
        {
        case GPT_COMP_OUT_MODE_DISCONNECTED:
            CLR_BIT(TCCR1A, 4);
            CLR_BIT(TCCR1A, 5);
            CLR_BIT(TCCR1A, 6);
            CLR_BIT(TCCR1A, 7);
            break;
        case GPT_COMP_OUT_MODE_TOGGLE:
            SET_BIT(TCCR1A, 4);
            CLR_BIT(TCCR1A, 5);
            SET_BIT(TCCR1A, 6);
            CLR_BIT(TCCR1A, 7);
            break;
        case GPT_COMP_OUT_MODE_CLEAR:
            CLR_BIT(TCCR1A, 4);
            SET_BIT(TCCR1A, 5);
            CLR_BIT(TCCR1A, 6);
            SET_BIT(TCCR1A, 7);
            break;
        case GPT_COMP_OUT_MODE_SET:
            SET_BIT(TCCR1A, 4);
            SET_BIT(TCCR1A, 5);
            SET_BIT(TCCR1A, 6);
            SET_BIT(TCCR1A, 7);
            break;
        default:
            break;
        }
        break;
    }
    case GPT_CHANNEL_TIM2:
    {
        switch (config->mode)
        {
        case GPT_MODE_NORMAL:
            CLR_BIT(TCCR2, 3);
            CLR_BIT(TCCR2, 6);
            break;
        case GPT_MODE_CTC:
            SET_BIT(TCCR2, 3);
            CLR_BIT(TCCR2, 6);
        default:
            break;
        }
        switch (config->compareMode)
        {
        case GPT_COMP_OUT_MODE_DISCONNECTED:
            CLR_BIT(TCCR2, 4);
            CLR_BIT(TCCR2, 5);
            break;
        case GPT_COMP_OUT_MODE_TOGGLE:
            SET_BIT(TCCR2, 4);
            CLR_BIT(TCCR2, 5);
            break;
        case GPT_COMP_OUT_MODE_CLEAR:
            CLR_BIT(TCCR2, 4);
            SET_BIT(TCCR2, 5);
            break;
        case GPT_COMP_OUT_MODE_SET:
            SET_BIT(TCCR2, 4);
            SET_BIT(TCCR2, 5);
            break;
        default:
            break;
        }
        break;
    }

    default:
        break;
    }
}

void Gpt_Start(Gpt_ChannelType channel, Gpt_PrescalerType prescaler) {
     switch (channel)
    {
    case GPT_CHANNEL_TIM0:
    {
        switch (prescaler)
        {
        case GPT_PRESCALER_1:
            SET_BIT(TCCR0,0);
            CLR_BIT(TCCR0,1);
            CLR_BIT(TCCR0,2);
            break;
        case GPT_PRESCALER_8:
            CLR_BIT(TCCR0,0);
            SET_BIT(TCCR0,1);
            CLR_BIT(TCCR0,2);
            break;
        case GPT_PRESCALER_64:
            SET_BIT(TCCR0,0);
            SET_BIT(TCCR0,1);
            CLR_BIT(TCCR0,2);
            break;
        case GPT_PRESCALER_256:
            CLR_BIT(TCCR0,0);
            CLR_BIT(TCCR0,1);
            SET_BIT(TCCR0,2);
            break;
        case GPT_PRESCALER_1024:
            SET_BIT(TCCR0,0);
            CLR_BIT(TCCR0,1);
            SET_BIT(TCCR0,2);
            break;
        case GPT_PRESCALER_EXT_FALLING:
            CLR_BIT(TCCR0,0);
            SET_BIT(TCCR0,1);
            SET_BIT(TCCR0,2);
            break;
        case GPT_PRESCALER_EXT_RISING:
            SET_BIT(TCCR0,0);
            SET_BIT(TCCR0,1);
            SET_BIT(TCCR0,2);
            break;
        default:
            break;
        }
        TCNT0 = 0;
        break;
    }
    case GPT_CHANNEL_TIM1:
    {
        switch (prescaler)
        {
        case GPT_PRESCALER_1:
            SET_BIT(TCCR1B,0);
            CLR_BIT(TCCR1B,1);
            CLR_BIT(TCCR1B,2);
            break;
        case GPT_PRESCALER_8:
            CLR_BIT(TCCR1B,0);
            SET_BIT(TCCR1B,1);
            CLR_BIT(TCCR1B,2);
            break;
        case GPT_PRESCALER_64:
            SET_BIT(TCCR1B,0);
            SET_BIT(TCCR1B,1);
            CLR_BIT(TCCR1B,2);
            break;
        case GPT_PRESCALER_256:
            CLR_BIT(TCCR1B,0);
            CLR_BIT(TCCR1B,1);
            SET_BIT(TCCR1B,2);
            break;
        case GPT_PRESCALER_1024:
            SET_BIT(TCCR1B,0);
            CLR_BIT(TCCR1B,1);
            SET_BIT(TCCR1B,2);
            break;
        case GPT_PRESCALER_EXT_FALLING:
            CLR_BIT(TCCR1B,0);
            SET_BIT(TCCR1B,1);
            SET_BIT(TCCR1B,2);
            break;
        case GPT_PRESCALER_EXT_RISING:
            SET_BIT(TCCR1B,0);
            SET_BIT(TCCR1B,1);
            SET_BIT(TCCR1B,2);
            break;
        default:
            break;
        }
        TCCR1B = 0;
        break;
    }
    case GPT_CHANNEL_TIM2:
    {
        switch (prescaler)
        {
        case GPT_PRESCALER_1:
            SET_BIT(TCCR2,0);
            CLR_BIT(TCCR2,1);
            CLR_BIT(TCCR2,2);
            break;
        case GPT_PRESCALER_8:
            CLR_BIT(TCCR2,0);
            SET_BIT(TCCR2,1);
            CLR_BIT(TCCR2,2);
            break;
        case GPT_PRESCALER_32:
            SET_BIT(TCCR2,0);
            SET_BIT(TCCR2,1);
            CLR_BIT(TCCR2,2);
            break;
        case GPT_PRESCALER_64:
            CLR_BIT(TCCR2,0);
            CLR_BIT(TCCR2,1);
            SET_BIT(TCCR2,2);
            break;
        case GPT_PRESCALER_128:
            SET_BIT(TCCR2,0);
            CLR_BIT(TCCR2,1);
            SET_BIT(TCCR2,2);
            break;
        case GPT_PRESCALER_256:
            CLR_BIT(TCCR2,0);
            SET_BIT(TCCR2,1);
            SET_BIT(TCCR2,2);
            break;
        case GPT_PRESCALER_1024:
            SET_BIT(TCCR2,0);
            SET_BIT(TCCR2,1);
            SET_BIT(TCCR2,2);
            break;
        default:
            break;
        }
        TCCR2 = 0;
        break;
    }
    default:
        break;
    }
}

void Gpt_Stop(Gpt_ChannelType channel) {
    switch (channel)
    {
    case GPT_CHANNEL_TIM0:
        CLR_BIT(TCCR0, 0);
        CLR_BIT(TCCR0, 1);
        CLR_BIT(TCCR0, 2);
        break;
    case GPT_CHANNEL_TIM1:
        CLR_BIT(TCCR1A, 0);
        CLR_BIT(TCCR1A, 1);
        CLR_BIT(TCCR1B, 3);
        CLR_BIT(TCCR1B, 4);
        break;
    case GPT_CHANNEL_TIM2:
        CLR_BIT(TCCR2, 0);
        CLR_BIT(TCCR2, 1);
        CLR_BIT(TCCR2, 2);
        break;
    default:
        break;
    }
}

void Gpt_Reset (Gpt_ChannelType channel) {
    switch (channel)
    {
    case GPT_CHANNEL_TIM0:
        TCNT0 = 0;
        break;
    case GPT_CHANNEL_TIM1:
    	TCNT1 = 0;
        break;
    case GPT_CHANNEL_TIM2:
        TCNT2 = 0;
        break;
    default:
        break;
    }
}

void Gpt_SetCounterValue (Gpt_ChannelType channel, u16 value) {
    switch (channel)
    {
    case GPT_CHANNEL_TIM0:
        TCNT0 = value;
        break;
    case GPT_CHANNEL_TIM1:
    	TCNT1 = value;
        break;
    case GPT_CHANNEL_TIM2:
        TCNT2 = value;
        break;
    default:
        break;
    }
}

void Gpt_SetCompareValue (Gpt_CompareRegType reg, u16 value) {
    switch (reg)
    {
    case GPT_COMP_REG_TIM0:
        OCR0 = value;
        break;
    case GPT_COMP_REG_TIM1A:
    	OCR1A = value;
        break;
    case GPT_COMP_REG_TIM1B:
        OCR1B = value;
        break;
    case GPT_COMP_REG_TIM2:
        OCR2 = value;
        break;
    default:
        break;
    }
}

void Gpt_EnableNotification(Gpt_InterruptSourceType source) {
    switch (source)
    {
    case GPT_INT_SOURCE_TIM0_COMP:
        SET_BIT(TIMSK, 1);
        break;
    case GPT_INT_SOURCE_TIM0_OVF:
        SET_BIT(TIMSK, 0);
        break;
    case GPT_INT_SOURCE_TIM1_CAPT:
        SET_BIT(TIMSK, 5);
        break;
    case GPT_INT_SOURCE_TIM1_OVF:
        SET_BIT(TIMSK, 2);
        break;
    case GPT_INT_SOURCE_TIM1_COMPA:
        SET_BIT(TIMSK, 4);
        break;
    case GPT_INT_SOURCE_TIM1_COMPB:
        SET_BIT(TIMSK, 3);
        break;
    case GPT_INT_SOURCE_TIM2_COMP:
        SET_BIT(TIMSK, 7);
        break;
    case GPT_INT_SOURCE_TIM2_OVF:
        SET_BIT(TIMSK, 6);
        break;
    default:
        break;
    }
}

void Gpt_DisableNotification(Gpt_InterruptSourceType source) {
    switch (source)
    {
    case GPT_INT_SOURCE_TIM0_COMP:
        CLR_BIT(TIMSK, 1);
        break;
    case GPT_INT_SOURCE_TIM0_OVF:
        CLR_BIT(TIMSK, 0);
        break;
    case GPT_INT_SOURCE_TIM1_CAPT:
        CLR_BIT(TIMSK, 5);
        break;
    case GPT_INT_SOURCE_TIM1_OVF:
        CLR_BIT(TIMSK, 2);
        break;
    case GPT_INT_SOURCE_TIM1_COMPA:
        CLR_BIT(TIMSK, 4);
        break;
    case GPT_INT_SOURCE_TIM1_COMPB:
        CLR_BIT(TIMSK, 3);
        break;
    case GPT_INT_SOURCE_TIM2_COMP:
        CLR_BIT(TIMSK, 7);
        break;
    case GPT_INT_SOURCE_TIM2_OVF:
        CLR_BIT(TIMSK, 6);
        break;
    default:
        break;
    }
}

void Gpt_SetCallback(Gpt_InterruptSourceType source, void (*funcPtr) (void)) {
    switch (source)
    {
    case GPT_INT_SOURCE_TIM0_COMP:
        Gpt_Callback_TIM0_COMP = funcPtr;
        break;
    case GPT_INT_SOURCE_TIM0_OVF:
        Gpt_Callback_TIM0_OVF = funcPtr;
        break;
    case GPT_INT_SOURCE_TIM1_COMPA:
        Gpt_Callback_TIM1A_COMP = funcPtr;
        break;
    case GPT_INT_SOURCE_TIM1_COMPB:
        Gpt_Callback_TIM1B_COMP = funcPtr;
        break;
    case GPT_INT_SOURCE_TIM1_OVF:
        Gpt_Callback_TIM1_OVF = funcPtr;
        break;
    case GPT_INT_SOURCE_TIM1_CAPT:
        Gpt_Callback_TIM1_CAPT = funcPtr;
        break;
    case GPT_INT_SOURCE_TIM2_COMP:
        Gpt_Callback_TIM2_COMP = funcPtr;
        break;
    case GPT_INT_SOURCE_TIM2_OVF:
        Gpt_Callback_TIM1_OVF = funcPtr;
        break;
    default:
        break;
    }
}

u16  Gpt_GetElapsedTime(Gpt_ChannelType channel) {
    u16 ret_value = 0;
    switch (channel)
    {
    case GPT_CHANNEL_TIM0:
        ret_value = TCNT0;
        break;
    case GPT_CHANNEL_TIM1:
        ret_value = TCNT1;
        break;
    case GPT_CHANNEL_TIM2:
        ret_value = TCNT2;
        break;

    default:
        break;
    }
    return ret_value;
}
