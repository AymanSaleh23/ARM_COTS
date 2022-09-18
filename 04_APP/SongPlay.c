/****************************************************/
/*	Author	:Ayman Saleh							*/
/*	Date	:17 SEP 2022 							*/
/*	Version	:V01		 							*/
/****************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "RCC_interface.h"

#include "DIO_interface.h"
#include "song.h"

static u8 index = 0;
void configFreq1(void);


void configFreq1 (void){
	static u16 joins = 0;
	//Zero 12231, Ten 19911
		DIO_voidSetPortValue(GPIO_PORTA, Hallo_raw[joins]);
		joins++;
		joins %= 51779;
}
void main (void){
	/*	RCC initiates the System Clock	*/
	RCC_voidInitSysClock();
	/*Enable GPIOA CLK*/
	RCC_voidEnableClock(RCC_APB2, RCC_APB2_IOPAEN);

	//Output "Out"
	DIO_voidSetPinDirection	(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection	(GPIO_PORTA, GPIO_PIN1, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection	(GPIO_PORTA, GPIO_PIN2, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection	(GPIO_PORTA, GPIO_PIN3, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection	(GPIO_PORTA, GPIO_PIN4, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection	(GPIO_PORTA, GPIO_PIN5, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection	(GPIO_PORTA, GPIO_PIN6, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection	(GPIO_PORTA, GPIO_PIN7, GPIO_OUTPUT_2MHZ_PP);

	MSTK_voidInit();
	/*	Put Freq to 8000 Hz = 125 us	*/
	MSTK_voidSetIntervalPriodic(125, configFreq1);
	while (1){
	}
}

