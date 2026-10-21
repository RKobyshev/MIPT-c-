#include <stdio.h>
#include <stdlib.h>

struct book
{
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;

void print_book(Book* p)
{
    printf("%s, %i, %f\n", p->title, p->pages, p->price);
}

int main()
{
    Book a = {"Don Quixote", 1000, 750.0};
    Book** p = (Book**)malloc(sizeof(Book*));
    *p = &a;
    print_book(*p);
    free(p);
}
