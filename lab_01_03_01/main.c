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

/**
 * @brief calculating average volume and temperature during mixing two containers
 * 
 * @return int
 * 0 — successful completion
 * 1 — input error
 * 2 — incorrect mathematical data
 */
int main(void)
{
    float v_1, v_2, v_total; /**< water volumes */
    float t_1, t_2, t_total; /**< water temperatures */

    printf("Enter the volume and temperature of the first container, and then the second: ");
    if (scanf("%f %f %f %f", &v_1, &t_1, &v_2, &t_2) != 4) /**< validation for input correctness */
    {
        printf("Incorrect input\n");
        return 1;
    }

    if (v_1 <= 0 || v_2 <= 0 || t_1 <= 0 || t_2 <= 0) /**< validation for mathematical correctness */
    {
        printf("Incorrect mathematical input\n");
        return 2;
    }
    
    v_total = v_1 + v_2; /**< total volume */
    t_total = (v_1 * t_1 + v_2 * t_2) / v_total; /**< total temperature */

    printf("The total volume and temperature: %.6f %.6f", v_total, t_total);
    return 0;
}
