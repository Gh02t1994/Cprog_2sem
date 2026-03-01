/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 01 03 01
 * @version 0.1
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
    float V_1, V_2, V_total; //**< water volumes */
    float T_1, T_2, T_total; //**< water temperatures */

    printf("Enter the volume and temperature of the first container, and then the second: ");
    if (scanf("%f %f %f %f", &V_1, &T_1, &V_2, &T_2) != 4) //**< validation for input correctness */
    {
        printf("Incorrect input\n");
        return 1;
    }

    if (V_1 <= 0 || V_2 <= 0 || T_1 <= 0 || T_2 <= 0) //**< validation for mathematical correctness */
    {
        printf("Incorrect mathematical input\n");
        return 2;
    }
    
    V_total = V_1 + V_2; //**< total volume */
    T_total = (V_1 * T_1 + V_2 * T_2) / V_total; //**< total temperature */

    printf("The total volume and temperature: %.6f %.6f", V_total, T_total);
    return 0;
}
