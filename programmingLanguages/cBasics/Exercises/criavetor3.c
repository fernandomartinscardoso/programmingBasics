/*
*****
*Geração do vetor de 24 elementos, aleatórios
*****
*/


#include <stdio.h>
#include <stdlib.h>

int main (){
    //Variaveis
    //int n, i, j;
    int v[24], i;
    
   
    srand(time(NULL));

    //Entrada de dados
    for(i=0; i<24; i++)
    {
        //if(v[5]<=1)
        //{
        v[i] = rand()%1001;
        //}
    }

    
    printf("O vetor de valores aleatórios é: \n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7],v[8],v[9],v[10],v[11],v[12],v[13],v[14],v[15],v[16],v[17],v[18],v[19],v[20],v[21],v[22],v[23]);
    
        
    system("pause");    
} 
 
