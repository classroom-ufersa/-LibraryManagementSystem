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
} Book;
/// Estrutura de uma lista
struct lista
{
    Book livro;
    struct lista *prox;
};

/// Fun�ao que cria uma lista vazia.
Lista *cria_lista(void)
{
    return NULL;
}

/// Fun�ao que insere um livro na lista.
Lista *cadastro_Book(Lista *l)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    if (novo == NULL)
    {
        printf("\nERRO AO CADASTRAR BOOK!");
        exit(1);
    }
    system("cls");
    printf("\n-------  SITEMA DE GERENCIAMENTE DE BIBLIOTECA ---------\n\n");
    printf("INFORME O NOME DO LIVRO\n");
    printf(">>> ");
    scanf("%s", &novo->livro.titulo);
    printf("\nINFORME O AUTOR DO LIVRO\n");
    printf(">>> ");
    scanf("%s", &novo->livro.autor);
    printf("\nINFORME O ANO DO LIVRO\n");
    printf(">>> ");
    scanf("%d", &novo->livro.ano);
    novo->prox = l;
    printf("\nLIVRO CADASTRADO COM SUCESSO...\n");
    system("pause");
    return novo;
}

void imprime_lista(Lista *l)
{
    Lista *aux;
    if (aux == NULL)
    {
        printf("ERRO AO EXIBIR...");
    }
    else
    {
        for (aux = l; aux != NULL; aux = aux->prox)
        {
            printf("Nome: %s\nAutor: %s\nAno: %d\n", aux->livro.titulo, aux->livro.autor, aux->livro.ano);
            system("pause");
        }
    }
}
