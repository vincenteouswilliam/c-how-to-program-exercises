#include <math.h>
#include <stdio.h>

int main(void)
{
    printf("fabs(10.85) = %f\n", fabs(10.85));
    printf("floor(10.85) = %f\n", floor(10.85));
    printf("fabs(-0.678) = %f\n", fabs(-0.678));
    printf("ceil(9.234) = %f\n", ceil(9.234));
    printf("fabs(0.0) = %f\n", fabs(0.0));
    printf("ceil(-34.87) = %f\n", ceil(-34.87));
    printf("ceil(-fabs(-12 - floor(-9.5))) = %f\n", ceil(-fabs(-12 - floor(-9.5))));

    return 0;
}