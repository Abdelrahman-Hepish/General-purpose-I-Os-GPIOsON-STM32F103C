/*******************************************************************************/
/*  Author        :       Abdelrahman Mohammed Hepish                          */ 
/*  File name     :       RCC_private.h                                        */
/*  Version       :       1.0                                                  */ 
/*  Date          :       11/21/2020                                           */
/*  Github        :       https://github.com/Abdelrahman-Hepish                */ 
/*******************************************************************************/

#ifndef __GPIO_PRIVATE_H__
#define __GPIO_PRIVATE_H__

#define  GPIO_Port_A_BASE     0x40010800
#define  GPIO_Port_B_BASE     0x40010C00
#define  GPIO_Port_C_BASE     0x40011000

#define  GPIOx_CRL_OFFSET     0X00 
#define  GPIOx_CRH_OFFSET     0X04
#define  GPIOx_IDR_OFFSET     0x08
#define  GPIOx_ODR_OFFSET     0x0C
#define  GPIOx_BSRR_OFFSET    0X10
#define  GPIOx_BRR_OFFSET     0X14 
#define  GPIOx_LCKR_OFFSET    0X18 

/* PORT A */                                   
#define PORTA_CRL                              *((volatile u32*) (GPIO_Port_A_BASE + GPIOx_CRL_OFFSET) )
#define PORTA_CRH                              *((volatile u32*) (GPIO_Port_A_BASE + GPIOx_CRH_OFFSET) )
#define PORTA_IDR                              *((volatile u32*) (GPIO_Port_A_BASE + GPIOx_IDR_OFFSET) )
#define PORTA_ODR                              *((volatile u32*) (GPIO_Port_A_BASE + GPIOx_ODR_OFFSET) )
#define PORTA_BSRR                             *((volatile u32*) (GPIO_Port_A_BASE + GPIOx_BSRR_OFFSET))
#define PORTA_BRR                              *((volatile u32*) (GPIO_Port_A_BASE + GPIOx_BRR_OFFSET) )
#define PORTA_LCKR                             *((volatile u32*) (GPIO_Port_A_BASE + GPIOx_LCKR_OFFSET))

/* PORT B */                                   
#define PORTB_CRL                              *((volatile u32*) (GPIO_Port_B_BASE + GPIOx_CRL_OFFSET) )
#define PORTB_CRH                              *((volatile u32*) (GPIO_Port_B_BASE + GPIOx_CRH_OFFSET) )
#define PORTB_IDR                              *((volatile u32*) (GPIO_Port_B_BASE + GPIOx_IDR_OFFSET) )
#define PORTB_ODR                              *((volatile u32*) (GPIO_Port_B_BASE + GPIOx_ODR_OFFSET) )
#define PORTB_BSRR                             *((volatile u32*) (GPIO_Port_B_BASE + GPIOx_BSRR_OFFSET))
#define PORTB_BRR                              *((volatile u32*) (GPIO_Port_B_BASE + GPIOx_BRR_OFFSET) )
#define PORTB_LCKR                             *((volatile u32*) (GPIO_Port_B_BASE + GPIOx_LCKR_OFFSET))

/* PORT C */                                   
#define PORTC_CRL                              *((volatile u32*) (GPIO_Port_C_BASE + GPIOx_CRL_OFFSET) )
#define PORTC_CRH                              *((volatile u32*) (GPIO_Port_C_BASE + GPIOx_CRH_OFFSET) )
#define PORTC_IDR                              *((volatile u32*) (GPIO_Port_C_BASE + GPIOx_IDR_OFFSET) )
#define PORTC_ODR                              *((volatile u32*) (GPIO_Port_C_BASE + GPIOx_ODR_OFFSET) )
#define PORTC_BSRR                             *((volatile u32*) (GPIO_Port_C_BASE + GPIOx_BSRR_OFFSET))
#define PORTC_BRR                              *((volatile u32*) (GPIO_Port_C_BASE + GPIOx_BRR_OFFSET) )
#define PORTC_LCKR                             *((volatile u32*) (GPIO_Port_C_BASE + GPIOx_LCKR_OFFSET))
/* PIN MODE */
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

#define SET_GPIO_MODE(REG,PIN,VAL)   (REG |= (VAL<<(PIN*4)))
#define SET_GPIO_CNG(REG,PIN,VAL)    (REG |= (VAL<<((PIN*4)+2)))

typedef enum
{
  PORT_A_CRL ,
  PORT_A_CRH ,
  PORT_B_CRL ,
  PORT_B_CRH ,
  PORT_C_CRL ,
  PORT_C_CRH ,
}PORTX_CR;

#endif //__GPIO_PRIVATE_H__
