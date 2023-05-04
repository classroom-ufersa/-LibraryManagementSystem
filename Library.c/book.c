#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "book.h"
#include"library.h"

typedef struct book
{
    char titulo[81];
    int ano;
    char autores[81];
    char status[81];
    int biblioteca;
} Book;


Book* criar_book(void)
{
    
    Book * novo_livro =(Book*)malloc(sizeof(Book));
if(novo_livro=NULL){
    printf("erro!!");
    exit(1);
}else{
    printf("adicionar dados do livro...\n");
printf("__________________________________________\n");
  printf("informe o nome do livro:\n");
  scanf("%[^\n]s", novo_livro->titulo);
  printf("informe o ano:\n");
  scanf("%d", novo_livro->ano);
  printf("informe o autor:\n");
  scanf("%[^\n]s", novo_livro->autores);
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
