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
#include "gpio.h"


#define USART_BRR_DIV_Mantissa_Pos    3U
#define USART_BRR_DIV_Fraction_Pos    0U


#define USART_SR_PE_FLAG              ((uint32_t)(1U << 0))
#define USART_SR_FE_FLAG              ((uint32_t)(1U << 1))
#define USART_SR_NF_FLAG              ((uint32_t)(1U << 2))
#define USART_SR_ORE_FLAG             ((uint32_t)(1U << 3))
#define USART_SR_IDLE_FLAG            ((uint32_t)(1U << 4))
#define USART_SR_RXNE_FLAG            ((uint32_t)(1U << 5))
#define USART_SR_TC_FLAG              ((uint32_t)(1U << 6))
#define USART_SR_TXE_FLAG             ((uint32_t)(1U << 7))
#define USART_SR_LBD_FLAG             ((uint32_t)(1U << 8))
#define USART_SR_CTS_FLAG             ((uint32_t)(1U << 9))


#define USART_CR1_SBK                 ((uint32_t)(1U << 0))
#define USART_CR1_RWU                 ((uint32_t)(1U << 1))
#define USART_CR1_RE                  ((uint32_t)(1U << 2))
#define USART_CR1_TE                  ((uint32_t)(1U << 3))
#define USART_CR1_IDLEIE              ((uint32_t)(1U << 4))
#define USART_CR1_RXNEIE              ((uint32_t)(1U << 5))
#define USART_CR1_TCIE                ((uint32_t)(1U << 6))
#define USART_CR1_TXEIE               ((uint32_t)(1U << 7))
#define USART_CR1_PEIE                ((uint32_t)(1U << 8))
#define USART_CR1_PS                  ((uint32_t)(1U << 9))
#define USART_CR1_PCE                 ((uint32_t)(1U << 10))
#define USART_CR1_WAKE                ((uint32_t)(1U << 11))
#define USART_CR1_M                   ((uint32_t)(1U << 12))
#define USART_CR1_UE                  ((uint32_t)(1U << 13))
#define USART_CR1_Reserved            ((uint32_t)(1U << 14))
#define USART_CR1_OVER8               ((uint32_t)(1U << 15))



#define USART_SR_ADD_FLAG             ((uint32_t)(1U << 0))
// #define USART_SR_Res_FLAG             ((uint32_t)(1U << 4))
#define USART_SR_LBDL_FLAG            ((uint32_t)(1U << 5))
#define USART_SR_LBDIE_FLAG           ((uint32_t)(1U << 6))
// #define USART_SR_Res_FLAG             ((uint32_t)(1U << 7))
#define USART_SR_LBCL_FLAG            ((uint32_t)(1U << 8))
#define USART_SR_CPHA_FLAG            ((uint32_t)(1U << 9))
#define USART_SR_CPOL_FLAG            ((uint32_t)(1U << 10))
#define USART_SR_CLKEN_FLAG           ((uint32_t)(1U << 11))
#define USART_SR_STOP_FLAG            ((uint32_t)(1U << 12))
#define USART_SR_LINEN_FLAG           ((uint32_t)(1U << 14))

#define USART_SR_EIE_FLAG             ((uint32_t)(1U << 0))
#define USART_SR_IREN_FLAG            ((uint32_t)(1U << 1))
#define USART_SR_IRLP_FLAG            ((uint32_t)(1U << 2))
#define USART_SR_HDSEL_FLAG           ((uint32_t)(1U << 3))
#define USART_SR_NACK_FLAG            ((uint32_t)(1U << 4))
#define USART_SR_SCEN_FLAG            ((uint32_t)(1U << 5))
#define USART_SR_DMAR_FLAG            ((uint32_t)(1U << 6))
#define USART_SR_DMAT_FLAG            ((uint32_t)(1U << 7))
#define USART_SR_RTSE_FLAG            ((uint32_t)(1U << 8))
#define USART_SR_CTSE_FLAG            ((uint32_t)(1U << 9))
#define USART_SR_CTSIE_FLAG           ((uint32_t)(1U << 10))
#define USART_SR_ONEBIT_FLAG          ((uint32_t)(1U << 11))

typedef struct 

{
  // __IO uint32_t BRR  ;            // 0x00
  // __IO uint32_t CR1  ;           // 0x04
  // __IO uint32_t CR2  ;          // 0x08
  // __IO uint32_t CR3  ;         // 0x0C
  // __IO uint32_t GTPR ;        // 0x10
  // __IO uint32_t ICR  ;       // 0x14
  // __IO uint32_t ISR  ;      // 0x18
  // __IO uint32_t RDR  ;     // 0x1c
  // __IO uint32_t RQR  ;    // 0x20
  // __IO uint32_t RTOR ;   // 0x24
  // __IO uint32_t TDR  ;  // 0x28


    __IO uint32_t  BRR ;          // 0x00
    __IO uint32_t  CR1 ;         // 0x04
    __IO uint32_t  CR2 ;        // 0x08
    __IO uint32_t  CR3 ;       // 0x0C
    __IO uint32_t  DR ;       // 0x10
    __IO uint32_t  GTPR ;    // 0x14
    __IO uint32_t  SR ;     // 0x18

} USART_TypeDef ; 

#define USART1_BASE 0x40013800
#define USART2_BASE 0x40004400
#define USART_BASE_OFFSET 0x400

#define USART1 ((USART_TypeDef *)(USART1_BASE))
#define USART2 ((USART_TypeDef *)(USART2_BASE 0*USART_BASE_OFFSET))
#define USART3 ((USART_TypeDef *)(USART3_BASE 1*USART_BASE_OFFSET))
#define USART4 ((USART_TypeDef *)(USART4_BASE 2*USART_BASE_OFFSET))
#define USART5 ((USART_TypeDef *)(USART5_BASE 3*USART_BASE_OFFSET))

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
    uint32_t Port ; 
    uint32_t TxPin ; 
    uint32_t RxPin ; 
} USART_InitTypeDef;

typedef enum
{
  HAL_USART_STATE_RESET             = 0x00U,    /*!< Peripheral is not yet Initialized   */
  HAL_USART_STATE_READY             = 0x01U,    /*!< Peripheral Initialized and ready for use */
  HAL_USART_STATE_BUSY              = 0x02U,    /*!< an internal process is ongoing */   
  HAL_USART_STATE_BUSY_TX           = 0x12U,    /*!< Data Transmission process is ongoing */ 
  HAL_USART_STATE_BUSY_RX           = 0x22U,    /*!< Data Reception process is ongoing */
  HAL_USART_STATE_BUSY_TX_RX        = 0x32U,    /*!< Data Transmission Reception process is ongoing */
  HAL_USART_STATE_TIMEOUT           = 0x03U,    /*!< Timeout state */
  HAL_USART_STATE_ERROR             = 0x04U     /*!< Error */      
}HAL_USART_StateTypeDef;

typedef enum 
{
HAL_USART_ERROR_NONE                = 0x00000000U,   /*!< No error            */
HAL_USART_ERROR_PE                  = 0x00000001U,   /*!< Parity error        */
HAL_USART_ERROR_NE                  = 0x00000002U,   /*!< Noise error         */
HAL_USART_ERROR_FE                  = 0x00000004U,   /*!< Frame error         */
HAL_USART_ERROR_ORE                 = 0x00000008U,   /*!< Overrun error       */
HAL_USART_ERROR_DMA                 = 0x00000010U,   /*!< DMA transfer error  */

} HAL_USART_Errors ; 

typedef enum 
{
  GPIOA_02  = GPIO_02,
  USART2_TxPin = GPIOA_02,
  GPIOA_03  = GPIO_03,
  USART2_RxPin = GPIOA_03,

} USART2_PinMap ; 

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
    __IO HAL_USART_StateTypeDef State ;
    __IO uint32_t ErrorCode ;
} USART_HandleTypeDef ; 



/**
 * @brief Application functions 
 * 
 */

void USART2_Init() ;

/* Exported functions --------------------------------------------------------*/
/** @addtogroup USART_Exported_Functions
  * @{
  */

/** LL Functions ----------------------------------------------------------*/
/**
 * @brief 
 * 
 */

void LL_BaudRate_Set(USART_TypeDef *USARTx, uint32_t BaudRate) ;
HAL_StatusTypeDef LL_Transmit_Byte(USART_TypeDef *USARTx,uint8_t Byte ) ;
HAL_StatusTypeDef LL_Transmit_String(USART_TypeDef *USARTx,const char *myString ) ;
HAL_StatusTypeDef LL_NewLine_UART(USART_TypeDef *USARTx) ;
char LL_Recive_Byte(USART_TypeDef *USARTx )  ;
HAL_StatusTypeDef LL_Recive(USART_TypeDef *USARTx, char *buff ) ;


/** @addtogroup USART_Exported_Functions_Group1
  * @{
  */
/* Initialization/de-initialization functions  **********************************/
HAL_StatusTypeDef HAL_USART_Init(USART_HandleTypeDef *husart);
HAL_StatusTypeDef HAL_USART_DeInit(USART_HandleTypeDef *husart);
void HAL_USART_MspInit(USART_HandleTypeDef *husart);
void HAL_USART_MspDeInit(USART_HandleTypeDef *husart);
/**
  * @}
  */

/** @addtogroup USART_Exported_Functions_Group2
  * @{
  */
/* IO operation functions *******************************************************/
HAL_StatusTypeDef HAL_USART_Transmit(USART_HandleTypeDef *husart, uint8_t *pTxData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_USART_Receive(USART_HandleTypeDef *husart, uint8_t *pRxData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_USART_TransmitReceive(USART_HandleTypeDef *husart, uint8_t *pTxData, uint8_t *pRxData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_USART_Transmit_IT(USART_HandleTypeDef *husart, uint8_t *pTxData, uint16_t Size);
HAL_StatusTypeDef HAL_USART_Receive_IT(USART_HandleTypeDef *husart, uint8_t *pRxData, uint16_t Size);
HAL_StatusTypeDef HAL_USART_TransmitReceive_IT(USART_HandleTypeDef *husart, uint8_t *pTxData, uint8_t *pRxData,  uint16_t Size);
HAL_StatusTypeDef HAL_USART_Transmit_DMA(USART_HandleTypeDef *husart, uint8_t *pTxData, uint16_t Size);
HAL_StatusTypeDef HAL_USART_Receive_DMA(USART_HandleTypeDef *husart, uint8_t *pRxData, uint16_t Size);
HAL_StatusTypeDef HAL_USART_TransmitReceive_DMA(USART_HandleTypeDef *husart, uint8_t *pTxData, uint8_t *pRxData, uint16_t Size);
HAL_StatusTypeDef HAL_USART_DMAPause(USART_HandleTypeDef *husart);
HAL_StatusTypeDef HAL_USART_DMAResume(USART_HandleTypeDef *husart);
HAL_StatusTypeDef HAL_USART_DMAStop(USART_HandleTypeDef *husart);


/* Transfer Abort functions */
HAL_StatusTypeDef HAL_USART_Abort(USART_HandleTypeDef *husart);
HAL_StatusTypeDef HAL_USART_Abort_IT(USART_HandleTypeDef *husart);

void HAL_USART_IRQHandler(USART_HandleTypeDef *husart);
void HAL_USART_TxCpltCallback(USART_HandleTypeDef *husart);
void HAL_USART_TxHalfCpltCallback(USART_HandleTypeDef *husart);
void HAL_USART_RxCpltCallback(USART_HandleTypeDef *husart);
void HAL_USART_RxHalfCpltCallback(USART_HandleTypeDef *husart);
void HAL_USART_TxRxCpltCallback(USART_HandleTypeDef *husart);
void HAL_USART_ErrorCallback(USART_HandleTypeDef *husart);
void HAL_USART_AbortCpltCallback (USART_HandleTypeDef *husart);
/**
  * @}
  */ 

/** @addtogroup USART_Exported_Functions_Group3
  * @{
  */
/* Peripheral State functions  ************************************************/
HAL_USART_StateTypeDef HAL_USART_GetState(USART_HandleTypeDef *husart);
uint32_t               HAL_USART_GetError(USART_HandleTypeDef *husart);

#endif