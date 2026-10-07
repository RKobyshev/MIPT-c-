#include <stdio.h>

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Error: Wrong number of arguments!\n");
        printf("Usage: ./line_extractor <input_file> <output_file> <lines>\n");
        return 1;
    }

    FILE* input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Error: File %s does not exist!\n", argv[1]);
        return 1;
    }

    int first;
    int last;
    char extra;
    if (sscanf(argv[3], "%i%c", &first, &extra) == 1) {
        last = first + 1;
    } else if (sscanf(argv[3], "%i:%i%c", &first, &last, &extra) != 2) {
        printf("Error: Wrong lines format!\n");
        fclose(input);
        return 1;
    }

    if (first < 1 || last <= first) {
        printf("Error: Wrong lines format!\n");
        fclose(input);
        return 1;
    }

    FILE* output = fopen(argv[2], "w");
    int line = 1;
    int c;
    while ((c = fgetc(input)) != EOF && line < last) {
        if (line >= first) fputc(c, output);
        if (c == '\n') line++;
    }
    fclose(input);
    fclose(output);
}
