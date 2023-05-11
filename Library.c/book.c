#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include "book.h"

#define TAM_MAX 100

struct livro
{
    char titulo[TAM_MAX];
    int ano;
    char autor[50];
    int biblioteca;
    char status[50];
};

struct listalivro
{
    Livro *livro;
    struct listalivro *prox;
    struct listalivro *prev;
};

Listalivro *lista_cria(void)
{
    Listalivro *l = (Listalivro *)malloc(sizeof(Listalivro));
    return l;
}

Livro livros_preenche(void)
{
    Livro livro;

    printf("Informe o titulo do livro: ");
    printf("\n>>> ");
    scanf(" %[^\n]s", livro.titulo);
    printf("Informe o ano do livro: ");
    printf("\n>>> ");
    scanf("%d", &livro.ano);
    printf("Informe o autor do livro: ");
    printf("\n>>> ");
    scanf(" %[^\n]s", livro.autor);

    return livro;
}

void livros_add(Listalivro *p, FILE *arquivo)
{
    Livro livro = *(p->prox->livro);
    fprintf(arquivo, "Titulo: %s\n", livro.titulo);
    fprintf(arquivo, "Ano: %d\n", livro.ano);
    fprintf(arquivo, "Autor: %s\n", livro.autor);
    fprintf(arquivo, "Biblioteca: 128\n");
}

Listalivro *lista_add(Listalivro *l, Livro livro)
{
    Listalivro *p = l;
    while (p->prox != NULL && strcmp(p->prox->livro->titulo, livro.titulo) < 0)
    {
        p = p->prox;
    }
    // Criar um novo nó para o novo paciente
    Listalivro *novo_no = (Listalivro *)malloc(sizeof(Listalivro));
    if (novo_no == NULL)
    {
        printf("Erro: memoria insuficiente.\n");
        exit(1);
    }
    novo_no->livro = (Livro *)malloc(sizeof(Livro));
    if (novo_no->livro == NULL)
    {
        printf("Erro: memoria insuficiente.\n");
        exit(1);
    }
    *novo_no->livro = livro;

    // Inserir o novo paciente na posição correta
    novo_no->prox = p->prox;
    novo_no->prev = p;
    if (p->prox != NULL)
    {
        p->prox->prev = novo_no;
    }
    p->prox = novo_no;
    return l;
}

Listalivro *busca_livro(Listalivro *l, char titulo[TAM_MAX])
{
    Listalivro *p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (strcmp(p->livro->titulo, titulo) == 0)
        {
            return p;
        }
    }
    return NULL;
}

void lista_imprime(Listalivro *l)
{
    Listalivro *p = l->prox;
    printf("\n\n          LIVROS      \n");
    while (p != NULL)
    {
        printf("-----------------------------\n");
        printf("Titulo: %s", p->livro->titulo);
        printf("\nAno: %d", p->livro->ano);
        printf("\nAutor: %s", p->livro->autor);
        printf("\nBiblioteca: 128\n");
        printf("-----------------------------\n");
        p = p->prox;
    }
    system("pause");
}