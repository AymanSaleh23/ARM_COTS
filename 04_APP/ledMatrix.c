/*
 * main.c
 *
 *  Created on: Sep 9, 2022
 *      Author: as292
 */
/****************************************************/
/*	Author	:Ayman Saleh							*/
/*	Date	:6 SEP 2022 							*/
/*	Version	:V01		 							*/
/****************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "RCC_interface.h"

#include "STK_interface.h"

#include "DIO_interface.h"
#include "LEDMRX_interface.h"
static u8 data [5][8] = {
		{0, 0, 124, 18, 18, 124, 0, 0},
		{0, 0, 0, 30, 240, 30, 0, 0},
		{0, 254, 4, 8, 4, 254, 0, 0},
		{0, 0, 124, 18, 18, 124, 0, 0},
		{0, 255, 1, 30, 112, 64, 255, 0}
};
u8 i = 0 ;
void inc (void){
	static c = 0;
	c++;
	if (c == 400){
		i++;
		i%=5;
		c=0;
	}
}
void main (void){
	/*	RCC initiates the System Clock	*/

	RCC_voidInitSysClock();
	/*Enable GPIOA CLK*/
	RCC_voidEnableClock(RCC_APB2, RCC_APB2_IOPAEN);
	RCC_voidEnableClock(RCC_APB2, RCC_APB2_IOPBEN);

	HLEDMRX_voidInit();
	MSTK_voidSetIntervalPriodic(2500, inc);

	while (1){

		HLEDMRX_voidDisplay(data[i]);

	}
}

