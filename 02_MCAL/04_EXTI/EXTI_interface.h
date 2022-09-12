/****************************************************/
/*	Author	:Ayman Saleh							*/
/*	Date	:12 SEP 2022 							*/
/*	Version	:V01		 							*/
/****************************************************/

/*	Header File Guard
	if file is not defined 
 */
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*Line and Mode are parameters in define */
void MEXTI_voidInit 		(void);
void MEXTI_voidEnableEXTI 	(u8 Copy_u8Line);
void MEXTI_voidDisableEXTI 	(u8 Copy_u8Line);
void MEXTI_voidSWTrigger 	(u8 Copy_u8Line);
void MEXTI_voidSetSignalLatch (u8 Copy_u8Line, u8 Copy_u8Mode);
#endif
