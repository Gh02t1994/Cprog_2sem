/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 05 03
 * @version 0.1
 * @date 2026-05-24
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>
#include <string.h>
#include "codes.h"
#include "functions.h"

/**
 * @brief creating, outputting, and sorting a file
 * 
 * @return int
 * rc - return code
 * FILE_NOT_EXIST - file not exist return code
 * INCORRECT_INPUT - incorrect input return code
 * WRONG_COUNT_ARGV - wrong count argv return code
 */
int main(int argc, char **argv)
{
    size_t number;
    if (argc == 4)
    {
        if (strcmp(argv[1], "c") == ZERO && check_is_num(argv[2], &number) == SUCCESS)
        {
            FILE *f = fopen(argv[3], "wb");
            make_new_file(f, number);
            fclose(f);
        }
        else if (strcmp(argv[1], "export") == ZERO)
        {
            if (check_file(argv[2]) != SUCCESS)
                return FILE_NOT_EXIST;

            bin_to_txt(argv[2], argv[3]);
        }
        else if (strcmp(argv[1], "import") == ZERO)
        {
            if (check_file(argv[2]) != SUCCESS)
                return FILE_NOT_EXIST;

            txt_to_bin(argv[2], argv[3]);
        }
        else
            return INCORRECT_INPUT;
    }
    else if (argc == 3)
    {
        if (strcmp(argv[1], "p") == ZERO)
        {
            if (check_file(argv[2]) != SUCCESS)
                return FILE_NOT_EXIST;

            FILE *f = fopen(argv[2], "rb");
            if (print_file(f) != SUCCESS)
                return EMPTY_FILE;
            fclose(f);
        }
        else if (strcmp(argv[1], "s") == ZERO)
        {
            if (check_file(argv[2]) != SUCCESS)
                return FILE_NOT_EXIST;

            FILE *f = fopen(argv[2], "rb+");
            if (sort_file(f) != SUCCESS)
                return EMPTY_FILE;
            fclose(f);
        }
        else
            return INCORRECT_INPUT;
    }
    else
        return WRONG_COUNT_ARGV;

    return SUCCESS;
}
