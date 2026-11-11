#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define M_PI 3.14159265358979323846

struct color
{
    unsigned char r, g, b;
};
typedef struct color Color;

const Color White = {255, 255, 255};
const Color Black = {0, 0, 0};

void draw_line(Color* data, int width, int height, int x0, int y0, int x1, int y1, Color c)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int ysign = y1 > y0 ? 1 : -1;
    int xsign = x1 > x0 ? 1 : -1;
    int error = (dx > dy ? dx : -dy) / 2;

    if (dx >= dy)
    {
        int y = y0;
        for (int x = x0; x != x1; x += xsign)
        {
            data[x + width * y] = c;
            error += dy;
            if (error >= dx)
            {
                y += ysign;
                error -= dx;
            }
        }
    }
    else
    {
        int x = x0;
        for (int y = y0; y != y1; y += ysign)
        {
            data[x + width * y] = c;
            error += dx;
            if (error >= dy)
            {
                x += xsign;
                error -= dy;
            }
        }
    }
}

void draw_tree(Color* data, int width, int height, int x, int y,
               float length, float angle, int depth)
{
    if (depth == 0)
        return;

    int x1 = x + length * cos(angle);
    int y1 = y - length * sin(angle);
    draw_line(data, width, height, x, y, x1, y1, Black);
    draw_tree(data, width, height, x1, y1, length * 0.72f, angle - 0.4f, depth - 1);
    draw_tree(data, width, height, x1, y1, length * 0.72f, angle + 0.4f, depth - 1);
}

int main()
{
    int width = 500, height = 500;
    Color* data = (Color*)malloc(sizeof(Color) * width * height);
    for (int i = 0; i < width * height; ++i)
        data[i] = White;

    draw_tree(data, width, height, 250, 490, 120, M_PI / 2, 11);

    FILE* file = fopen("tree.ppm", "wb");
    fprintf(file, "P6\n%d %d\n255\n", width, height);
    fwrite(data, sizeof(Color), height * width, file);
    fclose(file);
    free(data);
}
