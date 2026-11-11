#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct color
{
    unsigned char r, g, b;
};
typedef struct color Color;

void draw_circle(Color* data, int width, int height, int x0, int y0, int r, Color c)
{
    for (int y = 0; y < height; ++y)
        for (int x = 0; x < width; ++x)
            if ((x - x0) * (x - x0) + (y - y0) * (y - y0) <= r * r)
                data[x + width * y] = c;
}

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        printf("Error\n");
        exit(1);
    }

    int n = atoi(argv[1]);
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    int width = 600, height = 400;
    Color* data = (Color*)malloc(sizeof(Color) * width * height);

    for (int i = 0; i < width * height; ++i)
    {
        data[i].r = 255;
        data[i].g = 255;
        data[i].b = 255;
    }

    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; ++i)
    {
        int x = rand() % width;
        int y = rand() % height;
        int r = a + rand() % (b - a + 1);
        Color c = {rand() % 256, rand() % 256, rand() % 256};
        draw_circle(data, width, height, x, y, r, c);
    }

    FILE* file = fopen("circles.ppm", "wb");
    fprintf(file, "P6\n%i %i\n255\n", width, height);
    fwrite(data, sizeof(Color), width * height, file);
    fclose(file);
    free(data);
}
