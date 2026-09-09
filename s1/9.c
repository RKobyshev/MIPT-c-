#include <stdio.h>
int main() {
    int a;
    scanf("%i", &a);
    int b[a];
    for (int i = 0; i < a; i++) {
        scanf("%i", &b[i]);
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < a; j++) {
            printf("%i ", b[j]);
        }
    }
}