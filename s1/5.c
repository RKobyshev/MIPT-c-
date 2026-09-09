#include<stdio.h>
#include <limits.h>
int main() {
    int n;
    scanf("%i", &n);
    int min = INT_MAX;
    int count=0;
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%i", &a);
        if (a < min) {
            min=a;
            count = 1;
        }
        else if (a==min){count++;}
    }
    printf("%i %i", min, count);
}