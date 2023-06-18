/**
 * @file io.h
 * @author Harish Kumar Shivaramappa (harishkumarsedu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef IO_H__
#define IO_H__

typedef enum{
    IO_00,
    IO_01,
    IO_02,
    IO_03,
    IO_04,
    IO_05,
    IO_06,
    IO_07,
    IO_08,
    IO_09,
    IO_10,
    IO_11,
    IO_12,
    IO_13,
    IO_14,
    IO_15,
}IO;

/* Bitwise Operations */

#define BIT_SHIFT_RIGHT(BIT_POS)  ( (1U << BIT_POS) )
#define BIT_SET(REG, BIT_POS)  ( (REG) |= (1U << BIT_POS) )
#define BIT_CLR(REG, BIT_POS)  ( (REG) &= ( ~(1U << BIT_POS) ) )
#define BIT_FLIP(REG, BIT_POS) ( (REG) ^= (1U << BIT_POS) )
#define REG_UPDATE(REG, DATA, BITS, SHIFT_LEN) ( (REG) = ((REG & ~(BITS << SHIFT_LEN)) + (DATA << SHIFT_LEN)) )
#define BYTE_HIGH(DATA)        ( ((DATA & 0xF0) >> 4U) )
#define BYTE_LOW(DATA)         ( (DATA & 0x0F) )


#define GPIO_CHR_MODE_MASK(x) (0x7 << ((x - 8) * 4)) // Masking MODE and CONF conf bits  
#define GPIO_CHR_MODE_OUTPUT(MODE,GPIO_PIN) (MODE << ((GPIO_PIN - 8) * 4))
#define GPIO_CRL_MODE_MASK(x) (0x7 << ((x - 8) * 4)) 
#define GPIO_CRL_MODE_OUTPUT(MODE,GPIO_PIN) (MODE << ((GPIO_PIN - 8) * 4))


#define TWOBITS 0x3
#define ONEBIT  0x1


#endif