#include <stdio.h>
#include <math.h>

// Function prototypes
int roundToInteger(float num);
float roundToTenths(float num);
float roundToHundreths(float num);
float roundToThousandths(float num);

int main(void) {
    float num = 0;

    printf("%s", "Input your number: ");
    int resStatus = scanf("%f", &num);

    if (resStatus >= 1) {
        printf("%f round to integer is %d\n", num, roundToInteger(num));
        printf("%f round to tenths is %.1f\n", num, roundToTenths(num));
        printf("%f round to hundreths is %.2f\n", num, roundToHundreths(num));
        printf("%f round to thousandths is %.3f\n", num, roundToThousandths(num));
    } else {
        printf("%s\n", "Error reading input...");
    }

    return 0;
}

// Function definitions
int roundToInteger(float num) {
    float y = floor(num + 0.5);

    return (int)y;
}

float roundToTenths(float num) {
    return floor(num * 10 + 0.5) / 10;
}

float roundToHundreths(float num) {
    return floor(num * 100 + 0.5) / 100;
}

float roundToThousandths(float num) {
    return floor(num * 1000 + 0.5) / 1000;
}
