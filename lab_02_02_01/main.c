/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 02 02 01
 * @version 0.2
 * @date 2026-03-23
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>
#include <math.h>

#define MAX_SIZE 10 /**< maximum array size */
#define CHECK_POS 0 /**< the number to check for positivity */
#define PRIME 1 /**< return code for prime number */
#define NOT_PRIME 0 /**< return code for not prime number */
#define SUCCESS 0 /**< success return code */
#define INP_ERR 1 /**< input error return code */
#define LOGIC_ERR 2 /**< logical error return code */
#define NO_NUMBERS 3 /**< lack of numbers matching the condition */

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
int input_arr(int arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
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
void output_arr(int arr[], size_t size)
{
    printf("New array with prime numbers: ");

    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

/**
 * @brief checking that the number is prime
 * 
 * @param number - number to check
 * 
 * @return int
 * NOT_PRIME - number not prime
 * PRIME - number is prime
 */
int is_prime(int number)
{
    if (number <= 1)
    {
        return NOT_PRIME;
    }
    
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            return NOT_PRIME;
        }
    }

    return PRIME;
}

/**
 * @brief creating new array with prime numbers
 * 
 * @param arr - start array
 * @param size - start array size
 * @param new_arr - new array
 * 
 * @return size_t
 * new_size - size of new array
 */
int arr_of_prime(int arr[], size_t size, int *new_arr)
{
    size_t new_size = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (is_prime(arr[i]))
        {
            new_arr[new_size] = arr[i];
            new_size++;
        }
    }

    if (new_size == CHECK_POS)
    {
        printf("There are no prime numbers");
    }

    return new_size;
}

/**
 * @brief entering an array and outputting a new one with prime numbers
 * 
 * @return int
 * SUCCESS - success return code
 * INP_ERR - input error return code
 * LOGIC_ERR - logical error return code
 */
int main(void)
{
    int start_arr[MAX_SIZE], end_arr[MAX_SIZE]; /**< start and new arrays */
    size_t start_size_arr, end_size_arr; /**< sizes of start and new array */

    /** validation for input correctness */
    printf("Enter array size up to 10: ");
    if (scanf("%zu", &start_size_arr) != 1)
    {
        printf("Incorrect input");
        return INP_ERR;
    }

    /** validation for logical correctness */
    if (start_size_arr <= CHECK_POS || start_size_arr > MAX_SIZE)
    {
        printf("Logical error");
        return LOGIC_ERR;
    }

    /** input array */
    printf("Enter the array elements: ");
    if (input_arr(start_arr, start_size_arr) == INP_ERR)
    {
        return INP_ERR;
    }

    end_size_arr = arr_of_prime(start_arr, start_size_arr, end_arr);
    if (end_size_arr == CHECK_POS)
    {
        return NO_NUMBERS;
    }

    output_arr(end_arr, end_size_arr);
    return SUCCESS;
}
