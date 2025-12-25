#include <stdio.h>

// Function prototypes
void hanoiTower(int stack, int source, int dest, int temp);

int main(void) {
    int stack;

    printf("%s", "Please input the number of disks in the tower stack: ");
    int res = scanf("%d", &stack);

    // Input check
    if (res != 1) {
        puts("Invalid user input...");
        return 1;
    } else if (stack < 1) {
        puts("The tower must at least have 1 disk and cannot be a negative number!");
        return 1;
    }

    // Print the moving procedure
    puts("Procedure to move the tower:");
    hanoiTower(stack, 1, 3, 2);

    return 0;
}

// Function definitions
void hanoiTower(int stack, int source, int dest, int temp) {
    if (stack == 1) {
        printf("%d -> %d\n", source, dest);
        return;
    }

    hanoiTower(stack-1, source, temp, dest);
    printf("%d -> %d\n", source, dest);
    hanoiTower(stack-1, temp, dest, source);

    return;
}
