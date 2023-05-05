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
     Book * prim;
} Book;
 
  
  


Book* criar_book(void)
{
    Book* livro =(Book*)malloc(sizeof(Book));
    if(livro==NULL){
        printf("ERRO");
        exit(1);
    }
    livro->prim = NULL;
    return livro;
}
 Book * adiciona_livro(Book *l, char* titulo, int* ano, char* autor)
 {
    Book* novo_livro;
    Book* ant = NULL;
    Book* p=l->prim;
    while(p!=NULL && strcmp(p->titulo,titulo)<0){
        ant=p;
        p=p->prox;
    }
    novo_livro =(Book*)malloc(sizeof(Book));
if(novo_livro=NULL){
   
    printf("erro!!");
    exit(1);
     system("cls");
}
/*printf("adicionar dados do livro...\n");
printf("__________________________________________\n");*/
strcpy(novo_livro->titulo, titulo);
strcpy(novo_livro->ano, ano);
strcpy(novo_livro->autor, autor);
    printf("Titulo: %s\nAno: %d\nAutor: %s\n----------------------\n", novo_livro->titulo, novo_livro->ano, novo_livro->autor);
if(ant==NULL){
novo_livro->prox = l->prim;
l->prim = novo_livro;
}else{
    novo_livro->prox=ant->prox;
    ant->prox =novo_livro;
}
l=novo_livro;
  return l;
}

void remove_livro()
{
}

void exibe_livro(Book* l)
{
Book* p;
for(p = l->prim; p!=NULL; p=p->prox){
     
}
}
void busca_livro()
{
}

void edita_livro()
{
}
