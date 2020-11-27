/*******************************************************************************/
/*  Author        :       Abdelrahman Mohammed Hepish                          */
/*  File name     :       GPIO_interfacing.h                                   */
/*  Version       :       1.0                                                  */ 
/*  Date          :       11/21/2020                                           */
/*  Github        :       https://github.com/Abdelrahman-Hepish                */ 
/*******************************************************************************/

#ifndef __GPIO_INTERFACING_H__
#define __GPIO_INTERFACING_H__
#include "GPIO_config.h"
#include "STD_TYPES.h"

void GPIO_InitPinConfig(tPort port ,u8 pin ,tPinMode pin_mode ,tPinConfig pin_config ) ;
void GPIO_InitPortConfig(tPort port ,tPinMode port_mode_key ,tPinConfig port_config_key ) ;
void GPIO_InitHalfPortConfig(tPort port ,tHalfPart_Port part_of_port,tPinMode port_mode_key ,tPinConfig port_config_key ) ;
void GPIO_SetHalfPorttState(tPort port ,tHalfPart_Port part_of_port, u8 port_state ) ;
void GPIO_SetPorttState(tPort port , u16 port_state ) ;
void GPIO_SetPintState(tPort port , u8 pin ,tPinState state );
tPinState GPIO_GetPinState (tPort port , u8 pin );
u16 GPIO_GetPortState (tPort port ) ;


#endif // __GPIO_INTERFACING_H__
