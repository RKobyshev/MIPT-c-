#include <stdio.h>
#include <math.h>

int main() {
    float x1, y1, r1, x2, y2, r2;
    float eps = 1e-5;
    scanf("%f %f %f", &x1, &y1, &r1);
    scanf("%f %f %f", &x2, &y2, &r2);
    float dx = x1 - x2;
    float dy = y1 - y2;
    float d = sqrt(dx * dx + dy * dy);
    float sum = r1 + r2;
    float dif = fabs(r1 - r2);
    if (d < eps && dif < eps) {
        printf("Intersect\n");
    } else if (fabs(d - sum) < eps || fabs(d - dif) < eps) {
        printf("Touch\n");
    } else if (d > sum || d < dif) {
        printf("Do not intersect\n");
    } else {
        printf("Intersect\n");
    }
}
