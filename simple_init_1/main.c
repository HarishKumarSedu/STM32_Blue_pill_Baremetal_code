
#include <stdint.h>
#include "stm32f10xx.h"


#define GPIO_BLINK_NUM 13

int main() {

    RCC->APB2ENR |= SETBIT(4);

    // Configure GPIO C pin 13 as output.
    GPIOC->CRH &= ~(GPIO_CHR_MODE_MASK(GPIO_BLINK_NUM));
    GPIOC->CRH |= GPIO_CHR_MODE_OUTPUT(GPIO_BLINK_NUM);

    for (;;) {
        // Set the output bit.
        GPIOC->ODR ^= SETBIT(GPIO_BLINK_NUM); // Xor bitwise to perform teh inversoin of the value
        for (uint32_t i = 0; i < 40000; ++i) {}
        // Reset it again.
        GPIOC->ODR ^= SETBIT(GPIO_BLINK_NUM); // Xor Toggle the value 
        for (uint32_t i = 0; i < 4000000; ++i) {}
    }

    return 0;
}