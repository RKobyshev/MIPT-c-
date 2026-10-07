#include <stdio.h>

int trib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 0;
    if (n == 2) return 1;
    int t1 = 0;
    int t2 = 0;
    int t3 = 1;
    int a = 0;
    for (int i = 3; i <=n; i++) {
        a = t1+t2+t3;
        t1 = t2;
        t2 = t3;
        t3 = a;
    }
    return a;
}
int main() {
    printf("%i", trib(38));
}
