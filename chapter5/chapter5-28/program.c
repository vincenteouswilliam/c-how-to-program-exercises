#include <stdio.h>

// Function prototypes
int sumOfDigits(int num);

int main(void) {
    int num;

    printf("%s", "Please input a number: ");
    int res = scanf("%d", &num);

    // scanf check
    if (res < 1) {
        puts("Invalid user input...");
        return 1;
    }

    printf("Sum of digits from number %d is %d\n", num, sumOfDigits(num));

    return 0;
}

// Function definitions
int sumOfDigits(int num) {
    int sum = 0;

    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}
