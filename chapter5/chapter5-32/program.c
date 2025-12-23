#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Function prototypes
int checkNumber(int guess, int num);
int getNumber(void);
void printResult(int condition);
void clearBuffer(void);

int main(void) {
    // seed random
    srand(time(NULL));

    // Main program
    int res, num, guess, condition = -1;
    char again = 'y';

    // Continue playing while the choice is yes
    while (again == 'y') {
        // Get target number
        num = getNumber();
        puts("I have a number from 1 and 1000\nCan you guess my number?");

        // first guess validation
        while (1) {
            printf("%s", "Please type your first guess: ");
            res = scanf("%d", &guess);
            clearBuffer();

            // Check valid input
            if (res != 1) {
                puts("Invalid user input...");
                continue;
            }

            break;
        }

        condition = checkNumber(guess, num);
        puts("");
        printResult(condition);

        // Continue playing while guessed number is not the same as target number
        while (condition != 0) {
            // subsequent guesses validation
            while (1) {
                printf("%s", "Please type your next guess: ");
                res = scanf("%d", &guess);
                clearBuffer();

                // Check valid input
                if (res != 1) {
                    puts("Invalid user input...");
                    continue;
                }

                break;
            }

            condition = checkNumber(guess, num);
            puts("");
            printResult(condition);
        }

        // Validating user input for retrying
        while (1) {
            printf("%s", "Would you like to try again [y or n]? ");
            res = scanf(" %c", &again);
            clearBuffer();

            // scanf check
            if (res != 1) {
                puts("Invalid input character...");
                continue;
            }

            // Check if user input y or n
            again = tolower(again);
            if (again != 'y' && again != 'n') {
                puts("Please input only 'y' or 'n'");
                continue;
            }

            break;
        }
        puts("");
    }

    return 0;
}

// Function definitions
int checkNumber(int guess, int num) {
    if (guess < num) return -1;
    if (guess > num) return 1;

    // guess = num
    return 0;
}

int getNumber(void) {
    return rand() % 1000 + 1; // Get 0-1000
}

void printResult(int condition) {
    if (condition == -1)
        puts("Too low. Try again\n");
    else if (condition == 1)
        puts("Too high. Try again\n");
    else
        puts("Excellent! You guessed the number!\n");

    return;
}

void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
