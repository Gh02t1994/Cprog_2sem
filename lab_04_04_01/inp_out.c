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
    fgets(str, MAX_SIZE, stdin);

    size_t lenght =  strlen(str);

    if (lenght > 0 && str[lenght - 1] == '\n')
    {
        str[lenght - 1] = '\0';
    }
    else
    {
        char last_char = getchar();

        if (last_char != EOF)
        {
            return LOGICAL_ERROR;
        }
    }

    return SUCCESS;
}
