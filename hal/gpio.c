/**
 * @file gpio.c
 * @author Harish Kumar Shivaramppa  (harishkumarsedu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// ###################################################################################
// ###################################################################################

#include "gpio.h"
#include "io.h"

static gpio_typedef *const gpios[] = {
                                        GPIOA,
                                        GPIOB,
                                        GPIOC,
                                        GPIOD,
                                        GPIOE,
                                        GPIOF,
};

/**
 * @brief gpio_write__pin
 * 
 * @param GPIOx 
 * @param GPIO_Pin 
 * @param PinState 
 */
// void gpio_write__pin(gpio_typedef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState){
//     // BIT_SET(GPIOx->ODR ,GPIO_Pin);
// }

void gpio_toggle__pin(gpio_typedef* GPIOx, uint16_t GPIO_Pin){
            BIT_FLIP(GPIOx->ODR ,GPIO_Pin);
}