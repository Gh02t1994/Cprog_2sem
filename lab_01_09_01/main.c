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
            cur_sum = -1;
            break;
        }
        else
        {
            /** checking for the positivity of a number */
            if (x >= 0)
            {
                cur_sum += sqrt(x / n);
                n ++;
            }
        }
    } while (x >= 0);

    if (n == 1)
    {
        cur_sum = -2;
    }
    
    return cur_sum;
}

/**
 * @brief calculating the number g(x) = sin(...)
 * 
 * @return int
 * 0 — successful completion
 * 1 — input error
 * 2 - no input
 */
int main(void)
{
    double sum, g_x; /**< the sum of the numbers inside the sine and the result g(x) */

    printf("Enter positive numbers; to complete the input, enter a negative number: ");
    sum = take_sum();

    /** validation for input correctness */
    if (sum == -1)
    {
        printf("Incorrect input");
        return 1;
    }
    else if (sum == -2)
    {
        printf("There is no input");
        return 2;
    }
    
    g_x = sin(sum);
    
    printf("The result g(x): %lf", g_x);
}
