#include "stm32f10xx.h"

static inline void systick_init(uint32_t ticks) {
  if ((ticks - 1) > 0xffffff) return;  // Systick timer is 24 bit
  SYSTICK->LOAD = ticks - 1;
  SYSTICK->VAL = 0;
  SYSTICK->CTRL = SETBIT(0) | SETBIT(1) | SETBIT(2);  // Enable systick
  RCC->APB2ENR |= SETBIT(14);                   // Enable SYSCFG
}

static volatile uint32_t s_ticks; // volatile is important!!
void SysTick_Handler(void) {
  s_ticks++;
}

void delay(unsigned ms) {            // This function waits "ms" milliseconds
 uint32_t until = s_ticks + ms;      // Time in a future when we need to stop
 while (s_ticks < until) (void) 0;   // Loop until then
}