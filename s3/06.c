#include <stdio.h>

int is_palindrom(char str[]) {
    int n = 0;
    while (str[n] != '\0') n++;
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - 1 - i]) return 0;
    }
    return 1;
}

int main() {
    char str[100];
    scanf("%99s", str);
    if (is_palindrom(str)) printf("Yes\n");
    else printf("No\n");
}
