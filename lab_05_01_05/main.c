/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 05 01 05
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
 * @brief processing a file to find the maximum sequence of identical numbers
 * 
 * @return int
 * rc - return code
 */
int main(void)
{
    int max_count;
    int rc;

    rc = process(stdin, &max_count);
    if (rc != SUCCESS)
        return rc;

    printf("%d", max_count);

    return SUCCESS;
}
