#include <stdio.h>
#include "functions.h"

/**
 * @brief fills the top row of the current spiral layer from left to right
 * 
 * @param matrix - matrix to fill
 * @param number - pointer to current filling number
 * @param top - pointer to current top boundary
 * @param left - left boundary of current layer
 * @param right - right boundary of current layer
 * 
 * @return void
 */
void up_row(int matrix[MAX_SIZE][MAX_SIZE], int *number, int *top, int left, int right)
{
    for (int col = left; col <= right; col++)
    {
        matrix[*top][col] = (*number)++;
    }
    (*top)++;
}

/**
 * @brief fills the right column of the current spiral layer from top to bottom
 * 
 * @param matrix - matrix to fill
 * @param number - pointer to current filling number
 * @param top - top boundary of current layer
 * @param bottom - bottom boundary of current layer
 * @param right - pointer to current right boundary
 * 
 * @return void
 */
void right_col(int matrix[MAX_SIZE][MAX_SIZE], int *number, int top, int bottom, int *right)
{
    for (int row = top; row <= bottom; row++)
    {
        matrix[row][*right] = (*number)++;
    }
    (*right)--;
}

/**
 * @brief fills the bottom row of the current spiral layer from right to left
 * 
 * @param matrix - matrix to fill
 * @param number - pointer to current filling number
 * @param top - top boundary of current layer
 * @param bottom - pointer to current bottom boundary
 * @param left - left boundary of current layer
 * @param right - right boundary of current layer
 * 
 * @return void
 */
void down_row(int matrix[MAX_SIZE][MAX_SIZE], int *number, int top, int *bottom, int left, int right)
{
    if (top <= *bottom)
    {
        for (int col = right; col >= left; col--)
        {
            matrix[*bottom][col] = (*number)++;
        }
        (*bottom)--;
    }
}

/**
 * @brief fills the left column of the current spiral layer from bottom to top
 * 
 * @param matrix - matrix to fill
 * @param number - pointer to current filling number
 * @param top - top boundary of current layer
 * @param bottom - bottom boundary of current layer
 * @param left - pointer to current left boundary
 * @param right - right boundary of current layer
 * 
 * @return void
 */
void left_col(int matrix[MAX_SIZE][MAX_SIZE], int *number, int top, int bottom, int *left, int right)
{
    if (*left <= right)
    {
        for (int row = bottom; row >= top; row--)
        {
            matrix[row][*left] = (*number)++;
        }
        (*left)++;
    }
}

/**
 * @brief fills a matrix in spiral order using elements from an array
 * 
 * @param matrix - destination matrix to fill
 * @param rows - number of rows
 * @param cols - number of columns
 * 
 * @return void
 */
void make_matrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
    int top = ZERO_INDEX, bottom = rows - 1;
    int left = ZERO_INDEX, right = cols - 1;
    int number = ZERO_INDEX + 1;

    while (top <= bottom && left <= right)
    {
        up_row(matrix, &number, &top, left, right);
        if (top > bottom) break;

        right_col(matrix, &number, top, bottom, &right);
        if (left > right) break;

        down_row(matrix, &number, top, &bottom, left, right);
        if (top > bottom) break;

        left_col(matrix, &number, top, bottom, &left, right);
    }
}
