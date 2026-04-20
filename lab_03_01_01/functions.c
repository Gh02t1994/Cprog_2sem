#include <stdio.h>
#include "functions.h"

/**
 * @brief checking for row symmetry
 * 
 * @param matrix - matrix to print
 * @param res_arr - array to fill
 * @param rows - rows count
 * @param cols - columns count
 * 
 * @return void
 */
void check_symmetry(int matrix[MAX_SIZE][MAX_SIZE], int res_arr[], size_t rows, size_t cols)
{
    int sym_flag; /**< the flag indicates the symmetry of the row */

    for (size_t row = 0; row < rows; row++)
    {
        sym_flag = SYMMETRY;
        for (size_t col = 0; col <= cols / 2; col++)
        {
            if (matrix[row][col] != matrix[row][cols - col - 1])
            {
                sym_flag = NOT_SYMMERY;
                break;
            }
        }

        res_arr[row] = sym_flag;
    }
}
