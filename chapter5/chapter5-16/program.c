#include <stdio.h>
#include <math.h>

// Function prototypes
short isValidTriangle(double a, double b, double c);
double triangleArea(double a, double b, double c);

int main(void) {
    double a, b, c;

    printf("%s", "Input triangle sides separated by spaces: ");
    int res = scanf("%lf%lf%lf", &a, &b, &c);

    if (res >= 1) {
        if (isValidTriangle(a, b, c))
            printf("Triangle Area from given sides is %.2lf\n", triangleArea(a, b, c));
        else
            printf("%s\n", "Invalid triangle sides!");
    } else {
        printf("%s\n", "Invalid user input...");
    }

    return 0;
}

// Function definitions
short isValidTriangle(double a, double b, double c) {
    // Invalid side lengths
    if (a <= 0 || b <= 0 || c <= 0)
        return 0;

    // Invalid side combination
    if (a + b <= c || a + c <= b || b + c <= a)
        return 0;

    // Good checking
    return 1;
}

double triangleArea(double a, double b, double c) {
    double s = (a + b + c) / 2;

    return sqrt(s * (s-a) * (s-b) * (s-c));
}
