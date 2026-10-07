#include <stdio.h>

int is_integer(char str[]) {
    int i = 0;
    if (str[i] == '+' || str[i] == '-') i++;
    if (str[i] == '\0') return 0;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') return 0;
        i++;
    }
    return 1;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Error: Wrong number of arguments!\n");
        return 1;
    }

    char left[100];
    char right[100];
    char operation;
    char extra;
    if (sscanf(argv[1], "%99s %c %99s %c", left, &operation, right, &extra) != 3) {
        printf("Error: Wrong format!\n");
        return 1;
    }

    if (operation != '+' && operation != '-' && operation != '*' &&
        operation != '/' && operation != '%') {
        printf("Error: Invalid operator!\n");
        return 1;
    }

    if (!is_integer(left) || !is_integer(right)) {
        printf("Error: Operands should be integers!\n");
        return 1;
    }

    int a;
    int b;
    sscanf(left, "%i", &a);
    sscanf(right, "%i", &b);
    if ((operation == '/' || operation == '%') && b == 0) {
        printf("Error: Division by zero!\n");
        return 1;
    }

    if (operation == '+') printf("%i\n", a + b);
    if (operation == '-') printf("%i\n", a - b);
    if (operation == '*') printf("%i\n", a * b);
    if (operation == '/') printf("%i\n", a / b);
    if (operation == '%') printf("%i\n", a % b);
}
