#include <stdio.h>
#include "functions.h"


/**
 * @brief symmetric row swapping
 * 
 * @param matrix - matrix for rows to swap
 * @param row - index of the first row
 * @param column - starting column index for swapping
 * @param rows - number of rows
 * @param cols - number of columns
 * 
 * @return void
 */
void change_rows(int matrix[MAX_SIZE][MAX_SIZE], size_t row, size_t column, size_t rows, size_t cols)
{
    int temp;

    for (size_t col = column; col <= cols - column - 1; col++)
    {
        temp = matrix[row][col];
        matrix[row][col] = matrix[rows - row - 1][col];
        matrix[rows - row - 1][col] = temp;
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
        change_rows(matrix, row, col, rows, cols);
        col++;
    }
}
