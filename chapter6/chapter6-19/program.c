#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MAX_SUM 13
#define DICE_SIDE 6
#define MAX_ROLL 36000

// Function prototypes
unsigned int diceRoll(void);

int main(void) {
    // Seed for random
    srand(time(NULL));

    unsigned int sums[MAX_SUM] = {0};
    unsigned int dice1 = 0, dice2 = 0;

    // Rolling the dice
    for (size_t i = 0; i < MAX_ROLL; i++) {
        dice1 = diceRoll();
        dice2 = diceRoll();
        ++sums[dice1+dice2];
    }

    // Print in tabular format
    printf("%-15s%-10s\n", "Possible Sums", "Frequency");
    puts("=========================");
    for (size_t i = 2; i < MAX_SUM; i++)
        printf("%-15zu%-10u\n", i, sums[i]);

    return 0;
}

// Function definitions
unsigned int diceRoll(void) {
    return rand() % DICE_SIDE + 1;
}
