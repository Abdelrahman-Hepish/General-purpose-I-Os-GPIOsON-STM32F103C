/*******************************************************************************/
/*  Author        :       Abdelrahman Mohammed Hepish                          */
/*  File name     :       RCC_config.h                                         */  
/*  Version       :       1.0                                                  */ 
/*  Date          :       11/21/2020                                           */
/*  Github        :       https://github.com/Abdelrahman-Hepish                */ 
/*******************************************************************************/
#ifndef  __GPIO_H__
#define  __GPIO_H__
typedef enum 
{
	INPUT        ,
	OUTPUT_10MHZ ,
    OUTPUT_2MHZ  ,
    OUTPUT_50MHZ
}tPinMode ;
typedef enum
{
  PORT_A ,
  PORT_B ,
  PORT_C
}tPort ;
typedef enum 
{
	INPUT_ANALOG         ,
	INPUT_FLOATING       ,
    INPUT_PULL_RES       ,  // for pull down make PxODR = 0 , and for pull up make PxODR = 1
	GP_OUTPUT_PUSH_PULL  ,
	GP_OUTPUT_OPEN_DRAIN ,
    AF_OUTPUT_PUSH_PULL  ,
	AF_OUTPUT_OPEN_DRAIN
}tPinConfig ;
typedef enum 
{
	PIN_LOW = 0  ,
	PIN_HIGH
}tPinState ;
#endif // __GPIO_H__
