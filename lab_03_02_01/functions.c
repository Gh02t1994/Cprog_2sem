#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/**
 * @brief calculates the sum of digits
 * 
 * @param numb - number whose digits will be summed
 * 
 * @return int
 * sum - sum of digits
 */
int sum_digit(int numb)
{
    int sum = CHECK_POSITIVITY;
    int number = abs(numb);

    while (number > CHECK_POSITIVITY)
    {
        sum += number % DECIMAL;
        number /= DECIMAL;
    }

    return sum;
}

/**
 * @brief finds the position of the element with minimum digit sum
 * 
 * @param matrix - matrix to search in
 * @param rows - count of rows
 * @param cols - count of columns
 * @param row_pos - row position
 * @param col_pos - column position
 * 
 * @return void
 */
void search_min(int matrix [MAX_SIZE][MAX_SIZE], size_t rows, size_t cols, size_t *row_pos, size_t *col_pos)
{
    int minim = sum_digit(matrix[ZERO_INDEX][ZERO_INDEX]);
    int current;
    *row_pos = ZERO_INDEX;
    *col_pos = ZERO_INDEX;

    for (size_t row = 0; row < rows; row++)
    {
        for (size_t col = 0; col < cols; col++)
        {
            current = sum_digit(matrix[row][col]);
            if (current < minim)
            {
                minim = current;
                *row_pos = row;
                *col_pos = col;
            }
        }
    }
}

/**
 * @brief shifts elements in a row to the left
 * 
 * @param matrix - matrix for row to shift
 * @param row - index of the row to shift
 * @param cols - current count of columns
 * @param col_pos - column position of the element to remove
 * 
 * @return void
 */
void shift_row(int matrix[MAX_SIZE][MAX_SIZE], size_t row, size_t cols, size_t col_pos)
{
    for (size_t col = col_pos + 1; col < cols; col++)
    {
        matrix[row][col - 1] = matrix[row][col]; 
    }
}

/**
 * @brief shifts elements in a column upward
 * 
 * @param matrix - matrix for column to shift
 * @param rows - current count of rows
 * @param col - index of the column to shift
 * @param row_pos - row position of the element to remove
 * 
 * @return void
 */
void shift_col(int matrix[MAX_SIZE][MAX_SIZE], size_t rows, size_t col, size_t row_pos)
{
    for (size_t row = row_pos + 1; row < rows; row++)
    {
        matrix[row - 1][col] = matrix[row][col]; 
    }
}

/**
 * @brief deletes row and column from the matrix
 * 
 * @param matrix - matrix to modify
 * @param rows - count of rows
 * @param cols - count of columns
 * @param row_pos - index of the row to delete
 * @param col_pos - index of the column to delete
 * 
 * @return void
 */
void del_row_col(int matrix[MAX_SIZE][MAX_SIZE], size_t *rows, size_t *cols, size_t row_pos, size_t col_pos)
{
    for (size_t row = 0; row < *rows; row++)
    {
        shift_row(matrix, row, *cols, col_pos);
    }
    (*rows)--;

    for (size_t col = 0; col < *cols; col++)
    {
        shift_col(matrix, *rows, col, row_pos);
    }
    (*cols)--;
}
