#include <stdio.h>
#include <stddef.h>

// Constants
#define BOARD_LENGTH 50
#define TOTAL_MENU 7

// Function prototypes
void printBoard(const unsigned int board[BOARD_LENGTH][BOARD_LENGTH]);
unsigned int turnLeft(unsigned int face);
unsigned int turnRight(unsigned int face);
int boardTracing(
    unsigned int board[BOARD_LENGTH][BOARD_LENGTH],
    unsigned int posX,
    unsigned int posY,
    char axis,
    int direction,
    unsigned int steps,
    unsigned int penDown
);

int main(void) {
    /* BEGIN board variables */
    unsigned int board[BOARD_LENGTH][BOARD_LENGTH] = {{0, 0}};
    int direction[4] = {-1, 1, 1, -1}; // up, right, down, left
    unsigned int posX = 0, posY = 0, face = 0, penDown = 0;
    /* END board variables */

    /* BEGIN user input variables */
    char menu[TOTAL_MENU][30] = {"1 = Pen Up", "2 = Pen Down", "3 = Turn Right", "4 = Turn Left", "5,n = Move forward n steps",
            "6 = Print the 50-by-50 array", "9 = End of data (sentinel)"};
    unsigned int input1 = 0, input2 = 0;
    char buffer[10];
    /* END user input variables */

    // Program will run until user input 9 as End of Data (sentinel)
    puts("Turtle Graphics Program:");
    for (size_t i = 0; i < 7; i++)
        printf("%s\n", menu[i]);
    puts("Please input your turtle movement here based on the menu below:\n");

    /* BEGIN Input processing */
    while (input1 != 9) {
        int flag = 0, result = 0;

        /* BEGIN Input validation */
        while (flag != 1) {
            fgets(buffer, sizeof(buffer), stdin);
            result = sscanf(buffer, "%d , %d", &input1, &input2);

            // Invalid input (basic)
            if (result < 1) {
                puts("Invalid input value. Please input either a single integer or in the form of <int1>,<int2>!");
                continue;
            } else if (input1 != 1 && input1 != 2 && input1 != 3 && input1 != 4 && input1 != 5 && input1 != 6 && input1 != 9) {
                puts("Only input menu number from 1-6 and 9!");
                continue;
            } else if (input1 == 5 && result == 1) {
                puts("You need to input how many steps for move 5!");
                continue;
            }
            // Successful input
            flag = 1;
        }
        /* END Input validation */

        /* BEGIN Input selection */
        if (result == 2) { // For movement input
            char axis = (face % 2 == 1) ? 'x' : 'y';
            int pos = boardTracing(board, posX, posY, axis, direction[face], input2, penDown);

            // Invalid process
            if (pos == -1) {
                puts("Steps given results in out-of-bounds position. Please revise your input!");
                continue;
            }

            // Update position
            posX = (axis == 'y') ? (unsigned int)pos : posX;
            posY = (axis == 'x') ? (unsigned int)pos : posY;
            printf("Current Position: %u, %u\n", posX, posY);
        }
        else if (result == 1) { // For anything else
            switch (input1) {
                case 1:
                    penDown = 0;
                    puts("Pen is currently Up");
                    break;
                case 2:
                    penDown = 1;
                    puts("Pen is currently Down");
                    break;
                case 3:
                    face = turnRight(face);
                    printf("Currently facing: %s\n",
                        (face == 0) ? "Up" : (face == 1) ? "Right" : (face == 2) ? "Down" : "Left");
                    break;
                case 4:
                    face = turnLeft(face);
                    printf("Currently facing: %s\n",
                        (face == 0) ? "Up" : (face == 1) ? "Right" : (face == 2) ? "Down" : "Left");
                    break;
                case 6:
                    puts("Current Board condition:");
                    printBoard(board);
                    break;
                default:
                    puts("Thank you for playing!");
            }
        }
        /* END Input selection */
    }
    /* END Input processing */

    return 0;
}

// Function definitions
void printBoard(const unsigned int board[BOARD_LENGTH][BOARD_LENGTH]) {
    for (size_t i = 0; i < BOARD_LENGTH; i++) {
        for (size_t j = 0; j < BOARD_LENGTH; j++)
            printf("%u", board[i][j]);
        puts("");
    }

    return;
}

unsigned int turnLeft(unsigned int face) {
    return (face == 0) ? 3 : --face;
}

unsigned int turnRight(unsigned int face) {
    return ++face % 4;
}

int boardTracing(
    unsigned int board[BOARD_LENGTH][BOARD_LENGTH],
    unsigned int posX,
    unsigned int posY,
    char axis,
    int direction,
    unsigned int steps,
    unsigned int penDown
) {
    int distance = direction * steps;

    if (axis == 'x') {
        int targetPosY = (int)posY + distance;

        // Do not process if final position is out of bounds
        if (targetPosY < 0 || targetPosY > BOARD_LENGTH - 1)
            return -1;

        // Mark board only if pen down
        if (penDown == 1) {
            for (size_t i = 0; i < (size_t)steps; i++)
                board[posX][posY + (i*direction)] = 1;
        }

        return targetPosY;
    } else if (axis == 'y') {
        int targetPosX = (int)posX + distance;

        // Do not process if final position is out of bounds
        if (targetPosX < 0 || targetPosX > BOARD_LENGTH - 1)
            return -1;

        // Mark board only if pen down
        if (penDown == 1) {
            for (size_t i = 0; i < (size_t)steps; i++)
                board[posX + (i*direction)][posY] = 1;
        }

        return targetPosX;
    }

    return -1; // Default if improper axis
}
