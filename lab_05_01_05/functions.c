#include <stdio.h>
#include "functions.h"

/**
 * @brief finds the maximum number of consecutive identical integers in a file
 * 
 * @param f - file
 * @param max_count - pointer to store the maximum count of consecutive equal numbers
 * 
 * @return int
 * SUCCESS - if processing completed successfully
 * INCORRECT_INPUT - if the file does not contain valid integer data
 */
int process(FILE *f, int *max_count)
{
    int cur_number, old_number;
    int cur_count = START;
    *max_count = cur_count;

    if (fscanf(f, "%d", &old_number) != 1)
    {
        return INCORRECT_INPUT;
    }

    while (fscanf(f, "%d", &cur_number) == 1)
    {
        if (old_number == cur_number)
        {
            cur_count++;
        }
        else
        {
            if (cur_count > *max_count)
                *max_count = cur_count;
            
            cur_count = START;
        }

        old_number = cur_number;
    }

    if (cur_count > *max_count)
    {
        *max_count = cur_count;
    }

    return SUCCESS;
}
