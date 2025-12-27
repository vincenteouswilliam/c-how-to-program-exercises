#include <stdio.h>

// Function prototypes
unsigned long long int factorial(int number, int space);
void printSpace(int space);

int main(void) {
    int number;

    printf("%s", "Please input a number to calculate its factorial: ");
    int res = scanf("%d", &number);

    // Input check
    if (res != 1) {
        puts("Invalid user input...");
        return 1;
    }

    printf("%d! = %llu\n", number, factorial(number, 0));

    return 0;
}

// Function definitions
unsigned long long int factorial(int number, int space) {
    if (number <= 1) { // base case
        printSpace(space);
        printf("factorial(%d) = 1\n", number);
        return 1;
    } else {
        printSpace(space);
        printf("factorial(%d) = %d * factorial(%d)\n", number, number, number-1);
        return (number * factorial(number - 1, space + 4));
    }
}

void printSpace(int space) {
    for (int i = 0; i < space; i++)
        printf("%c", ' ');

    return;
}
