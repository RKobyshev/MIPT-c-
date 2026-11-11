#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Error\n");
        exit(1);
    }

    FILE* file = fopen(argv[1], "rb");
    if (file == NULL)
    {
        printf("Can't open file\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    printf("%li\n", ftell(file));
    fclose(file);
}
