#include <stdio.h>

// Function prototypes
short isPerfect(int num);
void printDivisors(int num);

int main(void) {
    printf("%s\n", "Perfect numbers from 1 - 10000:"); // This is to test computer power
    for (int i = 2; i <= 10000; i++) {
        if (isPerfect(i) == 1) {
            printf("%d, divisors: ", i);
            printDivisors(i);
        }
    }
    return 0;
}

// Function definitions
short isPerfect(int num) {
    // No need to check if number is smaller or equal to 1
    if (num <= 1) return 0;

    int divisor_sum = 1;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) divisor_sum += i;
    }

    return num == divisor_sum;
}

void printDivisors(int num) {
    for (int i = 1; i < num; i++) {
        if (num % i == 0) printf("%d", i);
        if (i == num - 1) puts("");
        else if (num % i == 0) printf("%c", ' ');
    }

    return;
}
