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
 * @brief extracts matrix elements with digit sum greater than 10 into an array
 * 
 * @param matrix - source matrix
 * @param arr - destination array to store extracted elements
 * @param rows - number of rows
 * @param cols - number of columns
 * 
 * @return size_t
 * index - number of elements stored in the array
 */
size_t take_arr(int matrix[MAX_SIZE][MAX_SIZE], int arr[], size_t rows, size_t cols)
{
    size_t index = ZERO_INDEX;

    for (size_t row = 0; row < rows; row++)
    {
        for (size_t col = 0; col < cols; col++)
        {
            if (sum_digit(matrix[row][col]) > TEN)
            {
                arr[index] = matrix[row][col];
                index++;
            }
        }
    }

    return index;
}

/**
 * @brief performs left cyclic shift on array elements
 * 
 * @param arr - array to shift
 * @param size - number of elements in the array
 * 
 * @return void
 */
void shift_array(int arr[], size_t size)
{
    int temp;

    for (int i = 0; i < SHIFT; i++)
    {
        temp = arr[ZERO_INDEX];

        for (size_t i = 1; i < size; i++)
        {
            arr[i - 1] = arr[i];
        }

        arr[size - 1] = temp;
    }
}

/**
 * @brief modifies matrix by replacing elements with digit sum > 10 with shifted array values
 * 
 * @param matrix - matrix to modify
 * @param rows - number of row
 * @param cols - number of columns
 * 
 * @return int
 * NO_NUMBER - return code if there are no numbers greater than 10
 * SUCCESS - success return code
 */
int modify_matrix(int matrix[MAX_SIZE][MAX_SIZE], size_t rows, size_t cols)
{
    int arr[MAX_SIZE_ARRAY];
    size_t index = ZERO_INDEX;
    size_t size;

    size = take_arr(matrix, arr, rows, cols);

    if (size == 0)
    {
        printf("There are no numbers greater than ten");
        return NO_NUMBER;
    }

    shift_array(arr, size);

    for (size_t row = 0; row < rows; row++)
    {
        for (size_t col = 0; col < cols; col++)
        {
            if (sum_digit(matrix[row][col]) > TEN)
            {
                matrix[row][col] = arr[index];
                index++;
            }
        }
    }

    return SUCCESS;
}
