/*******************************************************************************/
/*  Author        :       Abdelrahman Mohammed Hepish                          */ 
/*  File name     :       RCC_program.c                                        */ 
/*  Version       :       1.0                                                  */ 
/*  Date          :       11/11/2020                                           */
/*  Github        :       https://github.com/Abdelrahman-Hepish                */ 
/*******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interfacing.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void GPIO_InitPinConfig(tPort port ,u8 pin ,tPinMode pin_mode ,tPinConfig pin_config ) 
{
    switch(port)
	{
		case PORT_A :
		if(pin <=7 && pin >= 0) // PORTA_CRL
		{
			CLEAR_NIBBLE(PORTA_CRL,pin) ;
            switch(pin_mode)
			{
             case INPUT         : SET_GPIO_MODE(PORTA_CRL,pin,GPIO_MODE_INPUT)       ; break; 
             case OUTPUT_10MHZ  : SET_GPIO_MODE(PORTA_CRL,pin,GPIO_MODE_OUTPUT_10MHZ); break;
             case OUTPUT_2MHZ   : SET_GPIO_MODE(PORTA_CRL,pin,GPIO_MODE_OUTPUT_2MHZ) ; break;
             case OUTPUT_50MHZ  : SET_GPIO_MODE(PORTA_CRL,pin,GPIO_MODE_OUTPUT_50MHZ); break;
             default : /* should not be here */                                        break; 
			}	
            switch(pin_config)
			{
		     case INPUT_ANALOG         : SET_GPIO_CNG(PORTA_CRL,pin,GPIO_CNF_GP_IP_ANALOG     )  ; break ; 
			 case INPUT_FLOATING       : SET_GPIO_CNG(PORTA_CRL,pin,GPIO_CNF_GP_IP_FLOATING   )  ; break ;
			 case INPUT_PULL_RES       : SET_GPIO_CNG(PORTA_CRL,pin,GPIO_CNF_GP_IP_PULL_RES   )  ; break ;
			 case GP_OUTPUT_PUSH_PULL  : SET_GPIO_CNG(PORTA_CRL,pin,GPIO_CNF_GP_OP_PUSH_PULL  )  ; break ;
			 case GP_OUTPUT_OPEN_DRAIN : SET_GPIO_CNG(PORTA_CRL,pin,GPIO_CNF_GP_OP_OPEN_DRAIN )  ; break ;
			 case AF_OUTPUT_PUSH_PULL  : SET_GPIO_CNG(PORTA_CRL,pin,GPIO_CNF_GP_AF_PUSH_PULL  )  ; break ;
			 case AF_OUTPUT_OPEN_DRAIN : SET_GPIO_CNG(PORTA_CRL,pin,GPIO_CNF_GP_AF_OPEN_DRAIN )  ; break ;
			 default                   : /* should not be here */                                  break ;
			}				
		}else if (pin <= 15 && pin >= 8) // PORTA_CRH
		{
			pin -= 8 ;
			CLEAR_NIBBLE(PORTA_CRH,pin) ;
			switch(pin_mode)
			{
				// error was here  
             case INPUT         : SET_GPIO_MODE(PORTA_CRH,pin,GPIO_MODE_INPUT)       ; break; 
             case OUTPUT_10MHZ  : SET_GPIO_MODE(PORTA_CRH,pin,GPIO_MODE_OUTPUT_10MHZ); break;
             case OUTPUT_2MHZ   : SET_GPIO_MODE(PORTA_CRH,pin,GPIO_MODE_OUTPUT_2MHZ) ; break;
             case OUTPUT_50MHZ  : SET_GPIO_MODE(PORTA_CRH,pin,GPIO_MODE_OUTPUT_50MHZ); break;
             default : /* should not be here */                                        break; 
			}	
			switch(pin_config)
			{
		     case INPUT_ANALOG         : SET_GPIO_CNG(PORTA_CRH,pin,GPIO_CNF_GP_IP_ANALOG     )  ; break ; 
			 case INPUT_FLOATING       : SET_GPIO_CNG(PORTA_CRH,pin,GPIO_CNF_GP_IP_FLOATING   )  ; break ;
			 case INPUT_PULL_RES       : SET_GPIO_CNG(PORTA_CRH,pin,GPIO_CNF_GP_IP_PULL_RES   )  ; break ;
			 case GP_OUTPUT_PUSH_PULL  : SET_GPIO_CNG(PORTA_CRH,pin,GPIO_CNF_GP_OP_PUSH_PULL  )  ; break ;
			 case GP_OUTPUT_OPEN_DRAIN : SET_GPIO_CNG(PORTA_CRH,pin,GPIO_CNF_GP_OP_OPEN_DRAIN )  ; break ;
			 case AF_OUTPUT_PUSH_PULL  : SET_GPIO_CNG(PORTA_CRH,pin,GPIO_CNF_GP_AF_PUSH_PULL  )  ; break ;
			 case AF_OUTPUT_OPEN_DRAIN : SET_GPIO_CNG(PORTA_CRH,pin,GPIO_CNF_GP_AF_OPEN_DRAIN )  ; break ;
			 default                   : /* should not be here */                                  break ;
			}
		}
		break ; 
		case PORT_B :
		if(pin <=7 && pin >= 0) // PORTB_CRL
		{
			CLEAR_NIBBLE(PORTB_CRL,pin) ; 
			switch(pin_mode)
			{
             case INPUT         : SET_GPIO_MODE(PORTB_CRL,pin,GPIO_MODE_INPUT)       ; break; 
             case OUTPUT_10MHZ  : SET_GPIO_MODE(PORTB_CRL,pin,GPIO_MODE_OUTPUT_10MHZ); break;
             case OUTPUT_2MHZ   : SET_GPIO_MODE(PORTB_CRL,pin,GPIO_MODE_OUTPUT_2MHZ) ; break;
             case OUTPUT_50MHZ  : SET_GPIO_MODE(PORTB_CRL,pin,GPIO_MODE_OUTPUT_50MHZ); break;
             default : /* should not be here */                                        break; 
			}	
			switch(pin_config)
			{
		     case INPUT_ANALOG         : SET_GPIO_CNG(PORTB_CRL,pin,GPIO_CNF_GP_IP_ANALOG     )  ; break ; 
			 case INPUT_FLOATING       : SET_GPIO_CNG(PORTB_CRL,pin,GPIO_CNF_GP_IP_FLOATING   )  ; break ;
			 case INPUT_PULL_RES       : SET_GPIO_CNG(PORTB_CRL,pin,GPIO_CNF_GP_IP_PULL_RES   )  ; break ;
			 case GP_OUTPUT_PUSH_PULL  : SET_GPIO_CNG(PORTB_CRL,pin,GPIO_CNF_GP_OP_PUSH_PULL  )  ; break ;
			 case GP_OUTPUT_OPEN_DRAIN : SET_GPIO_CNG(PORTB_CRL,pin,GPIO_CNF_GP_OP_OPEN_DRAIN )  ; break ;
			 case AF_OUTPUT_PUSH_PULL  : SET_GPIO_CNG(PORTB_CRL,pin,GPIO_CNF_GP_AF_PUSH_PULL  )  ; break ;
			 case AF_OUTPUT_OPEN_DRAIN : SET_GPIO_CNG(PORTB_CRL,pin,GPIO_CNF_GP_AF_OPEN_DRAIN )  ; break ;
			 default                   : /* should not be here */                                  break ;
			}
		}else if (pin <= 15 && pin >= 8) // PORTB_CRH
		{
			pin -= 8 ;
			CLEAR_NIBBLE(PORTB_CRH,pin) ;
			switch(pin_mode)
			{
             case INPUT         : SET_GPIO_MODE(PORTB_CRH,pin,GPIO_MODE_INPUT)       ; break; 
             case OUTPUT_10MHZ  : SET_GPIO_MODE(PORTB_CRH,pin,GPIO_MODE_OUTPUT_10MHZ); break;
             case OUTPUT_2MHZ   : SET_GPIO_MODE(PORTB_CRH,pin,GPIO_MODE_OUTPUT_2MHZ) ; break;
             case OUTPUT_50MHZ  : SET_GPIO_MODE(PORTB_CRH,pin,GPIO_MODE_OUTPUT_50MHZ); break;
             default : /* should not be here */                                        break; 
			}
			switch(pin_config)
			{
		     case INPUT_ANALOG         : SET_GPIO_CNG(PORTB_CRH,pin,GPIO_CNF_GP_IP_ANALOG     )  ; break ; 
			 case INPUT_FLOATING       : SET_GPIO_CNG(PORTB_CRH,pin,GPIO_CNF_GP_IP_FLOATING   )  ; break ;
			 case INPUT_PULL_RES       : SET_GPIO_CNG(PORTB_CRH,pin,GPIO_CNF_GP_IP_PULL_RES   )  ; break ;
			 case GP_OUTPUT_PUSH_PULL  : SET_GPIO_CNG(PORTB_CRH,pin,GPIO_CNF_GP_OP_PUSH_PULL  )  ; break ;
			 case GP_OUTPUT_OPEN_DRAIN : SET_GPIO_CNG(PORTB_CRH,pin,GPIO_CNF_GP_OP_OPEN_DRAIN )  ; break ;
			 case AF_OUTPUT_PUSH_PULL  : SET_GPIO_CNG(PORTB_CRH,pin,GPIO_CNF_GP_AF_PUSH_PULL  )  ; break ;
			 case AF_OUTPUT_OPEN_DRAIN : SET_GPIO_CNG(PORTB_CRH,pin,GPIO_CNF_GP_AF_OPEN_DRAIN )  ; break ;
			 default                   : /* should not be here */                                  break ;
			}
		}
		break ;
		case PORT_C :
		if(pin <=15 && pin >= 13) // i don't know which register i has to choose between (PORTC_CRL or PORTC_CRH)
		{
			
		}
		break ;
		default :
		/* should not be here */
		break ; 
	}
}	
void GPIO_SetPintState(tPort port , u8 pin ,tPinState state )
{
	switch(port)
	{
		case PORT_A :
		if(pin <=15 && pin >= 0) 
		{
			SET_REGISTER_PIN(PORTA_ODR,pin,state) ; 
		}
		break ; 
		case PORT_B :
		if(pin <=15 && pin >= 0) 
		{
			SET_REGISTER_PIN(PORTB_ODR,pin,state) ;
		}
		break ;
		case PORT_C :
		if(pin <=15 && pin >= 13) 
		{
			SET_REGISTER_PIN(PORTB_ODR,pin,state) ;
		}
		break ;
		default :
		/* should not be here */
		break ; 
	}
}	
tPinState GPIO_GetPinState (tPort port , u8 pin )
{
	tPinState ret ; 
	switch(port)
	{
		case PORT_A :
		if(pin <=15 && pin >= 0) 
		{
			ret = READ_REGISTER_PIN(PORTA_IDR,pin) ; 
		}
		break ; 
		case PORT_B :
		if(pin <=15 && pin >= 0) 
		{
			ret = READ_REGISTER_PIN(PORTB_IDR,pin) ; 
		}
		break ;
		case PORT_C :
		if(pin <=15 && pin >= 13) 
		{
			ret = READ_REGISTER_PIN(PORTC_IDR,pin) ;
		}
		break ;
		default :
		/* should not be here */
		break ; 
	}
	return ret ; 
}
