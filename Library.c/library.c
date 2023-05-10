#include <stdlib.h>
#include <ctype.h>
#include "library.h"
#include "book.c"
#define TAM_LINHA 100


/*
int salvar_livros(Lista *l)
{
    FILE *arquivo_origem;
    char linha[TAM_LINHA], nome[91];
     int linhas = 0;
    ;

    arquivo_origem = fopen("biblioteca.txt", "r"); // Abre o arquivo_origem para leitura
    if (arquivo_origem == NULL)
    {
        printf("Erro ao abrir o sistema\n");
        exit(1);
    }
   
}*/
///Fun�ao que salva as informa�oes da lista no arquivo.
void insere_arquivoP(Lista* l, FILE* fp){
fp = fopen("biblioteca.txt", "r"); // Abre o arquivo_origem para leitura
    if (fp == NULL)
    {
        printf("Erro ao abrir o sistema\n");
        exit(1);
    }
    Book* aux;
    for(aux = l; aux != NULL; aux = aux->prox){
        fprintf(fp, "Nome: %s\nAutor: %s\nAno: %d\n",aux->titulo,aux->autor,aux->ano);
    }
}


