#include <stdio.h>

// Function definitions
void hanoiTower(int stack);

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
    hanoiTower(stack);
    return 0;
}

// Function definitions
void hanoiTower(int stack) {
    int source = -1, target = -1;
    int totalMoves = (1 << stack) - 1; // total moves should be 2^n - 1

    for (int i = 1; i <= totalMoves; i++) {
        source = (i & i-1) % 3; // between current step and previous step mod 3
        target = ((i | i-1) + 1) % 3; // between current step or previous step. Add 1 to ensure different peg and mod 3

        if (stack % 2 == 0) { // swap values for even number of disks
            source = (source == 1) ? 2 : (source == 2) ? 1 : 0;
            target = (target == 1) ? 2 : (target == 2) ? 1 : 0;
        }

        printf("%d -> %d\n", source+1, target+1);
    }

    return;
}
