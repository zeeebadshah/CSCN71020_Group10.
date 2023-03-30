#include <stdio.h>
#include <stdbool.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
    char* result = "";
    if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
        result = "Not a triangle";
    }
    else if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
        result = "Not a triangle";
    }
    else if (side1 == side2 && side1 == side3) {
        result = "Equilateral triangle";
        getInsideAngle(side1, side2, side3);

    }
    else if ((side1 == side2 && side1 != side3) ||
        (side1 == side3 && side1 != side2) ||
        (side2 == side3 && side2 != side1))
    {
        result = "Isosceles triangle";
        getInsideAngle(side1, side2, side3);

    }
    else {
        result = "Scalene triangle";
        getInsideAngle(side1, side2, side3);

    }

    return result;
}

void getInsideAngle(double side1, double side2, double side3) {
    double A, B, C, radian, s, area;
    s = (side1 + side2 + side3) / 2;
    

    area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
    radian = (side1 * side2 * side3) / (4 * area);

    double radian2 = radian * 2.0;
    if (side1 > radian2) {
        A = 180 / M_PI;
    }
    else {
        A = (180 / M_PI) * asin(side1 / radian2);
    }
    if (side2 > radian2) {
        B = 180 / M_PI;
    }
    else {
        B = (180 / M_PI) * asin(side2 / radian2);
    }
    if (side3 > radian2) {
        C = 180 / M_PI;
    }
    else {
        C = (180 / M_PI) * asin(side3 / radian2);
    }

    printf("Angles are : %.2f %.2f %3.2f \n", A, B, C);
}
