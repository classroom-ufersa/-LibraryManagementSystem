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

///Estrutura de uma lista que guarda o endere�o do primeiro elemento da lista do Book.
typedef struct lista{
    Book* prim;
}Lista;

///Fun�ao que cria uma lista vazia.
Lista* cria_lista(void){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    if(l == NULL){
        printf("\n\nErro de sistema lista\n");
        exit(1);
    }
    l->prim = NULL;
    return l;
}

///Fun�ao que insere um Book na lista.
Lista* cadastro_Book(Lista* l, char* titulo, int ano, char* autor){
    Book* novo;
    Book* ant = NULL;
    Book* p = l->prim;
    while(p != NULL && strcmp(p->titulo,titulo)<0){
        ant = p;
        p = p->prox;
    }
    novo = (Book*) malloc(sizeof(Book));
    if(novo == NULL){
        system("cls");
        printf("Erro no sistema de cadastro.");
        exit(1);
    }
    strcpy(novo->titulo, titulo);
    strcpy(novo->ano, ano);
    strcpy(novo->autor, autor);
    if(ant == NULL){
        novo->prox = l->prim;
        l->prim=novo;
    }else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return l;
}

void remove_livro()
{
}

void imprime_lista(Lista* l){
    Book* aux;
    for(aux = l->prim; aux != NULL; aux = aux->prox){
        printf("");
    }
    }
void busca_livro()
{
}
void edita_livro()
{
}