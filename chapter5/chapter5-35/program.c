#include <stdio.h>

// Function prototypes
unsigned long long int fibonacci(int order);

int main(void) {
    int order;

    printf("%s", "Please input the nth fibonacci number: ");
    int res = scanf("%d", &order);

    // Input check
    if (res != 1) {
        puts("Invalid user input...");
        return 1;
    } else if (order < 1) {
        puts("Your input cannot be less than 1!");
        return 1;
    }

    printf("The nth (%d) fibonacci number is: %llu\n", order, fibonacci(order));

    return 0;
}

// Function definitions
unsigned long long int fibonacci(int order) {
    unsigned long long int a = 0, b = 1, c;

    if (order == 1) return a;
    if (order == 2) return b;

    for (int i = 2; i < order; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}
