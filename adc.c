#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"

/***********************************************************************/
/*                                                                     */
/*  DATE        :Aug 5, 2012	                                       */
/*																	   */
/*  DESCRIPTION : This file contains the support for the analog to     */
/* 	digital convertor.												   */
/*																	   */
/*  CPU GROUP   :62P                                                   */
/*                                                                     */
/*  Christopher Scott Johnson										   */
/*  																   */
/*                                                                     */
/***********************************************************************/

void ADInit(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Set up the A2D for one shot mode.
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
	
   /* Configure ADC - AN0 (Analog Adjust Pot) */
   adcon0 = 0x80;	// AN0, One-shot, software trigger, fAD/2
   adcon1 = 0x28;	// 10-bit mode, Vref connected.
   adcon2 = 0x01;	// Sample and hold enabled
}   
