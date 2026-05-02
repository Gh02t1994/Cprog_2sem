#include <stdio.h>
#include "functions.h"

/**
 * @brief sorts an array of words in lexicographical order
 * 
 * @param words - 2D array containing words to sort
 * @param size - number of words in the array
 * 
 * @return void
 */
void sort_words(char words[MAX_COUNT_WORDS][MAX_LENGHT_WORD], size_t size)
{
    char temp[MAX_SIZE];

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            if (strcmp(words[i], words[j]) > CHECK_POSITIVITY)
            {
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }
}

/**
 * @brief removes duplicate consecutive words from a sorted array
 * 
 * @param words - sorted array of words
 * @param size - number of words in the array
 * 
 * @return size_t
 * size - new size after removing duplicates
 */
size_t del_duplicates(char words[MAX_COUNT_WORDS][MAX_LENGHT_WORD], size_t size)
{
    if (size < 2)
    {
        return size;
    }

    for (size_t i = 0; i < size - 1; i++)
    {
        if (strcmp(words[i], words[i + 1]) == CHECK_POSITIVITY)
        {
            for (size_t j = i; j < size - 1; j++)
            {
                strcpy(words[j], words[j + 1]);
            }
            size--;
            i--;
        }
    }

    return size;
}

/**
 * @brief checks if a character is not a punctuation separator
 * 
 * @param symbol - character to check
 * 
 * @return int
 * TRUE - if character is not a separator
 * FALSE - otherwise
 */
int is_not_sep(char symbol)
{
    char marks[] = PUNC_MARKS;
    for (size_t i = 0; marks[i] != END; i++)
    {
        if (symbol == marks[i])
            return FALSE;
    }

    return TRUE;
}

/**
 * @brief splits a string into words using punctuation marks as delimiters
 * 
 * @param str - input string to split
 * @param words - 2D array to store extracted words
 * @param numb_word - pointer to current word index
 * @param count_words - pointer to store total word count
 * 
 * @return void
 */
void split_str(char str[], char words[][MAX_LENGHT_WORD], size_t *numb_word, int *count_words)
{
    size_t pos = ZERO_INDEX, ind_char = ZERO_INDEX;

    while (str[pos] != END)
    {
        if (is_not_sep(str[pos]))
        {
            words[*numb_word][ind_char++] = str[pos];
        }
        else
        {
            if (ind_char > ZERO_INDEX)
            {
                words[(*numb_word)++][ind_char] = END; 
                ind_char = ZERO_INDEX;
            }
        }
        pos++;
    }

    if (ind_char > ZERO_INDEX)
    {
        words[*numb_word][ind_char] = END;
        *count_words = *numb_word + 1;
    }
    else
    {
        *count_words = *numb_word;
    }
}
