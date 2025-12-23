#include <stdio.h>

// Function prototypes
unsigned int power(int base, int exponent);

int main(void) {
    int base, exponent;

    printf("%s", "Please input your base and exponent separated by space: ");
    int res = scanf("%d%d", &base, &exponent);

    // scanf check
    if (res != 2) {
        puts("Invalid user input...");
        return 1;
    }

    printf("power(%d, %d) = %u\n", base, exponent, power(base, exponent));

    return 0;
}

// Function definitions
unsigned int power(int base, int exponent) {
    if (exponent == 1) return base;

    return base * power(base, exponent-1);
}
