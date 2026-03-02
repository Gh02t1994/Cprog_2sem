/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 01 05 01
 * @version 0.2
 * @date 2026-02-01
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

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
    if (full_number >= 10)
    {
        printing_number(full_number / 10);
    }
    /** output the low-order digits */
    printf("%d", full_number % 10);
}

/**
 * @brief output of the entered number
 * 
 * @return int
 * 0 — successful completion
 * 1 — input error
 * 2 — incorrect mathematical data
 */
int main(void)
{
    int number;

    printf("Enter the natural number (>0): ");
    /** validation for input correctness */
    if (scanf("%d", &number) != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    /** validation for mathematical correctness */
    if (number <= 0)
    {
        printf("Incorrect mathematical input");
        return 2;
    }

    printf("The number: ");
    printing_number(number);

    printf("\n");
}
