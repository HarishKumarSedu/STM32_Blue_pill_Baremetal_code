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
    IO_0,
    IO_1,
    IO_2,
    IO_3,
    IO_4,
    IO_5,
    IO_6,
    IO_7,
    IO_8,
    IO_9,
    IO_10,
    IO_11,
    IO_12,
    IO_13,
    IO_14,
    IO_15,
}io;

/* Bitwise Operations */

#define BIT_SET(REG, BIT_POS)  ( (REG) |= (1U << BIT_POS) )
#define BIT_CLR(REG, BIT_POS)  ( (REG) &= ( ~(1U << BIT_POS) ) )
#define BIT_FLIP(REG, BIT_POS) ( (REG) ^= (1U << BIT_POS) )
#define REG_UPDATE(REG, DATA, BITS, SHIFT_LEN) ( (REG) = ((REG & ~(BITS << SHIFT_LEN)) + (DATA << SHIFT_LEN)) )
#define BYTE_HIGH(DATA)        ( ((DATA & 0xF0) >> 4U) )
#define BYTE_LOW(DATA)         ( (DATA & 0x0F) )

#define TWOBITS 0x3
#define ONEBIT  0x1


#endif