#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"

/***********************************************************************/
/*                                                                     */
/*  DATE        :Aug 5, 2012	                                       */
/*																	   */
/*  DESCRIPTION : This function contains the main function for this    */
/*					program 										   */
/*																	   */
/*  CPU GROUP   :62P                                                   */
/*                                                                     */
/*  Christopher Scott Johnson										   */
/*  																   */
/*                                                                     */
/***********************************************************************/



int disp_count;				// LED control variable
uint A2DValue;
uint A2DValuePot;
uint A2DValueTherm;
uchar A2DProcessed;

#define SWITCH_PRESSED 0
#define TRUE 1

void main(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	The MCU will come here after reset. 
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
	
	system_clock_init();
	InitDisplay("csjohns3  ");
	InitUART();
	BNSPrintf(SERIAL, "\n\rTutor1\n\r");
  	TimerInit();
	ADInit();	
	ENABLE_SWITCHES;
	
	/* LED initialization - macro defined in qsk_bsp.h */
 	ENABLE_LEDS	

	while(TRUE) 
	{
		LEDDisplay();		// display current value of LED control variable */
		if(S1 == SWITCH_PRESSED)
		{
			BNSPrintf(LCD,"\tButton1 \n        ");
			BNSPrintf(SERIAL,"\n\rButton1");
		}
		else if (S2 == SWITCH_PRESSED)
		{
			BNSPrintf(LCD,"\tButton2 \n        ");
			BNSPrintf(SERIAL,"\n\rButton2");
		}
		else if (S3 == SWITCH_PRESSED)
		{
			BNSPrintf(LCD,"\tButton3 \n        ");
			BNSPrintf(SERIAL,"\n\rButton3");
		}
		else
		{
            if (A2DProcessed == TRUE) 
			{         								// only update the display when a new value is available
                A2DProcessed = FALSE;
                BNSPrintf(LCD,"\tRT1:%04u \nAD0:%04u",A2DValueTherm,A2DValuePot);
            }
		}
	}
}