#include <stdio.h>
int main() {
    int n, m;
    int a[10000];
    scanf("%i %i", &n, &m);
    for (int i = 0; i < n*m; i++) {
        scanf("%i", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        int s = 0;
        for (int j = 0; j < n; j++) {
            s += a[j * m + i];
        }
        printf("%i ", s);
    }
}
