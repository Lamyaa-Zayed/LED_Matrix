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

unsigned char Active_Pin[Column_Numbers]={0x7F,0xBF,0xDF,0xEF,0xF7,0xFB,0xFD,0xFE};

unsigned char Numbers_To_Display[BCD_Numbers][Column_Numbers]={
										 {0x0F,0x09,0x09,0x09,0x09,0x09,0x09,0x0F}/*0*/
										,{0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01}/*1*/
										,{0x0F,0x01,0x01,0x0F,0x08,0x08,0x08,0x0F}/*2*/
										,{0x0F,0x01,0x01,0x0F,0x01,0x01,0x01,0x0F}/*3*/
										,{0x09,0x09,0x09,0x0F,0x01,0x01,0x01,0x01}/*4*/
										,{0x0F,0x08,0x08,0x0F,0x01,0x01,0x01,0x0F}/*5*/
										,{0x0F,0x08,0x08,0x0F,0x09,0x09,0x09,0x0F}/*6*/
										,{0x0F,0x01,0x01,0x01,0x01,0x01,0x01,0x01}/*7*/
										,{0x0F,0x09,0x09,0x0F,0x09,0x09,0x09,0x0F}/*8*/
										,{0x0F,0x09,0x09,0x0F,0x01,0x01,0x01,0x0F}/*9*/
										};	

unsigned char Minutes,Hours,Seconds;
unsigned int Adjustment_Delay;

void Display_LED_Matrix(unsigned char Number,volatile unsigned char *const Display_PORT)
{
	unsigned char Unit_Digit,Tenth_Digit,Matrix_Column;
	Unit_Digit=Number%10u;
	Tenth_Digit=Number/10u;
	for(Matrix_Column=0;Matrix_Column<Column_Numbers;Matrix_Column++)
	{
		ACT_PORT=Active_Pin[Matrix_Column];
		*Display_PORT=((Numbers_To_Display[Tenth_Digit][Matrix_Column])<<4)|(Numbers_To_Display[Unit_Digit][Matrix_Column]);
		_delay_us(150);
	}
	*Display_PORT=LED_Matrix_OFF;
}

void Clock_Run(void)
{
	for (Hours=0;Hours<24;Hours++)
	{
		for(Minutes=0;Minutes<60;Minutes++)
		{
			for (Seconds=0;Seconds<60;Seconds++)
			{
				for(Adjustment_Delay=0;Adjustment_Delay<Adjustment_Delay_Number;Adjustment_Delay++)
				{

					Display_LED_Matrix(Hours,&HRS_PORT);
					Display_LED_Matrix(Minutes,&MINS_PORT);
					Display_LED_Matrix(Seconds,&SECS_PORT);
				}
			}
			
		}
	}
	
}

int main(void)
{
	myDDRA = PORT_OUTPUT;  //hrs columns
	myDDRB = PORT_OUTPUT;  //hrs rows
	myDDRC = PORT_OUTPUT;  //min columns
	myDDRD = PORT_OUTPUT;  //min rows
	
	while(1)
	{
		Clock_Run();	
	}
	return 0;
}
