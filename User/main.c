#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "LED.h"
#include "Key.h"
#include "Buzzer.h"
#include "LightSensor.h"
#include "OLED.h"


int main(void)
{
	OLED_Init();
	OLED_ShowChar(1,1,'A');
	OLED_ShowString(1,3,"HelloWord!");
	OLED_ShowNum(2,1,123456,6);
	OLED_ShowSignedNum(2,8,123,4);
	OLED_ShowHexNum(3,1,0x0A,2);
	OLED_ShowBinNum(4,1,0x01,16);
	while(1)
	{

	}
	
}

