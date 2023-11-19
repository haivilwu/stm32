#include "stm32f10x.h"                  // Device header

extern uint16_t Num;

void Timer_Init(void)
{   
    //RCC_Init GPIO
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructure);
    
    //TIM_ETRClockMode2Config 外部时钟 
    TIM_ETRClockMode2Config(TIM2,TIM_ExtTRGPSC_OFF,TIM_ExtTRGPolarity_NonInverted,0x0F);//最后一个滤波器参数加到最大0x0F，可滤除时钟信号抖动
    
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
    TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStruct.TIM_Period = 10-1;    //arr
    TIM_TimeBaseInitStruct.TIM_Prescaler = 1-1;  //PSC
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
    Nvic_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&Nvic_InitStructure);
    
    //TIM_Init
    TIM_Cmd(TIM2,ENABLE);
    
}


uint16_t Timer_GetCounter(void)
{
    return TIM_GetCounter(TIM2);
}

void TIM2_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM2,TIM_IT_Update)== SET)
    {
    Num++;
    TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
    
    }
}
