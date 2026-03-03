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

/**
 * @brief printing a number in binary format
 * 
 * @param byte - packed 32-bit number
 * 
 * @return void
 */
void print_in_binary(uint32_t byte)
{
    for (int i = 31; i >= 0; i--)
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
    unsigned int byte = (packed_byte >> shift) & 255;

    return byte;
}

/**
 * @brief packing 4 bytes into 1 unsigned number and decompressing back 4 numbers of 1 byte each
 * 
 * @return int
 * 0 — successful completion
 * 1 — input error
 * 2 — incorrect mathematical data
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
        return 1;
    }
    /** validation for mathematical correctness */
    if (!(0 <= byte_1 && byte_1 <= 255 && 0 <= byte_2 && byte_2 <= 255 \
        && 0 <= byte_3 && byte_3 <= 255 && 0 <= byte_4 && byte_4 <= 255))
    {
        printf("Error: Incorrect mathematical input");
        return 2;
    }

    /** shift each byte by the appropriate number of bits and connect using | */
    total_byte = (byte_1 << 24) | (byte_2 << 16) | (byte_3 << 8) | byte_4;
    
    printf("Result: ");
    print_in_binary(total_byte);

    /** decompressing bytes */
    res_b_1 = unpacking_from_unsight_32(total_byte, 24);
    res_b_2 = unpacking_from_unsight_32(total_byte, 16);
    res_b_3 = unpacking_from_unsight_32(total_byte, 8);
    res_b_4 = unpacking_from_unsight_32(total_byte, 0);

    printf(" %u %u %u %u", res_b_1, res_b_2, res_b_3, res_b_4);
}
