/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 04 04 01
 * @version 0.1
 * @date 2026-04-30
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>
#include "codes.h"
#include "const.h"
#include "inp_out.h"
#include "functions.h"

/**
 * @brief entering a string and recognizing a real number in it
 * 
 * @return int
 * SUCCESS - success return code
 * rc - input error return code
 */
int main(void)
{
    char str[MAX_SIZE];
    int rc;

    rc = input_str(str);
    if (rc != SUCCESS)
    {
        return rc;
    }

    del_space(str);

    if (is_float(str))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return SUCCESS;
}
