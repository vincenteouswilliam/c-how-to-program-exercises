#include <stdio.h>
#include <math.h>

// Function prototypes
void calculateRoots(double a, double b, double c);
double determinant(double a, double b, double c);

int main(void) {
    double a, b, c;

    printf("%s", "Given ax^2+bx+c formula, please input a, b, and c coefficients: ");
    int res = scanf("%lf%lf%lf", &a, &b, &c);

    // scanf check
    if (res < 1) {
        printf("%s\n", "Invalid user input...");
        return 1;
    }

    // a coefficient can't be 0
    if (a == 0) {
        printf("%s\n", "a coefficient can't be 0!");
        return 1;
    }

    calculateRoots(a, b, c);

    return 0;
}

// Function definitions
void calculateRoots(double a, double b, double c) {
    if (determinant(a, b, c) < 0) {
        puts("This equation has no real roots.");
        return;
    }

    double x1 = (-b + sqrt(determinant(a, b, c))) / 2*a;
    double x2 = (-b - sqrt(determinant(a, b, c))) / 2*a;

    printf("This equation has real roots: %.2lf & %.2lf\n", x1, x2);
    return;
}

double determinant(double a, double b, double c) {
    return pow(b, 2) - 4*a*c;
}
