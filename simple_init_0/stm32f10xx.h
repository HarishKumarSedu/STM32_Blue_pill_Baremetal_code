/**
 * @file stm32f10xx.h
 * @author Harish Kumar Shivaramappa
 * @brief 
 * @version 0.1
 * @date 2023-05-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdint.h>

// shift the x number of the bits to right 
#define BIT(x) (1UL << (x))

// Bit SET
#define BITSET(x) (1UL << (x))

// shift the x number of the bits to right with value y towards right 
#define BITSHIFRIGHT(x,y) (y << (x))

// particular pin in the pin bank A to E -> inputs to the macro is bank and the which pin 
#define PIN(bank,num) (((bank) - 'A')<<8 | (num)) // macro  will pack the bank and the pin number 

// mask the pin -> pinnumber 
#define PINNO(pin)(pin & 255) 

// pin wiull be poacked with the pinbank and the pin number seperate the pinbank higher 8 bits from pin 
#define PINBANK(pin) (pin >>8)

/**
 * @brief RCC_Typedef struct with all the RCC registers are stored in the struct 
 * @brief RCC_Typedef struct -> assiged to the base address 
 * 
 */
typedef struct 
{
    uint32_t volatile AHBENR ;
    uint32_t volatile APB1ENR ;
    uint32_t volatile APB1RSTR ;
    uint32_t volatile APB2ENR ;
    uint32_t volatile APB2RSTR ;
    uint32_t volatile BDCR ;
    uint32_t volatile CFGR ;
    uint32_t volatile CIR ;
    uint32_t volatile CR ;
    uint32_t volatile CSR ;
} RCC_Typedef;

/**
 * @brief Assign he base address for the RCC_Typedef 
 * 
 */
#define RCC (( RCC_Typedef * ) 0x40021000)

typedef struct 
{
    uint32_t volatile BRR;
    uint32_t volatile BSRR ;
    uint32_t volatile CRH ;
    uint32_t volatile CRL ;
    uint32_t volatile IDR ;
    uint32_t volatile LCKR ;
    uint32_t volatile ODR;
}GPIO_Typedef;





// GPIO base address 
// 0x4001 0800
// Particular bank registers 
// #define GPIO(bank) (( GPIO_Typedef *) (0x40010800 + 0x400 * (bank)))
#define GPIO (( GPIO_Typedef *) (0x40011000))