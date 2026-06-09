#include <stdio.h>
#include "functions.h"

/**
 * @brief checks if a character is a digit
 * 
 * @param chr - character to check
 * 
 * @return int - non-zero if character is a digit, zero otherwise
 */
int my_isdigit(char chr)
{
    return chr >= '0' && chr <= '9';
}


/**
 * @brief removes leading and trailing spaces from a string
 * 
 * @param str - string to trim
 * 
 * @return int
 * LOGICAL_ERROR - logical error return code
 */
int del_space(char str[])
{
    size_t start = ZERO_INDEX, end;

    str[strcspn(str, "\n")] = END;
    while (isspace((unsigned char)str[start]))
    {
        start++;
    }
    if (str[start] == END)
    {
        return LOGICAL_ERROR;
    }

    size_t i = ZERO_INDEX;
    while (str[start] != END)
    {
        str[i++] = str[start++];
    }
    str[i] = END;

    end = strlen(str);
    while (end > ZERO_INDEX && isspace((unsigned char)str[end - 1]))
    {
        end--;
    }

    str[end] = END;
    return SUCCESS;
}

/**
 * @brief skips all consecutive digits in a string from current position
 * 
 * @param str - input string
 * @param i - pointer to current index
 * 
 * @return void
 */
void while_dig(char str[], size_t *i)
{
    while (my_isdigit(str[*i]))
    {
        (*i)++;
    }
}

/**
 * @brief handles parsing when first character after optional sign is a digit
 * 
 * @param str - input string
 * @param i - pointer to current index
 * @param was_digit - pointer to flag indicating if any digit was seen
 * 
 * @return void
 */
int first_is_digit(char str[], size_t *i, int *was_digit)
{
    *was_digit = TRUE;

    if (str[*i] == '0')
    {
        (*i)++;

        if (my_isdigit(str[*i]))
        {
            return FALSE;
        }
    }

    while_dig(str, i);

    if (str[*i] == '.')
    {
        (*i)++;
        while_dig(str, i);
    }

    return TRUE;
}

/**
 * @brief handles parsing when first character after optional sign is a decimal point
 * 
 * @param str - input string
 * @param i - pointer to current index (will be advanced)
 * @param was_digit - pointer to flag indicating if any digit was seen
 * 
 * @return int
 * FALSE if no digit found after point
 * TRUE otherwise
 */
int first_is_point(char str[], size_t *i, int *was_digit)
{
    (*i)++;

    if (!my_isdigit(str[*i]))
    {
        return FALSE;
    }

    *was_digit = TRUE;

    while_dig(str, i);

    return TRUE;
}

/**
 * @brief handles parsing of the exponent part
 * 
 * @param str - input string
 * @param i - pointer to current index
 * 
 * @return int
 * FALSE if exponent format is invalid
 * TRUE otherwise
 */

int first_is_exp(char str[], size_t *i)
{
    (*i)++;

    if (str[*i] == '+' || str[*i] == '-')
    {
        (*i)++;
    }

    if (!my_isdigit(str[*i]))
    {
        return FALSE;
    }

    while_dig(str, i);

    return TRUE;
}

/**
 * @brief checks if a string represents a valid floating-point number
 * 
 * @param str - string to validate
 * 
 * @return int - non-zero if string is a valid float, zero otherwise
 */
int is_float(char str[])
{
    size_t i = ZERO_INDEX;
    int was_digit = FALSE;

    if (str[i] == '+' || str[i] == '-')
    {
        i++;
    }

    if (my_isdigit(str[i]))
    {
        if (first_is_digit(str, &i, &was_digit) == FALSE)
        {
            return FALSE;
        }
    }
    else if (str[i] == '.')
    {
        if (first_is_point(str, &i, &was_digit) == FALSE)
        {
            return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    if (str[i] == 'e' || str[i] == 'E')
    {
        if (first_is_exp(str, &i) == FALSE)
        {
            return FALSE;
        }
    } 
    
    return was_digit && str[i] == END;
}
