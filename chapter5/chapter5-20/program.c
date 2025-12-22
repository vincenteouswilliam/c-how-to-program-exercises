#include <stdio.h>

// Function prototype
void printRectangle(int side1, int side2, char fillCharacter);

int main(void) {
    int side1, side2;
    char fillCharacter;

    printf("%s", "Please input side1 and side 2 numbers: ");
    int res = scanf("%d%d", &side1, &side2);
    printf("%s", "Please input your fill character: ");
    int res2 = scanf(" %c", &fillCharacter);

    if (res >= 1) {
        if (res2 >= 1) printRectangle(side1, side2, fillCharacter);
        else printf("%s\n", "Invalid fill character input...");
    } else {
        printf("%s\n", "Invalid user input...");
    }

    return 0;
}

// Function definition
void printRectangle(int side1, int side2, char fillCharacter) {
    for (int i = 0; i < side1; i++) {
        for (int j = 0; j < side2; j++) printf("%c", fillCharacter);
        puts("");
    }
}
