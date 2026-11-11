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

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        printf("Error!\n");
        exit(1);
    }

    int width, height;
    Color* data = load_image(argv[1], &width, &height);
    blur(data, width, height, atoi(argv[2]));
    save_image("result.ppm", data, width, height);
    free(data);
}
