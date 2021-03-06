#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"

/***********************************************************************/
/*                                                                     */
/*  DATE        :Aug 5, 2012	                                       */
/*																	   */
/*  DESCRIPTION : This file contains the support the cpu clock.        */
/*																	   */
/*  CPU GROUP   :62P                                                   */
/*                                                                     */
/*  Christopher Scott Johnson										   */
/*  																   */
/*                                                                     */
/***********************************************************************/

void system_clock_init(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose: The starter kit startup file initializes the clock circuit
//           to the main crystal with a divide by 1.  This function also sets
//			 the main clock to divide by 1 in case the SKP startup file is not 
//			 used.  It then enables the PLL 
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
	 unsigned int count = 40000;
  
	/* configure clock for divide by 1 mode */
	prc0 =1;					/* enable access to clock registers */
	cm1 = 0x20;					/* set CM16,CM17 divide ratio to 1, 
									main clock on in high drive no PLL*/
	cm06 = 0;					/* set divide ratio to 1 */		
	
    /* configure and switch main clock to PLL at 24MHz - uncomment this section
		out if PLL operation is desired								*/
   
	prc1 = 1;					/* allow writing to processor mode register */
	pm20 = 1;					/* set SFR access to 2 wait which is required for
   									operation greater than 16 MHz */
	prc1 = 0;					/* protect processor mode register */

	plc0= 0x92;					// enable PLL (2X) and turn on

	while(count > 0) count--;   /* wait for PLL to stabilize (20mS maximum, 240,000 cycles @12Mhz)
                                   this decrement with no optimization is 12 cycles each */
    cm11 = 1;                   /* switch to PLL */
    prc0 = 0;   				/* protect clock control register */
	
	prc1 = 1;
	pm10 = 1;		// enable data flash area
	prc1 = 0;
	
}
