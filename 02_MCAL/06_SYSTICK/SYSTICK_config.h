/****************************************************/
/*	Author	:Ayman Saleh							*/
/*	Date	:12 SEP 2022 							*/
/*	Version	:V01		 							*/
/****************************************************/

/*	Header File Guard
	if file is not defined 
 */
#ifndef SYSTICK_CONFIG_H_
#define SYSTICK_CONFIG_H_
/*	Options:
		STK_SOURCE_AHB
		STK_SOURCE_AHB_DIV_8
 */

#define STK_SOURCE	STK_SOURCE_AHB_DIV_8

/*	Options:
		STK_ENABLE
		STK_DISABLE
 */
#define STK_STATE	STK_ENABLE

/*	Options:
		STK_INT_ENABLE
		STK_INT_DISABLE
 */
#define STK_INT_STATE	STK_INT_ENABLE
/*	Options:
		1 : 16777215
Note: Configure this Only if STK_STATE is STK_ENABLE
 */
#define STK_INIT_VAL	1000000
#endif
