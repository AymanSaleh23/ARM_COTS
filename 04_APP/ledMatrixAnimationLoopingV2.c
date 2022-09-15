
/****************************************************/
/*	Author	:Ayman Saleh							*/
/*	Date	:15 SEP 2022 							*/
/*	Version	:V02		 							*/
/****************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "RCC_interface.h"

#include "STK_interface.h"

#include "DIO_interface.h"
#include "LEDMRX_interface.h"
static u8 data [] = {
		0, 63, 72, 72, 63, 0, 112, 15, 112, 0, 127, 32, 16, 32, 127, 0, 63, 72, 72, 63, 0, 63, 64, 62, 1, 126, 0, 0, 0, 0
};
u8 shift = 0 ;
void inc (void){
	static u8 c = 0;
	c++;
	if (c == 50){
		shift++;
		c=0;
	}
}
void main (void){
	/*	RCC initiates the System Clock	*/

	RCC_voidInitSysClock();
	/*Enable GPIOA CLK*/
	RCC_voidEnableClock(RCC_APB2, RCC_APB2_IOPAEN);
	RCC_voidEnableClock(RCC_APB2, RCC_APB2_IOPBEN);

	DIO_voidSetPinDirection	(GPIO_PORTA, GPIO_PIN8, GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinValue		(GPIO_PORTA, GPIO_PIN8, GPIO_PIN_HIGH);

	HLEDMRX_voidInit();
	MSTK_voidSetIntervalPriodic(2500, inc);

	while (1){
		u8 drivenChar [8] ={
				data[(0+shift)%30],
				data[(1+shift)%30],
				data[(2+shift)%30],
				data[(3+shift)%30],
				data[(4+shift)%30],
				data[(5+shift)%30],
				data[(6+shift)%30],
				data[(7+shift)%30]
		};
		HLEDMRX_voidDisplay(drivenChar);
	}
}

