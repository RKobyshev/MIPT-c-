#include <stdio.h>

void mult2(int* p, size_t n) {
    for (size_t i = 0; i < n; i++) {
        *(p + i) *= 2;
    }
}

int main() {
    int a[5] = {10, 20, 30, 40, 50};
    mult2(a, 5);
    for (int i = 0; i < 5; i++) {
        printf("%i ", a[i]);
    }
    printf("\n");
}
