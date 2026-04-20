/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 03 01 01
 * @version 0.1
 * @date 2026-04-19
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>
#include "codes.h"
#include "const.h"
#include "inp_out.h"
#include "functions.h"

/**
 * @brief matrix input and array output with row symmetry results
 * 
 * @return int
 * SUCCESS - success return code
 * INPUT_ERROR - input error return code
 * LOGICAL_ERROR - logical error return code
 */
int main(void)
{
    int matrix[MAX_SIZE][MAX_SIZE]; /**< matrix */
    int result_arr[MAX_SIZE]; /**< result array */
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

    /** checking symmerty */
    check_symmetry(matrix, result_arr, row_size, col_size);

    /** array output */
    output_arr(result_arr, row_size);

    return SUCCESS;
}
