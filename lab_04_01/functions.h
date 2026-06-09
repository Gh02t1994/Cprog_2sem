#ifndef FUNCTIONS

#define FUNCTIONS

#include <stdio.h>
#include "const.h"
#include "codes.h"

char *my_strpbrk(char str[], char sym[]);

size_t my_strspn(char str[], char sym[]);

size_t my_strcspn(char str[], char sym[]);

char *my_strchr(char str[], char sym);

char *my_strrchr(char str[], char sym);

#endif
