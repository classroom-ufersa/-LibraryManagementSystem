#include <stdlib.h>
#include <stdio.h>
#include "library.h"
#include "book.c"
#define TAM_LINHA 100

/// Fun�ao que cria uma lista vazia.
Lista *cria_lista(void)
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    if (l == NULL)
    {
        printf("\n\nErro de sistema lista\n");
        system("pause");
        exit(1);
    }
    l->prim = NULL;
    return l;
}
/// Fun�ao que insere um livro na lista.
Lista *cadastro_Book(Lista *l, char *titulo)
{
    Book *novo;
    Book *ant = NULL;
    Book *p = l->prim;
    while (p != NULL && strcmp(p->titulo, titulo) < 0)
    {
        ant = p;
        p = p->prox;
    }
    novo = (Book *)malloc(sizeof(Book));
    if (novo == NULL)
    {
        printf("\nERRO AO CADASTRAR BOOK!");
        exit(1);
    }
    system("cls");
    printf("\n-------  SITEMA DE GERENCIAMENTE DE BIBLIOTECA ---------\n\n");
    printf("INFORME O NOME DO LIVRO\n");
    printf("\n>>> ");
    scanf("%s", novo->titulo);
    printf("\nINFORME O AUTOR DO LIVRO\n");
    printf(">>> ");
    scanf(" %s", novo->autor);
    printf("\nINFORME O ANO DO LIVRO\n");
    printf(">>> ");
    scanf("%d", &novo->ano);
    if (ant == NULL)
    {
        novo->prox = l->prim;
        l->prim = novo;
    }
    else
    {
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    system("pause");
    printf("\nLIVRO CADASTRADO COM SUCESSO...\n");

    return l;
}

void imprime_lista(Lista *l)
{
    Book *aux;
    if (aux == NULL)
    {
        printf("ERRO AO EXIBIR...");
    }
    else
    {
        for (aux = l->prim; aux != NULL; aux = aux->prox)
        {
            printf("Nome: %s\nAutor: %s\nAno: %d\n\n", aux->titulo, aux->autor, aux->ano);
        }
    }
    system("pause");
}

int lista_vazia(Lista *l)
{
    if (l == NULL)
    {
        printf("nenhum livro cadastrado...\n");
    }
    return 0;
}

FILE *insere_arquivoP(Lista *l, FILE *fp)
{
    fp = fopen("BLIBLIOTECA.txt", "w"); // Abre o arquivo_origem para leitura
    if (fp == NULL)
    {
        printf("Erro ao abrir o sistema\n");
        system("pause");
    }

    Book *aux;
    for (aux = l->prim; aux != NULL; aux = aux->prox)
    {
        fprintf(fp, "Nome: %s\nAutor: %s\nAno: %d\n", aux->titulo, aux->autor, aux->ano);
    }

    fclose(fp);
    return fp;
}

/// Fun�ao que busca o paciente pelo nome.
void busca_nome(Lista *l, char *nome)
{
    Book *aux;
    for (aux = l->prim; aux != NULL; aux = aux->prox)
    {
        if (strcmp(aux->titulo, nome) == 0)
        {
            printf("Nome: %s\nAutor: %s\nAno: %d\n", aux->titulo, aux->autor, aux->ano);
        }
        else
        {
            printf("livro n�o encontrado.\n");
            printf("\n");
        }
    }
}

Lista *excluir_book(Lista *l, char *nome)
{
    Book *aux;
    if (aux != NULL)
    {
        for (aux = l->prim; aux != NULL; aux = aux->prox)
        {
            if (strcmp(aux->titulo, nome) == 0)
            {
                free(aux->titulo);
                free(aux->autor);
                free(aux->ano);
            }
        }
    }
    printf("livrro excluido com sucesso!\n\n");
    return aux;
}
