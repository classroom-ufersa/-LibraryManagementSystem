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

} Library;

typedef struct library
{
Book livro;
li *prox;
}Lista;

void adicionar_livro()


