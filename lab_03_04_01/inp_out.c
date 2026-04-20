#include <stdio.h>
#include "inp_out.h"

/**
 * @brief entering sizes
 * 
 * @param size_rows - rows count
 * @param size_cols - columns count
 * 
 * @return int
 * INPUT_ERROR - input error return code
 * LOGICAL_ERROR - logical error return code
 * SUCCESS - success return code
 */
int input_size(size_t *size_rows, size_t *size_cols)
{
    printf("Enter matrix size up to 10: ");

    /** validation for input correctness */
    if (scanf("%zu %zu", size_rows, size_cols) != 2)
    {
        printf("Incorrect input");
        return INPUT_ERROR;
    }

    /** validation for logical correctness */
    if (*size_rows <= CHECK_POSITIVITY || *size_rows > MAX_SIZE ||
        *size_cols <= CHECK_POSITIVITY || *size_cols > MAX_SIZE)
    {
        printf("Logical error");
        return LOGICAL_ERROR;
    }

    if (*size_rows != *size_cols)
    {
        printf("Logical error");
        return LOGICAL_ERROR;
    }

    return SUCCESS;
}

/**
 * @brief matrix input
 * 
 * @param matrix - matrix to fill
 * @param rows - rows count
 * @param cols - columns count
 * 
 * @return int
 * INPUT_ERROR - input error return code
 * SUCCESS - success return code
 */
int input_matrix(int matrix[MAX_SIZE][MAX_SIZE], size_t rows, size_t cols)
{
    printf("Enter the matrix elements: ");

    for (size_t row = 0; row < rows; row++)
    {
        for (size_t col = 0; col < cols; col++)
        {
            if (scanf("%d", &matrix[row][col]) != 1)
            {
                printf("Incorrect input");
                return INPUT_ERROR;
            }
        }
    }
    
    return SUCCESS;
}

/**
 * @brief matrix output
 * 
 * @param matrix - matrix to print
 * @param rows - rows count
 * @param cols - columns count
 * 
 * @return void
 */
void output_matrix(int matrix[MAX_SIZE][MAX_SIZE], size_t rows, size_t cols)
{
    printf("The resulting matrix: ");
    
    for (size_t row = 0; row < rows; row++)
    {
        printf("\n");
        for (size_t col = 0; col < cols; col++)
        {
            printf("%d ", matrix[row][col]);
        }
    }
}
