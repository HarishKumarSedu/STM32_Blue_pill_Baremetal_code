/**
 * @file rcc.h
 * @author Harish Kumar Shivaramappa (harishkumarsedu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef RCC_H__
#define RCC_H__

#include "int_types.h"
#include "gpio.h"
#include "io.h"

#define RCC_BASE 0x40021000 // RCC base Address 

#define GPIO_PORTC_BASE 0x40011000 // port C base address 

#define GPIO_CRH_REGISTER(x) (*(volatile uint32_t *)(x + 0x4))
#define GPIO_CHR_MODE_MASK(x) (0x3 << ((x - 8) * 4))
#define GPIO_CHR_MODE_OUTPUT(x) (0x1 << ((x - 8) * 4))



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

}rcc_typedef;

#define rcc ((rcc_typedef *) (RCC_BASE))

// void rcc_init(rcc_typedef * rcc,io io);

#endif