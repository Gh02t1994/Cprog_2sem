/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 01 07 05
 * @version 0.1
 * @date 2026-03-01
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>
#include <math.h>

/**
 * @brief calculating the next term of the number expansion
 * 
 * @param cur_n - the current value of n
 * @param cur_x - the current value of x
 * @param old_term - previous term
 * 
 * @return float
 * new_term - the next term of the number expansion
 */
float next_term(int cur_n, float cur_x, float old_term)
{
    float new_term = (old_term * (2 * cur_n - 1) * cur_x * cur_x) / (2 * cur_n);

    return new_term;
}

/**
 * @brief сalculation of the numbers s(x), f(x), absolute and relative accuracy
 * 
 * @return int
 * 0 — successful completion
 * 1 — input error
 * 2 — incorrect mathematical data
 */
int main(void)
{
    float abs_accuracy, rel_accuracy, f_x, s_x = 0;
    float x, eps;
    float cur_term = 1;
    int n = 1;

    printf("Enter x (|x| < 1) and epsilon accuracy (0 < eps <= 1): ");
    /** validation for input correctness */
    if (scanf("%f %f", &x, &eps) != 2)
    {
        printf("Incorrect input");
        return 1;
    }
    /** validation for mathematical correctness */
    if (eps <= 0 || eps > 1 || fabs(x) >= 1)
    {
        printf("Incorrect mathematical input");
        return 2;
    }

    f_x = 1 / sqrt(1 - x * x); /**< f(x) */

    /** calculating s(x) with epsilon accuracy */
    while (cur_term >= eps)
    {
        s_x += cur_term;
        cur_term = next_term(n, x, cur_term);
        n ++;
    }

    abs_accuracy = fabs(f_x - s_x); /**< absolute accuracy */
    rel_accuracy = abs_accuracy / fabs(f_x); /**< relative accuracy */

    printf("The result f_x, s_x, absolute accuracy and relative accuracy: %f %f %f %f", \
        f_x, s_x, abs_accuracy, rel_accuracy);
}
