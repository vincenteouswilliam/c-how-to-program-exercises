#include <stdio.h>

// Function prototypes
double toYen(double usd);
double toEuro(double usd);

int main(void) {
    printf("%-10s%-10s%-10s\n", "USD", "YEN", "EURO");
    printf("%s\n", "=============================");

    for (int usd = 10; usd < 50; usd += 10) {
        printf("%-10d%-10.2lf%-10.2lf\n", usd, toYen((double)usd), toEuro((double)usd));
    }

    printf("%s\n", "=============================");

    return 0;
}

// Function definitions
double toYen(double usd) {
    return usd * 118.87;
}

double toEuro(double usd) {
    return usd * 0.92;
}
