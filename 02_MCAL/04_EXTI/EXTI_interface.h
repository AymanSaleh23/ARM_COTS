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

/*	Can be Enumerate but not Standard in C*/
#define EXTI_LINE_0	 0
#define EXTI_LINE_1  1
#define EXTI_LINE_2  2
#define EXTI_LINE_3  3
#define EXTI_LINE_4  4
#define EXTI_LINE_5  5
#define EXTI_LINE_6  6
#define EXTI_LINE_7  7
#define EXTI_LINE_8  8
#define EXTI_LINE_9  9
#define EXTI_LINE_10 10
#define EXTI_LINE_11 11
#define EXTI_LINE_12 12
#define EXTI_LINE_13 13
#define EXTI_LINE_14 14
#define EXTI_LINE_15 15

/*Line and Mode are parameters in define */
void MEXTI_voidInit 			(void);
void MEXTI_voidEnableEXTI 		(u8 Copy_u8Line);
void MEXTI_voidDisableEXTI 		(u8 Copy_u8Line);
void MEXTI_voidSWTrigger 		(u8 Copy_u8Line);
void MEXTI_voidSetSignalLatch	(u8 Copy_u8Line, u8 Copy_u8Mode);
void MEXTI_voidSetCallBack		(u8 Copy_u8Line, void (* ptr)(void) );
#endif
