#pragma once

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define DECLARE_LIST(type) \
struct node_##type \
{ \
    type value; \
    struct node_##type* next; \
    struct node_##type* prev; \
}; \
typedef struct node_##type Node_##type; \
\
struct list_##type \
{ \
    Node_##type* head; \
    Node_##type* tail; \
    size_t size; \
}; \
typedef struct list_##type List_##type; \
\
Node_##type* list_##type##_create_node(type value) \
{ \
    Node_##type* p = (Node_##type*)malloc(sizeof(Node_##type)); \
    if (p == NULL) \
    { \
        fprintf(stderr, "Memory allocation error.\n"); \
        exit(1); \
    } \
    p->value = value; \
    p->next = NULL; \
    p->prev = NULL; \
    return p; \
} \
\
void list_##type##_push_back(List_##type* pl, type value) \
{ \
    Node_##type* p = list_##type##_create_node(value); \
    p->prev = pl->tail; \
    if (pl->tail == NULL) \
        pl->head = p; \
    else \
        pl->tail->next = p; \
    pl->tail = p; \
    pl->size += 1; \
} \
\
List_##type list_##type##_init(size_t n) \
{ \
    List_##type result = {NULL, NULL, 0}; \
    type zero = {0}; \
    for (size_t i = 0; i < n; ++i) \
        list_##type##_push_back(&result, zero); \
    return result; \
} \
\
void list_##type##_print(const List_##type* pl, void (*print_value)(type)) \
{ \
    Node_##type* p = pl->head; \
    while (p != NULL) \
    { \
        print_value(p->value); \
        p = p->next; \
    } \
    printf("\n"); \
} \
\
type list_##type##_pop_back(List_##type* pl) \
{ \
    if (pl->tail == NULL) \
    { \
        fprintf(stderr, "List is empty.\n"); \
        exit(1); \
    } \
    Node_##type* p = pl->tail; \
    type result = p->value; \
    pl->tail = p->prev; \
    if (pl->tail == NULL) \
        pl->head = NULL; \
    else \
        pl->tail->next = NULL; \
    free(p); \
    pl->size -= 1; \
    return result; \
} \
\
void list_##type##_push_front(List_##type* pl, type value) \
{ \
    Node_##type* p = list_##type##_create_node(value); \
    p->next = pl->head; \
    if (pl->head == NULL) \
        pl->tail = p; \
    else \
        pl->head->prev = p; \
    pl->head = p; \
    pl->size += 1; \
} \
\
type list_##type##_pop_front(List_##type* pl) \
{ \
    if (pl->head == NULL) \
    { \
        fprintf(stderr, "List is empty.\n"); \
        exit(1); \
    } \
    Node_##type* p = pl->head; \
    type result = p->value; \
    pl->head = p->next; \
    if (pl->head == NULL) \
        pl->tail = NULL; \
    else \
        pl->head->prev = NULL; \
    free(p); \
    pl->size -= 1; \
    return result; \
} \
\
Node_##type* list_##type##_erase(List_##type* pl, Node_##type* p) \
{ \
    Node_##type* next = p->next; \
    if (p->prev == NULL) \
        pl->head = p->next; \
    else \
        p->prev->next = p->next; \
    if (p->next == NULL) \
        pl->tail = p->prev; \
    else \
        p->next->prev = p->prev; \
    free(p); \
    pl->size -= 1; \
    return next; \
} \
\
void list_##type##_splice(List_##type* plist, Node_##type* p, List_##type* pother) \
{ \
    if (pother->size == 0) \
        return; \
    pother->head->prev = p->prev; \
    pother->tail->next = p; \
    if (p->prev == NULL) \
        plist->head = pother->head; \
    else \
        p->prev->next = pother->head; \
    p->prev = pother->tail; \
    plist->size += pother->size; \
    pother->head = NULL; \
    pother->tail = NULL; \
    pother->size = 0; \
} \
\
void list_##type##_destroy(List_##type* pl) \
{ \
    Node_##type* p = pl->head; \
    while (p != NULL) \
    { \
        Node_##type* next = p->next; \
        free(p); \
        p = next; \
    } \
    pl->head = NULL; \
    pl->tail = NULL; \
    pl->size = 0; \
} \
\
void list_##type##_advance(Node_##type** pp, size_t n) \
{ \
    for (size_t i = 0; i < n && *pp != NULL; ++i) \
        *pp = (*pp)->next; \
}
