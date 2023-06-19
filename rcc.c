/**
 * @file rcc.c
 * @author Harish Kumar Shivaramappa (harishkumarsedu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "hal/rcc.h"
#include "hal/int_types.h"
#include "hal/gpio.h"

void RCC_APB2ENR_Init(uint32_t PheripherlClockEnable)
{
    // BIT_SET(BusReg->APB2ENR ,value);
    RCC->APB2ENR|= ~ PheripherlClockEnable;
    RCC->APB2ENR|=   PheripherlClockEnable;
}

void RCC_APB1ENR_Init(uint32_t PheripherlClockEnable)
{
    // BIT_SET(BusReg->APB2ENR ,value);
    RCC->APB1ENR|= ~ PheripherlClockEnable;
    RCC->APB1ENR|=   PheripherlClockEnable;
}