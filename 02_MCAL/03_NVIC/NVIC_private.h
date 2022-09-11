/****************************************************/
/*	Author	:Ayman Saleh							*/
/*	Date	:11 SEP 2022 							*/
/*	Version	:V01		 							*/
/****************************************************/

/*	Header File Guard
	if file is not defined 
 */
#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#define NVIC_BASE_ADDRESS	0xE000E100

#define NVIC_ISER0 			*((u32*) (NVIC_BASE_ADDRESS + 0x0))
#define NVIC_ISER1 			*((u32*) (NVIC_BASE_ADDRESS + 0x4))


#define NVIC_ICER0 			*((u32*) (NVIC_BASE_ADDRESS + 0x80))
#define NVIC_ICER1 			*((u32*) (NVIC_BASE_ADDRESS + 0x84))


#define NVIC_ISPR0 			*((u32*) (NVIC_BASE_ADDRESS + 0x100))
#define NVIC_ISPR1 			*((u32*) (NVIC_BASE_ADDRESS + 0x104))

#define NVIC_ICPR0 			*((u32*) (NVIC_BASE_ADDRESS + 0x180))
#define NVIC_ICPR1 			*((u32*) (NVIC_BASE_ADDRESS + 0x184))

#define NVIC_IABR0 			*((volatile u32*) (NVIC_BASE_ADDRESS + 0x200))
#define NVIC_IABR1 			*((volatile u32*) (NVIC_BASE_ADDRESS + 0x204))




#endif