#include "main.h"

void Light_Leds(float distance)
	{
	if(distance <= 95)
		{
	  GPIO_PORTF_DATA_R = 0x02;
		}
	else if(distance <= 97.5)
		{
			GPIO_PORTF_DATA_R = 0x0A;
		}
	else
		{
			GPIO_PORTF_DATA_R = 0x08;
		}
	}