#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"

/***********************************************************************/
/*                                                                     */
/*  DATE        :Aug 5, 2012	                                       */
/*																	   */
/*  DESCRIPTION : This file contains the support for the LED lights.   */
/*																	   */
/*  CPU GROUP   :62P                                                   */
/*                                                                     */
/*  Christopher Scott Johnson										   */
/*  																   */
/*                                                                     */
/***********************************************************************/

void LEDDisplay(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Make the LEDs scan back and forth.
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{

	switch (disp_count){
		
		case 1:							/* green on */
   				LED0 = LED_OFF;			
				LED1 = LED_OFF;
				LED2 = LED_ON;
				break;
		case 2:							/* yellow on */
		case 4:
   				LED0 = LED_OFF;			
				LED1 = LED_ON;
				LED2 = LED_OFF;
				break;
		case 3:							/* red on */
   				LED0 = LED_ON;			
				LED1 = LED_OFF;
				LED2 = LED_OFF;
				break;
		default:						/* all LED's off */
   				LED0 = LED_OFF;			
				LED1 = LED_OFF;
				LED2 = LED_OFF;
	}
}