#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"

/***********************************************************************/
/*                                                                     */
/*  DATE        :Mon, Mar 23, 2009                                     */
/*																	   */
/*  DESCRIPTION :  This file contains all the interrupt routines for   */
/* 	  				the peripherals.  								   */
/*																	   */
/*  CPU GROUP   :62P                                                   */
/*                                                                     */
/*  Copyright (c) 2009 by BNS Solutions, Inc.						   */
/*  All rights reserved.											   */
/*                                                                     */
/***********************************************************************/

#pragma INTERRUPT A2DInterrupt
#pragma INTERRUPT UART0TransmitInterrupt
#pragma INTERRUPT UART0ReceiveInterrupt
#pragma INTERRUPT TimerA1Interrupt
#pragma INTERRUPT TimerA2Interrupt
#pragma INTERRUPT KeyBoardInterrupt
#pragma INTERRUPT DMA0Interrupt
#pragma INTERRUPT WakeUpInterrupt
#pragma INTERRUPT RTCInterrupt
#pragma INTERRUPT TimerB0Interrupt
#pragma INTERRUPT WatchDogInterrupt

void A2DInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

void UART0TransmitInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

void DMA0Interrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

void UART0ReceiveInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
	while(ri_u0c1 == 0);	  // make sure receive is complete
	
    while(ti_u0c1 == 0); 			//  puts it in the UART 0 transmit buffer 

	u0tb = (char) u0rb;      // read in received data
    
}

void TimerA1Interrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	This handles the interrupt for Timer A1. It will start an A2D every time in.
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
// Uncomment the lines "//$" below to read the two channels every other timer 
// interrupt instead of every interrupt
    
//$    static unsigned char adSwitch;
    
//$    if (adSwitch == 0) {    // read the a/d channel every other entry.
//$        adSwitch = 1;
    	adcon0 = 0x80;	// AN0, One-shot, software trigger, fAD/2
        adst = 1;				// Start A2D conversion	
    	while(adst == 1);		// wait for A/D conversion start bit to return to 0 read AD value 
    	ta1 = ad0 + 10;			// and preload Timer A1 to vary the LED switching rate 
    							// (the + 10 is to ensure the counter is not loaded with 0"
    	A2DValue = ad0;
        A2DValuePot = A2DValue;
//$    }
//$    else {
//$        adSwitch = 0;
    	adcon0 = 0x81;	// AN0, One-shot, software trigger, fAD/2
        adst = 1;				// Start A2D conversion	
    	while(adst == 1);		// wait for A/D conversion start bit to return to 0 

    	A2DValueTherm = ad1;
//$    }						
                            
	++disp_count;			// increment display control variable 
	if (disp_count > 4){	// if LED control variable exceeds valid number 
		disp_count = 1;		// return to initial state 
	}
	
    A2DProcessed = TRUE;	// only update the display when a new value is available
}

void TimerA2Interrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

void KeyBoardInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

void WakeUpInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

void RTCInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

void TimerB0Interrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

void WatchDogInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

