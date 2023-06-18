/**
 * @file usart.h
 * @author Harish Kumar Shivaramappa (harishkumarsedu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef USART_H__
#define USART_H__

#include <stdint.h>
#include "common.h"

typedef struct 

{

} USART_TypeDef ; 

#define USART1_BASE 0x40013800

#define USART1 ((USART_TypeDef *)(USART1_BASE))

typedef struct 
{
    uint32_t BaudRate ;
    uint32_t WordLength ;
    uint32_t StopBits ;
    uint32_t Parity ;
    uint32_t Mode ;
    uint32_t CLKPolarity ;
    uint32_t CLKPhase ;
    uint32_t CLKLastBit ;
} USART_InitTypeDef;

typedef struct 
{

    USART_TypeDef * Instance ;
    USART_InitTypeDef Init ;
    uint8_t * pTxBuffPtr ;
    uint16_t TxXferSize ;
    __IO uint16_t TxXferCount ;
    uint8_t * pRxBuffPtr ;
    uint16_t RxXferSize ;
    __IO uint16_t RxXferCount ;
    // DMA_HandleTypeDef * hdmatx ;
    // DMA_HandleTypeDef * hdmarx ;
    HAL_LockTypeDef Lock ;
    // __IO HAL_USART_StateTypeDef State ;
    __IO uint32_t ErrorCode ;
} USART_HandleTypeDef ; 

HAL_StatusTypeDef HAL_USART_Init (USART_HandleTypeDef * husart) ;
HAL_StatusTypeDef HAL_USART_DeInit (USART_HandleTypeDef * husart) ;
void HAL_USART_MspInit (USART_HandleTypeDef * husart) ;
void HAL_USART_MspDeInit (USART_HandleTypeDef * husart) ;
HAL_StatusTypeDef HAL_USART_Transmit (USART_HandleTypeDef * husart, uint8_t * pTxData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_USART_Receive (USART_HandleTypeDef * husart, uint8_t * pRxData, uint16_t Size, uint32_t Timeout) ;
HAL_StatusTypeDef HAL_USART_TransmitReceive (USART_HandleTypeDef * husart, uint8_t * pTxData, uint8_t * pRxData, uint16_t Size, uint32_t Timeout) ;
HAL_StatusTypeDef HAL_USART_Transmit_IT (USART_HandleTypeDef * husart, uint8_t * pTxData, uint16_t Size) ;
HAL_StatusTypeDef HAL_USART_Receive_IT (USART_HandleTypeDef * husart, uint8_t * pRxData, uint16_t Size) ;
// void HAL_USART_TransmitReceive_IT ();
// void HAL_USART_Transmit_DMA ();
// void HAL_USART_Receive_DMA ();
// void HAL_USART_TransmitReceive_DMA ();
// void HAL_USART_DMAPause ();
// void HAL_USART_DMAResume ();
// void HAL_USART_DMAStop ();
// void HAL_USART_Abort ();
// void HAL_USART_Abort_IT ();
// void HAL_USART_IRQHandler ();
// void HAL_USART_TxCpltCallback ();
// void HAL_USART_TxHalfCpltCallback ();
// void HAL_USART_RxCpltCallback ();
// void HAL_USART_RxHalfCpltCallback ();
// void HAL_USART_TxRxCpltCallback ();
// void HAL_USART_ErrorCallback ();
// void HAL_USART_AbortCpltCallback ();
// void HAL_USART_GetState ();
// void HAL_USART_GetError ();
#endif
