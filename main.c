
#include <stdint.h>
#include "hal/rcc.h"
#include "hal/int_types.h"
#include "hal/gpio.h"
#include "hal/io.h"


#define GPIO_BLINK_NUM 13
#define delay 40000


int main() {

    BIT_SET(rcc->APB2ENR ,4);
    // Configure GPIO C pin 13 as output.
    GPIOC->CRH &= ~(GPIO_CHR_MODE_MASK(GPIO_BLINK_NUM));
    GPIOC->CRH |= GPIO_CHR_MODE_OUTPUT(GPIO_BLINK_NUM);
    for (;;) {
        // Set the output bit.
        // BIT_SET(GPIOC->ODR ,GPIO_BLINK_NUM); // Xor bitwise to perform teh inversoin of the value
        // gpio_write__pin(GPIOC,GPIO_BLINK_NUM,HIGH);
        // gpio_toggle__pin(GPIOC,GPIO_BLINK_NUM);
        
        for (uint32_t i = 0; i < delay; ++i) {}
        // Reset it again.
        // BIT_CLR(GPIOC->ODR ,GPIO_BLINK_NUM); // Xor Toggle the value 
        // gpio_toggle__pin(GPIOC,GPIO_BLINK_NUM);
        // gpio_write__pin(GPIOC,GPIO_BLINK_NUM,LOW);
        for (uint32_t i = 0; i < delay; ++i) {}
    }

    return 0;
}

// void gpio_write__pin(gpio_typedef* GPIOx, uint16_t GPIO_Pin, gpio_pinstate_t PinState){
//     if (HIGH == PinState){

//         BIT_SET(GPIOx->ODR ,GPIO_Pin);
//     }
//     else if (LOW == PinState)
//     {
//         BIT_CLR(GPIOx->ODR ,GPIO_Pin);
//     }    
// }

    // void gpio_toggle__pin(gpio_typedef* GPIOx, uint16_t GPIO_Pin){
    //         BIT_FLIP(GPIOx->ODR ,GPIO_Pin);
    // }