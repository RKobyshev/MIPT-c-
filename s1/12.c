#include <stdio.h>
int main() {
    freopen("numbers.txt", "r", stdin);
    freopen("sorted.txt", "w", stdout);
    int n;
    int a[10000];
    int sum[10000];
    scanf("%i", &n);
    for (int i = 0; i < n; i++) {
        scanf("%i", &a[i]);
        int x = a[i];
        sum[i] = 0;
        while (x > 0) {
            sum[i] += x % 10;
            x /= 10;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sum[j] > sum[j + 1]) {
                int x = a[j];
                a[j] = a[j + 1];
                a[j + 1] = x;
                int s = sum[j];
                sum[j] = sum[j + 1];
                sum[j + 1] = s;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%i ", a[i]);
    }
}
