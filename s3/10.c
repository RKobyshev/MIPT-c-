#include <stdio.h>
#include <string.h>

int main() {
    int n;
    int x = 0;
    int y = 0;
    scanf("%i", &n);
    for (int i = 0; i < n; i++) {
        char direction[10];
        int distance;
        scanf("%9s %i", direction, &distance);
        if (strcmp(direction, "North") == 0) y += distance;
        if (strcmp(direction, "South") == 0) y -= distance;
        if (strcmp(direction, "East") == 0) x += distance;
        if (strcmp(direction, "West") == 0) x -= distance;
    }
    printf("%i %i\n", x, y);
}
