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
Lista* cadastro_Book(Lista* l){
Lista* novo = (Lista*)malloc(sizeof(Lista));
if(novo == NULL){
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
        l= novo;
        system("cls");
printf("\nLIVRO CADASTRADO COM SUCESSO...\n");
 system("pause");
 return l;
}



void imprime_lista(Lista* l){
    lista_vazia(l);
    Lista* aux = l;
    if(aux == NULL){
        printf("ERRO AO EXIBIR...");
    }else{
    for(aux = l; aux != NULL; aux = aux->prox){
        printf("Nome: %s\nAutor: %s\nAno: %d\n",aux->livro.titulo,aux->livro.autor,aux->livro.ano);
        system("pause");
        }
    }
}


Lista* busca_nome(Lista* l, char* nome){
    Lista* aux;
    for(aux = l; aux != NULL; aux = aux->prox){
        if(aux->livro.titulo == nome){
        printf("Nome: %s\nAutor: %s\nAno: %d\n",aux->livro.titulo,aux->livro.autor,aux->livro.ano);
            return aux->prox;
        }
        printf("livro nao encontrado...\n");
        system("pause");
    }
    return NULL;
}
int lista_vazia(Lista* l){
    if(l == NULL){
        printf("nenhum livro cadastrado...\n");
    }
    return 0;
}



void insere_arquivoP(Lista* l, FILE* fp){
    fp = fopen("biblioteca.txt", "w"); // Abre o arquivo_origem para leitura
    if (fp == NULL)
    {
        printf("Erro ao abrir o sistema\n");
        system("pause");
    }
   
    Lista* aux;
    for(aux = l; aux != NULL; aux = aux->prox){
        fprintf(fp, "Nome: %s\nAutor: %s\nAno: %d\n",aux->livro.titulo,aux->livro.autor,aux->livro.ano);
    }
    fclose(fp);
}
