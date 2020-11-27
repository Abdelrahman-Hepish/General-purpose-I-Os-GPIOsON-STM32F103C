/*******************************************************************************/
/*  Author        :       Abdelrahman Mohammed Hepish                          */ 
/*  Version       :       1.0                                                  */ 
/*  Date          :       11/11/2020                                           */
/*  Github        :       https://github.com/Abdelrahman-Hepish                */ 
/*******************************************************************************/
#ifndef  __BIT_MATH_H__
#define __BIT_MATH_H__

#define SET_REGISTER_PIN(REG,PIN,VAL)     (REG = ((REG & (~(1<<PIN))) | (VAL << PIN)))
#define SET_REGISTER_BYTE(REG,HALF,u8_VAL)     ( REG = ( (!HALF) ? ( (REG & (~(0XFF<<0))) | (u8_VAL << 0) ) : ( (REG & (~(0XFF<<8))) | (u8_VAL << 8) ) ) )
#define SET_REGISTER_PIN_1(REG,PIN)       SET_REGISTER_PIN(REG,PIN,1)
#define SET_REGISTER_PIN_0(REG,PIN)       SET_REGISTER_PIN(REG,PIN,0)
#define CLEAR_REGISTER_PIN(REG,PIN)       SET_REGISTER_PIN(REG,PIN,0)

#define CLEAR_NIBBLE(REG,START_NIBBLE)    (REG &= (~(0xf<<(4 * START_NIBBLE))))
#define CLERA_REGISTER(REG)               (REG &= (~(0xffffffff)))
#define CLEAR_BYTE(REG,START_NIBBLE)    (REG &= (~(0xff<<(4 * START_NIBBLE))))

#define READ_REGISTER_PIN(REG,PIN)        ((REG &(1<<PIN))>>(PIN))
#endif //__BIT_MATH_H__
