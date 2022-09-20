
/****************************************************/
/*	Author	:Ayman Saleh							*/
/*	Date	:20 SEP 2022 							*/
/*	Version	:V01		 							*/
/****************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void MUART_voidInit		(void){
	/*	For 8MHz Clock System		*/
	/*	9600	:52.08 = 0x34,0x1 	*/
	/*	115200	:4.34  = 0x04,0x6 	*/
	UART1 -> BRR_reg.Fraction = 0x1;
	UART1 -> BRR_reg.Mantissa = 0x34;
	/*	Enable Tx	*/
	UART1 -> CR1_reg.TE = 1;
	/*	Enable Rx	*/
	UART1 -> CR1_reg.RE = 1;
	/*	UART enable */
	UART1 -> CR1_reg.UE = 1;
	/*	Reset the Status Register	*/
	UART1->SR_reg.Value= 0;
}
void MUART_voidTransmit	(u8 *Copy_u8Arr []){
	u32 LOC_u32I = 0;
	while (Copy_u8Arr[LOC_u32I] != '\0'){
		/*	Put value toe be transmitted	*/
		UART1 ->DR_reg = Copy_u8Arr[LOC_u32I];
		/*	Wait till transmission is complete	*/
		while ((UART1 ->SR_reg.SR_bits.TC) == 0 );
		LOC_u32I++;
	}
}
u8	 MUART_u8Receive	(void){
	u8 LOC_u8Data = 0;
	while ((UART1 ->SR_reg.SR_bits.RXNE) == 0);
	LOC_u8Data = UART1 ->DR_reg;
	return (u8) LOC_u8Data;
}
