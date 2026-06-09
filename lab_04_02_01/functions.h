#ifndef FUNCTIONS_H

#define FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include "const.h"
#include "codes.h"

void sort_words(char words[MAX_COUNT_WORDS][MAX_LENGHT_WORD], size_t size);

size_t del_duplicates(char words[MAX_COUNT_WORDS][MAX_LENGHT_WORD], size_t size);

int split_str(char str[], char words[][MAX_LENGHT_WORD], size_t *numb_word, int *count_words);

#endif
