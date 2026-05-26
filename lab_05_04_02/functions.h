#ifndef FUNCTIONS_H

#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdint.h>
#include "const.h"
#include "codes.h"

typedef struct
{
    char name[MAX_NAME];
    char maker[MAX_MAKER];
    uint32_t price;
    uint32_t count;
} product;

int check_file(char str[]);

size_t take_array_products(product p[], FILE *f);

int sort_arr_prod(FILE *f_src, FILE *f_dst);

int print_if_substr(char substr[], FILE *f);

int add_new_pr_in_arr(FILE *f);

int argc_4(char **argv);

int argc_3(char **argv);

#endif
