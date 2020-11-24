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

void GPIO_InitPinConfig(tPort port ,u8 pin ,tPinMode pin_mode ,tPinConfig pin_config ) ;
void GPIO_SetPintState(tPort port , u8 pin ,tPinState state );
tPinState GPIO_GetPinState (tPort port , u8 pin );


#endif // __GPIO_INTERFACING_H__
