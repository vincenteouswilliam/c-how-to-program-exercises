#include <stdio.h>
#include <ctype.h>

// Function prototypes
int gcd(int x, int y);

int main(void) {
    int x, y;

    printf("%s", "Please input 2 numbers separated by space: ");
    int res = scanf("%d%d", &x, &y);

    // Input check
    if (res != 2) {
        puts("Invalid user input ...");
        return 1;
    }

    printf("GCD of %d and %d is %d\n", x, y, gcd(x, y));

    return 0;
}

// Function definitions
int gcd(int x, int y) {
    if (x < 0 || y < 0) return 0; // Invalid number, just return 0
    if (y == 0) return x; // GCD returned

    return gcd(y, x%y);
}
