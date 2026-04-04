/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 02 05 00
 * @version 0.1
 * @date 2026-03-25
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

#define MAX_SIZE 10 /**< maximum array size */
#define SUCCESS 0 /**< success return code */
#define INP_ERR 1 /**< input error return code */
#define LOGIC_ERR 2 /**< logical error return code */

/**
 * @brief array input
 * 
 * @param arr - array to fill and the first index
 * @param end - index after last element
 * 
 * @return int
 * INP_ERR - input error return code
 * SUCCESS - success return code
 */
int input_arr(int arr[], int *end)
{
    int *current = arr; /**< current index */

    while (current < end)
    {
        if (scanf("%d", current) != 1)
        {
            printf("Incorrect input");
            return INP_ERR;
        }

        current++;
    }
    
    return SUCCESS;
}

/**
 * @brief finding maximum in array
 * 
 * @param arr - array for searching and the first index
 * @param end - index after last element
 * 
 * @return int
 * maximum - maximum amount
 */
int find_max(int arr[], int *end)
{
    int *current = arr; /**< current index */
    
    end--;
    int maximum = *current + *end;

    while (current < end)
    {
        current++;
        end--;
        if (*current + *end > maximum)
        {
            maximum = *current + *end;
        }
    }

    return maximum;
}

/**
 * @brief entering an array and finding maximum summ in array
 * 
 * @return int
 * SUCCESS - success return code
 * INP_ERR - input error return code
 * LOGIC_ERR - logical error return code
 */
int main(void)
{
    int arr[MAX_SIZE]; /**< array */
    int *start = arr; /**< start index */
    size_t size_arr; /**< array size */
    int max_of_sum; /**< maximum amount */

    /** validation for input correctness */
    printf("Enter array size up to 10: ");
    if (scanf("%zu", &size_arr) != 1)
    {
        printf("Incorrect input");
        return INP_ERR;
    }

    int *end = arr + size_arr; /**< index after last element */

    /** validation for logical correctness */
    if (end <= start || end - arr > MAX_SIZE)
    {
        printf("Logical error");
        return LOGIC_ERR;
    }

    /** input array */
    printf("Enter the array elements: ");
    if (input_arr(arr, end) == INP_ERR)
    {
        return INP_ERR;
    }

    max_of_sum = find_max(arr, end);
    printf("\nThe maximum sum of elements: %d", max_of_sum);

    return SUCCESS;
}
