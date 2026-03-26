/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 01 07 05
 * @version 0.2
 * @date 2026-03-01
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>
#include <math.h>

#define CHECK_POS 0.0 /**< the number to check for positivity */
#define CHECK_LESS_ONE 1.0 /**< checking that the number is less than 1 */
#define SUCCESS 0 /**< success return code */
#define INP_ERR 1 /**< input error return code */
#define MATH_ERR 2 /**< mathematical error return code */

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
 * SUCCESS — successful completion
 * INP_ERR — input error
 * MATH_ERR — incorrect mathematical data
 */
int main(void)
{
    float abs_accuracy, rel_accuracy; /**< absolute and realtive accuracy */
    float f_x; /**< f(x) */
    float s_x = 0; /**< s(x) */
    float eps; /**< epsylon */
    float cur_term = 1.0f; /**< current term */
    float x;
    int n = 1;

    printf("Enter x (|x| < 1) and epsilon accuracy (0 < eps <= 1): ");
    /** validation for input correctness */
    if (scanf("%f %f", &x, &eps) != 2)
    {
        printf("Incorrect input");
        return INP_ERR;
    }
    /** validation for mathematical correctness */
    if (eps <= CHECK_POS || eps > CHECK_LESS_ONE || fabs(x) >= CHECK_LESS_ONE)
    {
        printf("Incorrect mathematical input");
        return MATH_ERR;
    }

    f_x = 1.0f / sqrtf(1.0f - x * x); /**< f(x) */

    /** calculating s(x) with epsilon accuracy */
    while (cur_term >= eps)
    {
        s_x += cur_term;
        cur_term = next_term(n, x, cur_term);
        n ++;
    }

    abs_accuracy = fabsf(f_x - s_x); /**< absolute accuracy */
    rel_accuracy = abs_accuracy / fabsf(f_x); /**< relative accuracy */

    printf("The result f_x, s_x, absolute accuracy and relative accuracy: %f %f %f %f", \
    f_x, s_x, abs_accuracy, rel_accuracy);

    return SUCCESS;
}
