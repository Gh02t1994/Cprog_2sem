#include <stdio.h>
#include "functions.h"

/**
 * @brief calculates the average value of numbers in a file
 * 
 * @param f - file
 * @param avg - pointer to store the calculated average value
 * 
 * @return int
 * SUCCESS - if average was successfully calculated
 * INCORRECT_INPUT - if the file contains no valid numbers
 */
int calc_avg(FILE *f, double *avg)
{
    int count_number = ZERO;
    double cur_number;
    double sum = ZERO;

    while (fscanf(f, "%lf", &cur_number) == 1)
    {
        sum += cur_number;
        count_number++;
    }

    if (count_number == ZERO)
        return INCORRECT_INPUT;

    *avg = sum / count_number;

    return SUCCESS;
}

/**
 * @brief finds the number in the file that is closest to the given average value
 * 
 * @param f - file
 * @param avg - average value to compare against
 * 
 * @return double
 * near_number - number from the file with minimal difference from the average
 */
double search_nearest(FILE *f, double avg)
{
    double min_diff = START, cur_diff;
    double cur_number, near_number;

    while (fscanf(f, "%lf", &cur_number) == 1)
    {
        cur_diff = fabs(cur_number - avg);
        
        if (min_diff == START || cur_diff < min_diff)
        {
            min_diff = cur_diff;
            near_number = cur_number;
        }
    }

    return near_number;
}
