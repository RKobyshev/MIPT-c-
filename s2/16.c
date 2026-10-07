#include <stdio.h>

int main() {
    int n;
    float sum = 0;
    scanf("%i", &n);
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) sum += 1.0f / (2 * i - 1);
        else sum -= 1.0f / (2 * i - 1);
    }
    printf("%f\n", 4 * sum);
}
