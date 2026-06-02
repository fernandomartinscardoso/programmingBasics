#include <stdio.h>
#include <stdlib.h>

int main ()
{
    //Variaveis
    int meninos, meninas, soma;
    
    //Entrada de dados
    printf("Digite o numero de meninos na sala:");
    scanf("%d", &meninos);
    printf("Digite o numero de meninas na sala:");
    scanf("%d", &meninas);
    
    //Processamento
    soma = meninos + meninas;
    
    printf("O total de alunos na sala e: %d", soma);
    
    if(soma>40){
                printf("\nExiste mais alunos do que deveria na sala");
                }else{
                      printf("\nAinda ha espaco na sala de aula");
                      }

    
    //Final de Código
    fflush (stdin);
    getch();
    return 0;    
}
