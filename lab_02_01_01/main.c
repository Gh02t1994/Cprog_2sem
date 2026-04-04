/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 02 01 01
 * @version 0.2
 * @date 2026-03-23
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

#define MAX_SIZE 10 /**< maximum array size */
#define CHECK_POS 0 /**< the number to check for positivity */
#define SUCCESS 0 /**< success return code */
#define INP_ERR 1 /**< input error return code */
#define LOGIC_ERR 2 /**< logical error return code */
#define NO_NUMBERS 3 /**< lack of numbers matching the condition */
#define FLAG_NO_NUM 0 /**< no numbers flag */
#define FLAG_NUM 1 /**< flag about the presence of numbers */

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
 * @brief multiplication of odd numbers in an array
 * 
 * @param arr - array to multiply
 * @param size - array size
 * 
 * @return int
 * mult - multiplication result
 * FLAG_NO_NUM - a code meaning that there were no odd numbers
 */
int multiplication_arr(int arr[], size_t size)
{
    int mult = 1;
    int flag_odd = FLAG_NO_NUM; /**< a flag that indicates the presence of odd numbers */

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % 2 != 0)
        {
            mult *= arr[i];
            flag_odd = FLAG_NUM;
        }
    }
    
    /** check for odd numbers */
    if (flag_odd == FLAG_NO_NUM)
    {
        return FLAG_NO_NUM;
    }
    else
    {
        return mult;
    }
}

/**
 * @brief input of an array and output of the multiplication of its odd numbers
 * 
 * @return int
 * SUCCESS - success return code
 * INP_ERR - input error return code
 * LOGIC_ERR - logical error return code
 */
int main(void)
{
    size_t size_arr;
    int arr[MAX_SIZE];
    int mult_of_odd; /**< multiplication result */

    /** validation for input correctness */
    printf("Enter array size up to 10: ");
    if (scanf("%zu", &size_arr) != 1)
    {
        printf("Incorrect input");
        return INP_ERR;
    }

    /** validation for logical correctness */
    if (size_arr <= CHECK_POS || size_arr > MAX_SIZE)
    {
        printf("Logical error");
        return LOGIC_ERR;
    }

    /** input array */
    printf("Enter the array elements: ");
    if (input_arr(arr, size_arr) == INP_ERR)
    {
        return INP_ERR;
    }

    mult_of_odd = multiplication_arr(arr, size_arr);

    if (mult_of_odd == FLAG_NO_NUM)
    {
        printf("There are no odd numbers");
        return NO_NUMBERS;
    }
    else
    {
        printf("Multiplication of odd numbers: %d", mult_of_odd);
    }

    return SUCCESS;
}
