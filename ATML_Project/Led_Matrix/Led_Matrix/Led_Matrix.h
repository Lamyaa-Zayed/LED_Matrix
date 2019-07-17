﻿/*
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



#endif /* LED_MATRIX_H_ */