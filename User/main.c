#include "stm32f10x.h"                  // Device header
#include "delay.h"
int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	while(1)
	{
		GPIO_Write(GPIOA,~0x0001);//低电平点亮（要按位取反，控制PA15~PA0）0000 0000 0000 0001
		Delay_ms(500);
		GPIO_Write(GPIOA,~0x0002);//低电平点亮（要按位取反，控制PA15~PA1）0000 0000 0000 0010
		Delay_ms(500);		
        GPIO_Write(GPIOA,~0x0004);//低电平点亮（要按位取反，控制PA15~PA2）0000 0000 0000 0100
		Delay_ms(500);
        GPIO_Write(GPIOA,~0x0008);//低电平点亮（要按位取反，控制PA15~PA3）0000 0000 0000 1000
		Delay_ms(500);
        GPIO_Write(GPIOA,~0x0010);//低电平点亮（要按位取反，控制PA15~PA4）0000 0000 0001 0000
		Delay_ms(500);
        GPIO_Write(GPIOA,~0x0020);//低电平点亮（要按位取反，控制PA15~PA5）0000 0000 0010 0000
		Delay_ms(500);
        GPIO_Write(GPIOA,~0x0040);//低电平点亮（要按位取反，控制PA15~PA6）0000 0000 0100 0000
		Delay_ms(500);
        GPIO_Write(GPIOA,~0x0080);//低电平点亮（要按位取反，控制PA15~PA7）0000 0000 1000 0000
		Delay_ms(500);
	}
}
