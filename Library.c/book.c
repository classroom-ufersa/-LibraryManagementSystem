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
    Book* prox;
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
novo_livro->prox = l;
l=novo_livro;
  return l;
}
}
void remove_livro()
{
}

void exibe_livro(Book* l)
{
Book* p;
for(p = l;p!=NULL; p=p->prox)
    printf("Titulo: %s\nAno: %d\nAutor: %s", p->titulo, p->ano, p->autor);
}

void busca_livro()
{
}

void edita_livro()
{
}
