#include <stdio.h>
#include <math.h>

// Function prototypes
double hypotenuse(double a, double b);

int main(void) {
    double a = 0, b = 0;

    printf("%s", "Input base and height number separated by space: ");
    int res = scanf("%lf%lf", &a, &b);

    if (res >= 1) {
        printf("Hypothenuse of base %.1lf and height %.1lf is %.1lf\n", a, b, hypotenuse(a, b));
    } else {
        printf("%s", "Error reading input...");
    }

    return 0;
}

// Function definition
double hypotenuse(double a, double b) {
    return sqrt(pow(a, 2) + pow(b, 2));
}
