#include <stdio.h>
#include <stdlib.h>
int main (){
    //Variaveis
    int x, i, j;
    int vet[5];
    
    //Entrada de dados
    for(i=0; i<5; i++)
    {
        printf("Entre com o elemento numero %d:", i+1);
        scanf("%d", &vet[i]);
    }
    
    //Processamento
    for(i=0; i<4; i++)
    {
             for(j=i+1; j<5; j++)
             {
                      if(vet[i]>vet[j])
                      {
                                       x=vet[i];
                                       vet[i]=vet[j];
                                       vet[j]=x;
                      }
             }
    }
    
    printf("Os valores do vetor, ordenados em ordem decrescente, sao: \n%d\n%d\n%d\n%d\n%d\n", vet[0], vet[1], vet[2], vet[3], vet[4]);
    
    system("pause");    
} 
                   

