#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "Construcao.h"
#include "Util.h"
#include "Descida.h"
#include "GRASP.h"

float GRASP(int n, int *s, float **d, float alpha, int GRASP_max, int tipo_construcao){
   int *s_star,
       iter = 0;
   float fo_star = INT_MAX;
   float fo;

   s_star = cria_vetor(n);
   while (iter < GRASP_max){
     iter++;
     if (tipo_construcao == 1)
       constroi_solucao_parcialmente_gulosa_vizinho_mais_proximo(n,s,d,alpha);
       /* Ha erro no metodo abaixo */
//     if (tipo_construcao == 2)
//       constroi_solucao_parcialmente_gulosa_insercao_mais_barata(n,s,d,alpha);

//     float fo_antes = calcula_fo(n,s,d);
     fo = descida(n,s,d);
//     printf("solucao construida com fo = %10.3f \t  Apos descida fo = %10.3f \n",fo_antes,fo);
     fo = calcula_fo(n,s,d);
     if (fo < fo_star){
       fo_star = fo;
       atualiza_vetor(s_star, s, n);
//       printf("\Iteracao GRASP = %3d \t  fo_star = %10.3f \n",iter,fo_star);
     }
   }
   atualiza_vetor(s,s_star,n);

   libera_vetor(s_star);
   return fo_star;
}


