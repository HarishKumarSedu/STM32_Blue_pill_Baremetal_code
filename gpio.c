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

#include "hal/gpio.h"
#include "hal/io.h"

void LED_Config(){

    GPIO_InitTypeDef GPIO_LED_Init;

    GPIO_LED_Init.Pin   = GPIO_13; // GPIO_13 is the LED in Stm32 blue pill board 
    GPIO_LED_Init.Pull  = GPIO_CONF_OUTPUT_OPENDRAIN;
    GPIO_LED_Init.Mode  = GPIO_MODE_OUTPUT_OPENDRAIN;
    GPIO_LED_Init.Speed = NOT_DEFINED;

    HAL_GPIO_Init(GPIOC, &GPIO_LED_Init);
}


void GPIO_Config_C15Input(){

    GPIO_InitTypeDef GPIO_C15_Init;
    GPIO_C15_Init.Pin   = GPIO_15; 
    GPIO_C15_Init.Pull  = GPIO_CONF_INPUT_PULLUP;
    GPIO_C15_Init.Mode  = GPIO_MODE_INPUT_PULLUP;
    GPIO_C15_Init.Speed = NOT_DEFINED;
    HAL_GPIO_Init(GPIOC, &GPIO_C15_Init);
}
void  HAL_GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_Init)
{
    if (GPIO_Init->Pin > GPIO_07)
    {
        GPIOx->CRH &= ~(GPIO_CHR_MODE_MASK(GPIO_Init->Pin));
        GPIOx->CRH |= GPIO_CHR_MODE_OUTPUT( ((GPIO_Init->Pull << 2 ) | GPIO_Init->Mode | GPIO_Init->Speed), GPIO_Init->Pin); // Shift the CONF bits -> Pull by two bits and add with the mode bits 
    }
    else 
    {
        GPIOx->CRL &= ~(GPIO_CRL_MODE_MASK(GPIO_Init->Pin));
        GPIOx->CRL |= GPIO_CRL_MODE_OUTPUT( ((GPIO_Init->Pull << 2 ) | GPIO_Init->Mode | GPIO_Init->Speed), GPIO_Init->Pin); // Shift the CONF bits -> Pull by two bits and add with the mode bits 
    }
    
}

void  HAL_GPIO_DeInit(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin)
{
    if (GPIO_Pin > GPIO_07)
    {
        GPIOx->CRH &= ~(GPIO_CHR_MODE_MASK(GPIO_Pin)); // For Deinit just mask the bits 
    }
    else 
    {
        GPIOx->CRL &= ~(GPIO_CRL_MODE_MASK(GPIO_Pin)); // For Deinit just mask the bits 
    }
    
}
void HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
    if (HIGH == PinState)
    {
        BIT_SET(GPIOx->ODR,GPIO_Pin);
    }
    else
    {
        
        BIT_CLR(GPIOx->ODR,GPIO_Pin);
    }
    
}

void HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    BIT_FLIP(GPIOx->ODR,GPIO_Pin);
}


GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    GPIO_PinState GPIO_Value = LOW;
    if (HIGH != (GPIOx->IDR & 1<<GPIO_Pin ) >> GPIO_Pin )
    {
        GPIO_Value = HIGH;
    }
      
    return GPIO_Value;
}