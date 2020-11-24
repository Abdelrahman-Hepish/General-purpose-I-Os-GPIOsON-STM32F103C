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

void GPIO_InitPinConfig(tPort port ,u8 pin ,tPinMode pin_mode_key ,tPinConfig pin_config_key )
{
	PORTX_CR  port_x_CRX = PORT_A_CRL ;
	/* change settings of selected scope of the port */
    switch(port)
	{
		case PORT_A :
		if(pin <=7 && pin >= 0) // PORTA_CRL
		{
			port_x_CRX = PORT_A_CRL ;
		}else if (pin <= 15 && pin >= 8) // PORTA_CRH
		{
			port_x_CRX = PORT_A_CRH ;
			pin -= 8 ;
		}
		break ; 
		case PORT_B :
		if(pin <=7 && pin >= 0) // PORTB_CRL
		{
			port_x_CRX = PORT_B_CRL ;
		}else if (pin <= 15 && pin >= 8) // PORTB_CRH
		{
			port_x_CRX = PORT_B_CRH ;
			pin -= 8 ;
		}
		break ;
		case PORT_C :
		if(pin <=15 && pin >= 13) // i don't know which register i has to choose between (PORTC_CRL or PORTC_CRH)
		{
			port_x_CRX = PORT_C_CRH ;
			pin -= 8 ;
		}
		break ;
		default :
		/* should not be here */
		break ; 
     }
    /* reset the scope of the pin */
   /* set the mode and the configuration */
   switch (port_x_CRX)
   {
     case PORT_A_CRL :
    	              CLEAR_NIBBLE(PORTA_CRL,pin) ;
    	              SET_GPIO_MODE(PORTA_CRL,pin,pin_mode_key) ;
    	              SET_GPIO_CNG(PORTA_CRL,pin,pin_config_key ) ;
    	              break;
     case PORT_A_CRH :
    	              CLEAR_NIBBLE(PORTA_CRH,pin) ;
                      SET_GPIO_MODE(PORTA_CRH,pin,pin_mode_key) ;
                      SET_GPIO_CNG(PORTA_CRH,pin,pin_config_key ) ;
                      break;
     case PORT_B_CRL :
    	              CLEAR_NIBBLE(PORTB_CRL,pin) ;
    	              SET_GPIO_MODE(PORTB_CRL,pin,pin_mode_key) ;
    	              SET_GPIO_CNG(PORTB_CRL,pin,pin_config_key ) ;
    	              break;
     case PORT_B_CRH :
    	              CLEAR_NIBBLE(PORTB_CRH,pin) ;
    	              SET_GPIO_MODE(PORTB_CRH,pin,pin_mode_key) ;
                      SET_GPIO_CNG(PORTB_CRH,pin,pin_config_key ) ;
                      break;
     case PORT_C_CRL :
    	              break;
     case PORT_C_CRH :
    	              CLEAR_NIBBLE(PORTC_CRH,pin) ;
    	              SET_GPIO_MODE(PORTC_CRH,pin,pin_mode_key) ;
					  SET_GPIO_CNG(PORTC_CRH,pin,pin_config_key ) ;
					  break;
     default          :
    	              /* should not be here */
    	              break;
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
