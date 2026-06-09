/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 04 02 01
 * @version 0.1
 * @date 2026-04-28
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
 * @brief entering a string, splitting words into an array, and lexicographic ordering
 * 
 * @return int
 * SUCCESS - success return code
 * rc_inp - input error return code
 * LOGICAL_ERROR - logical error return code
 */
int main(void)
{
    char str[MAX_SIZE], words[MAX_COUNT_WORDS][MAX_LENGHT_WORD];
    size_t numb_word = ZERO_INDEX;
    int count_words;
    int rc_inp;

    rc_inp = input_str(str);
    if (rc_inp != SUCCESS)
        return rc_inp;

    if (split_str(str, words, &numb_word, &count_words) != SUCCESS)
    {
        return LOGICAL_ERROR;
    }

    if (count_words == 0)
        return LOGICAL_ERROR;

    sort_words(words, count_words);
    count_words = del_duplicates(words, count_words);
    output_words(words, count_words);

    return SUCCESS;
}
