#include <stdio.h>

void encrypt(char* str, int k) {
    k %= 26;
    if (k < 0) k += 26;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = (str[i] - 'A' + k) % 26 + 'A';
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (str[i] - 'a' + k) % 26 + 'a';
        }
    }
}

int main() {
    int k;
    char str[200];
    scanf("%i", &k);
    scanf(" %199[^\n]", str);
    encrypt(str, k);
    printf("%s\n", str);
}
