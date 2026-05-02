#include <stdio.h>
#include "inp_out.h"

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
 * @brief prints a string
 * 
 * @param str - string
 * 
 * @return void
 */
void output_str(char str[])
{
    printf("Result: %s\n", str);
}

