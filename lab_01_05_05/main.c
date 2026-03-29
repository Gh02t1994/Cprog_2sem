/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 01 05 05
 * @version 0.2
 * @date 2026-02-01
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

#define DEC 10 /**< decimal number system */
#define CHECK_POS 0 /**< the number to check for positivity */
#define SUCCESS 0 /**< success return code */
#define INP_ERR 1 /**< input error return code */
#define MATH_ERR 2 /**< mathematical error return code */

/**
 * @brief character-by-character printing of a number
 * 
 * @param full_number - the original number
 * 
 * @return void
 */
void printing_number(int full_number)
{
    /** move to the higher digits of the number */
    if (full_number >= DEC)
    {
        printing_number(full_number / DEC);
    }
    /** output the low-order digits */
    printf("%d", full_number % DEC);
}

/**
 * @brief output of the entered number
 * 
 * @return int
 * SUCCESS — successful completion
 * INP_ERR — input error
 * MATH_ERR — incorrect mathematical data
 */
int main(void)
{
    int number;

    printf("Enter the natural number more than zero: ");
    /** validation for input correctness */
    if (scanf("%d", &number) != 1)
    {
        printf("Incorrect input");
        return INP_ERR;
    }

    /** validation for mathematical correctness */
    if (number <= CHECK_POS)
    {
        printf("Incorrect mathematical input");
        return MATH_ERR;
    }

    printf("The number: ");
    printing_number(number);

    printf("\n");
    return SUCCESS;
}
