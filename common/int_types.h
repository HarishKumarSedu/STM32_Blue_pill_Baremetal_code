/**
 * @file int_types.h
 * @author Harish Kumar Shivaramappa (harishkumarsedu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef INT_TYPES_H__
#define INT_TYPES_H__

#define int32_t     int
#define int16_t     short
#define int8_t      char
#define uint32_t    unsigned int
#define uint16_t    unsigned short
#define uint8_t     unsigned char

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