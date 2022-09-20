
/****************************************************/
/*	Author	:Ayman Saleh							*/
/*	Date	:20 SEP 2022 							*/
/*	Version	:V01		 							*/
/****************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"

#include "NVIC_interface.h"

#include "DIO_interface.h"
#include "UART_interface.h"

void main (void){
	/*	RCC initiates the System Clock	*/
	RCC_voidInitSysClock();

	/*	GPIOA Clock Enable	*/
	RCC_voidEnableClock(RCC_APB2, RCC_APB2_IOPAEN);
	RCC_voidEnableClock(RCC_APB2, RCC_APB2_USART1EN);

	/*	A9 - Tx Output */
	DIO_voidSetPinDirection	(GPIO_PORTA, GPIO_PIN9, GPIO_OUTPUT_50MHZ_PP);
	/*	A10 - Rx Input */
	DIO_voidSetPinDirection	(GPIO_PORTA, GPIO_PIN10, GPIO_INPUT_FLOATING);
	/*	Test Pin*/
	DIO_voidSetPinDirection	(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT_50MHZ_PP);

	MUART_voidInit();
	u8 LOC_u8TestSend;
	while (1){
		MUART_voidTransmit("Ayman Saleh Zien");
		LOC_u8TestSend = MUART_u8Receive();
		if (LOC_u8TestSend == '5'){
			DIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_LOW);
		}
		else if (LOC_u8TestSend == 'a'){
			DIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_HIGH);
		}
	}
}

