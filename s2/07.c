#include <stdio.h>

int count_even(int a[], int n) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) c++;
    }
    return c;
}
int main() {
    int a[7] = {0, 1, 2, 3, 4, 5, 6};
    printf("%i", count_even(a, 7));
}