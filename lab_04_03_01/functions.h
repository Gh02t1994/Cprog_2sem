#ifndef FUNCTIONS_H

#define FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include "const.h"
#include "codes.h"

void del_dupl_chr(char word[]);

size_t del_like_last(char words[][MAX_LENGHT_WORD], char last_word[], size_t size);

int split_str(char str[], char words[][MAX_LENGHT_WORD], int *count_words);

void make_new_str(char new_str[], char words[][MAX_LENGHT_WORD], int count_words);

#endif
