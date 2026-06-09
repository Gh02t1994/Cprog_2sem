/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 01 08 01
 * @version 0.1
 * @date 2026-03-01
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define CHECK_POS 0 /**< the number to check for positivity */
#define BYTE_LIMIT ((1U << CHAR_BIT) - 1) /**< checking a number to see if it is 1 byte */
#define SIZE (CHAR_BIT * sizeof(uint32_t)) /**< the size */
#define SUCCESS 0 /**< success return code */
#define INP_ERR 1 /**< input error return code */
#define MATH_ERR 2 /**< mathematical error return code */

/**
 * @brief printing a number in binary format
 * 
 * @param byte - packed 32-bit number
 * 
 * @return void
 */
void print_in_binary(uint32_t byte)
{
    for (int i = SIZE - 1; i >= 0; i--)
    {
        printf("%u", (byte >> i) & 1);
    }
}

/**
 * @brief decompressing an unsigned integer into a 1 byte number
 * 
 * @param packed_byte - packed 32-bit number
 * @param shift - the number to be shifted by
 * 
 * @return unsigned int
 * the decompressed 1 byte number
 */
unsigned int unpacking_from_unsight_32(uint32_t packed_byte, int shift)
{
    unsigned int byte = (packed_byte >> shift) & BYTE_LIMIT;

    return byte;
}

/**
 * @brief packing 4 bytes into 1 unsigned number and decompressing back 4 numbers of 1 byte each
 * 
 * @return int
 * SUCCESS — successful completion
 * INP_ERR — input error
 * MATH_ERR — incorrect mathematical data
 */
int main(void)
{
    unsigned int byte_1, byte_2, byte_3, byte_4; /**< the initial 4 bytes */
    uint32_t total_byte; /**< packed number */
    unsigned int res_b_1, res_b_2, res_b_3, res_b_4; /**< decompressed bytes */

    printf("Enter: ");
    /** validation for input correctness */
    if (scanf("%u %u %u %u", &byte_1, &byte_2, &byte_3, &byte_4) != 4)
    {
        printf("Error: Incorrect input");
        return INP_ERR;
    }
    /** validation for mathematical correctness */
    if (!(CHECK_POS <= byte_1 && byte_1 <= BYTE_LIMIT && CHECK_POS <= byte_2 && byte_2 <= BYTE_LIMIT \
        && CHECK_POS <= byte_3 && byte_3 <= BYTE_LIMIT && CHECK_POS <= byte_4 && byte_4 <= BYTE_LIMIT))
    {
        printf("Error: Incorrect mathematical input");
        return MATH_ERR;
    }

    /** shift each byte by the appropriate number of bits and connect using | */
    total_byte = (byte_1 << 3 * CHAR_BIT) | (byte_2 << 2 * CHAR_BIT) | (byte_3 << CHAR_BIT) | byte_4;
    
    printf("Result: ");
    print_in_binary(total_byte);

    /** decompressing bytes */
    res_b_1 = unpacking_from_unsight_32(total_byte, 3 * CHAR_BIT);
    res_b_2 = unpacking_from_unsight_32(total_byte, 2 * CHAR_BIT);
    res_b_3 = unpacking_from_unsight_32(total_byte, CHAR_BIT);
    res_b_4 = unpacking_from_unsight_32(total_byte, 0);

    printf(" %u %u %u %u", res_b_1, res_b_2, res_b_3, res_b_4);

    return SUCCESS;
}
