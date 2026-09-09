#include <stdio.h>
int main() {
    freopen("matAB.txt", "r", stdin);
    freopen("matC.txt", "w", stdout);
    int n;
    int a[10000];
    int b[10000];
    scanf("%i", &n);
    for (int i = 0; i < n * n; i++) {
        scanf("%i", &a[i]);
    }
    scanf("%i", &n);
    for (int i = 0; i < n * n; i++) {
        scanf("%i", &b[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int s = 0;
            for (int k = 0; k < n; k++) {
                s += a[i * n + k] * b[k * n + j];
            }
            printf("%i ", s);
        }
        printf("\n");
    }
}
