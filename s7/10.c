#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct color
{
    unsigned char r, g, b;
};
typedef struct color Color;

int main()
{
    int width = 500, height = 500;
    Color* data = (Color*)malloc(sizeof(Color) * width * height);

    for (int number = 1; number <= 5; ++number)
    {
        for (int j = 0; j < height; ++j)
        {
            for (int i = 0; i < width; ++i)
            {
                float x = 2.0f * i / width - 1;
                float y = 2.0f * j / height - 1;
                int value;

                if (number == 1)
                    value = 255 * fabs(x * y);
                else if (number == 2)
                    value = 255 * fabs(sin(10 * (x * x + y * y)));
                else if (number == 3)
                    value = 255 * fabs(sin(5000 * (x * x + y * y)));
                else if (number == 4)
                    value = 255 * fabs(cos(10 * x) * sin(10 * y));
                else
                    value = 255 * 0.5 * fabs(sin(3 / (0.1 + fabs(x))) +
                                              sin(3 / (0.1 + fabs(y))));

                data[i + width * j].r = value;
                data[i + width * j].g = value;
                data[i + width * j].b = value;
            }
        }

        char filename[20];
        sprintf(filename, "function%i.ppm", number);
        FILE* file = fopen(filename, "wb");
        fprintf(file, "P6\n%i %i\n255\n", width, height);
        fwrite(data, sizeof(Color), width * height, file);
        fclose(file);
    }

    free(data);
}
