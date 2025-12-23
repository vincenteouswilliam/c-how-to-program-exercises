#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int flip(void);

int main(void) {
    // seed random
    srand(time(NULL));

    int headCounter = 0, tailCounter = 0;
    for (int i = 0; i < 100; i++) {
        printf("Flip %d: ", i+1);
        if (flip() == 1) {
            printf("%s\n", "HEAD");
            headCounter++;
        } else {
            printf("%s\n", "TAIL");
            tailCounter++;
        }
    }

    // Print flip results
    puts("==============================");
    printf("HEAD = %d, TAIL = %d\n", headCounter, tailCounter);

    return 0;
}

// Function definition
int flip(void) {
    return rand() % 2;
}
