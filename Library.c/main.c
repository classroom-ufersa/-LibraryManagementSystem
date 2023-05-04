#include<stdio.h>

#include"book.c"




int main(){
    char titulo[81];
    int ano;
    char autor[81];
int escolha=0; 

//system("cls");

    while (escolha!= 8)
    { 
         printf("-------MENU--------\n");
         printf("1- Adicinor Livro:\n");
         printf("2- Remover Livro:\n");
         printf("3- listar Livros cadastrados:\n");
         printf("4- Buscar livro:\n");
         printf("5- Editar livro:\n");
         printf("6- Consultar livro em uma data biblioteca:\n");
         printf("7- consultar quantidade de biblioteca:\n");
         printf("8- sair do programa:");
         printf("\n-----escolha uma opcao------\n");
         scanf("%d", &escolha);
    system("cls");
    switch (escolha)
    {
        case 1: 
        printf("1- adicionar Livro:\n");
         Book * l;
         l= criar_book();
         printf("informe o nome do livro:\n");
scanf(" %s", &titulo);
printf("informe o ano:\n");
scanf(" %d", &ano);
printf("informe o autor:\n");
scanf(" %s", &autor);
 system("cls");
        break;
        case 2: 
        printf("2- Remover Livro:\n ");
         break;
        case 3:
        printf("3- listar Livros cadastrados:\n");
       exibe_livro(l);
    
         break;
        case 4:
         printf("4- Buscar livro:\n");
          break;
        case 5:
        printf("5- Editar livro:\n"); 
         break;
        case 6: 
        printf("6- Consultar livro em uma dada biblioteca:\n");
         break;
        case 7: 
         printf("7- consultar quantidade de biblioteca:\n");
        case 8:
         printf("saindo do programa:");
         exit(1);
         break;
        default:
         printf("Opcao invalida, tente novamente\n\t\n\t\n");

    
}
    }
return 0;
}