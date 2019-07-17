/*
 * Led_Matrix.c
 *
 * Created: 16/07/2019 12:31:14 ص
 *  Author: Lamyaa Zayed
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "Led_Matrix.h"

#define BCD_Numbers 10
#define  Column_Numbers 8

unsigned char Active_Pin[Column_Numbers]={0x7F,0xBF,0xDF,0xEF,0xF7,0xFB,0xFD,0xFE};

unsigned char Numbers_To_Display[BCD_Numbers][Column_Numbers]={
										 {0x0F,0x09,0x09,0x09,0x09,0x09,0x09,0x0F}
										,{0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01}
										,{0x0F,0x01,0x01,0x0F,0x08,0x08,0x08,0x0F}
										,{0x0F,0x01,0x01,0x0F,0x01,0x01,0x01,0x0F}
										,{0x09,0x09,0x09,0x0F,0x01,0x01,0x01,0x01}
										,{0x0F,0x08,0x08,0x0F,0x01,0x01,0x01,0x0F}
										,{0x0F,0x08,0x08,0x0F,0x09,0x09,0x09,0x0F}
										,{0x0F,0x01,0x01,0x01,0x01,0x01,0x01,0x01}
										,{0x0F,0x09,0x09,0x0F,0x09,0x09,0x09,0x0F}
										,{0x0F,0x09,0x09,0x0F,0x01,0x01,0x01,0x0F}
										};	

unsigned char Minutes,Hours,Seconds;
unsigned int Adjustment_Delay;

void Display_MINs(unsigned char Number)
{
	unsigned char Unit_Digit,Tenth_Digit,Matrix_Column;
	Unit_Digit=Number%10u;  
	Tenth_Digit=Number/10u;  
	for(Matrix_Column=0;Matrix_Column<Column_Numbers;Matrix_Column++)
	{
		PORTC=Active_Pin[Matrix_Column];
		PORTD=((Numbers_To_Display[Tenth_Digit][Matrix_Column])<<4)|(Numbers_To_Display[Unit_Digit][Matrix_Column]);
		_delay_us(150);
	}	
}

void Display_HRs(unsigned char Number)
{
	unsigned char Unit_Digit,Tenth_Digit,Matrix_Column;
	Unit_Digit=Number%10u;  
	Tenth_Digit=Number/10u;  
	for(Matrix_Column=0;Matrix_Column<Column_Numbers;Matrix_Column++)
	{
		PORTA=Active_Pin[Matrix_Column];
		PORTB=((Numbers_To_Display[Tenth_Digit][Matrix_Column])<<4)|(Numbers_To_Display[Unit_Digit][Matrix_Column]);
		_delay_us(150);
	}
}

void Clock_Run(void)
{
	for (Hours=0;Hours<24;Hours++)
	{
		for(Minutes=0;Minutes<60;Minutes++)
		{
			for (Seconds=0;Seconds<60;Seconds++)
			{
				for(Adjustment_Delay=0;Adjustment_Delay<416;Adjustment_Delay++)
				{
					Display_HRs(Hours);
					Display_MINs(Minutes);
				}
			}
			
		}
	}
	
}

int main(void)
{
	myDDRA = 0xFF;  //hrs columns
	myDDRB = 0xFF;  //hrs rows
	myDDRC = 0xFF;  //min columns
	myDDRD = 0xFF;  //min rows
	
	while(1)
	{
		Clock_Run();	
	}
	return 0;
}
