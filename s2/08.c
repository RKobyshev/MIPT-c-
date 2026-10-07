#include <stdio.h>

void reverse(int a[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }
}

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    reverse(a, 5);
    for (int i = 0; i < 5; i++) {
        printf("%i ", a[i]);
    }
}
