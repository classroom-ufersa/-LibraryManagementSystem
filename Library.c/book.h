typedef struct livro Livro;
typedef struct listalivro Listalivro;

// preenche os campos de dados do paciente
Livro livros_preenche(void);

// adiciona o paciente a lista
Listalivro *lista_add(Listalivro *l, Livro livro);

// adiciona o paciente ao arquivo
void livros_add(Listalivro *p, FILE *arquivo);

// busca um paciente na lista
Listalivro *busca_livro(Listalivro *l, char nome[]);

// edita um paciente
void edita_livro(Listalivro *p);

// libera a lista
void lista_libera(Listalivro *l);

// imprime os pacientes
void lista_imprime(Listalivro *l);

// corrige o nome
void corrige_nome(char nome[]);