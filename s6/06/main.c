#include <stdio.h>
#include "list.h"

DECLARE_LIST(int)
DECLARE_LIST(float)

void print_int(int x)
{
    printf("%i ", x);
}

void print_float(float x)
{
    printf("%f ", x);
}

int main()
{
    List_int a = list_int_init(0);
    list_int_push_back(&a, 10);
    list_int_push_back(&a, 20);
    list_int_push_front(&a, 5);
    list_int_print(&a, print_int);

    List_float b = list_float_init(0);
    list_float_push_back(&b, 1.5f);
    list_float_push_back(&b, 2.5f);
    list_float_print(&b, print_float);

    list_int_destroy(&a);
    list_float_destroy(&b);
}
