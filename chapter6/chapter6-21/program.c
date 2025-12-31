#include <stddef.h>
#include <stdio.h>

// Function prototypes
void clearBuffer(void);

int main(void) {
    unsigned int row1, col1, row2, col2;

    /* BEGIN Row and column input */
    printf("%s", "Please input the first matrix row and column size (separated by space): ");
    int res = scanf("%u %u", &row1, &col1);
    if (res != 2) {
        puts("Invalid row or column value for matrix 1!");
        return 1;
    }

    printf("%s", "Please input the second matrix row and column size (separated by space): ");
    res = scanf("%u %u", &row2, &col2);
    if (res != 2) {
        puts("Invalid row or column value for matrix 2!");
        return 1;
    }
    /* END Row and column input */

    // Make sure that col1 is equal to row2 for a valid multiplication
    if (col1 != row2) {
        puts("Value for column matrix 1 must be equal to row matrix 2!");
        return 1;
    }

    /* BEGIN matrix data input */
    int matrix1[row1][col1], matrix2[row2][col2], resMatrix[row1][col2];
    // first matrix
    for (size_t i = 0; i < row1; i++) {
        for (size_t j = 0; j < col1; j++) {
            while (res != 1) {
                printf("Input matrix1 %zu-%zu: ", i, j);
                res = scanf("%d", &matrix1[i][j]);

                if (res != 1)
                    puts("Invalid value. Please input a proper number for value!");

                clearBuffer();
            }
            res = 0;
        }
    }
    puts("");
    // second matrix
    for (size_t i = 0; i < row2; i++) {
        for (size_t j = 0; j < col2; j++) {
            while (res != 1) {
                printf("Input matrix2 %zu-%zu: ", i, j);
                res = scanf("%d", &matrix2[i][j]);

                if (res != 1)
                    puts("Invalid value. Please input a proper number for value!");

                clearBuffer();
            }
            res = 0;
        }
    }
    /* END matrix data input */

    /* BEGIN matrix multiplication */
    puts("\nMultiplication result:");
    for (size_t i = 0; i < row1; i++)
        for (size_t j = 0; j < col2; j++) {
            resMatrix[i][j] = 0;
            for (size_t k = 0; k < col1; k++)
                resMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
        }

    // Print result
    for (size_t i = 0; i < row1; i++) {
        for (size_t j = 0; j < col2; j++)
            printf("%-5d", resMatrix[i][j]);
        puts("");
    }
    /* END matrix multiplication */
    return 0;
}

// Function definitions
void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
