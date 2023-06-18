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

void RCC_GPIO_Init(RCC_TypeDef* BusReg, uint32_t value)
{
    BIT_SET(BusReg->APB2ENR ,value);
}