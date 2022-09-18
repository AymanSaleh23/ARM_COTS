
/****************************************************/
/*	Author	:Ayman Saleh							*/
/*	Date	:16 SEP 2022 							*/
/*	Version	:V01		 							*/
/****************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"

#include "NVIC_interface.h"
#include "DIO_interface.h"
#include "DMA_interface.h"

void callBackDMA (void){
	static u8 login = 0;
	DIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_HIGH);
	login++;
}
void main (void){
	/*	RCC initiates the System Clock	*/
	RCC_voidInitSysClock();
	/*	GPIOA Clock Enable	*/
	RCC_voidEnableClock(RCC_APB2, RCC_APB2_IOPAEN	);
	/*	DMA Clock Enable	*/
	RCC_voidEnableClock(RCC_AHB	, RCC_AHB_DMA1EN	);
	/*	NVIC enable Channel 1*/
	MNVIC_voidEnableInterrupt(NVIC_DMA1_CH1);

	//Output "Out"
	DIO_voidSetPinDirection	(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT_2MHZ_PP);

	u32 ArrS[10]= {900,2343,43,345434,534,353,44543,5434,5434,54453};
	u32 ArrD[10]= {032,42,4,5,2,43,42,23,4,3};

	DMA_ChannelReq_t DMA_req;
	DMA_req.BlockLenght	= 10;
	DMA_req.Channel		= DMA_CHANNEL_1;
	DMA_req.CircularOperation	= DMA_CIRCULAR_MODE_DISABLE;
	DMA_req.DMA_module			= DMA_MODULE_1;
	DMA_req.Direction 			= DMA_READ_FROM_MEMORY;
	DMA_req.MemoryInc 			= DMA_MEMROTY_INC_ENABLE;
	DMA_req.PeripheralInc 		= DMA_PERIPHERAL_INC_ENABLE;
	DMA_req.MemorySize 		= DMA_MEMORY_SIZE_32_BIT;
	DMA_req.PeripheralSize	= DMA_PERIPHERAL_SIZE_32_BIT;
	DMA_req.Priority 		= DMA_PRIORITY_VERY_HIGH;
	DMA_req.fptr 			= callBackDMA;
	DMA_req.pu32SourceAddress 		= ArrS;
	DMA_req.pu32DestinationAddress	= ArrD;

	MDMA_voidChannelStartRequest(&DMA_req);

	while (1){
	}
}

