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


#define GPIOA_RCC_APB2ENR_ENABLE        ((uint32_t)(1U << 2))
#define GPIOB_RCC_APB2ENR_ENABLE        ((uint32_t)(1U << 3))
#define GPIOC_RCC_APB2ENR_ENABLE        ((uint32_t)(1U << 4))
#define GPIOD_RCC_APB2ENR_ENABLE        ((uint32_t)(1U << 5))
#define GPIOE_RCC_APB2ENR_ENABLE        ((uint32_t)(1U << 6))
#define GPIOF_RCC_APB2ENR_ENABLE        ((uint32_t)(1U << 7))
#define GPIOG_RCC_APB2ENR_ENABLE        ((uint32_t)(1U << 8))

#define ADC1_RCC_APB2ENR_ENABLE         ((uint32_t)(1U << 9))
#define TIM1_RCC_APB2ENR_ENABLE         ((uint32_t)(1U << 11))
#define SPI1_RCC_APB2ENR_ENABLE         ((uint32_t)(1U << 12))
#define USART1_RCC_APB2ENR_ENABLE       ((uint32_t)(1U << 14))

#define TIM15_RCC_APB2ENR_ENABLE        ((uint32_t)(1U << 16))
#define TIM16_RCC_APB2ENR_ENABLE        ((uint32_t)(1U << 17))
#define TIM17_RCC_APB2ENR_ENABLE        ((uint32_t)(1U << 18))


#define TIM2_RCC_APB1ENR_ENABLE        ((uint32_t)(1U << 0))
#define TIM3_RCC_APB1ENR_ENABLE        ((uint32_t)(1U << 1))
#define TIM4_RCC_APB1ENR_ENABLE        ((uint32_t)(1U << 2))
#define TIM5_RCC_APB1ENR_ENABLE        ((uint32_t)(1U << 3))
#define TIM6_RCC_APB1ENR_ENABLE        ((uint32_t)(1U << 4))
#define TIM7_RCC_APB1ENR_ENABLE        ((uint32_t)(1U << 5))
#define TIM12_RCC_APB1ENR_ENABLE       ((uint32_t)(1U << 6))
#define TIM13_RCC_APB1ENR_ENABLE       ((uint32_t)(1U << 7))
#define TIM14_RCC_APB1ENR_ENABLE       ((uint32_t)(1U << 8))


#define USART2_RCC_APB1ENR_ENABLE      ((uint32_t)(1U << 17))
#define USART3_RCC_APB1ENR_ENABLE      ((uint32_t)(1U << 18))
#define USART4_RCC_APB1ENR_ENABLE      ((uint32_t)(1U << 19))
#define USART5_RCC_APB1ENR_ENABLE      ((uint32_t)(1U << 20))

#define I2C1_RCC_APB1ENR_ENABLE        ((uint32_t)(1U << 21))
#define I2C2_RCC_APB1ENR_ENABLE        ((uint32_t)(1U << 22))


#define CECEN_RCC_APB1ENR_ENABLE        ((uint32_t)(1U << 30))
#define DACEN_RCC_APB1ENR_ENABLE        ((uint32_t)(1U << 29))
#define PWREN_RCC_APB1ENR_ENABLE        ((uint32_t)(1U << 28))
#define BKPEN_RCC_APB1ENR_ENABLE        ((uint32_t)(1U << 27))



#define SystemCoreClock  (uint32_t)16000000

#define RCC_BASE 0x40021000 // RCC base Address 

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

}RCC_TypeDef;

#define RCC ((RCC_TypeDef *) (RCC_BASE))


void RCC_APB2ENR_Init( uint32_t PheripherlClockEnable);
void RCC_APB1ENR_Init( uint32_t PheripherlClockEnable);

#endif