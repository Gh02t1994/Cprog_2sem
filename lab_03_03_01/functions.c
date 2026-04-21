#include <stdio.h>
#include "functions.h"

/**
 * @brief finds the maximum element in a row
 * 
 * @param matrix - input matrix
 * @param row - index of the row to search
 * @param cols - number of columns
 * 
 * @return int
 * maxim - maximum value in the row
 */
int search_max(int matrix[MAX_SIZE][MAX_SIZE], size_t row, size_t cols)
{
    int maxim = matrix[row][ZERO_INDEX];

    for (size_t col = ZERO_INDEX + 1; col < cols; col++)
    {
        if (matrix[row][col] > maxim)
        {
            maxim = matrix[row][col];
        }
    }

    return maxim;
}

/**
 * @brief swaps two rows in the matrix
 * 
 * @param matrix - matrix for rows to swap
 * @param row_1 - index of the first row
 * @param row_2 - index of the second row
 * @param cols - number of columns
 * 
 * @return void
 */
void change_rows(int matrix[MAX_SIZE][MAX_SIZE], size_t row_1, size_t row_2, size_t cols)
{
    int temp;

    for (size_t col = 0; col < cols; col++)
    {
        temp = matrix[row_1][col];
        matrix[row_1][col] = matrix[row_2][col];
        matrix[row_2][col] = temp;
    }
}

/**
 * @brief sorts matrix rows by their minimum element in row
 * 
 * @param matrix - matrix to sort
 * @param rows - number of rows 
 * @param cols - number of columns
 * 
 * @return void
 */
void sort_matrix(int matrix[MAX_SIZE][MAX_SIZE], size_t rows, size_t cols)
{
    for (size_t row_i = 0; row_i < rows; row_i++)
    {
        for (size_t row_j = row_i; row_j < rows; row_j++)
        {
            if (search_max(matrix, row_i, cols) < search_max(matrix, row_j, cols))
            {
                change_rows(matrix, row_i, row_j, cols);
            }
        }
    }
}
