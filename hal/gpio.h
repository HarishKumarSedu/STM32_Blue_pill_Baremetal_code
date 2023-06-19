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
#include "common.h"

typedef struct 
{   
    volatile uint32_t CRL ;          // 0x00
    volatile uint32_t CRH ;         //0x04
    volatile uint32_t IDR ;        //0x08
    volatile uint32_t ODR ;       //0x0c
    volatile uint32_t BSRR ;     //0x10
    volatile uint32_t BRR;      //0x14
    volatile uint32_t LCKR ;   //0x18

} GPIO_TypeDef;

#define GPIO_PORT_BASE 0x40010800 // GPIO PORT base 
#define GPIO_PORT_OFFSET 0x400   // OFFESET from each GPIO port from A-F 

#define GPIOA (( GPIO_TypeDef *) (GPIO_PORT_BASE + 0*GPIO_PORT_OFFSET))      // PORTA address => 0x40010800
#define GPIOB (( GPIO_TypeDef *) (GPIO_PORT_BASE + 1*GPIO_PORT_OFFSET))     // PORTA address => 0x40010c00
#define GPIOC (( GPIO_TypeDef *) (GPIO_PORT_BASE + 2*GPIO_PORT_OFFSET))    // PORTA address => 0x40011000
#define GPIOD (( GPIO_TypeDef *) (GPIO_PORT_BASE + 3*GPIO_PORT_OFFSET))   // PORTA address => 0x40011400
#define GPIOE (( GPIO_TypeDef *) (GPIO_PORT_BASE + 4*GPIO_PORT_OFFSET))  // PORTA address => 0x40011800
#define GPIOF (( GPIO_TypeDef *) (GPIO_PORT_BASE + 5*GPIO_PORT_OFFSET)) // PORTA address => 0x40011c00

/* GPIO data types */

typedef enum 
{
    GPIO_00 = IO_00,
    GPIO_01 = IO_01,
    GPIO_02 = IO_02,
    GPIO_03 = IO_03,
    GPIO_04 = IO_04,
    GPIO_05 = IO_05,
    GPIO_06 = IO_06,
    GPIO_07 = IO_07,
    GPIO_08 = IO_08,
    GPIO_09 = IO_09,
    GPIO_10 = IO_10,
    GPIO_11 = IO_11,
    GPIO_12 = IO_12,
    GPIO_13 = IO_13,
    GPIO_14 = IO_14,
    GPIO_15 = IO_15,

} GPIO_Pins ;

typedef enum  
{
    LOW,
    HIGH
} GPIO_PinState;

typedef enum 
{
    GPIO_CONF_OUTPUT_PUSHPULL           = 0x00,
    GPIO_CONF_OUTPUT_OPENDRAIN          = 0x01,
    GPIO_CONF_AF_OUTPUT_OPENDRAIN       = 0x02,
    GPIO_CONF_AF_OUTPUT_PUSHPULL        = 0x03,
    GPIO_CONF_ANALOG                    = 0x00,
    GPIO_CONF_INPUT                     = 0x01,
    GPIO_CONF_INPUT_PULLDOWN            = 0x02,
    GPIO_CONF_INPUT_PULLUP              = 0x02
} GPIO_ConfMode ;

typedef enum 
{
    GPIO_MODE_OUTPUT_PUSHPULL           = 0x01,
    GPIO_MODE_OUTPUT_OPENDRAIN          = 0x02,
    GPIO_MODE_AF_OUTPUT_OPENDRAIN       = 0x03,
    GPIO_MODE_ANALOG                    = 0x00,
    GPIO_MODE_INPUT                     = 0x00,
    GPIO_MODE_INPUT_PULLDOWN            = 0x00,
    GPIO_MODE_INPUT_PULLUP              = 0x00
} GPIO_Mode ;

typedef enum 
{
    NOT_DEFINED,
    OUTPUT_10MHZ,
    OUTPUT_2MHZ,
    OUTPUT_50MHZ
} GPIO_Speed ;


typedef struct 
{
    volatile uint32_t Pin;
    volatile uint32_t Mode;
    volatile uint32_t Pull;
    volatile uint32_t Speed;
    volatile uint32_t Alternate;
} GPIO_InitTypeDef;


typedef enum 
{
    GPIOA_Port,
    GPIOB_Port,
    GPIOC_Port,
    GPIOD_Port,
    GPIOE_Port,
    GPIOF_Port,
    GPIOG_Port,
} GPIO_Port ;



// App testing functions 
void LED_Config();
void GPIO_Config_C15Input();

void  HAL_GPIO_Init(GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init);
void  HAL_GPIO_DeInit(GPIO_TypeDef  *GPIOx, uint32_t GPIO_Pin);
GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
void HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
HAL_StatusTypeDef HAL_GPIO_LockPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void HAL_GPIO_EXTI_IRQHandler(uint16_t GPIO_Pin);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

#endif