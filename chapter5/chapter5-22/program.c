#include <stdio.h>

int main(void) {
    unsigned int num, counter = 10000;

    printf("%s", "Input your number: ");
    int res = scanf("%u", &num);

    // Check invalid input
    if (res < 1) {
        printf("%s\n", "Invalid user input...");
        return 1;
    }

    printf("%s\n", "The digits:");
    while (counter > 0) {
        if (num / counter == 0) {
            counter /= 10;
            continue;
        }
        printf("%d", num / counter);
        num %= counter;
        counter /= 10;
        if (counter == 0) puts("");
        else printf("%s", "  ");
    }

    return 0;
}
