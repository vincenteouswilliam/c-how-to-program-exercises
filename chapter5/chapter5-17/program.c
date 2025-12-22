#include <stdio.h>
#include <math.h>

// Function prototype
short isValidRightTriangle(double a, double b, double c);

int main(void) {
    double a, b, c;

    printf("%s", "Input 3 sides for a right triangle: ");
    int res = scanf("%lf%lf%lf", &a, &b, &c);

    if (res >= 1) {
        if (isValidRightTriangle(a, b, c))
            printf("%s\n", "It's a valid right triangle!");
        else
            printf("%s\n", "It's not a valid right triangle!");
    } else {
        printf("%s\n", "Invalid user input...");
    }
    return 0;
}

// Function definitions
short isValidRightTriangle(double a, double b, double c) {
    // Invalid side length value
    if (a <= 0 || b <= 0 || c <= 0) return 0;
    // Not a valid triangle
    if (a + b <= c || a + c <= b || b + c <= a) return 0;

    // Valid as a triangle, check as a right triangle
    double hypotenuse;
    if (a >= b && a >= c) {
        hypotenuse = sqrt(pow(b, 2) + pow(c, 2));
        if ((int)hypotenuse != (int)a) return 0;
    } else if (b >= a && b >= c) {
        hypotenuse = sqrt(pow(a, 2) + pow(c, 2));
        if ((int)hypotenuse != (int)b) return 0;
    } else {
        hypotenuse = sqrt(pow(a, 2) + pow(b, 2));
        if ((int)hypotenuse != (int)c) return 0;
    }

    return 1;
}
