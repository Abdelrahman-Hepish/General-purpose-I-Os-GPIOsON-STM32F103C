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
		if(pin <PORT_BREAK && pin >= 0) // PORTA_CRL
		{
			port_x_CRX = PORT_A_CRL ;
		}else if (pin <= PORT_SIZE && pin >= PORT_BREAK) // PORTA_CRH
		{
			port_x_CRX = PORT_A_CRH ;
			pin -= PORT_BREAK ;
		}
		break ; 
		case PORT_B :
		if(pin <PORT_BREAK && pin >= 0) // PORTB_CRL
		{
			port_x_CRX = PORT_B_CRL ;
		}else if (pin <= PORT_SIZE && pin >= PORT_BREAK) // PORTB_CRH
		{
			port_x_CRX = PORT_B_CRH ;
			pin -= PORT_BREAK ;
		}
		break ;
		case PORT_C :
		if(pin <PORT_BREAK && pin >= 0) // PORTB_CRL
		{
			port_x_CRX = PORT_C_CRL ;
		}else if (pin <= PORT_SIZE && pin >= PORT_BREAK) // PORTB_CRH
		{
			port_x_CRX = PORT_C_CRH ;
			pin -= PORT_BREAK ;
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
    	              SET_GPIO_CNFG(PORTA_CRL,pin,pin_config_key ) ;
    	              break;
     case PORT_A_CRH :
    	              CLEAR_NIBBLE(PORTA_CRH,pin) ;
                      SET_GPIO_MODE(PORTA_CRH,pin,pin_mode_key) ;
                      SET_GPIO_CNFG(PORTA_CRH,pin,pin_config_key ) ;
                      break;
     case PORT_B_CRL :
    	              CLEAR_NIBBLE(PORTB_CRL,pin) ;
    	              SET_GPIO_MODE(PORTB_CRL,pin,pin_mode_key) ;
    	              SET_GPIO_CNFG(PORTB_CRL,pin,pin_config_key ) ;
    	              break;
     case PORT_B_CRH :
    	              CLEAR_NIBBLE(PORTB_CRH,pin) ;
    	              SET_GPIO_MODE(PORTB_CRH,pin,pin_mode_key) ;
    	              SET_GPIO_CNFG(PORTB_CRH,pin,pin_config_key ) ;
                      break;
     case PORT_C_CRL :
    	              CLEAR_NIBBLE(PORTC_CRL,pin) ;
    	     	      SET_GPIO_MODE(PORTC_CRL,pin,pin_mode_key) ;
    	     	     SET_GPIO_CNFG(PORTC_CRL,pin,pin_config_key ) ;
    	              break;
     case PORT_C_CRH :
    	              CLEAR_NIBBLE(PORTC_CRH,pin) ;
    	              SET_GPIO_MODE(PORTC_CRH,pin,pin_mode_key) ;
    	              SET_GPIO_CNFG(PORTC_CRH,pin,pin_config_key ) ;
					  break;
     default          :
    	              /* should not be here */
    	              break;
	}
}	
void GPIO_InitPortConfig(tPort port ,tPinMode port_mode_key ,tPinConfig port_config_key )
{
	u8 pin_iterator = 0 ;
	switch (port)
	{case PORT_A :
		CLERA_REGISTER(PORTA_CRL) ;
		CLERA_REGISTER(PORTA_CRH) ;
		for(pin_iterator = 0 ; pin_iterator <= PORT_SIZE ;pin_iterator ++)
		{
			if(pin_iterator <PORT_BREAK)
			{
				SET_GPIO_MODE(PORTA_CRL,pin_iterator,port_mode_key) ;
				SET_GPIO_CNFG(PORTA_CRL,pin_iterator,port_config_key ) ;
			}else
			{
				SET_GPIO_MODE(PORTA_CRH,(pin_iterator-PORT_BREAK),port_mode_key) ;
				SET_GPIO_CNFG(PORTA_CRH,(pin_iterator-PORT_BREAK),port_config_key ) ;
			}
		}
		break ;
	case PORT_B :
		CLERA_REGISTER(PORTB_CRL) ;
		CLERA_REGISTER(PORTB_CRH) ;
		for(pin_iterator = 0 ; pin_iterator <= PORT_SIZE ;pin_iterator ++)
		{
			if(pin_iterator <PORT_BREAK)
			{
				SET_GPIO_MODE(PORTB_CRL,pin_iterator,port_mode_key) ;
				SET_GPIO_CNFG(PORTB_CRL,pin_iterator,port_config_key ) ;
			}else
			{
				SET_GPIO_MODE(PORTB_CRH,(pin_iterator-PORT_BREAK),port_mode_key) ;
				SET_GPIO_CNFG(PORTB_CRH,(pin_iterator-PORT_BREAK),port_config_key ) ;
			}
	    }
		break  ;
	case PORT_C :
		CLERA_REGISTER(PORTC_CRL) ;
		CLERA_REGISTER(PORTC_CRH) ;
		for(pin_iterator = 0 ; pin_iterator <= PORT_SIZE ;pin_iterator ++)
		{
			if(pin_iterator <PORT_BREAK)
			{
				SET_GPIO_MODE(PORTC_CRL,pin_iterator,port_mode_key) ;
				SET_GPIO_CNFG(PORTC_CRL,pin_iterator,port_config_key ) ;
			}else
			{
				SET_GPIO_MODE(PORTC_CRH,(pin_iterator-PORT_BREAK),port_mode_key) ;
				SET_GPIO_CNFG(PORTC_CRH,(pin_iterator-PORT_BREAK),port_config_key ) ;
			}
		}
		break ;
	}
}
void GPIO_InitHalfPortConfig(tPort port ,tHalfPart_Port part_of_port,tPinMode port_mode_key ,tPinConfig port_config_key )
{
	PORTX_CR  port_x_CRX = PORT_A_CRL ;
	u8 pin_iterator = 0 ;
	switch(port)
	{
		case PORT_A :
             if(part_of_port == LOW_PART)
             {
            	 port_x_CRX = PORT_A_CRL ;
             }else if (part_of_port == HIGH_PART)
			 {
            	 port_x_CRX = PORT_A_CRH ;
			 }
		break ;
		case PORT_B :
			if(part_of_port == LOW_PART)
			{
			     port_x_CRX = PORT_B_CRL ;
			}else if (part_of_port == HIGH_PART)
			{
			     port_x_CRX = PORT_B_CRH ;
			}
		break ;
		case PORT_C :
			if(part_of_port == LOW_PART)
			{
				port_x_CRX = PORT_C_CRL ;
			}else if (part_of_port == HIGH_PART)
			{
				port_x_CRX = PORT_C_CRH ;
			}
		break ;
		default :
		/* should not be here */
		break ;
	}
	switch (port_x_CRX)
	   {
	     case PORT_A_CRL :
	    	              CLERA_REGISTER(PORTA_CRL) ;
	    	              for(pin_iterator = 0 ; pin_iterator  < PORT_BREAK ;pin_iterator ++)
	    	              {
	    	              	 SET_GPIO_MODE(PORTA_CRL,pin_iterator,port_mode_key) ;
	    	              	 SET_GPIO_CNFG(PORTA_CRL,pin_iterator,port_config_key ) ;
	    	              }
	     break;
	     case PORT_A_CRH :
	    	             CLERA_REGISTER(PORTA_CRH) ;
	    	              for(pin_iterator = 0 ; pin_iterator < PORT_BREAK ;pin_iterator ++)
	    	              {
	    	              	SET_GPIO_MODE(PORTA_CRH,pin_iterator,port_mode_key) ;
	    	              	SET_GPIO_CNFG(PORTA_CRH,pin_iterator,port_config_key ) ;
	    	              }
	     break;
	     case PORT_B_CRL :
	    	              CLERA_REGISTER(PORTB_CRL) ;
	    	 	    	  for(pin_iterator = 0 ; pin_iterator < PORT_BREAK ;pin_iterator ++)
	    	 	    	  {
	    	 	    	    SET_GPIO_MODE(PORTB_CRL,pin_iterator,port_mode_key) ;
	    	 	    	    SET_GPIO_CNFG(PORTB_CRL,pin_iterator,port_config_key ) ;
	    	 	    	  }
	     break;
	     case PORT_B_CRH :
	    	              CLERA_REGISTER(PORTB_CRH) ;
	    	 	    	  for(pin_iterator = 0 ; pin_iterator < PORT_BREAK ;pin_iterator ++)
	    	 	    	  {
	    	 	    	 	SET_GPIO_MODE(PORTB_CRH,pin_iterator,port_mode_key) ;
	    	 	    	 	SET_GPIO_CNFG(PORTB_CRH,pin_iterator,port_config_key ) ;
	    	 	    	  }
	     break;
	     case PORT_C_CRL :
	    	              CLERA_REGISTER(PORTC_CRL) ;
	    	 	    	  for(pin_iterator = 0 ; pin_iterator < PORT_BREAK ;pin_iterator ++)
	    	 	    	  {
	    	 	    	 	 SET_GPIO_MODE(PORTC_CRL,pin_iterator,port_mode_key) ;
	    	 	    	 	SET_GPIO_CNFG(PORTC_CRL,pin_iterator,port_config_key ) ;
	    	 	    	  }
	     break;
	     case PORT_C_CRH :
                          CLERA_REGISTER(PORTC_CRH) ;
	                 	  for(pin_iterator = 0 ; pin_iterator < PORT_BREAK ;pin_iterator ++)
	                  	  {
	    	 	             SET_GPIO_MODE(PORTC_CRH,pin_iterator,port_mode_key) ;
	    	 	            SET_GPIO_CNFG(PORTC_CRH,pin_iterator,port_config_key ) ;
	    	             }
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
void GPIO_SetPorttState(tPort port ,u16 port_state  )
{
	switch(port)
		{
			case PORT_A :
			PORTA_ODR  = port_state ;
			break ;
			case PORT_B :
			PORTB_ODR  = port_state ;
			break ;
			case PORT_C :
			PORTC_ODR  = port_state ;
			break ;
			default :
			/* should not be here */
			break ;
		}
}
void GPIO_SetHalfPorttState(tPort port ,tHalfPart_Port part_of_port, u8 port_state )
{
	switch(port)
	{
	  case PORT_A :
		  SET_REGISTER_BYTE(PORTA_ODR,part_of_port,port_state) ;
	  break ;
	  case PORT_B :
		  SET_REGISTER_BYTE(PORTB_ODR,part_of_port,port_state) ;
	  break ;
	  case PORT_C :
		  SET_REGISTER_BYTE(PORTC_ODR,part_of_port,port_state) ;
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
u16 GPIO_GetPortState (tPort port )
{
	u16 ret ;
		switch(port)
		{
			case PORT_A :
			ret = (u16)PORTA_IDR ;
			break ;
			case PORT_B :
			ret = (u16)PORTB_IDR ;
			break ;
			case PORT_C :
			ret = (u16)PORTC_IDR ;
			break ;
			default :
			/* should not be here */
			break ;
		}
		return ret ;
}
/* the bug is in the initalization */
