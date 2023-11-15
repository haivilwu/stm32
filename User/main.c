#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "LED.h"
#include "Key.h"
#include "Buzzer.h"
#include "LightSensor.h"

//uint8_t KeyNum;

int main(void)
{
	Buzzer_Init();
	LightSensor_Init();
	while(1)
	{
	if (LightSensor_Get()==0)
	{
	Buzzer_ON();
	//Delay_ms(500);
	}
	else
	{
	Buzzer_Off();
	//Delay_ms(500);
	}
	}
	
}

