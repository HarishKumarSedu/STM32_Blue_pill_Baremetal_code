/**
 * @file common.h
 * @author Harish Kumar Shivaramappa(harishkumarsedu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef COMMON_H__
#define COMMON_H__

// The HAL status is used by almost all HAL API's
typedef enum
{
    HAL_OK      = 0x00,
    HAL_ERROR   = 0x01,
    HAL_BUSY    = 0x02,
    HAL_TIMEOUT = 0x03,

} HAL_StatusTypeDef ;

typedef enum
{
    HAL_UNLOCKED = 0x00,
    HAL_locked   = 0x01,
} HAL_LockTypeDef ;

#endif