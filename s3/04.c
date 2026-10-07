#include <stdio.h>

int main() {
    char a[100];
    char b[100];
    scanf("%99s %99s", a, b);
    int n = 0;
    int m = 0;
    while (a[n] != '\0') n++;
    while (b[m] != '\0') m++;
    for (int i = 0; i < n || i < m; i++) {
        if (i < n) printf("%c", a[i]);
        if (i < m) printf("%c", b[i]);
    }
    printf("\n");
}
