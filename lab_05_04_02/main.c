/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 05 04 02
 * @version 0.1
 * @date 2026-05-25
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>
#include <string.h>
#include "codes.h"
#include "functions.h"

/**
 * @brief sorting, suffixing, and adding a new product to a file
 * and with a file consisting of structures-product information
 * 
 * @return int
 * rc - return code
 * FILE_NOT_EXIST - file not exist return code
 * INCORRECT_INPUT - incorrect input return code
 * WRONG_COUNT_ARGV - wrong count argv return code
 */
int main(int argc, char **argv)
{
    int rc;

    if (argc == 4)
    {
        rc = argc_4(argv);

        if (rc != SUCCESS)
            return rc;
    }
    else if (argc == 3)
    {
        rc = argc_3(argv);

        if (rc != SUCCESS)
            return rc;
    }
    else
        return WRONG_COUNT_ARGV;

    return SUCCESS;
}
