#include <stdio.h>
#include "inp_out.h"

/**
 * @brief reads and validates the number of strings from input
 * 
 * @param count_str - pointer to store the input count value
 * 
 * @return int
 * INPUT_ERROR - input error return code
 * LOGICAL_ERROR - logical error return code
 * SUCCESS - success return code
 */
int input_count_str(int *count_str)
{
    if (scanf("%d", count_str) != 1)
    {
        return INPUT_ERROR;
    }

    if (*count_str != COUNT_STRINGS)
    {
        return LOGICAL_ERROR;
    }

    getchar();
    return SUCCESS;
}

/**
 * @brief reads a string from standard input
 * 
 * @param str - character array to store the input string
 * 
 * @return int
 * INPUT_ERROR - input error return code
 * LOGICAL_ERROR - logical error return code
 * SUCCESS - success return code
 */
int input_str(char str[])
{
    if (fgets(str, MAX_SIZE, stdin) == NULL)
    {
        return INPUT_ERROR;
    }

    char last_char = getchar();

    if (last_char != EOF)
    {
        return LOGICAL_ERROR;
    }

    return SUCCESS;
}

/**
 * @brief prints an array of words to standard output
 * 
 * @param words - 2D array containing words to print
 * @param size - number of words in the array
 * 
 * @return void
 */
void output_words(char words[][MAX_LENGHT_WORD], size_t size)
{
    printf("Result: ");
    for (size_t ind_word = 0; ind_word < size - 1; ind_word++)
    {
        printf("%s ", words[ind_word]);
    }

    printf("%s", words[size - 1]);
}

