#include "stm32f10x.h"                  // Device header


uint16_t Countersensor_Count;

void CounterSensor_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStructure;//声明GPIO结构体
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB,&GPIO_InitStructure);
    
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);
    EXTI_InitTypeDef  EXTI_Init_Structure;//声明EXTI_InitTypeDef
    EXTI_Init_Structure.EXTI_Line = EXTI_Line14;
    EXTI_Init_Structure.EXTI_LineCmd = ENABLE;
    EXTI_Init_Structure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_Init_Structure.EXTI_Trigger = EXTI_Trigger_Rising;
    
    EXTI_Init(&EXTI_Init_Structure);
    
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    NVIC_InitTypeDef NVIC_InitStructure;//声明NVIC_InitTypeDef
    NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&NVIC_InitStructure);
    
}

uint16_t CountSensor_Get(void)
{
    return Countersensor_Count;
}
void EXTI15_10_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_Line14) ==SET)
    {
    Countersensor_Count++;
    EXTI_ClearITPendingBit(EXTI_Line14);
    }
        
}
