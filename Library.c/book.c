#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "book.h"

typedef struct book
{
    char titulo[51];
    char autor[51];
    int ano;
    char status[51];
    char biblioteca[51];
    Book *prox;
} Book;
/// Estrutura de uma lista
struct lista
{
    Book *prim;
};