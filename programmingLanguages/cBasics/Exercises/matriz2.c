#include <stdio.h>
#include <stdlib.h>

int main(){
    //Variaveis
    int matriz[3][3];
    int linha, coluna;
    
    //Processamento
    for(linha=0; linha<3; linha++)
    {
                 for(coluna=0; coluna<3; coluna++)
                 {
                               printf("Digite o numero:");
                               scanf("%d", &matriz[linha][coluna]);
                 }
                 
    }
                 
    
    printf("A matriz formada e:\n%d%d%d\n%d%d%d\n%d%d%d\n", matriz[0][0], matriz[0][1], matriz[0][2], matriz[1][0], matriz[1][1], matriz[1][2], matriz[2][0], matriz[2][1], matriz[2][2]);
               
    system("pause");
    }
