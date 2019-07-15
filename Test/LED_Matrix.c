#include "LED_Matrix.h"
#define F_CPU 1000000UL

void myDelay (unsigned long int time)
{
	volatile int j;
	for(j=13333;j>0;j--)
	{
		time--;
	}
}

void main(void)
{
	unsigned char i;
	myDDRC = 0xff;
	myDDRD = 0xff;


			while(1)
			{


			}
}
