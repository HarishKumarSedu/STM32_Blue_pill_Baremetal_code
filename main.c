
#include <stdint.h>
#include "hal/rcc.h"
#include "hal/int_types.h"
#include "hal/gpio.h"
#include "hal/io.h"
#include "hal/systick.h"


#define GPIO_BLINK_NUM 13

int main() {

    RCC_GPIO_Init(RCC,4 ); // Enable clock for port C 

    LED_Config();
    for (;;) {

        HAL_GPIO_TogglePin(GPIOC,GPIO_13);
        HAL_Delay(100);
    }

    return 0;
}

