#include <stdio.h>
#include <string.h>

int main()
{
    int a[4] = {1819043144, 1461726319, 1684828783, 2593};
    printf("%s", (char*)a);

    union
    {
        int numbers[4];
        char string[16];
    } b = {{1819043144, 1461726319, 1684828783, 2593}};
    printf("%s", b.string);

    char c[17];
    memcpy(c, a, sizeof(a));
    c[16] = '\0';
    printf("%s", c);
}
