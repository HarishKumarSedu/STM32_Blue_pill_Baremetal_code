
#include <stdint.h>
#include "hal/rcc.h"
#include "hal/int_types.h"
#include "hal/gpio.h"
#include "hal/io.h"


#define GPIO_BLINK_NUM 13
#define delay 40000

void LoopDelay();

int main() {

    RCC_GPIO_Init(RCC,4 ); // Enable clock for port C 

    LED_Config();
    GPIO_Config_C15Input();
    for (;;) {

        if (HIGH == HAL_GPIO_ReadPin(GPIOC,GPIO_15))
        {
            HAL_GPIO_WritePin(GPIOC,GPIO_13,HIGH);
        }
        else
        {  
            HAL_GPIO_WritePin(GPIOC,GPIO_13,LOW); 
        }

        // LoopDelay();
    }

    return 0;
}

void LoopDelay(){
    for (uint32_t i = 0; i < delay; ++i) {}
}