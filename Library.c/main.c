# include<stdio.h>




int main(){
int escolha=0; 

    while (escolha!= 8)
    { 
         printf("-------MENU--------\n");
         printf("1- Adicinor Livro:\n");
         printf("2- Remover Livro:\n");
         printf("3- listar Livros cadastrados:\n");
         printf("4- Buscar livro:\n");
         printf("5- Editar livro:\n");
         printf("6- Consultar livro em uma dada biblioteca:\n");
         printf("7- consultar quantidade de biblioteca:\n");
         printf("8- sair do programa:");
         printf("\n escolha uma opcao:");
         scanf("%d", &escolha);
    
    switch (escolha)
    {
        case 1: 
        printf("1- Adicinor Livro:\n");
        break;
        case 2: 
        printf("2- Remover Livro:\n ");
         break;
        case 3:
        printf("3- listar Livros cadastrados:\n");
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
          break;
        case 8:
         printf("8- sair do programa:");
         default:
         printf("Opcao invalida, tente novamente");

    }
}
return 0;
}