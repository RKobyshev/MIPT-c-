#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book
{
    char* title;
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
    Book* p = (Book*)malloc(sizeof(Book));
    p->title = (char*)malloc(12 * sizeof(char));
    strcpy(p->title, "Don Quixote");
    p->pages = 1000;
    p->price = 750.0;
    print_book(p);
    free(p->title);
    free(p);
}
