/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 02 03 01
 * @version 0.1
 * @date 2026-03-23
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

#define MAX_SIZE 20 /**< maximum array size */
#define SUCCESS 0 /**< success return code */
#define INP_ERR 1 /**< input error return code */
#define LOGIC_ERR 2 /**< logical error return code */

/**
 * @brief array input
 * 
 * @param arr - array to fill
 * @param size - array size
 * 
 * @return int
 * INP_ERR - input error return code
 * SUCCESS - success return code
 */
int input_arr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        /** validation for input correctness */
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Incorrect input");
            return INP_ERR;
        }
    }
    
    return SUCCESS;
}

/**
 * @brief array output
 * 
 * @param arr - array to print
 * @param size - array size
 * 
 * @return void
 */
void output_arr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

/**
 * @brief inserting a number in array
 * 
 * @param arr - array for inserting
 * @param size - array size
 * @param pos - index of position to insert
 * @param numb - number to insert
 * 
 * @return int
 * size + 1 - new size of array
 */
int insert_in_arr(int *arr, int size, int pos, int numb)
{
    for (int i = size - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[pos] = numb;

    return size + 1;
}

/**
 * @brief inserting a Fibonacci number in array after numbers multiples of 3
 * 
 * @param arr - array for inserting
 * @param size - array size
 * 
 * @return int
 * size - new size of array
 */
int insert_fib_in_arr(int *arr, int size)
{
    int fib_0 = 0, fib_1 = 1, fib_copy;
    int i = 0;

    while (i < size)
    {
        if (arr[i] % 3 == 0)
        {
            size = insert_in_arr(arr, size, i + 1, fib_0);

            i += 2;

            /** calculating next Fibonacci numbers */
            fib_copy = fib_1;
            fib_1 += fib_0;
            fib_0 = fib_copy;
        }
        else
        {
            i++;
        }
    }

    return size;
}

/**
 * @brief 
 * 
 * @return int
 * SUCCESS - success return code
 * INP_ERR - input error return code
 * LOGIC_ERR - logical error return code
 */
int main(void)
{
    int arr[MAX_SIZE];
    int size_arr, new_size;

    /** validation for input correctness */
    printf("Enter array size up to 10: ");
    if (scanf("%d", &size_arr) != 1)
    {
        printf("Incorrect input");
        return INP_ERR;
    }

    /** validation for logical correctness */
    if (size_arr <= 0 || size_arr > 10)
    {
        printf("Logical error");
        return LOGIC_ERR;
    }

    /** input array */
    if (input_arr(arr, size_arr) == INP_ERR)
    {
        return INP_ERR;
    }

    new_size = insert_fib_in_arr(arr, size_arr);

    /** checking for multiples of 3 */
    if (new_size == size_arr)
    {
        printf("There are no multiples of three here");
    }
    else
    {
        printf("Modified array with Fiboncci numbers: ");
        output_arr(arr, new_size);
    }

    return SUCCESS;
}
