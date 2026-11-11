#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Error!\n");
        exit(1);
    }

    int width, height;
    Color* data = load_image(argv[1], &width, &height);
    sepia(data, width, height);
    save_image("result.ppm", data, width, height);
    free(data);
}
