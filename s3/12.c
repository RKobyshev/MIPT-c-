#include <stdio.h>

int main(int argc, char** argv) {
    if (argc != 3) return 1;
    int n;
    sscanf(argv[2], "%i", &n);
    for (int i = 0; i < n; i++) {
        printf("%s", argv[1]);
        if (i + 1 < n) printf(" ");
    }
    printf("\n");
}
