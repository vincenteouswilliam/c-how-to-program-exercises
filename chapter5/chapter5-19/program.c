#include <stdio.h>

// Function prototype
void printRectangle(int side1, int side2);

int main(void) {
    int side1, side2;

    printf("%s", "Please input side1 and side 2 numbers: ");
    int res = scanf("%d%d", &side1, &side2);

    if (res >= 1) {
        printRectangle(side1, side2);
    } else {
        printf("%s\n", "Invalid user input...");
    }

    return 0;
}

// Function definition
void printRectangle(int side1, int side2) {
    for (int i = 0; i < side1; i++) {
        for (int j = 0; j < side2; j++) printf("%c", '*');
        puts("");
    }
}
