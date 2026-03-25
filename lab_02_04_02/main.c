/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 02 04 02
 * @version 0.1
 * @date 2026-03-25
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

#define MAX_SIZE 10 /**< maximum array size */
#define SUCCESS 0 /**< success return code */
#define EMPTY 1 /**< return code for an empty array */
#define SPECIAL_RC 100 /**< when overflowing */

/**
 * @brief array input
 * 
 * @param arr - array to fill
 * @param size - array size
 * 
 * @return int
 * SPECIAL_RC - overflow return code
 * i - array size
 */
int input_arr(int *arr)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        /** validation for input correctness */
        if (scanf("%d", &arr[i]) != 1)
        {
            return i;
        }
    }
    
    return SPECIAL_RC;
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
 * @brief sorting array by bubble sort method
 * 
 * @param arr - array to sort
 * @param size - array size
 * 
 * @return void
 */
void bubble_sort(int *arr, int size)
{
    int min_ind; /**< the index of the minimum number */
    int buf; /**< buffer number */

    for (int i = 0; i < size; i++)
    {
        min_ind = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_ind])
            {
                min_ind = j;
            }
        }

        buf = arr[i];
        arr[i] = arr[min_ind];
        arr[min_ind] = buf;
    }
}

/**
 * @brief entering an array and outputting a sorted array
 * 
 * @return int
 * SUCCESS - success return code
 * SPECIAL_RC - when overflowing
 */
int main(void)
{
    int arr[MAX_SIZE]; /**< array */
    int size_arr; /**< array size */
    int rc_inp = 0; /**< overflow return code */

    printf("Enter the array elements: ");
    size_arr = input_arr(arr);

    /** checking overflowing */
    if (size_arr == 100)
    {
        rc_inp = 100;
        size_arr = 10;
    }

    /** checking for an empty array */
    if (size_arr == 0)
    {
        printf("Empty array");
        return EMPTY;
    }
    
    bubble_sort(arr, size_arr);

    printf("Sorted array: ");
    output_arr(arr, size_arr);

    /** checking overflowing */
    if (rc_inp == SPECIAL_RC)
    {
        return SPECIAL_RC;
    }
    else
    {
        return SUCCESS;
    }
}
