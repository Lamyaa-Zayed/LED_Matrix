/*
 * Led_Matrix.h
 *
 * Created: 16/07/2019 12:32:06 ص
 *  Author: Lamyaa Zayed
 */ 


#ifndef LED_MATRIX_H_
#define LED_MATRIX_H_

#define myDDRD *((volatile unsigned char *const)0x31)
#define myPORTD *((volatile unsigned char *const)0x32)

#define myDDRC *((volatile unsigned char *const)0x34)
#define myPORTC *((volatile unsigned char *const)0x35)

#define myDDRA *((volatile unsigned char *const)0x3A)
#define myPORTA *((volatile unsigned char *const)0x3B)

#define myDDRB *((volatile unsigned char *const)0x37)
#define myPORTB *((volatile unsigned char *const)0x38)

#define  HRS_PORT	myPORTB
#define  MINS_PORT	myPORTD
#define  SECS_PORT	myPORTC
#define  ACT_PORT	myPORTA 


#define BCD_Numbers 10
#define  Column_Numbers 8
#define Adjustment_Delay_Number 278     //(1s/(150us*8*8*8))

#define  LED_Matrix_OFF 0x00
#define  PORT_OUTPUT 0xff


#endif /* LED_MATRIX_H_ */
