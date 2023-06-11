/**
 * @file rcc.c
 * @author Harish Kumar Shivaramappa (harishkumarsedu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "rcc.h"
#include "int_types.h"
#include "gpio.h"


void rcc_init(rcc_typedef * rcc,io io){
    BIT_SET(rcc->APB2ENR ,io);
}

