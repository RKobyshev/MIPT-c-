#include <stdio.h>

int main() {
    char number[200];
    int sum = 0;
    scanf("%199s", number);
    for (int i = 0; number[i] != '\0'; i++) {
        sum += number[i] - '0';
    }
    printf("%i\n", sum);
}
