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
    Book* prox;
} Book;
/// Estrutura de uma lista
struct lista
{
     Book* prim;
};



/// Fun�ao que cria uma lista vazia.
Lista *cria_lista(void)
{
    Lista* l = (Lista*) malloc(sizeof(Lista));
    if(l == NULL){
        printf("\n\nErro de sistema lista\n");
        system("pause");
        exit(1);
    }
    l->prim= NULL;
    return l;
}
///Fun�ao que insere um livro na lista.
Lista* cadastro_Book(Lista* l, char* titulo){
    Book* novo;
    Book* ant = NULL;
    Book* p = l->prim;
    while(p != NULL && strcmp(p->titulo, titulo)<0){
        ant = p;
        p = p->prox;
    }
    novo = (Book*)malloc(sizeof(Book));
if(novo == NULL){
    printf("\nERRO AO CADASTRAR BOOK!");
    exit(1);
}
    system("cls");
        printf("\n-------  SITEMA DE GERENCIAMENTE DE BIBLIOTECA ---------\n\n");
        printf("INFORME O NOME DO LIVRO\n");
        printf("\n>>> ");
        scanf("%s", &novo->titulo);
        printf("\nINFORME O AUTOR DO LIVRO\n");
        printf(">>> ");
        scanf(" %s", novo->autor);
        printf("\nINFORME O ANO DO LIVRO\n");
        printf(">>> ");
        scanf("%d", &novo->ano);
  if(ant == NULL){
        novo->prox = l->prim;
        l->prim=novo;
    }else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    printf("\nLIVRO CADASTRADO COM SUCESSO...\n");
 system("pause");
    return l;
}

void imprime_lista(Lista* l){
    Book* aux;
    if(aux == NULL){
        printf("ERRO AO EXIBIR...");
    }
    else
    {
        for (aux = l->prim; aux != NULL; aux = aux->prox)
        {
            printf("Nome: %s\nAutor: %s\nAno: %d\n", aux->titulo, aux->autor, aux->ano);
            system("pause");
        }
    }
}

int lista_vazia(Lista* l){
    if(l == NULL){
        printf("nenhum livro cadastrado...\n");
    }
    return 0;
}


void insere_arquivoP(Lista* l, FILE* fp, int contador){
    fp = fopen("biblioteca.txt", "w"); // Abre o arquivo_origem para leitura
    if (fp == NULL)
    {
        printf("Erro ao abrir o sistema\n");
        system("pause");
    }
   
    Book* aux;
    for(aux = l->prim; aux != NULL; aux = aux->prox){
        fprintf(fp, "Nome: %s\nAutor: %s\nAno: %d\n",aux->titulo,aux->autor,aux->ano);
    }
   contador++;
    fclose(fp);
}

             ///Fun�ao que busca o paciente pelo nome.  
void busca_nome(Lista* l, char* nome){
    Book* aux;
    for(aux = l->prim; aux != NULL; aux = aux->prox){
        if(strcmp(aux->titulo, nome) == 0){
         printf("Nome: %s\nAutor: %s\nAno: %d\n",aux->titulo,aux->autor,aux->ano);
            }
        }
          printf("livro n�o encontrado.\n");
                printf("\n");
                system("pause");
    }
   