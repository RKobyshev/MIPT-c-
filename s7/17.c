#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct color
{
    unsigned char r, g, b;
};
typedef struct color Color;

Color* load_image(char* filename, int* pwidth, int* pheight)
{
    FILE* inputfile = fopen(filename, "rb");
    if (inputfile == 0)
    {
        printf("Can't open the file: %s\n", filename);
        exit(1);
    }
    fscanf(inputfile, "P6\n%d %d\n255\n", pwidth, pheight);
    Color* data = (Color*)malloc(sizeof(Color) * (*pwidth) * (*pheight));
    fread(data, sizeof(Color), (*pwidth) * (*pheight), inputfile);
    fclose(inputfile);
    return data;
}

void save_image(char* filename, Color* data, int width, int height)
{
    FILE* outputfile = fopen(filename, "wb");
    fprintf(outputfile, "P6\n%d %d\n255\n", width, height);
    fwrite(data, sizeof(Color), height * width, outputfile);
    fclose(outputfile);
}

void sepia(Color* data, int width, int height)
{
    for (int i = 0; i < width * height; ++i)
    {
        int red = 0.393 * data[i].r + 0.769 * data[i].g + 0.189 * data[i].b;
        int green = 0.349 * data[i].r + 0.686 * data[i].g + 0.168 * data[i].b;
        int blue = 0.272 * data[i].r + 0.534 * data[i].g + 0.131 * data[i].b;
        if (red > 255)
            red = 255;
        if (green > 255)
            green = 255;
        if (blue > 255)
            blue = 255;
        data[i].r = red;
        data[i].g = green;
        data[i].b = blue;
    }
}

void blur(Color* data, int width, int height, int n)
{
    Color* copy = (Color*)malloc(sizeof(Color) * width * height);
    for (int step = 0; step < n; ++step)
    {
        memcpy(copy, data, sizeof(Color) * width * height);
        for (int y = 1; y < height - 1; ++y)
        {
            for (int x = 1; x < width - 1; ++x)
            {
                int red = 0, green = 0, blue = 0;
                for (int j = -1; j <= 1; ++j)
                {
                    for (int i = -1; i <= 1; ++i)
                    {
                        red += data[x + i + width * (y + j)].r;
                        green += data[x + i + width * (y + j)].g;
                        blue += data[x + i + width * (y + j)].b;
                    }
                }
                copy[x + width * y].r = red / 9;
                copy[x + width * y].g = green / 9;
                copy[x + width * y].b = blue / 9;
            }
        }
        memcpy(data, copy, sizeof(Color) * width * height);
    }
    free(copy);
}

void brighter(Color* data, int width, int height, int brightness)
{
    for (int i = 0; i < width * height; ++i)
    {
        int red = data[i].r + brightness;
        int green = data[i].g + brightness;
        int blue = data[i].b + brightness;
        if (red > 255) red = 255;
        if (green > 255) green = 255;
        if (blue > 255) blue = 255;
        if (red < 0) red = 0;
        if (green < 0) green = 0;
        if (blue < 0) blue = 0;
        data[i].r = red;
        data[i].g = green;
        data[i].b = blue;
    }
}

void black_and_white(Color* data, int width, int height)
{
    for (int i = 0; i < width * height; ++i)
    {
        int color = (data[i].r + data[i].g + data[i].b) / 3;
        data[i].r = color;
        data[i].g = color;
        data[i].b = color;
    }
}

void change_colors(Color* data, int width, int height)
{
    for (int i = 0; i < width * height; ++i)
    {
        unsigned char temp = data[i].r;
        data[i].r = data[i].b;
        data[i].b = temp;
    }
}

void mirror(Color* data, int width, int height)
{
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width / 2; ++x)
        {
            Color temp = data[x + width * y];
            data[x + width * y] = data[width - 1 - x + width * y];
            data[width - 1 - x + width * y] = temp;
        }
    }
}

int main(int argc, char** argv)
{
    if (argc < 4)
    {
        printf("Error\n");
        exit(1);
    }

    char* input;
    char* output;
    int value = 0;

    if (strcmp(argv[1], "--blur") == 0 || strcmp(argv[1], "--brighter") == 0)
    {
        if (argc != 5)
            exit(1);
        value = atoi(argv[2]);
        input = argv[3];
        output = argv[4];
    }
    else
    {
        if (argc != 4)
            exit(1);
        input = argv[2];
        output = argv[3];
    }

    int width, height;
    Color* data = load_image(input, &width, &height);

    if (strcmp(argv[1], "--sepia") == 0)
        sepia(data, width, height);
    else if (strcmp(argv[1], "--blur") == 0)
        blur(data, width, height, value);
    else if (strcmp(argv[1], "--brighter") == 0)
        brighter(data, width, height, value);
    else if (strcmp(argv[1], "--bw") == 0)
        black_and_white(data, width, height);
    else if (strcmp(argv[1], "--changecolors") == 0)
        change_colors(data, width, height);
    else if (strcmp(argv[1], "--mirror") == 0)
        mirror(data, width, height);
    else
    {
        printf("Unknown option\n");
        free(data);
        exit(1);
    }

    save_image(output, data, width, height);
    free(data);
}
