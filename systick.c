/**
 * @file systick.c
 * @author Harish Kumar Shivaramappa (Harishkumarsedu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdint.h>
#include "hal/io.h"
#include "hal/rcc.h"
#include "hal/systick.h"

static volatile uint32_t msTicks = 0;

void SysTick_Handler() 
{
	msTicks++;
}

static inline void LL_SysTick_Init()
{   
    // This uses the global SystemCoreClock value with the current system clock in Hertz, 
    //dividing it to create the equivalent value for 1 millisecond.
    // Reload value register 
    STK->RVR = (uint32_t)((SystemCoreClock / 1000) - 1);
	
	// Reset the SysTick counter value Register .
	STK->CVR = 0UL;

    // CSR => Bit 2 CLKSOURCE [2]: Clock source selection
    // Selects the timer clock source.
    // 0: External reference clock
    // 1: Processor clock
    BIT_SET(STK->CSR,IO_02);

    // CSR => Bit 1 TICKINT [1]: SysTick exception request enable
    // 0: Counting down to zero does not assert the SysTick exception request
    // 1: Counting down to zero to assert the SysTick exception request.
    BIT_SET(STK->CSR,IO_01);

}

void HAL_Delay(uint32_t ms){

    // CSR => Bit 0 ENABLE [0]: Counter enable
    // Enables the counter. When ENABLE is set to 1, the counter starts counting down. On reaching 0, it sets the COUNTFLAG to
    // 1 and optionally asserts the SysTick depending on the value of TICKINT. It then loads the RELOAD value again, and begins
    // counting.
    // 0: Counter disabled
    // 1: Counter enabled

    LL_SysTick_Init();

    BIT_SET(STK->CSR,IO_00);
    // msTicks = 0;
    uint32_t expected_ticks = msTicks + ms;
	while (msTicks < expected_ticks) ;

    BIT_CLR(STK->CSR,IO_00);
}