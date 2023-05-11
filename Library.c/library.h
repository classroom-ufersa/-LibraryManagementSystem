#include "book.h"
typedef struct biblioteca Biblioteca;

FILE *add_arquivo(Biblioteca *h, char *caminho);

// adiciona livro
Biblioteca *cadastra_livros(Biblioteca *h, int *qnt);

Biblioteca *biblioteca_cria(void);

// le o arquivo e armazena na lista encadeada dupla
void ler_arquivo(Biblioteca *h, char *caminho, int *qnt);

// remove livros
Biblioteca *excluir_livro(Listalivro *p, Biblioteca *h);