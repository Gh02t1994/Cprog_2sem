/**
 * @file main.c
 * @author Balyabin Yaroslav (balyabinyav@student.bmstu.ru)
 * @brief Lab 01 06 05
 * @version 0.2
 * @date 2026-03-01
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

#define EPS 0.000001

/**
 * @brief calculating the lenght of segment
 * 
 * @param x_1 - the x coordinate for point 1
 * @param y_1 - the y coordinate for point 1
 * @param x_2 - the x coordinate for point 2
 * @param y_2 - the y coordinate for point 2
 * 
 * @return float
 * lenght_of_seg - the length squared of the segment
 */
float check_segments(float x_1, float y_1, float x_2, float y_2)
{
    float lenght_of_seg = (x_2 - x_1) * (x_2 - x_1) + (y_2 - y_1) * (y_2 - y_1); /**< the length squared */

    return lenght_of_seg;
}

/**
 * @brief calculating determinant for 2 vectors
 * |(x_2 - x_1) (y_2 - y_1)| - 1 vector
 * |(x_3 - x_1) (y_3 - y_1)| - 2 vector
 * 
 * @param x_1 - the x coordinate for point 1
 * @param y_1 - the y coordinate for point 1
 * @param x_2 - the x coordinate for point 2
 * @param y_2 - the y coordinate for point 2
 * @param x_3 - the x coordinate for point 3
 * @param y_3 - the y coordinate for point 3
 * 
 * @return float
 * determinant - the determinant
 */
float calc_determinant(float x_1, float y_1, float x_2, float y_2, float x_3, float y_3)
{
    float determinant = (x_2 - x_1) * (y_3 - y_1) - (y_2 - y_1) * (x_3 - x_1);

    return determinant;
}

/**
 * @brief checking two segments for an intersection
 * 
 * @return int
 * 0 — successful completion
 * 1 — input error
 * 2 — incorrect segment entry
 */
int main(void)
{
    float x_p, y_p, x_q, y_q, x_r, y_r, x_s, y_s; /**< coordinates for points p, q, r, s */
    float det_1, det_2, det_3, det_4; /**< determinants */

    printf("Enter the coordinates of the points p, q, r, s in the appropriate order in the X Y format: ");
    /** validation for input correctness */
    if (scanf("%f %f %f %f %f %f %f %f", &x_p, &y_p, &x_q, &y_q, &x_r, &y_r, &x_s, &y_s) != 8)
    {
        printf("Incorrect input");
        return 1;
    }

    /** validation for the correctness of the segment input */
    if (check_segments(x_p, y_p, x_q, y_q) < EPS || check_segments(x_r, y_r, x_s, y_s) < EPS)
    {
        printf("Should be a segment, not a point");
        return 2;
    }

    det_1 = calc_determinant(x_p, y_p, x_q, y_q, x_r, y_r); /**< the determinant of pq pr (pq and r) */
    det_2 = calc_determinant(x_p, y_p, x_q, y_q, x_s, y_s); /**< the determinant of pq ps (pq and s) */
    det_3 = calc_determinant(x_r, y_r, x_s, y_s, x_p, y_p); /**< the determinant of rs rp (rs and p) */
    det_4 = calc_determinant(x_r, y_r, x_s, y_s, x_q, y_q); /**< the determinant of rs rq (rs and q) */

    /**
     * determinants are used to check where the point is relative to the segment:
     * if det > 0, it means the point to the left of the segment, det < 0, it means
     * the point to the right of the segment, det = 0, it means they lie on a
     * straight line. To check the intersection, it is necessary that
     * the multiplication of the determinants be negative, which means that the
     * points are on different sides of the segment, which means the intersection.
     */
    if (det_1 * det_2 < 0 && det_3 * det_4 < 0)
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
}
