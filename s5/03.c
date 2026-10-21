#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(const char* a, const char* b)
{
    char* result = (char*)malloc((strlen(a) + strlen(b) + 1) * sizeof(char));
    strcpy(result, a);
    strcat(result, b);
    return result;
}

int main()
{
    char* result = concat("Hello, ", "World!");
    printf("%s\n", result);
    free(result);
}
