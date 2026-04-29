#include <stdio.h>
#include "functions.h"


/**
 * @brief symmetric row swapping
 * 
 * @param row_1 - the first row to swap
 * @param row_2 - the second row to swap
 * @param column - starting column index for swapping
 * @param cols - number of columns
 * 
 * @return void
 */
void change_rows(int row_1[], int row_2[], size_t column, size_t cols)
{
    int temp;

    for (size_t col = column; col <= cols - column - 1; col++)
    {
        temp = row_1[col];
        row_1[col] = row_2[col];
        row_2[col] = temp;
    }
}

/**
 * @brief performs symmetric row swapping with decreasing column area
 * 
 * @param matrix - matrix to modify
 * @param rows - number of rows
 * @param cols - number of columns
 * 
 * @return void
 */
void switch_rows(int matrix[MAX_SIZE][MAX_SIZE], size_t rows, size_t cols)
{
    size_t col = ZERO_INDEX;

    for (size_t row = 0; row <= rows / 2; row++)
    {
        change_rows(matrix[row], matrix[rows - row - 1], col, cols);
        col++;
    }
}
