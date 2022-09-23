
/****************************************************/
/*	Author	:Ayman Saleh							*/
/*	Date	:16 SEP 2022 							*/
/*	Version	:V01		 							*/
/****************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "SPI_interface.h"
#include "TFT_interface.h"

#include "img.h"

void main (void){
	/*	RCC initiates the System Clock	*/
	RCC_voidInitSysClock();

	/*	GPIOA Clock Enable	*/
	RCC_voidEnableClock(RCC_APB2, RCC_APB2_IOPAEN);
	RCC_voidEnableClock(RCC_APB2, RCC_APB2_SPI1EN);

	/*	A0			*/
	DIO_voidSetPinDirection	(GPIO_PORTA, GPIO_PIN1, GPIO_OUTPUT_2MHZ_PP);
	/*	Reset Pin	*/
	DIO_voidSetPinDirection	(GPIO_PORTA, GPIO_PIN2, GPIO_OUTPUT_2MHZ_PP);
	/*	CLK			*/
	DIO_voidSetPinDirection	(GPIO_PORTA, GPIO_PIN5, GPIO_OUTPUT_10MHZ_AF_PP);
	/*	MOSI		*/
	DIO_voidSetPinDirection	(GPIO_PORTA, GPIO_PIN7, GPIO_OUTPUT_10MHZ_AF_PP);

	/*	Init STK	*/
	MSTK_voidInit();
	/*	Init SPI1	*/
	MSPI1_voidInit();
	/*	Init TFT	*/
	HTFT_voidInit();

	while (1){
		HTFT_voidDisplayImg(holyImg);
		MSTK_voidSetBusyWait(1000000);
		HTFT_voidFillColor(0b0000011111100000);
		MSTK_voidSetBusyWait(1000000);

	}
}
