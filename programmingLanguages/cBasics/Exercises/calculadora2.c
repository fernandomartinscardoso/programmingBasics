#include <stdio.h>
#include <stdlib.h>

int main ()
{
    //Variaveis
    float n1,n2;
    int opcao;
    
    //Entrada de dados
    printf("Entre com um numero;\n");
    scanf("%f", &n1);
    fflush (stdin);
    printf("Entre com a opcao desejada:"
           "\n 1:Somar"
           "\n 2:Subtrair"
           "\n 3:Dividir"
           "\n 4:Multiplicar"
           "\n");
    scanf("%d", &opcao);
    fflush (stdin);
    if(opcao>4){
                printf("Voce digitou uma opcao invalida.\nDigite a opcao desejada:\n");
                scanf("%d", &opcao);
                printf("Entre com outro numero;\n");
                scanf("%f", &n2);
                }else{
                      printf("Entre com outro numero;\n");
                      scanf("%f", &n2);
                      }
    
    //Processamento
                   switch(opcao){
                  case 1:
                       printf("A soma entre %.2f e %.2f = %.2f", n1, n2, n1+n2);
                       break;
                  case 2:
                       printf("A subtracao entre %.2f e %.2f = %.2f", n1, n2, n1-n2);
                       break;
                  case 3:
                       if(n2==0){
                                 printf("Nenhum numero e divisivel por zero");
                                 }else{
                                       printf("A divisao entre %.2f e %.2f = %.2f", n1, n2, n1/n2);
                                       }
                       break;
                  case 4:
                       printf("A multiplicacao entre %.2f e %.2f = %.2f", n1, n2, n1*n2);
                       break;
                                }              
                   
          

    //Final de Código
    fflush (stdin);
    getch();
    return 0;    
}
