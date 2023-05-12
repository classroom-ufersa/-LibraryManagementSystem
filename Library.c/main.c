#include <stdio.h>
#include <string.h>
#include "library.c"

int main()
{
    int op = 0, id = 0;
    int quantidade = 0;
    char nome[TAM_MAX];
    Listalivro *livrotemp = (Listalivro *)malloc(sizeof(Listalivro));
    FILE *arquivo;
    char caminho[] = "C:/Users/ddegu/OneDrive/Documentos/GitHub/LibraryManagementSystem/Library.c/output/biblioteca.txt";
    arquivo = fopen(caminho, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo!");
        exit(1);
    }

    Biblioteca *Sapiencia = biblioteca_cria();
    ler_arquivo(Sapiencia, caminho, &quantidade);

    do
    {
        system("cls");
        printf("\n-------  SISTEMA DE GERENCIAMENTE DE BIBLIOTECA ---------\n\n");
        printf("[1] - ADICIONAR LIVRO\n");
        printf("[2] - REMOVER LIVRO\n");
        printf("[3] - LISTAR LIVROS CADASTRADOS\n");
        printf("[4] - BUSCAR LIVRO\n");
        printf("[5] - EDITAR LIVRO\n");
        printf("[6] - CONSUTAR LIVROS EM UMA DADA BIBLIOTECA\n");
        printf("[7] - CONSULTAR QUANTITATIVO DE BIBLIOTECA\n");
        printf("[8] - SAIR DO PROGRAMA\n");
        printf("\n>>> ");
        scanf("%d", &op);
        system("cls");

        switch (op)
        {
        case 1:
            Sapiencia = cadastra_livros(Sapiencia, &quantidade);
            arquivo = add_arquivo(Sapiencia, caminho);
            break;
        case 2:
            printf("Insira o nome do livro que deseja excluir: ");
            scanf(" %[^\n]s", nome);
            livrotemp = busca_livro(Sapiencia->lista, nome);
            excluir_livro(livrotemp, Sapiencia);
            add_arquivo(Sapiencia, caminho);
            break;
        case 3:
            lista_imprime(Sapiencia->lista);
            break;
        case 4:
            printf("Insira o nome do livro que deseja buscar: ");
            scanf(" %[^\n]s", nome);
            livrotemp = busca_livro(Sapiencia->lista, nome);

            printf("Titulo: %s\n", livrotemp->livro->titulo);
            printf("Ano: %d\n", livrotemp->livro->ano);
            printf("Autor: %s\n", livrotemp->livro->autor);
            printf("Biblioteca: %d\n", livrotemp->livro->biblioteca);
            printf("Status: %s\n", livrotemp->livro->status);
            system("pause");
            break;
        case 5:
            printf("Insira o nome do livro que deseja editar: ");
            scanf(" %[^\n]s", nome);
            livrotemp = busca_livro(Sapiencia->lista, nome);
            edita_livro(livrotemp);
            add_arquivo(Sapiencia, caminho);
            system("pause");
            break;
        case 6:
            printf("Digite o codigo da biblioteca deseja consultar: ");
            scanf(" %d", &id);
            livrotemp = busca_id(Sapiencia->lista, id);
            break;
        case 7:
            dados_biblioteca(Sapiencia);
            dados_lib();
            break;
        case 8:
            printf("Deseja sair do sistema?\n");
            printf("[1] - SIM \n[2] - NAO\n");
            printf("\n>>> ");
            scanf("%d", &op);
            if (op == 1)
            {
                system("cls");
                printf("\n\n==========================================");
                printf("\n     OBRIGADO POR USAR NOSSO SISTEMA!!       ");
                printf("\n==========================================\n");
                exit(1);
            }
        default:
            printf("Opcao invalida, tente novamente!!\n");
            system("pause");
        }
    } while (op != 8);
    return op;
    lista_libera(Sapiencia->lista);
    free(Sapiencia);
}