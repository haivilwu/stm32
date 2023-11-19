#include "stm32f10x.h"                  // Device header

extern uint16_t Num;

void Timer_Init(void)
{   
    //RCC_Init
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
    
    //TIM_TimeBaseInit
    TIM_InternalClockConfig(TIM2);
    
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
    TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStruct.TIM_Period = 10000-1;    //arr
    TIM_TimeBaseInitStruct.TIM_Prescaler = 7200-1;  //PSC
    TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStruct);
    TIM_ClearFlag(TIM2,TIM_FLAG_Update);//clear flag,防止从1开始
    TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
    
    //NVIC_Init
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    NVIC_InitTypeDef    Nvic_InitStructure;
    Nvic_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    Nvic_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    Nvic_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    Nvic_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_Init(&Nvic_InitStructure);
    
    //TIM_Init
    TIM_Cmd(TIM2,ENABLE);
    
}

void TIM2_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM2,TIM_IT_Update)== SET)
    {
    Num++;
    TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
    
    }
}
