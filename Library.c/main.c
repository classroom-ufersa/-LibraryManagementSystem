#include <stdio.h>
#include <string.h>
#include "book.c"

int main()
{
    char titulo[50], nome[50];
    int op = 0, o, contador;
    Lista *l= cria_lista();
    FILE* fp;
    

    do
    {
        system("cls");
        printf("\n-------  SITEMA DE GERENCIAMENTE DE BIBLIOTECA ---------\n\n");
        printf("[1] - CADASTRA LIVRO NA BIBLIOTECA\n");
        printf("[2] - REMOVER LIVRO\n");
        printf("[3] - LISTAR LIVROS CADASTRADOS\n");
        printf("[4] - BUSCAR LIVRO\n");
        printf("[5] - EDITAR LIVRO\n");
        printf("[6] - CONSUTAR LIVRO EM UMA DADA BIBLIOTECA\n");
        printf("[7] - CONSULTAR QUANTITATIVO DE BIBLIOTECA\n");
        printf("[8] - SAIR DO PROGRAMA\n");
        printf("\n>>> ");
        scanf("%d", &op);
        system("cls");

        switch (op)
        {
        case 1:
        cadastro_Book(l, titulo);
        insere_arquivoP(l, fp, contador);
         
            break;
        case 3:
        imprime_lista(l);
            break;

            case 4:
         system("cls");
        printf("\n-------  SITEMA DE GERENCIAMENTE DE BIBLIOTECA ---------\n\n");
        printf("INFORME O NOME DO LIVRO QUE DESEJA BUSCAR\n");
        printf("\n>>> ");
        scanf(" %[^\n]s", &nome);
        system("cls");
         printf("\n-------  SITEMA DE GERENCIAMENTE DE BIBLIOTECA ---------\n\n");
         busca_nome(l, nome);
                system("\n\npause");
            

            break;
















        case 8:
            printf("\n-------  SITEMA DE GERENCIAMENTE DE BIBLIOTECA ---------\n\n");
            printf("DESEJA SAIR DO PROGRAMA\n");
            printf("[1] - SIM\n[2] - NAO\n");
            printf("\n>>> ");
            scanf("%d", &o);
            system("cls");
            if (o == 1)
            {
                printf("OBRIGADO POR USAR O SISTEMA\n");
                printf("VOLTE SEMPRE...\n");
                exit(1);
            }
            else
            {
                op = 2;
            }
            break;
        }
    } while (op != 8);
    return op;
}
