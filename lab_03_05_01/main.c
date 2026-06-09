/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 03 05 01
 * @version 0.1
 * @date 2026-04-19
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>
#include "inp_out.h"
#include "functions.h"

/**
 * @brief entering a matrix and and shift the elements by 3 to the left,
 * the sum of the digits of which is greater than 10
 * 
 * @return int
 * SUCCESS - success return code
 * INPUT_ERROR - input error return code
 * LOGICAL_ERROR - logical error return code
 */
int main(void)
{
    int matrix[MAX_SIZE][MAX_SIZE]; /**< matrix */
    size_t row_size, col_size; /**< matrix size */
    int rc; /**< input return code */

    /** input sizes */
    rc = input_size(&row_size, &col_size);
    if (rc != SUCCESS)
    {
        return rc;
    }

    /** input matrix */
    if (input_matrix(matrix, row_size, col_size) == INPUT_ERROR)
    {
        return INPUT_ERROR;
    }

    if (modify_matrix(matrix, row_size, col_size) != SUCCESS)
    {
        return NO_NUMBER;
    }

    output_matrix(matrix, row_size, col_size);

    return SUCCESS;
}
