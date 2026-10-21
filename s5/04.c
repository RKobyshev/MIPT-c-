#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** get_test_strings()
{
    char** result = (char**)malloc(4 * sizeof(char*));
    result[0] = (char*)malloc(4 * sizeof(char));
    result[1] = (char*)malloc(6 * sizeof(char));
    result[2] = (char*)malloc(9 * sizeof(char));
    strcpy(result[0], "Cat");
    strcpy(result[1], "Mouse");
    strcpy(result[2], "Elephant");
    result[3] = NULL;
    return result;
}

void print_strings(const char** string_array)
{
    for (int i = 0; string_array[i] != NULL; i++)
        printf("%s\n", string_array[i]);
}

size_t* get_sizes(const char** string_array)
{
    int n = 0;
    while (string_array[n] != NULL)
        n++;

    size_t* sizes = (size_t*)malloc(n * sizeof(size_t));
    for (int i = 0; i < n; i++)
        sizes[i] = strlen(string_array[i]);
    return sizes;
}

char** load_lines(const char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL) return NULL;

    int number_of_lines = 1;
    int c;
    while ((c = fgetc(file)) != EOF)
    {
        if (c == '\n') number_of_lines++;
    }

    char** result = (char**)malloc((number_of_lines + 1) * sizeof(char*));
    size_t* sizes = (size_t*)malloc(number_of_lines * sizeof(size_t));
    for (int i = 0; i < number_of_lines; i++)
        sizes[i] = 0;

    fseek(file, 0, SEEK_SET);
    int line = 0;
    while ((c = fgetc(file)) != EOF)
    {
        if (c == '\n') line++;
        else sizes[line]++;
    }

    for (int i = 0; i < number_of_lines; i++)
        result[i] = (char*)malloc((sizes[i] + 1) * sizeof(char));
    result[number_of_lines] = NULL;

    fseek(file, 0, SEEK_SET);
    line = 0;
    int column = 0;
    while ((c = fgetc(file)) != EOF)
    {
        if (c == '\n')
        {
            result[line][column] = '\0';
            line++;
            column = 0;
        }
        else
        {
            result[line][column] = c;
            column++;
        }
    }
    result[line][column] = '\0';

    free(sizes);
    fclose(file);
    return result;
}

void destroy_strings(char*** p_string_array)
{
    char** p = *p_string_array;
    for (int i = 0; p[i] != NULL; i++)
        free(p[i]);
    free(p);
    *p_string_array = NULL;
}

void sort_strings(char** words)
{
    int n = 0;
    while (words[n] != NULL)
        n++;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(words[j], words[j + 1]) > 0)
            {
                char* temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char** argv)
{
    if (argc != 3) return 1;

    char** lines = load_lines(argv[1]);
    if (lines == NULL) return 1;
    sort_strings(lines);

    FILE* file = fopen(argv[2], "w");
    if (file == NULL)
    {
        destroy_strings(&lines);
        return 1;
    }

    for (int i = 0; lines[i] != NULL; i++)
        fprintf(file, "%s\n", lines[i]);

    fclose(file);
    destroy_strings(&lines);
}
