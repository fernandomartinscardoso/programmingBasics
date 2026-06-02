#include <stdio.h>
#include <stdlib.h>

    //Procedimento
void criavetor(int v[]){
     int i;
     srand(n);
     for(i=0; i<=n-1; i++)
        v[i] = rand()%101;
     
     printf("Os valores do vetor sao: \n%d\n%d\n%d\n", v[0], v[1], v[2]);
     }
     
int main(){
    //Variaveis
    const n=10;
    int v[n];
    
    //Entrada de Dados
    printf("Entre com o numero de elementos:");
    scanf("%d", &n);
    
    criavetor(v[n]);     

    system("pause");
}
