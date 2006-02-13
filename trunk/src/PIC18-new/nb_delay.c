//Non blocking delay functions

#include <system.h>
#include "input.h"
#include "nb_delay.h"

uint8 delayMs(uint8 ms)
{
	uint8 i;
	uint8 input;
	for (i = 0; i < ms; i ++)
	{
		delay_ms(1);
		input = getInput();
		if (input) 
			return input;
	}
	//if no input, return false
	return false;
}

uint8 delayMs(uint16 ms)
{
	uint16 i;
	uint8 input;
	for (i = 0; i < ms; i ++)
	{
		delay_ms(1);
		input = getInput();
		if (input) 
			return input;
	}
	//if no input, return false
	return false;
}
				
uint8 delayS(uint8 s)
{
	uint16 ms = (s * 1000);
	uint16 i;
	uint8 input;
	
	for (i = 0; i < ms; i ++)
	{
		delay_ms(1);
		input = getInput();
		if (input) 
			return input;
	}
	//if no input, return false
	return false;
}
			
