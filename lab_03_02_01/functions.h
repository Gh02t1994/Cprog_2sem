#ifndef FUNCTIONS_H

#define FUNCTIONS_H

#include <stdio.h>
#include "const.h"

void search_min(int matrix [MAX_SIZE][MAX_SIZE],size_t rows, size_t cols, size_t *row_pos, size_t *col_pos);

void del_row_col(int matrix[MAX_SIZE][MAX_SIZE], size_t *rows, size_t *cols, size_t row_pos, size_t col_pos);

#endif
