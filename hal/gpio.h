/**
 * @file gpio.h
 * @author Harish Kumar Shivaramppa  (harishkumarsedu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef GPIO_H__
#define GPIO_H__

#include "int_types.h"
#include "io.h"


typedef struct 
{   
    volatile uint32_t CRL ;          // 0x00
    volatile uint32_t CRH ;         //0x04
    volatile uint32_t IDR ;        //0x08
    volatile uint32_t ODR ;       //0x0c
    volatile uint32_t BSRR ;     //0x10
    volatile uint32_t BRR;      //0x14
    volatile uint32_t LCKR ;   //0x18

}gpio_typedef;

#define GPIO_PORT_BASE 0x40010800 // GPIO PORT base 
#define GPIO_PORT_OFFSET 0x400   // OFFESET from each GPIO port from A-F 

#define GPIOA ((gpio_typedef *) (GPIO_PORT_BASE + 0*GPIO_PORT_OFFSET))      // PORTA address => 0x40010800
#define GPIOB ((gpio_typedef *) (GPIO_PORT_BASE + 1*GPIO_PORT_OFFSET))     // PORTA address => 0x40010c00
#define GPIOC ((gpio_typedef *) (GPIO_PORT_BASE + 2*GPIO_PORT_OFFSET))    // PORTA address => 0x40011000
#define GPIOD ((gpio_typedef *) (GPIO_PORT_BASE + 3*GPIO_PORT_OFFSET))   // PORTA address => 0x40011400
#define GPIOE ((gpio_typedef *) (GPIO_PORT_BASE + 4*GPIO_PORT_OFFSET))  // PORTA address => 0x40011800
#define GPIOF ((gpio_typedef *) (GPIO_PORT_BASE + 5*GPIO_PORT_OFFSET)) // PORTA address => 0x40011c00

/* GPIO data types */

typedef enum gpio_value_t {
    LOW,
    HIGH
} gpio_pinstate_t;

typedef enum gpio_mode_t {
    OUTPUT_PUSHPULL  = 0x00,
    OUTPUT_OPENDRAIN = 0x01,
    ANALOG           = 0x00,
    INPUT            = 0x01,
    INPUT_PULLDOWN   = 0x02,
    INPUT_PULLUP     = 0x12
} gpio_mode_t;

typedef enum gpio_speed_t {
    NOT_DEFINED,
    OUTPUT_10MHZ,
    OUTPUT_2MHZ,
    OUTPUT_50MHZ
} gpio_speed_t;


typedef enum gpio_port_t{
    GPIO_A=0,
    GPIO_B,
    GPIO_C,

}gpio_port_t;


typedef struct 
{   
    volatile uint32_t Pin ;          
    volatile uint32_t Mode ;          
    volatile uint32_t Pull ;          
    volatile uint32_t Speed ;          
    volatile uint32_t Alternate ;          


}gpio_initTypedef;





// void gpio_init(gpio_typedef *GPIOx,gpio_initTypedef *gpio_init,uint16_t Pin);
// void gpio_deinit(gpio_typedef *GPIOx,uint16_t Pin);
// gpio_pinstate_t gpio_read__pin(gpio_typedef *GPIOx,uint16_t Pin);

/**
 * @brief gpio_write__pin
 * 
 * @param GPIOx 
 * @param GPIO_Pin 
 * @param PinState 
 */
void gpio_write__pin(gpio_typedef* GPIOx, uint16_t GPIO_Pin, gpio_pinstate_t PinState);

/**
 * @brief gpio_toggle__pin
 * 
 * @param GPIOx 
 * @param GPIO_Pin 
 */
void gpio_toggle__pin(gpio_typedef* GPIOx, uint16_t GPIO_Pin);

#endif