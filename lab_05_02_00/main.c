/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 05 02 00
 * @version 0.1
 * @date 2026-05-24
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>
#include "codes.h"
#include "functions.h"

/**
 * @brief finding the number closest to the average
 * 
 * @return int
 * rc - return code
 * FILE_NOT_EXIST - file not exist return code
 */
int main(int argc, char **argv)
{
    double near_number;
    double avg;
    FILE *f;
    int rc;

    if (argc != 2)
        return WRONG_COUNT_ARGV;
    
    f = fopen(argv[1], "r");
    if (f == NULL)
        return FILE_NOT_EXIST;

    rc = calc_avg(f, &avg);
    if (rc != SUCCESS)
        return rc;
    
    rewind(f);
    near_number = search_nearest(f, avg);

    printf("%lf", near_number);
    
    fclose(f);
    return SUCCESS;
}
