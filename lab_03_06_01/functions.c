#include <stdio.h>
#include "functions.h"

/**
 * @brief fills a matrix in spiral order using elements from an array
 * 
 * @param matrix - destination matrix to fill
 * @param arr - source array containing elements
 * @param rows - number of rows
 * @param cols - number of columns
 * 
 * @return void
 */
void make_matrix(int matrix[MAX_SIZE][MAX_SIZE], int arr[], int rows, int cols)
{
    int top = ZERO_INDEX, bottom = rows - 1;
    int left = ZERO_INDEX, right = cols - 1;
    int index_arr = ZERO_INDEX;
    int total = rows * cols;

    while (top <= bottom && left <= right)
    {
        for (int col = left; col <= right; col++)
        {
            matrix[top][col] = arr[index_arr++];
        }
        top++;
        if (index_arr >= total)
        {
            break;
        }

        for (int row = top; row <= bottom; row++)
        {
            matrix[row][right] = arr[index_arr++];
        }
        right--;
        if (index_arr >= total)
        {
            break;
        }

        if (top <= bottom)
        {
            for (int col = right; col >= left; col--)
            {
                matrix[bottom][col] = arr[index_arr++];
            }
            bottom--;
        }
        if (index_arr >= total)
        {
            break;
        }

        if (left <= right)
        {
            for (int row = bottom; row >= top; row--)
            {
                matrix[row][left] = arr[index_arr++];
            }
            left++;
        }
    }
}
