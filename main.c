
#include <stdint.h>
#include "hal/rcc.h"
#include "hal/int_types.h"
#include "hal/gpio.h"
#include "hal/io.h"


#define GPIO_BLINK_NUM 13


int main() {

    BIT_SET(rcc->APB2ENR ,4);
    // Configure GPIO C pin 13 as output.
    GPIOC->CRH &= ~(GPIO_CHR_MODE_MASK(GPIO_BLINK_NUM));
    GPIOC->CRH |= GPIO_CHR_MODE_OUTPUT(GPIO_BLINK_NUM);

    for (;;) {
        // Set the output bit.
        BIT_SET(GPIOC->ODR ,GPIO_BLINK_NUM); // Xor bitwise to perform teh inversoin of the value
        for (uint32_t i = 0; i < 40000; ++i) {}
        // Reset it again.
        BIT_CLR(GPIOC->ODR ,GPIO_BLINK_NUM); // Xor Toggle the value 
        for (uint32_t i = 0; i < 40000; ++i) {}
    }

    return 0;
}