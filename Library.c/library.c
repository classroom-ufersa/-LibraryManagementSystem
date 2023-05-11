#include "library.h"
#include "book.c"
#define TAM_MAX 100
#define Livros 150
#define codigobiblioteca 128

struct biblioteca
{
    char nome[15];
    int codigo;
    int livro;
    int qtd_livros;
    char localizacao[20];
    Listalivro *lista;
};

Biblioteca *biblioteca_cria(void)
{
    Biblioteca *h = (Biblioteca *)malloc(sizeof(Biblioteca));
    if (h == NULL)
    {
        printf("ERRO de alocacao de memoria!\n");
        exit(1);
    }
    h->lista = lista_cria();
    h->lista->prox = NULL;
    h->lista->prev = NULL;
    h->livro = Livros;
    h->codigo = codigobiblioteca;
    strcpy(h->nome, "Sapiencia");
    strcpy(h->localizacao, "Shopping de PDF");
    return h;
}

Biblioteca *cadastra_livros(Biblioteca *h, int *qnt)
{
    if ((*qnt) == Livros)
    {
        printf("Capacidade máxima atingida!\n");
        exit(1);
    }
    // Adicionando o paciente na lista do hospital
    Livro p = livros_preenche();
    h->lista = lista_add((h->lista), p);
    (*qnt)++;
    (h->livro)--;
    printf("Livro adicionado com sucesso.\n\n");
    return h;
}

FILE *add_arquivo(Biblioteca *h, char *caminho)
{
    FILE *arquivo = fopen(caminho, "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    Listalivro *p = h->lista;
    while (p->prox != NULL)
    {
        livros_add(p, arquivo);
        p = p->prox;
    }
    fclose(arquivo);
    return arquivo;
}

void ler_arquivo(Biblioteca *h, char *caminho, int *num_livro)
{
    Livro livro;
    FILE *arquivo = fopen(caminho, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    char linha[100];
    int i = 0;
    while (fgets(linha, 100, arquivo) != NULL)
    {
        sscanf(linha, "Titulo: %[^\n]", livro.titulo);
        fgets(linha, 100, arquivo);
        sscanf(linha, "Ano: %d", &livro.ano);
        fgets(linha, 100, arquivo);
        sscanf(linha, "Autor: %[^\n]", livro.autor);
        fgets(linha, 100, arquivo);

        h->lista = lista_add(h->lista, livro);
        i++;
    }
    fclose(arquivo);
    *num_livro = i;
    h->livro -= i;
}

Biblioteca *excluir_livro(Listalivro *p, Biblioteca *h)
{
    if (p == NULL)
    {
        return h; // não achou
    }
    else
    {
        // retira o elemento
        if (h->lista == p) // testa se é o primeiro elemento
        {
            h->lista = p->prox;
        }
        else
        {
            p->prev->prox = p->prox; // retira o do meio
        }
        if (p->prox != NULL) // testa se é o ultimo elemento
        {
            p->prox->prev = p->prev;
        }
        free(p);
        h->livro++;
        printf("Paciente excluido com sucesso!\n\n");
    }
    return h;
}

void dados_biblioteca(Biblioteca *h)
{
    printf("\nSISTEMA DE GERENCIAMENTE DE BIBLIOTECA      \n");
    printf("                                                                \n"
           "Bem-vindo a Biblioteca %s                                 \n"
           "Codigo: %d                                                \n"
           "Localizado na %s                                          \n"
           "Horario de funcionamento das 08:00 as 17:00               \n",
           h->nome, h->codigo, h->localizacao);
}