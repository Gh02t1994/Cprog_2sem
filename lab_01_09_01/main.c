/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 01 09 01
 * @version 0.2
 * @date 2026-03-01
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>
#include <math.h>

#define EPS 1e-6 /**< epsylon */
#define CHECK_POS 0.0 /**< the number to check for positivity */
#define SUCCESS 0 /**< success return code */
#define INP_ERR 1 /**< input error return code */
#define NO_INP 2 /**< no input return code */

/**
 * @brief calculating the number g(x) = sin(...)
 * 
 * @return double
 * cur_sum - the sum of the numbers inside the sine or -1 - input error or -2 - no input
 */
double take_sum(void)
{
    double x, cur_sum = 0.0; /**< the input x and the current sum */
    int rc, n = 1; /**< return code and operation number */

    do
    {
        rc = scanf("%lf", &x);

        /** validation for input correctness */
        if (rc != 1)
        {
            cur_sum = -INP_ERR;
            break;
        }
        else
        {
            /** checking for the positivity of a number */
            if (x >= CHECK_POS)
            {
                cur_sum += sqrt(x / n);
                n ++;
            }
        }
    } while (x >= CHECK_POS);

    if (n == 1)
    {
        cur_sum = -NO_INP;
    }
    
    return cur_sum;
}

/**
 * @brief calculating the number g(x) = sin(...)
 * 
 * @return int
 * SUCCESS — successful completion
 * INP_ERR — input error
 * NO_INP — no input
 */
int main(void)
{
    double sum, g_x; /**< the sum of the numbers inside the sine and the result g(x) */

    printf("Enter positive numbers; to complete the input, enter a negative number: ");
    sum = take_sum();

    /** validation for input correctness */
    if (sum + NO_INP < EPS)
    {
        printf("There is no input");
        return NO_INP;
    }
    if (sum + INP_ERR < EPS)
    {
        printf("Incorrect input");
        return INP_ERR;
    }
    
    g_x = sin(sum);
    
    printf("The result g(x): %lf", g_x);

    return SUCCESS;
}
