#include <stdio.h>
#include "functions.h"

/**
 * @brief finds the maximum element in a row
 * 
 * @param row - row to search
 * @param cols - number of columns
 * 
 * @return int
 * maxim - maximum value in the row
 */
int search_max(int row[], size_t cols)
{
    int maxim = row[ZERO_INDEX];

    for (size_t col = ZERO_INDEX + 1; col < cols; col++)
    {
        if (row[col] > maxim)
        {
            maxim = row[col];
        }
    }

    return maxim;
}

/**
 * @brief swaps two rows in the matrix
 * 
 * @param row_1 - the first row to swap
 * @param row_2 - the second row to swap
 * @param cols - number of columns
 * 
 * @return void
 */
void change_rows(int row_1[], int row_2[], size_t cols)
{
    int temp;

    for (size_t col = 0; col < cols; col++)
    {
        temp = row_1[col];
        row_1[col] = row_2[col];
        row_2[col] = temp;
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
            if (search_max(matrix[row_i], cols) < search_max(matrix[row_j], cols))
            {
                change_rows(matrix[row_i], matrix[row_j], cols);
            }
        }
    }
}
