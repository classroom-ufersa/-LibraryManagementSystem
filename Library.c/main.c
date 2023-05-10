#include<stdio.h>
#include <string.h>
#include"book.c"




int main(){
    char titulo[50];
    char autor[50];
    int ano;
    int op=0, o; 
    Lista * l;
   
    
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
        Lista * l;
        l = cria_lista();
        l = cadastro_Book(l);
         
            break;
        case 3:
        printf("\n-------  SITEMA DE GERENCIAMENTE DE BIBLIOTECA ---------\n\n");
        imprime_lista(l);
            break;
        case 8:
        printf("\n-------  SITEMA DE GERENCIAMENTE DE BIBLIOTECA ---------\n\n");
        printf("DESEJA SAIR DO PROGRAMA\n");
        printf("[1] - SIM\n[2] - NAO\n");
        printf("\n>>> ");
        scanf("%d", &o);
        if(o == 1){
            system("cls");
         printf("\n-------  SITEMA DE GERENCIAMENTE DE BIBLIOTECA ---------\n\n");
         printf("\tOBRIGADO POR USAR NOSSO SISTEMA\n");
         printf("\t>>>VOLTE SEMPRE<<<\n");
        exit(1);
        } else{
            op = 2;
        }
        break;

    }
        }while(op != 8);
    return op;
}
