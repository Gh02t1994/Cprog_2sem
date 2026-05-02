#ifndef INP_OUT_H

#define INP_OUT_H

#include <stdio.h>
#include "const.h"
#include "codes.h"

int input_count_str(int *count_str);

int input_str(char str[]);

void output_words(char words[][MAX_LENGHT_WORD], size_t size);

#endif
