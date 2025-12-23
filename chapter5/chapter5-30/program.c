#include <stdio.h>

// Function prototypes
short toQualityPoints(float average);

int main(void) {
    float average;

    printf("%s", "Please input student's average score: ");
    int res = scanf("%f", &average);

    // scanf check
    if (res < 1) {
        puts("Invalid user input...");
        return 1;
    }

    printf("The quality score based on student's average is %hd\n", toQualityPoints(average));
    return 0;
}

// Function definitions
short toQualityPoints(float average) {
    if (average >= 90) return 4;
    if (average >= 80) return 3;
    if (average >= 70) return 2;
    if (average >= 60) return 1;

    // Default score
    return 0;
}
