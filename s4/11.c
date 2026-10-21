#include <stdio.h>
#include <math.h>

struct point
{
    double x;
    double y;
};
typedef struct point Point;

struct triangle
{
    Point a;
    Point b;
    Point c;
};
typedef struct triangle Triangle;

void print_point(Point p)
{
    printf("(%.2f, %.2f)", p.x, p.y);
}

void print_triangle(const Triangle* pt)
{
    printf("{");
    print_point(pt->a);
    printf(", ");
    print_point(pt->b);
    printf(", ");
    print_point(pt->c);
    printf("}\n");
}

double distance(Point a, Point b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double get_triangle_perimeter(const Triangle* pt)
{
    return distance(pt->a, pt->b) + distance(pt->b, pt->c) +
           distance(pt->c, pt->a);
}

Triangle moved_triangle(const Triangle* pt, Point d)
{
    Triangle result = *pt;
    result.a.x += d.x;
    result.a.y += d.y;
    result.b.x += d.x;
    result.b.y += d.y;
    result.c.x += d.x;
    result.c.y += d.y;
    return result;
}

void move_triangle(Triangle* pt, Point d)
{
    *pt = moved_triangle(pt, d);
}

int main()
{
    Triangle t = {{1.00, 0.00}, {0.50, 2.00}, {0.00, 1.50}};
    printf("Perimeter = %.2f\n", get_triangle_perimeter(&t));

    Point d = {1.0, 1.0};
    print_triangle(&t);
    move_triangle(&t, d);
    print_triangle(&t);
}
