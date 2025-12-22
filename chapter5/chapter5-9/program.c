#include <stdio.h>
#include <math.h>

// Function prototypes
int calculateCharges(int hour);

int main(void)
{
    int hour1 = 0, hour2 = 0, hour3 = 0;
    printf("%s", "Please input rent hours (separated by spaces): ");
    scanf("%d%d%d", &hour1, &hour2, &hour3);

    int chargeHour1 = calculateCharges(hour1);
    int chargeHour2 = calculateCharges(hour2);
    int chargeHour3 = calculateCharges(hour3);
    int allRent = chargeHour1 + chargeHour2 + chargeHour3;
    int allHours = hour1 + hour2 + hour3;

    printf("%-10s%-10s%10s\n", "Car", "Hours", "Charge");
    printf("%-10s%-10d%10d\n", "1", hour1, chargeHour1);
    printf("%-10s%-10d%10d\n", "2", hour2, chargeHour2);
    printf("%-10s%-10d%10d\n", "3", hour3, chargeHour3);
    printf("%-10s%-10d%10d\n", "TOTAL", allHours, allRent);

    return 0;
}

// Function definitions
int calculateCharges(int hour)
{
    int totalRent = 0;
    int daysRent = hour / 24;
    int remainingHour = hour - daysRent * 24;
    int chargedRemainingHour = remainingHour > 8 ? remainingHour - 8 : 0;
    int baseCharge = (remainingHour > 0 && remainingHour <= 8) || (remainingHour > 8) ? 25 : 0;

    // max $50 charge per day
    totalRent += daysRent * 50;
    // charge per additional hours after 8 hours of rent. Base charge is $25 for 8 hours
    totalRent += baseCharge + chargedRemainingHour * 5;
    // service tax, $0.5 per hour
    totalRent += (int)ceil(hour * 0.5);

    return totalRent;
}