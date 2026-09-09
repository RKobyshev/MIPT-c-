#include <stdio.h>
int main () {
    int a, b, c;
    scanf("%i %i %i", &a, &b, &c);
    int d = a + (c - a%c);
    int dd=d;
    while (dd <= b) {
        printf("%i ", dd);
        dd+=d;
    }
}