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
    printf("Informe a biblioteca: ");
    printf("\n>>> ");
    scanf("%d", &livro.biblioteca);
    printf("Informe o status do livro: ");
    printf("\n>>> ");
    scanf(" %[^\n]s", livro.status);

    return livro;
}

void livros_add(Listalivro *p, FILE *arquivo)
{
    Livro livro = *(p->prox->livro);
    fprintf(arquivo, "Titulo: %s\n", livro.titulo);
    fprintf(arquivo, "Ano: %d\n", livro.ano);
    fprintf(arquivo, "Autor: %s\n", livro.autor);
    fprintf(arquivo, "Biblioteca: %d\n", livro.biblioteca);
    fprintf(arquivo, "Status: %s\n", livro.status);
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
void edita_livro(Listalivro *p)
{
    int cont;
    printf("\nTitulo: %s\n", p->livro->titulo);
    printf("\nAno: %d\n", p->livro->ano);
    printf("\nAutor: %s\n", p->livro->autor);
    printf("\nBiblioteca: %d\n", p->livro->biblioteca);
    printf("\nStatus: %s\n", p->livro->status);

    do
    {
        printf("\nDeseja editar esse livro? (1-sim)(2-nao)\n");
        printf("\n>>> ");
        scanf("%d", &cont);
        if (cont != 1 && cont != 2 && cont != 3)
            printf("Erro: entrada invalida\n");
    } while (cont != 1 && cont != 2 && cont != 3);

    int op;
    printf("\nO que voce deseja editar?\n");
    printf("1 - Titulo\n");
    printf("2 - Ano\n");
    printf("3 - Autor\n");
    printf("4 - Biblioteca\n");
    printf("5 - Status\n");
    printf("\n>>> ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        printf("\nDigite o novo titulo: ");
        scanf(" %[^\n]s", p->livro->titulo);
        printf("Livro atualizado!\n");
        break;
    case 2:
        printf("\nDigite novo ano: ");
        scanf("%d", &p->livro->ano);
        printf("Livro atualizado!\n");
        break;
    case 3:
        printf("\nDigite o novo autor: ");
        scanf(" %[^\n]s", p->livro->autor);
        printf("Livro atualizado!\n");
        break;
    case 4:
        printf("Digite a nova biblioteca: ");
        scanf("%d", &p->livro->biblioteca);
        printf("Livro atualizado!\n");
        break;
    case 5:
        printf("Digite o novo status: \n");
        scanf(" %[^\n]s", p->livro->status);
        printf("Livro atualizado!\n");
        break;

    default:
        printf("Opcao invalida!\n");
        break;
    }
    printf("\n");
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
        printf("\nBiblioteca: %d", p->livro->biblioteca);
        printf("\nStatus: %s\n", p->livro->status);
        printf("-----------------------------\n");
        p = p->prox;
    }
    system("pause");
}