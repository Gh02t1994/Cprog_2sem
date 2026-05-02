/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 04 01
 * @version 0.1
 * @date 2026-04-28
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>
#include "const.h"
#include "codes.h"
#include "testing.h"

/**
 * @brief counting failed tests for written functions
 * 
 * @return int
 * SUCCESS - success return code
 */
int main(void)
{
    int count_fail = ZERO;

    count_fail += test_strpbrk();
    count_fail += test_strspn();
    count_fail += test_strcspn();
    count_fail += test_strchr();
    count_fail += test_strrchr();

    printf("%d", count_fail);

    return SUCCESS;
}
