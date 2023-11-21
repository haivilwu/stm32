#include "stm32f10x.h"                  // Device header


void PWM_Init(void)
{
    //RCC_Init GPIO
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //AF 复用推挽输出模式
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructure);
    
    //舵机要求50ms ：PWM频率50Hz,再计算ARR PSC CCR
    TIM_InternalClockConfig(TIM2);
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
    TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStruct.TIM_Period = 100-1;    //arr
    TIM_TimeBaseInitStruct.TIM_Prescaler = 720-1;  //PSC
    TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStruct);
    
    TIM_OCInitTypeDef TIM_OCInitStructure;
    TIM_OCStructInit(&TIM_OCInitStructure);//strcut init origin value
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = 0;   //CCR
    TIM_OC2Init(TIM2,&TIM_OCInitStructure);
    
    //TIM_Init
    TIM_Cmd(TIM2,ENABLE);
}

void PWM_SetCompare2(uint16_t Compare)
{
    TIM_SetCompare2(TIM2,Compare);
}
