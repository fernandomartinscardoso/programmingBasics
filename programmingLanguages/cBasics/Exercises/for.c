#include <stdio.h>
#include <stdlib.h>

int main ()
{
    //Variaveis
    int n, cont;
    
    //Entrada de dados
    printf("Entre com um numero:");
    scanf("%d", &n);
    
    //Processamento
    for(cont=0; cont<=n; cont++){
                printf("\n%d", cont);
    }          
    
    //Final de Código
    fflush (stdin);
    getch();
    return 0;    
}
