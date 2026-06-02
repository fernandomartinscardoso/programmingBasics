#include <stdio.h>
#include <stdlib.h>

    //Procedimento
void media(float m1, float m2){
     float result;
     result = (m1+m2)/2;
     
     printf("A media e: %.2f\n", result);
     }

int main(){
    //Variaveis
    float n1, n2;
    
    //Entrada de Dados
    printf("Entre com a primeira nota:");
    scanf("%f", &n1);
    printf("Entre com a segunda nota:");
    scanf("%f", &n2); 
    
    media(n1, n2);
    
    system("pause");
    
}   
