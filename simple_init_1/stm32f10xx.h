/**
 * @file stm32f10xx.h
 * @author Harish Kumar Shivaramappa (harishkumarsedu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef stm32f10xx__
#define stm32f10xx__
#include <stdint.h>


#define RCC_BASE 0x40021000 // RCC base Address 

#define GPIO_PORTC_BASE 0x40011000 // port C base address 

#define GPIO_CRH_REGISTER(x) (*(volatile uint32_t *)(x + 0x4))
#define GPIO_CHR_MODE_MASK(x) (0x3 << ((x - 8) * 4))
#define GPIO_CHR_MODE_OUTPUT(x) (0x1 << ((x - 8) * 4))


#define SETBIT(x) (1 << x)


typedef struct 
{   
    volatile uint32_t CRL ;              // 0x00
    volatile uint32_t CFGR ;            //0x04
    volatile uint32_t CIR ;            //0x08
    volatile uint32_t APB2RSTR ;      //0x0c
    volatile uint32_t APB1RSTR ;     //0x10
    volatile uint32_t AHBENR;       //0x14
    volatile uint32_t APB2ENR ;    //0x18
    volatile uint32_t APB1ENR ;   //0x1c
    volatile uint32_t BDCR ;     //0x20
    volatile uint32_t CSR ;     //0x24
    volatile uint32_t AHBSTR ; //0x28
    volatile uint32_t CFGR2 ; //0x2c

}RCC_Typedef;

#define RCC ((RCC_Typedef *) (RCC_BASE))

typedef struct 
{   
    volatile uint32_t CRL ;          // 0x00
    volatile uint32_t CRH ;         //0x04
    volatile uint32_t IDR ;        //0x08
    volatile uint32_t ODR ;       //0x0c
    volatile uint32_t BSRR ;     //0x10
    volatile uint32_t BRR;      //0x14
    volatile uint32_t LCKR ;   //0x18

}GPIOC_Typedef;

#define GPIOC ((GPIOC_Typedef *) (GPIO_PORTC_BASE))


#endif