typedef struct livro Livro;
typedef struct listalivro Listalivro;

Livro livros_preenche(void);

Listalivro *lista_add(Listalivro *l, Livro livro);

void livros_add(Listalivro *p, FILE *arquivo);

Listalivro *busca_livro(Listalivro *l, char nome[]);

void edita_livro(Listalivro *p);

void lista_libera(Listalivro *l);

void lista_imprime(Listalivro *l);

void corrige_nome(char nome[]);