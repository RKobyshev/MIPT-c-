#include <stdio.h>
#include <math.h>

const double eps = 1e-10;

int solve_quadratic(double a, double b, double c, double* px1, double* px2) {
    double d = b * b - 4 * a * c;
    if (d < -eps) return 0;
    if (d < eps) {
        *px1 = -b / (2 * a);
        return 1;
    }
    *px1 = (-b - sqrt(d)) / (2 * a);
    *px2 = (-b + sqrt(d)) / (2 * a);
    return 2;
}

int main() {
    double a, b, c;
    double x1, x2;
    scanf("%lf %lf %lf", &a, &b, &c);
    int n = solve_quadratic(a, b, c, &x1, &x2);
    printf("%i\n", n);
    if (n >= 1) printf("%f\n", x1);
    if (n == 2) printf("%f\n", x2);
}
