#include <stdio.h>
#include <math.h>

const double step = 1e-2;
const double eps = 1e-10;

double gamma(double x) {
    double result = 0;
    double t = 0;
    double area = 1;
    while (t <= x || area > eps) {
        double left = pow(t, x - 1) * exp(-t);
        double right = pow(t + step, x - 1) * exp(-t - step);
        area = (left + right) * step / 2;
        result += area;
        t += step;
    }
    return result;
}

int main() {
    double x;
    scanf("%lf", &x);
    printf("%f\n", gamma(x));
}
