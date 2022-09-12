/*
 * main.c
 *
 *  Created on: Sep 12, 2022
 *      Author: as292
 */
/****************************************************/
/*	Author	:Ayman Saleh							*/
/*	Date	:6 SEP 2022 							*/
/*	Version	:V01		 							*/
/****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "SYSTICK_interface.h"
u8 idle=1;

void main (void){
	RCC_voidInitSysClock();
	/*Enable GPIOA CLK*/
	RCC_voidEnableClock(RCC_APB2, RCC_APB2_IOPAEN);

	STK_voidInit();

	/*Pin Modes */
	DIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN1, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN2, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN3, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN4, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN5, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN6, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN7, GPIO_OUTPUT_2MHZ_PP);

	DIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_HIGH);
	DIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_PIN_HIGH);
	DIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_PIN_HIGH);
	DIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_PIN_HIGH);
	DIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN4, GPIO_PIN_HIGH);
	DIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_PIN_HIGH);
	DIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN6, GPIO_PIN_HIGH);
	DIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN7, GPIO_PIN_HIGH);

	while (1){
		for (u8 j = 0 ; j < 4 ; j ++){
			for (u8 i = 0; i < 7 ; i++){
				dalay(200);
				DIO_voidSetPortValue(GPIO_PORTA, (u16)(1<<i) );
			}
			for (u8 i = 0; i <= 7 ; i++){
				dalay(200);
				DIO_voidSetPortValue(GPIO_PORTA, (u16)(1<<(7-i)) );
			}
		}

		for (u8 j = 0 ; j < 4 ; j ++){
			for (u8 i = 0; i <= 7 ; i++){
				dalay(200);
				DIO_voidSetPortValue(GPIO_PORTA, (u16)( (1<<i) | (1<<(7-i)) )	);
			}
		}


		for (u8 i = 0; i < 8 ; i++){
			dalay(500);
			DIO_voidSetPortValue(GPIO_PORTA, (u16)0xffff );
			dalay(500);
			DIO_voidSetPortValue(GPIO_PORTA, (u16)0x0000 );
		}
	}
}

void SysTick_Handler(void){
	STK_voidDisable();
	idle=0;
}
void dalay(u32 Copy_u32Delayms){
	STK_voidLoad(Copy_u32Delayms*1000);
	STK_voidEnable();
	while(idle);
	idle=1;
}
