#include <stdio.h>

float yearfrac(int year, int day) {
    if (year % 4 == 0) return day / 366.0f;
    return day / 365.0f;
}

int main() {
    int year, day;
    scanf("%i %i", &year, &day);
    printf("%.5f\n", yearfrac(year, day));
}
