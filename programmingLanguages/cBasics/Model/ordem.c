#include<stdio.h>
#include<stdlib.h>
/*Autor: Ruben Alves do Nascimento
  Contato: rubenanapu@hotmail.com      
*/
main()
{
    int a,n;
    printf("Quantos numeros pretendes exibir? ");
    scanf("%i",&n);
    printf("Ordem normal:\n");
    for(a=1;a<=n;a++) printf("%d ",a);
    printf("\n\nOrdem inversa:\n");
    for(a=n;a>0;a--) printf("%d ",a);
    printf("\n\n");
system("pause");
}
