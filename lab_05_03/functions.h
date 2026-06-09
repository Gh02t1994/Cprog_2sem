#ifndef FUNCTIONS_H

#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "const.h"
#include "codes.h"

void make_new_file(FILE *f, size_t count);

int print_file(FILE *f);

int sort_file(FILE *f);

int check_is_num(char str[], size_t *number);

int check_file(char str[]);

void txt_to_bin(char txt_name[], char bin_name[]);

void bin_to_txt(char bin_name[], char txt_name[]);

#endif
