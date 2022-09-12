/****************************************************/
/*	Author	:Ayman Saleh							*/
/*	Date	:12 SEP 2022 							*/
/*	Version	:V01		 							*/
/****************************************************/

/*	Header File Guard
	if file is not defined 
 */
#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

void STK_voidInit		(void);
void STK_voidEnable 	(void);
void STK_voidDisable	(void);
void STK_voidLoad		(u32 Copy_u32Value);
u32  STK_u32GetCurrent	(void);
#endif
