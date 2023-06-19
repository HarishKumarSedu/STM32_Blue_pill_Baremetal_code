/**
 * @file usart.c
 * @author Harish Kumar Shivaramappa (harishkumarsedu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "hal/usart.h"
#include "hal/rcc.h"
#include "hal/gpio.h"

void USART2_Init() 
{   

    // Enable clock for USART2 GPIO port A -> APB2ENR
    RCC_APB2ENR_Init(GPIOA_RCC_APB2ENR_ENABLE);

    // Enable clock for USART2 -> APB1ENR
    RCC_APB1ENR_Init(USART2_RCC_APB1ENR_ENABLE);

    GPIO_InitTypeDef USART2_GPIO_TxInit; 
    GPIO_InitTypeDef USART2_GPIO_RxInit; 

    // GPIOA_2 = USART2_TxPin
    USART2_GPIO_TxInit.Pin = USART2_TxPin ;
    USART2_GPIO_TxInit.Pull = GPIO_CONF_AF_OUTPUT_PUSHPULL;
    USART2_GPIO_TxInit.Mode = NOT_DEFINED;
    USART2_GPIO_TxInit.Mode = OUTPUT_10MHZ;

    // GPIOA_3 = USART2_RxPin
    // the RX pin (A3) is configured 
    // as a floating input rather than an alternate-function output.
    USART2_GPIO_RxInit.Pin = USART2_RxPin ;
    USART2_GPIO_RxInit.Pull = GPIO_CONF_INPUT;
    USART2_GPIO_RxInit.Mode = GPIO_MODE_INPUT;
    USART2_GPIO_RxInit.Mode = NOT_DEFINED;
    
    HAL_GPIO_Init(GPIOA, &USART2_GPIO_TxInit);
    HAL_GPIO_Init(GPIOA, &USART2_GPIO_RxInit);

    // USART_InitTypeDef  hUSART2_Init ; 
    // USART_HandleTypeDef hUSART2 ; 

    // hUSART2_Init.BaudRate = 9600;
    // hUSART2_Init.TxPin    = USART2_Tx ;
    // hUSART2_Init.TxPin    = USART2_Rx ;

    // hUSART2.Instance = USART2 ; 
    // hUSART2.Init = hUSART2
    
}

void LL_BaudRate_Set(USART_TypeDef *USARTx, uint32_t BaudRate) 
{
    uint16_t uartdiv = SystemCoreClock / BaudRate;

    USARTx->BRR = ( ( ( uartdiv / 16 ) << USART_BRR_DIV_Mantissa_Pos ) | ( ( uartdiv % 16 ) << USART_BRR_DIV_Fraction_Pos ) );
}


HAL_StatusTypeDef LL_Transmit_Byte(USART_TypeDef *USARTx,uint8_t Byte ) 
{
      while(!(USARTx->SR & USART_SR_TXEIE_FLAG));
	    USARTx->DR = Byte;
	    while(!(USARTx->SR & USART_SR_TCIE_FLAG));
        
    return HAL_OK;
}

char LL_Transmit_Byte(USART_TypeDef *USARTx ) 
{
	while(!(USARTx->SR & USART_SR_RXNEIE_FLAG)); //  Block until char rec'd
	return  USARTx->DR;
}

HAL_StatusTypeDef HAL_USART_Init(USART_HandleTypeDef *husart) 
{
    LL_BaudRate_Set(husart->Instance, husart->Init.BaudRate) ;

    husart->Instance->CR1 |= ( USART_CR1_RE | USART_CR1_TE | USART_CR1_UE );

    return HAL_OK;
}