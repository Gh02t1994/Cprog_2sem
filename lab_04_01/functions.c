#include <stdio.h>
#include "functions.h"

/**
 * @brief finds the first occurrence of any character from sym in str
 * 
 * @param str - string to search in
 * @param sym - string containing characters to search for
 * 
 * @return char* 
 * &str[min_ind] - pointer to first matching character in str, or NULL if not found
 */
char *my_strpbrk(char str[], char sym[])
{
    size_t ind_sym, ind_str = 0;

    while (str[ind_str] != END)
    {
        ind_sym = ZERO_INDEX;
        
        while (sym[ind_sym] != END)
        {
            if (str[ind_str] == sym[ind_sym])
            {
                return &str[ind_str];
            }
            ind_sym++;
        }
        ind_str++;
    }
    
    return NULL;
}

/**
 * @brief returns the length of the initial segment of str that consists of characters from sym
 * 
 * @param str - string to examine
 * @param sym - string containing allowed characters
 * 
 * @return size_t
 * count - number of characters in the initial segment matching sym
 */
size_t my_strspn(char str[], char sym[])
{
    size_t ind_sym, ind_str = ZERO_INDEX;
    size_t count = ZERO;
    int found;
    
    while (str[ind_str] != END)
    {
        ind_sym = ZERO;
        found = FALSE;

        while (sym[ind_sym] != END)
        {
            if (sym[ind_sym++] == str[ind_str])
            {
                found = TRUE;
            }
        }

        if (found == 0)
        {
            break;
        }

        ind_str++;
        count++;
    }

    return count;
}

/**
 * @brief returns the length of the initial segment of str that does not contain any characters from sym
 * 
 * @param str - string to examine
 * @param sym - string containing characters to reject
 * 
 * @return size_t 
 * ind_str - number of characters before first matching character from sym
 */
size_t my_strcspn(char str[], char sym[])
{
    size_t ind_sym, ind_str = ZERO_INDEX;
    
    while (str[ind_str] != END)
    {
        ind_sym = ZERO_INDEX;

        while (sym[ind_sym] != END)
        {
            if (sym[ind_sym++] == str[ind_str])
            {
                return ind_str;
            }
        }
        ind_str++;
    }

    return ind_str; 
}

/**
 * @brief finds the first occurrence of character sym in str
 * 
 * @param str - string to search in
 * @param sym - character to search for
 * 
 * @return char*
 * &str[ind_start] - pointer to first occurrence of sym in str, or NULL if not found
 */
char *my_strchr(char str[], char sym)
{
    size_t ind_str = ZERO_INDEX;

    while (str[ind_str] != END)
    {
        if (str[ind_str] == sym)
        {
            return &str[ind_str];
        }
        ind_str++;
    }
    
    if (str[ind_str] == sym)
    {
        return &str[ind_str];
    }

    return NULL;
}

/**
 * @brief finds the last occurrence of character sym in str
 * 
 * @param str - string to search in
 * @param sym - character to search for
 * 
 * @return char*
 * &str[ind_start] - pointer to last occurrence of sym in str, or NULL if not found
 */
char *my_strrchr(char str[], char sym)
{
    size_t ind_str = ZERO_INDEX, ind_start = MAX_SIZE;

    while (str[ind_str] != END)
    {
        if (str[ind_str++] == sym)
        {
            ind_start = ind_str - 1;
        }
    }

    if (str[ind_str] == sym)
    {
        ind_start = ind_str;
    }

    if (ind_start == MAX_SIZE)
    {
        return NULL;
    }

    return &str[ind_start];
}
