/****************************************************/
/*	Author	:Ayman Saleh							*/
/*	Date	:11 SEP 2022 							*/
/*	Version	:V01		 							*/
/****************************************************/

/*	Header File Guard
	if file is not defined 
 */
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

void MNVIC_voidEnableInterrupt 	(u8 Copy_u8IntNumber);

void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber);

void MNVIC_voidSetPendingFlag	(u8 Copy_u8IntNumber);

void MNVIC_voidClearPendingFlag	(u8 Copy_u8IntNumber);

u8   MNVIC_u8GetActiveFlag		(u8 Copy_u8IntNumber);
#endif