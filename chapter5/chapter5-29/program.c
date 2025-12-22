#include <stdio.h>

// Function definitions
int lcm(int num1, int num2);

int main(void) {
    int num1, num2;

    printf("%s", "Please input 2 numbers separated by space (not negative): ");
    int res = scanf("%d%d", &num1, &num2);

    // scanf check
    if (res < 1) {
        puts("Invalid user input...");
        return 1;
    }

    // Check input validity
    if (num1 <= 0 || num2 <= 0) {
        puts("Numbers cannot be negative!");
        return 1;
    }

    printf("LCM for %d and %d is %d\n", num1, num2, lcm(num1, num2));
    return 0;
}

// Function definitions
int lcm(int num1, int num2) {
    // No need to process same number
    if (num1 == num2) return num1;

    int left = num1;
    int right = num2;

    while (left != right) {
        if (left < right) left += num1;
        else right += num2;
    }

    return left;
}
