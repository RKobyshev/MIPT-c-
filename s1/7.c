#include <stdio.h>
int main() {
    int m, n;
    scanf("%i %i", &m, &n);
    int s = 0;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            int sign;
            if ((i+j)%2==0){sign = 1;}
            else {sign = -1;}
            s += (sign*i*j);
        }
    }
    printf("%i", s);
}