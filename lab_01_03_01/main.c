/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 01 03 01
 * @version 0.2
 * @date 2026-01-01
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

#define CHECK_POS 0 /**< the number to check for positivity */
#define CHECK_TEM 100 /**< the number for checking the water temperature */
#define SUCCESS 0 /**< success return code */
#define INP_ERR 1 /**< input error return code */
#define MATH_ERR 2 /**< mathematical error return code */

/**
 * @brief calculating average volume and temperature during mixing two containers
 * 
 * @return int
 * SUCCESS — successful completion
 * INP_ERR — input error
 * MATH_ERR — incorrect mathematical data
 */
int main(void)
{
    float v_1, v_2, v_total; /**< water volumes */
    float t_1, t_2, t_total; /**< water temperatures */

    printf("Enter the volume and temperature of the first container, and then the second: ");
    /** validation for input correctness */
    if (scanf("%f %f %f %f", &v_1, &t_1, &v_2, &t_2) != 4)
    {
        printf("Incorrect input\n");
        return INP_ERR;
    }

    /** validation for mathematical correctness */
    if (v_1 <= CHECK_POS || v_2 <= CHECK_POS || t_1 <= CHECK_POS || \
        t_2 <= CHECK_POS || t_1 >= CHECK_TEM || t_2 >= CHECK_TEM)
    {
        printf("Incorrect mathematical input\n");
        return MATH_ERR;
    }
    
    v_total = v_1 + v_2; /**< total volume */
    t_total = (v_1 * t_1 + v_2 * t_2) / v_total; /**< total temperature */

    printf("The total volume and temperature: %.6f %.6f", v_total, t_total);
    return SUCCESS;
}
