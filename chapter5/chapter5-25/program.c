#include <stdio.h>

// Function prototypes
float maxNumber(float a, float b, float c, float d);

int main(void) {
    float a, b, c, d;

    printf("%s", "Input 4 floating point numbers: ");
    int res = scanf("%f%f%f%f", &a, &b, &c, &d);

    if (res < 1) {
        printf("%s\n", "Invalid user input...");
        return 1;
    }

    printf("The largest number is %.2f\n", maxNumber(a, b, c, d));

    return 0;
}

// Function definition
float maxNumber(float a, float b, float c, float d) {
    float max = a;

    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;

    return max;
}
