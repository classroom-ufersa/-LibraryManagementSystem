#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "book.h"
#include"library.h"
#include <string.h>

typedef struct book
{
    char titulo[81];
    int ano;
    char autor[81];
    char status[81];
    int biblioteca;
} Book;


Book* criar_book(void)
{
    return NULL;
}
 Book * adiciona_livro(Book *l, char* titulo, int* ano, char* autor)
 {
    Book * novo_livro =(Book*)malloc(sizeof(Book));
if(novo_livro=NULL){
    printf("erro!!");
    exit(1);
}else{
printf("adicionar dados do livro...\n");
printf("__________________________________________\n");
strcpy(novo_livro->titulo, titulo);
strcpy(novo_livro->ano, ano);
strcpy(novo_livro->autor, autor);


  return novo_livro;
}
}
void remove_livro()
{
}

void exibe_livro()
{
}

void busca_livro()
{
}

void edita_livro()
{
}
