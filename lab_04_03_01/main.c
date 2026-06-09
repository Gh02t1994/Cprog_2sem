/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 04 03 01
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
 * @brief entering a string, creating a new string of words in reverse order,
 * composing words from the first characters and deleting words equal to the last
 * 
 * @return int
 * SUCCESS - success return code
 * rc_inp - input error return code
 * LOGICAL_ERROR - logical error return code
 */
int main(void)
{
    char str[MAX_SIZE], new_str[MAX_SIZE], words[MAX_COUNT_WORDS][MAX_LENGHT_WORD];
    int count_words;
    int rc;

    rc = input_str(str);
    if (rc != SUCCESS)
    {
        return rc;
    }

    rc = split_str(str, words, &count_words);
    if (rc != SUCCESS)
    {
        return rc;
    }

    make_new_str(new_str, words, count_words);

    if (strlen(new_str) == ZERO)
    {
        return LOGICAL_ERROR;
    }

    output_str(new_str);

    return SUCCESS;
}
