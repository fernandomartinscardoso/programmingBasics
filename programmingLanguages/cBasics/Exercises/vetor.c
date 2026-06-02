#include <stdio.h>
#include <stdlib.h>

int main (){
    //Variaveis
    int cont;
    int vet[5];
    
    //Entrada de dados
    for (cont=0; cont<5; cont++){
        printf("Entre com um numero:");
        scanf("%d", &vet[cont]);
    }
    for (cont=0; cont<5; cont++){
        printf("\nO numero armazenado no %d = %d\n", cont+1, vet[cont]);
    }
    system("pause");    
}
