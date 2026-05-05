#include <stdio.h>
#include "functions.h"

/**
 * @brief removes duplicate characters from a word, keeping only the first occurrence of each character
 * 
 * @param word - string to process
 * 
 * @return void
 */
void del_dupl_chr(char word[])
{
    size_t new_ind = ZERO_INDEX;

    for (size_t i = 0; word[i] != END; i++)
    {
        if (strchr(word, word[i]) == &word[i])
        {
            word[new_ind++] = word[i];
        }
    }

    word[new_ind] = END;
}

/**
 * @brief removes all words from the array that match the given last word
 * 
 * @param words - 2D array of words
 * @param last_word - word to compare against for removal
 * @param size - current number of words in the array
 * 
 * @return size_t
 * size - new size after removing matching words
 */
size_t del_like_last(char words[][MAX_LENGHT_WORD], char last_word[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(words[i], last_word) == ZERO)
        {
            for (size_t k = i; k < size - 1; k++)
            {
                strcpy(words[k], words[k + 1]);
            }
            size--;
            i--;
        }
    }

    return size;
}


/**
 * @brief splits a string into words using punctuation marks as delimiters via strtok
 * 
 * @param str - input string to split
 * @param words - 2D array to store extracted words
 * @param count_words - pointer to store the number of words found
 * 
 * @return int
 * SUCCESS - success return code
 * LOGICAL_ERROR - logical error return code
 */
int split_str(char str[], char words[][MAX_LENGHT_WORD], int *count_words)
{
    *count_words = ZERO;
    char *word = strtok(str, PUNC_MARKS);

    while (word != NULL && *count_words < MAX_COUNT_WORDS)
    {
        if (strlen(word) > MAX_LENGHT_WORD)
        {
            return LOGICAL_ERROR;
        }

        strcpy(words[(*count_words)++], word);
        word = strtok(NULL, PUNC_MARKS);
    }

    if (*count_words < 2 || *count_words > MAX_COUNT_WORDS)
    {
        return LOGICAL_ERROR;
    }

    return SUCCESS;
}


/**
 * @brief creates a new string by processing words in reverse order, removing duplicate characters from each word
 * 
 * @param new_str - destination string to build (must have sufficient capacity)
 * @param words - 2D array of processed words
 * @param count_words - number of words in the array
 * 
 * @return void
 */
void make_new_str(char new_str[], char words[][MAX_LENGHT_WORD], int count_words)
{
    new_str[0] = END;
    
    for (int w = count_words - 2; w >= 0; w--)
    {
        if (strcmp(words[w], words[count_words - 1]) != 0)
        {
            del_dupl_chr(words[w]);
            strcat(new_str, words[w]);

            if (w > 0)
            {
                strcat(new_str, " ");
            }
        }        
    }
}
