/*******************************************************************************/
/*  Author        :       Abdelrahman Mohammed Hepish                          */
/*  File name     :       RCC_config.h                                         */  
/*  Version       :       1.0                                                  */ 
/*  Date          :       11/21/2020                                           */
/*  Github        :       https://github.com/Abdelrahman-Hepish                */ 
/*******************************************************************************/
#ifndef  __GPIO_H__
#define  __GPIO_H__
#define GPIO_MODE_INPUT                   0B00
#define GPIO_MODE_OUTPUT_10MHZ            0B01
#define GPIO_MODE_OUTPUT_2MHZ             0B10
#define GPIO_MODE_OUTPUT_50MHZ            0B11
/* PIN CONFIG */
#define GPIO_CNF_GP_OP_PUSH_PULL          0B00
#define GPIO_CNF_GP_OP_OPEN_DRAIN         0B01
#define GPIO_CNF_GP_AF_PUSH_PULL          0B10
#define GPIO_CNF_GP_AF_OPEN_DRAIN         0B11
#define GPIO_CNF_GP_IP_ANALOG             0B00
#define GPIO_CNF_GP_IP_FLOATING           0B01
#define GPIO_CNF_GP_IP_PULL_RES           0B10
typedef enum 
{
	INPUT         =  0B00  ,
	OUTPUT_10MHZ  =  0B01  ,
    OUTPUT_2MHZ   =  0B10  ,
    OUTPUT_50MHZ  =  0B11
}tPinMode ;
typedef enum
{
  PORT_A ,
  PORT_B ,
  PORT_C
}tPort ;
typedef enum 
{
	INPUT_ANALOG         = 0B00  ,
	INPUT_FLOATING       = 0B01  ,
    INPUT_PULL_RES       = 0B10  ,  // for pull down make PxODR = 0 , and for pull up make PxODR = 1
	GP_OUTPUT_PUSH_PULL  = 0B00  ,
	GP_OUTPUT_OPEN_DRAIN = 0B01  ,
    AF_OUTPUT_PUSH_PULL  = 0B10  ,
	AF_OUTPUT_OPEN_DRAIN = 0B11
}tPinConfig ;
typedef enum 
{
	PIN_LOW = 0  ,
	PIN_HIGH
}tPinState ;
#endif // __GPIO_H__
