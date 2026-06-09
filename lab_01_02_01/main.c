/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 01 02 01
 * @version 0.2
 * @date 2026-02-27
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>
#include <math.h>

#define PI 3.14159265 /**< the number of pi */
#define CHECK_POS 0 /**< the number to check for positivity */
#define CHECK_ACUTE 90.0 /**< the number to check for an acute angle */
#define UNFOLD_ANG 180.0 /**< the number to convert to radians */
#define SUCCESS 0 /**< success return code */
#define INP_ERR 1 /**< input error return code */
#define MATH_ERR 2 /**< mathematical error return code */

/**
 * @brief calculating the area of an isosceles trapezoid by bases and angle with a larger base
 * 
 * @return int
 * SUCCESS — successful completion
 * INP_ERR — input error
 * MATH_ERR — incorrect mathematical data
 */
int main(void)
{
    float side_a, side_b; /**< trapezoid bases */
    float angle_phi; /**< trapezoid angle */
    float square; /**< trapezoid area */
    float phi_rad; /**< angle in radians */

    printf("Enter the length of the base a, b and the angle phi: ");
    /** validation for input correctness */
    if (scanf("%f %f %f", &side_a, &side_b, &angle_phi) != 3)
    {
        printf("Incorrect input\n");
        return INP_ERR;
    }

    /** validation for mathematical correctness */
    if (side_a <= CHECK_POS || side_b <= CHECK_POS || angle_phi <= CHECK_POS || angle_phi >= CHECK_ACUTE)
    {
        printf("Incorrect mathematical input\n");
        return MATH_ERR;
    }

    phi_rad = angle_phi * PI / UNFOLD_ANG; /**< convert angle from degrees to radians */
    square = fabs(side_a * side_a - side_b * side_b) * tan(phi_rad) / 4; /**< calculation of the trapezoid area */

    printf("The area of the trapezoid S: %.6f\n", square);
    return SUCCESS;
}
