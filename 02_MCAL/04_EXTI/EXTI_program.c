/****************************************************/
/*	Author	:Ayman Saleh							*/
/*	Date	:12 SEP 2022 							*/
/*	Version	:V01		 							*/
/****************************************************/

/*	Header File Guard
	if file is not defined 
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

/*	Initialize all EXTI as defined 	*/
void MEXTI_voidInit 		(void)
{
	/*	Check EXTI_MODE Configuration parametner Start*/
	#if EXTI_MODE ==	RISING
	SET_BIT(EXTI -> RTSR, EXTI_LINE);
	#elif EXTI_MODE ==	FALLING
	SET_BIT(EXTI -> FTSR, EXTI_LINE);
	#elif EXTI_MODE ==	ON_CHANGE
	SET_BIT(EXTI -> FTSR, EXTI_LINE);
	SET_BIT(EXTI -> RTSR, EXTI_LINE);
	#else 
		#error "Wrong EXTI_MODE Configuration parametner"
	/*	Check EXTI_MODE Configuration parametner end*/
	#endif
}

/*Enable the external Interrupt from Copy_u8Line*/
void MEXTI_voidEnableEXTI 	(u8 Copy_u8Line){
	SET_BIT(EXTI -> IMR, Copy_u8Line);
}
/*Disable the external Interrupt from Copy_u8Line*/
void MEXTI_voidDisableEXTI 	(u8 Copy_u8Line){
	CLR_BIT(EXTI -> IMR, Copy_u8Line);
}
/*SW trigger Interrupt from Copy_u8Line*/
void MEXTI_voidSWTrigger 	(u8 Copy_u8Line){
	/*	Fire interrupt by SW for test or debug*/
	SET_BIT(EXTI -> SWIER, Copy_u8Line);
}/*	Runtine Change Configuration*/

/*Latch (change configuration) of external Interrupt from Copy_u8Line*/
void MEXTI_voidSetSignalLatch (u8 Copy_u8Line, u8 Copy_u8Mode){
	MEXTI_voidDisableEXTI(Copy_u8Line);
	switch (Copy_u8Mode){
		case RISING: {
			SET_BIT(EXTI -> RTSR, EXTI_LINE);
			}
		break;
		case FALLING: {
			SET_BIT(EXTI -> FTSR, EXTI_LINE);
			}
		break;
		case ON_CHANGE: {
			SET_BIT(EXTI -> FTSR, EXTI_LINE);
			SET_BIT(EXTI -> RTSR, EXTI_LINE);
		}
		break;
	}
	MEXTI_voidEnableEXTI(Copy_u8Line);
}
