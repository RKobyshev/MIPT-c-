#include <stdio.h>
int main() {
    int a[1000];
    int n;
    scanf("%i", &n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        scanf("%i", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) {
            a[s] = a[i];
            s++;
        }
    }
    for (int i = 0; i < s; i++) {
        printf("%i ", a[i]);
    }
}