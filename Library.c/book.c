#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "book.h"


typedef struct book
{
    char titulo[50];
    char autor[50];
    int ano;
}Book;
///Estrutura de uma lista
struct lista{
    Book livro;
struct lista * prox;

};

///Fun�ao que cria uma lista vazia.
Lista* cria_lista(void){
    return NULL;
}

///Fun�ao que insere um livro na lista.
Lista* cadastro_Book(Lista* l, char* titulo, char* autor, int* ano){
Lista* novo = (Lista*)malloc(sizeof(Lista));
if(novo == NULL){
    printf("\nERRO AO CADASTRAR BOOK!");
    exit(1);
}
novo->livro.titulo,titulo;
novo->livro.autor,autor;
novo->livro.ano,ano;
novo->prox = l;
printf("\nLIVRO CADASTRADO COM SUCESSO...");
 return novo;
}

void imprime_lista(Lista* l){
    Lista* aux;
    if(aux == NULL){
        printf("ERRO AO EXIBIR...");
    }else{
    for(aux = l; aux != NULL; aux = aux->prox){
        printf("Nome: %s\nAutor: %s\nAno: %d\n",aux->livro.titulo,aux->livro.autor,aux->livro.ano);
        }
    }
}
