
/****************************************************/
/*	Author	:Ayman Saleh							*/
/*	Date	:16 SEP 2022 							*/
/*	Version	:V01		 							*/
/****************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SCB_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"

#include "RCC_interface.h"

#include "DIO_interface.h"
#include "OS_interface.h"

void Task1(void);
void Task2(void);
void Task3(void);


static Task_t taskList [3] = {
		{0, 1, 1000, 0},
		{1, 2, 2000, 2},
		{2, 3, 3000, 4}
};
static void (* ptf[3])(void) = {Task1,Task2,Task3};

void Task1(void){
	DIO_voidToggPin(GPIO_PORTA, GPIO_PIN0);
}
void Task2(void){
	DIO_voidToggPin(GPIO_PORTA, GPIO_PIN1);
}
void Task3(void){
	DIO_voidToggPin(GPIO_PORTA, GPIO_PIN2);
}

void main (void){
	/*	RCC initiates the System Clock	*/
	RCC_voidInitSysClock();
	/*Enable GPIOA CLK*/
	RCC_voidEnableClock(RCC_APB2, RCC_APB2_IOPAEN);

	//Output "Red"
	DIO_voidSetPinDirection	(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT_2MHZ_PP);
	//Output "Green"
	DIO_voidSetPinDirection	(GPIO_PORTA, GPIO_PIN1, GPIO_OUTPUT_2MHZ_PP);
	//Output "Blue"
	DIO_voidSetPinDirection	(GPIO_PORTA, GPIO_PIN2, GPIO_OUTPUT_2MHZ_PP);

	/*	NVIC initialize*/
	MNVIC_voidInit();

	MSTK_voidInit();
	/*	u8	number;
		u16 priority;
		u16 priodicity;
		u16 firstDalay;
		void (*fptr) (void);
	 */

	for (u8 i = 0 ; i < 3 ; i ++){
		taskList[i].fptr = ptf[i];
		SOS_voidCreateTask(&taskList[i]);
	}
	SOS_voidStart();
	while (1){

	}
}

