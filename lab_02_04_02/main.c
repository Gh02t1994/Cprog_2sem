/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 02 04 02
 * @version 0.2
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
int input_arr(int *arr, int *size_ind)
{
    int temp; /**< temp number */
    *size_ind = 0; /**< current index and size */

    while (*size_ind < MAX_SIZE)
    {
        if (scanf("%d", &arr[*size_ind]) != 1)
        {
            return SUCCESS;
        }
        else
        {
            (*size_ind)++;
        }
    }

    if (scanf("%d", &temp) == 1)
    {
        return SPECIAL_RC;
    }
    else
    {
        return SUCCESS;
    }
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
void selection_sort(int *arr, int size)
{
    int min_ind; /**< the index of the minimum number */
    int buf; /**< buffer number */

    for (int i = 0; i < size - 1; i++)
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
    rc_inp = input_arr(arr, &size_arr);

    /** checking for an empty array */
    if (size_arr == 0)
    {
        printf("Empty array");
        return EMPTY;
    }
    
    selection_sort(arr, size_arr);

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
