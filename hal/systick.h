/**
 * @file systick.h
 * @author Harish Kumar Shivaramappa (Harishkumarsedu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SYSTICK_H__
#define SYSTICK_H__

#include <stdint.h>

typedef struct 
{
    volatile uint32_t CSR  ; // 0xE000E010 CSR  SysTick control and status register (STK_CSR)
    volatile uint32_t RVR  ; // 0xE000E014 RVR  SysTick reload value register (STK_RVR)
    volatile uint32_t CVR  ; // 0xE000E018 CVR  SysTick current value register (STK_CVR)
    volatile uint32_t CALIB; // 0xE000E01C CALIB 
} SYSTICK_TypeDef ;

#define SYSTICK_BASE 0xE000E010

#define STK (( SYSTICK_TypeDef *) (SYSTICK_BASE))

void HAL_Delay(uint32_t ms);
void LL_SysTick_Init();


#endif