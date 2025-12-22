#include <stdio.h>

// Function prototype
short isEven(int num);

int main(void) {
    int num1, num2, num3, num4, num5;

    printf("%s", "Input 5 integers to test: ");
    int res = scanf("%d%d%d%d%d", &num1, &num2, &num3, &num4, &num5);

    if (res >= 1) {
        printf("%d is %s\n", num1, isEven(num1) ? "Even" : "Odd");
        printf("%d is %s\n", num2, isEven(num2) ? "Even" : "Odd");
        printf("%d is %s\n", num3, isEven(num3) ? "Even" : "Odd");
        printf("%d is %s\n", num4, isEven(num4) ? "Even" : "Odd");
        printf("%d is %s\n", num5, isEven(num5) ? "Even" : "Odd");
    } else {
        printf("%s\n", "Invalid user input...");
    }

    return 0;
}

// Function definition
short isEven(int num) {
    // return 1 if even and 0 if odd
    return !(num % 2);
}
