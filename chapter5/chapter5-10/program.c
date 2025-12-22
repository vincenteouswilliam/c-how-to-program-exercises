#include <stdio.h>
#include <math.h>

// Function prototypes
int nearestInteger(float num);

int main(void) {
    float num1 = 0, num2 = 0, num3 = 0;

    printf("%s", "Please input 3 numbers for rounding: ");
    int resStatus = scanf("%f%f%f", &num1, &num2, &num3);

    // printf("%d\n", resStatus);
    if (resStatus >= 1) {
        printf("%.2f nearest integer is: %d\n", num1, nearestInteger(num1));
        printf("%.2f nearest integer is: %d\n", num2, nearestInteger(num2));
        printf("%.2f nearest integer is: %d\n", num3, nearestInteger(num3));
    } else {
        printf("%s\n", "Failed to read input...");
    }

    return 0;
}

// Function definitions
int nearestInteger(float num) {
    float y = floor(num + 0.5);

    return (int)y;
}
