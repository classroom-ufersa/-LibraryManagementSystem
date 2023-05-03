#include <stdlib.h>
#include <ctype.h>
#include "library.h"
#include "book.c"



typedef struct library
{
    char nome[50];
    int identificador;
    char localizacao[50];
    int numero_de_livro;
    float hora_de_funionamento;
    Book livro;
    Library *prox;
} Library;

Library *criar_Library(void){
    return NULL;
}
Library *adicionar_livro(Library* b, Book l){
 Library * novo_livro = (Library*) malloc(sizeof(Library));
novo_livro->livro= l;
}


