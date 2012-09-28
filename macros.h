/***********************************************************************/
/*                                                                     */
/*  DATE        :Sun, Sept 23, 2012                                    */
/*																	   */
/*  DESCRIPTION :      All the defines for the projects are kept here. */
/* 	  																   */
/*																	   */
/*  CPU GROUP   :62P                                                   */
/*                                                                     */
/*  Copyright (c) 2009 by BNS Solutions, Inc.						   */
/*  All rights reserved.											   */
/*                                                                     */
/***********************************************************************/

/* Initialize Ports */
#define LED_ON      		0
#define LED_OFF     		1

#define PORT_DIRECTION_IN	0
#define PORT_DIRECTION_OUT	1

#define PORT_IN_LOW			0
#define PORT_IN_HIGH		1

#define TEST_PIN 			p0_7

/* Switches */
#define	S1 					p8_3 
#define S2 					p8_1 
#define S3 					p8_2 
#define S1_DDR				pd8_3
#define S2_DDR				pd8_1
#define S3_DDR				pd8_2

/* LEDs */
#define	LED0				p8_0
#define	LED1				p7_4
#define	LED2				p7_2

#define BIG_NUMBER			1000;
		
#define	LED0_DDR 			pd8_0		// LED port direction register
#define	LED1_DDR 			pd7_4
#define	LED2_DDR 			pd7_2

/* Turn */

#define LEFT_FORWARD			p3_0
#define RIGHT_FORWARD			p3_2

#define LEFT_FORWARD_DDR		pd3_0
#define RIGHT_FORWARD_DDR		pd3_1


