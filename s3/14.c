#include <stdio.h>

char encrypt_char(char c, int k) {
    if (c >= 'A' && c <= 'Z') return (c - 'A' + k) % 26 + 'A';
    if (c >= 'a' && c <= 'z') return (c - 'a' + k) % 26 + 'a';
    return c;
}

int main(int argc, char** argv) {
    if (argc != 4) return 1;
    int k;
    sscanf(argv[3], "%i", &k);
    k %= 26;
    if (k < 0) k += 26;

    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "w");
    int c;
    while ((c = fgetc(input)) != EOF) {
        fputc(encrypt_char(c, k), output);
    }
    fclose(input);
    fclose(output);
}
