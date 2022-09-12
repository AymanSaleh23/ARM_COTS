/****************************************************/
/*	Author	:Ayman Saleh							*/
/*	Date	:12 SEP 2022 							*/
/*	Version	:V01		 							*/
/****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"

void STK_voidInit		(void){

	/*	STK_STATE	Start check	*/
#if STK_STATE	== STK_ENABLE
	SET_BIT(STK_CTRL, STK_CTRL_ENABLE);
	/*	STK_INIT_VAL	Start check	*/
#if  STK_INIT_VAL	> 0 && STK_INIT_VAL	<= 16777215
	STK_LOAD = 1000000;
#else
#error "Wrong STK_STATE configuration parameter"
	/*	STK_INIT_VAL	End check	*/
#endif

	/*	STK_INT_STATE	Start check	*/
#if 	STK_INT_STATE	== STK_INT_ENABLE
	SET_BIT(STK_CTRL, STK_CTRL_TICKINT);
#elif 	STK_INT_STATE	== STK_INT_DISABLE
	CLR_BIT(STK_CTRL, STK_CTRL_TICKINT);
#else 
#error "Wrong STK_INT_STATE configuration parameter"
	/*	STK_INT_STATE	End check	*/
#endif

	/*	STK_SOURCE	Start check	*/
#if 	STK_SOURCE	== STK_SOURCE_AHB
	SET_BIT(STK_CTRL, STK_CTRL_CLKSOURCE);
#elif 	STK_SOURCE	== STK_SOURCE_AHB_DIV_8
	CLR_BIT(STK_CTRL, STK_CTRL_CLKSOURCE);
#else
#error "Wrong STK_SOURCE configuration parameter"
	/*	STK_SOURCE	End check	*/
#endif

#elif STK_STATE ==	STK_DISABLE
	CLR_BIT(STK_CTRL, STK_CTRL_ENABLE);
#else
#error "Wrong STK_STATE configuration parameter"
	/*	STK_STATE	End check	*/
#endif

}

void STK_voidDisable	(void){
	CLR_BIT(STK_CTRL, STK_CTRL_TICKINT);
	CLR_BIT(STK_CTRL, STK_CTRL_ENABLE);
	STK_LOAD = 0;
	STK_VAL = 0;
}

void STK_voidEnable 	(void){
	SET_BIT(STK_CTRL, STK_CTRL_TICKINT);
	SET_BIT(STK_CTRL, STK_CTRL_ENABLE);
}
void STK_voidLoad		(u32 Copy_u32Value){
	STK_LOAD = Copy_u32Value;
}
u32  STK_u32GetCurrent		(void){
	u32 Local_u32Current;
	Local_u32Current = STK_VAL;
	return Local_u32Current;
}
