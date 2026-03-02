/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 01 05 01
 * @version 0.1
 * @date 2026-02-01
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

/**
 * @brief input validation
 * 
 * @param arg_scanf - scanf result
 * @param inp_num - the entered number
 * 
 * @return int
 * 0 — successful completion
 * 1 — input error
 * 2 — incorrect mathematical data
 */
int val_of_correct_inp(int arg_scanf, int inp_num)
{
    if (arg_scanf != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    if (inp_num <= 0)
    {
        printf("Incorrect mathematical input");
        return 2;
    }
    return 0;
}

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
    int rc; /**< return code */

    printf("Enter the natural number (>0): ");
    rc = val_of_correct_inp(scanf("%d", &number), number);
    /** validation */
    if (rc != 0)
    {
        return rc;
    }

    printf("The number: ");
    printing_number(number);

    printf("\n");
}
