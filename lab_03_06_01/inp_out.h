#ifndef INP_OUT_H

#define INP_OUT_H

#include <stdio.h>
#include "const.h"
#include "codes.h"

int input_size(size_t *size_rows, size_t *size_cols);

int input_matrix(int arr[], size_t rows, size_t cols);

void output_matrix(int matrix[MAX_SIZE][MAX_SIZE], size_t rows, size_t cols);

#endif
