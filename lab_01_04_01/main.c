/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 01 04 01
 * @version 0.2
 * @date 2026-01-01
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

/**
 * @brief calculating the number of apartments and floor by number of flat
 * 
 * @return int
 * 0 — successful completion
 * 1 — input error
 * 2 — incorrect mathematical data
 */
int main(void)
{
    int num_of_flat; /**< the number of flat */
    int num_apart, floor; /**< the number of apartments and number of floor */

    printf("Enter the number of flat: ");
    if (scanf("%d", &num_of_flat) != 1) /**< validation for input correctness */
    {
        printf("Incorrect input");
        return 1;
    }

    if (num_of_flat <= 0) /**< validation for mathematical correctness */
    {
        printf("Incorrect mathematical input");
        return 2;
    }

    num_apart = (num_of_flat - 1) / 36 + 1; /**< calculating the number of apartments */
    floor = ((num_of_flat - 1) % 36) / 4 + 1; /**< calculating the number of floor*/
    
    printf("The number of apartments and floor: %d %d", num_apart, floor);
    return 0;
}
