/**
 * @file i2c.h
 * @author Harish Kumar Shivaramappa (harishkumarksha0@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef I2C_H__
#define I2C_H__

#include "baseaddress.h"
#include "io.h"
#include "common.h"
#include "gpio.h"


#define I2C_CR1_PE_FLAG                         ((uint32_t)(1U << 0))
#define I2C_CR1_SMBUS_FLAG                      ((uint32_t)(1U << 1))
#define I2C_CR1_SMBTYPE_FLAG                    ((uint32_t)(1U << 3))
#define I2C_CR1_ENARP_FLAG                      ((uint32_t)(1U << 4))
#define I2C_CR1_ENPEC_FLAG                      ((uint32_t)(1U << 5))
#define I2C_CR1_ENGC_FLAG                       ((uint32_t)(1U << 6))
#define I2C_CR1_NOSTRETCH_FLAG                  ((uint32_t)(1U << 7))
#define I2C_CR1_START_FLAG                      ((uint32_t)(1U << 8))
#define I2C_CR1_STOP_FLAG                       ((uint32_t)(1U << 9))
#define I2C_CR1_ACK_FLAG                        ((uint32_t)(1U << 10))
#define I2C_CR1_POS_FLAG                        ((uint32_t)(1U << 11))
#define I2C_CR1_PEC_FLAG                        ((uint32_t)(1U << 12))
#define I2C_CR1_ALERT_FLAG                      ((uint32_t)(1U << 13))
#define I2C_CR1_SWRST_FLAG                      ((uint32_t)(1U << 15))


#define I2C_CR2_FREQ_FLAG                       ((uint32_t)(0x3F << 0))
#define I2C_CR2_ITEREN_FLAG                     ((uint32_t)(1U << 8))
#define I2C_CR2_ITEVTEN_FLAG                    ((uint32_t)(1U << 9))
#define I2C_CR2_ITBUFEN_FLAG                    ((uint32_t)(1U << 10))
#define I2C_CR2_DMAEN_FLAG                      ((uint32_t)(1U << 11))
#define I2C_CR2_LAST_FLAG                       ((uint32_t)(1U << 12))


#define I2C_SR1_SB_FLAG                         ((uint32_t)(1U << 0))
#define I2C_SR1_ADDR_FLAG                       ((uint32_t)(1U << 1))
#define I2C_SR1_BTF_FLAG                        ((uint32_t)(1U << 2))
#define I2C_SR1_ADD10_FLAG                      ((uint32_t)(1U << 3))
#define I2C_SR1_STOPF_FLAG                      ((uint32_t)(1U << 4))
#define I2C_SR1_RXNE_FLAG                       ((uint32_t)(1U << 6))
#define I2C_SR1_TXE_FLAG                        ((uint32_t)(1U << 7))
#define I2C_SR1_BERR_FLAG                       ((uint32_t)(1U << 8))
#define I2C_SR1_ARLO_FLAG                       ((uint32_t)(1U << 9))
#define I2C_SR1_AF_FLAG                         ((uint32_t)(1U << 10))
#define I2C_SR1_OVR_FLAG                        ((uint32_t)(1U << 11))
#define I2C_SR1_PEC_ERR_FLAG                    ((uint32_t)(1U << 12))
#define I2C_SR1_TIME_OUT_FLAG                   ((uint32_t)(1U << 14))
#define I2C_SR1_SMB_ALERT_FLAG                  ((uint32_t)(1U << 15))

#define I2C_SR1_MSL_FLAG                        ((uint32_t)(1U << 0))
#define I2C_SR1_BUSY_FLAG                       ((uint32_t)(1U << 1))
#define I2C_SR1_TRA_FLAG                        ((uint32_t)(1U << 2))
#define I2C_SR1_GEN_CALL_FLAG                   ((uint32_t)(1U << 4))
#define I2C_SR1_SMBDE_FAULT_FLAG                ((uint32_t)(1U << 5))
#define I2C_SR1_SMB_HOST_FLAG                   ((uint32_t)(1U << 6))
#define I2C_SR1_DUALF_FLAG                      ((uint32_t)(1U << 7))
#define I2C_SR1_PEC_FLAG                        ((uint32_t)(0xFF << 8))

typedef struct 
{
    __IO uint32_t CR1    ;            // 0x00
    __IO uint32_t CR2    ;           // 0x04
    __IO uint32_t OAR1   ;          // 0x08
    __IO uint32_t OAR2   ;         // 0x0C
    __IO uint32_t DR     ;        // 0x10
    __IO uint32_t SR1    ;       // 0x14
    __IO uint32_t SR2    ;      // 0x18
    __IO uint32_t CCR    ;     // 0x1c
    __IO uint32_t TRISE  ;    // 0x20

} I2C_TypeDef ;

#define I2C1 ((I2C_TypeDef *) (I2C1_BASE_ADDRESS))
#define I2C2 ((I2C_TypeDef *) (I2C2_BASE_ADDRESS))

#endif