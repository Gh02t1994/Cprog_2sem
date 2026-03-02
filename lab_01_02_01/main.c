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

/** The number of pi */
#define PI 3.14159265

/**
 * @brief calculating the area of an isosceles trapezoid by bases and angle with a larger base
 * 
 * @return int
 * 0 — successful completion
 * 1 — input error
 * 2 — incorrect mathematical data
 */
int main(void)
{
    float side_a, side_b, angle_phi; /**< trapezoid bases and angle */
    float square; /**< trapezoid area */
    float phi_rad; /**< angle in radians */

    printf("Enter the length of the base a, b and the angle phi: ");
    if (scanf("%f %f %f", &side_a, &side_b, &angle_phi) != 3) /**< validation for input correctness */
    {
        printf("Incorrect input\n");
        return 1;
    }

    if (side_a <= 0 || side_b <= 0 || angle_phi <= 0 || angle_phi >= 180) /**< validation for mathematical correctness */
    {
        printf("Incorrect mathematical input\n");
        return 2;
    }

    phi_rad = angle_phi * PI / 180.0; /**< convert angle from degrees to radians */
    square = fabs(side_a * side_a - side_b * side_b) * tan(phi_rad) / 4; /**< calculation of the trapezoid area */

    printf("The area of the trapezoid S: %.6f\n", square);
    return 0;
}
