#include <stdio.h>

// Function prototype
int calculateSeconds(int hours, int minutes, int seconds);
short isValidTime(int hours, int minutes, int seconds);

int main(void) {
    int hours, minutes, seconds;

    printf("%s", "Input your time [hours minutes seconds]: ");
    int res = scanf("%d%d%d", &hours, &minutes, &seconds);

    // scanf check
    if (res < 1) {
        printf("%s\n", "Invalid user input...");
        return 1;
    }

    // check valid time before proceeding
    if (!isValidTime(hours, minutes, seconds)) {
        printf("%s\n", "Not a valid time. Please input a valid time (12 hour format)!");
        return 1;
    }

    printf("Total seconds since 12 o'clock is %d second(s)\n", calculateSeconds(hours, minutes, seconds));

    return 0;
}

// Function definitions
int calculateSeconds(int hours, int minutes, int seconds) {
    int normalized_hours = hours == 12 ? 0 : hours;

    return normalized_hours*3600 + minutes*60 + seconds;
}

short isValidTime(int hours, int minutes, int seconds) {
    if (hours < 1 || hours > 12 || minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59) return 0;

    return 1;
}
