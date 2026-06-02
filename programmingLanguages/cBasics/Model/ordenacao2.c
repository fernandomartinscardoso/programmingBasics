#include<stdio.h>
#include<stdlib.h>

main(){
       
       int vetor[10], x, i, j;
       
       for(i=0; i<10; i++)
       {
                printf("Digite o elemento numero %d:", i+1);
                scanf("%d", &vetor[i]);
       }
       
       for(i=0; i<9; i++)
       {
                for(j=i+1; j<10; j++)
                {
                           if(vetor[i]<vetor[j])
                           {
                                                x=vetor[i];
                                                vetor[i]=vetor[j];
                                                vetor[j]=x;
                           }
                }
       }
       
       printf("Os cinco maiores valores do vetor, em ordem decrescente são:\n%d\n%d\n%d\n%d\n%d", vetor[0], vetor[1], vetor[2], vetor[3], vetor[4]);
       
       getch();
 
         
    
      }
