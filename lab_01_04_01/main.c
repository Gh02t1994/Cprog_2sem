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

#define NUM_FLATS 36 /**< number of flats in one entrance */
#define NUM_FLATS_ON_FLOOR 4 /**< number of apartments per floor */
#define CHECK_POS 0 /**< the number to check for positivity */
#define SUCCESS 0 /**< success return code */
#define INP_ERR 1 /**< input error return code */
#define MATH_ERR 2 /**< mathematical error return code */

/**
 * @brief calculating the number of apartments and floor by number of flat
 * 
 * @return int
 * SUCCESS — successful completion
 * INP_ERR — input error
 * MATH_ERR — incorrect mathematical data
 */
int main(void)
{
    int num_of_flat; /**< the number of flat */
    int num_apart; /**< the number of apartments */
    int floor; /**< the number of floor */

    printf("Enter the number of flat: ");
    /** validation for input correctness */
    if (scanf("%d", &num_of_flat) != 1)
    {
        printf("Incorrect input");
        return INP_ERR;
    }

    /** validation for mathematical correctness */
    if (num_of_flat <= 0)
    {
        printf("Incorrect mathematical input");
        return MATH_ERR;
    }

    num_apart = (num_of_flat - 1) / NUM_FLATS + 1; /**< calculating the number of apartments */
    floor = ((num_of_flat - 1) % NUM_FLATS) / NUM_FLATS_ON_FLOOR + 1; /**< calculating the number of floor*/
    
    printf("The number of apartments and floor: %d %d", num_apart, floor);
    return SUCCESS;
}
