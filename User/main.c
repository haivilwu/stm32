#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "LED.h"
#include "Key.h"

uint8_t KeyNum;

int main(void)
{
	LED_Init();
	Key_Init();
	while(1)
	{
//	LED1_ON();
//	Delay_ms(500);
//	LED1_Off();
//	Delay_ms(500);
//	LED2_ON();
//	Delay_ms(500);
//	LED2_Off();
	KeyNum=Key_GetNum();
		if(KeyNum==1)
		{
		//LED1_ON();
		LED1_TurnOnOff();
		}
		if(KeyNum==2)
		{
		LED2_TurnOnOff();
		}
	}
}

