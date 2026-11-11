#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node* create_node(int value)
{
    Node* p = (Node*)malloc(sizeof(Node));
    if (p == NULL)
    {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    p->value = value;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

List init(size_t n)
{
    List result = {NULL, NULL, 0};
    for (size_t i = 0; i < n; ++i)
        push_back(&result, 0);
    return result;
}

void print(const List* pl)
{
    Node* p = pl->head;
    while (p != NULL)
    {
        printf("%i ", p->value);
        p = p->next;
    }
    printf("\n");
}

void push_back(List* pl, int value)
{
    Node* p = create_node(value);
    p->prev = pl->tail;

    if (pl->tail == NULL)
        pl->head = p;
    else
        pl->tail->next = p;

    pl->tail = p;
    pl->size += 1;
}

int pop_back(List* pl)
{
    if (pl->tail == NULL)
    {
        fprintf(stderr, "List is empty.\n");
        exit(1);
    }

    Node* p = pl->tail;
    int result = p->value;
    pl->tail = p->prev;

    if (pl->tail == NULL)
        pl->head = NULL;
    else
        pl->tail->next = NULL;

    free(p);
    pl->size -= 1;
    return result;
}

void push_front(List* pl, int value)
{
    Node* p = create_node(value);
    p->next = pl->head;

    if (pl->head == NULL)
        pl->tail = p;
    else
        pl->head->prev = p;

    pl->head = p;
    pl->size += 1;
}

int pop_front(List* pl)
{
    if (pl->head == NULL)
    {
        fprintf(stderr, "List is empty.\n");
        exit(1);
    }

    Node* p = pl->head;
    int result = p->value;
    pl->head = p->next;

    if (pl->head == NULL)
        pl->tail = NULL;
    else
        pl->head->prev = NULL;

    free(p);
    pl->size -= 1;
    return result;
}

Node* erase(List* pl, Node* p)
{
    Node* next = p->next;

    if (p->prev == NULL)
        pl->head = p->next;
    else
        p->prev->next = p->next;

    if (p->next == NULL)
        pl->tail = p->prev;
    else
        p->next->prev = p->prev;

    free(p);
    pl->size -= 1;
    return next;
}

void splice(List* plist, Node* p, List* pother)
{
    if (pother->size == 0)
        return;

    pother->head->prev = p->prev;
    pother->tail->next = p;

    if (p->prev == NULL)
        plist->head = pother->head;
    else
        p->prev->next = pother->head;

    p->prev = pother->tail;
    plist->size += pother->size;

    pother->head = NULL;
    pother->tail = NULL;
    pother->size = 0;
}

void destroy(List* pl)
{
    Node* p = pl->head;
    while (p != NULL)
    {
        Node* next = p->next;
        free(p);
        p = next;
    }

    pl->head = NULL;
    pl->tail = NULL;
    pl->size = 0;
}

void advance(Node** pp, size_t n)
{
    for (size_t i = 0; i < n && *pp != NULL; ++i)
        *pp = (*pp)->next;
}
