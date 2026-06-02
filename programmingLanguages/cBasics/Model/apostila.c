/*
****
* SGA
****
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <math.h>

#define RAND_MAX   0x7FFF
#define random(num)   (rand()%(num))
#define randomize()   srand((unsigned)time(NULL))

#define POPULATION_SIZE   10
#define CHROM_LENGTH       4
#define PCROSS           0.6
#define PMUT           0.050
#define MAX_GEN           50

struct population
{
       int            value;
       unsigned char  string[CHROM_LENGTH];
       unsigned int   fitness;
};

struct population pool[POPULATION_SIZE];
struct population new_pool [POPULATION_SIZE];

int selected[POPULATION_SIZE];
int generations;

/*
****
* Algorithm Control
****
*/
main()
{
      int i;
      double sum_fitness,
             avg_fitness,
             old_avg_fitness;
             
      generations = 1;
      avg_fitness = 1;
      
      initialise_population();
      
/****
Main Loop
****/

      do
      {
                              old_avg_fitness = avg_fitness;
                              sum_fitness = 0;
                              /* fitness evaluation */
                              for (i=0; i<POPULATION_SIZE; i++)
                              {
                                  pool[i].value = decode(i);
                                  pool[i].fitness = evaluate(pool[i].value);
                                  sum_fitness += pool[i].fitness;
                              }
                              
                              avg_fitness = sum_fitness/POPULATION_SIZE;
                              for (i=0; i<POPULATION_SIZE; i++)
                                  selected[i] = select(sum_fitness);
                                  
                              for (i=0; i<POPULATION_SIZE; i=i+2)
                              
                              crossover(selected[i], selected[i+1], i, i+1);
                              
                              mutation();
                              
                              statistics();
                              printf("\nImprovement: &f\n", avg_fitness/old_avg_fitness);
      }
      while ((++generations < MAX_GEN) && ((avg_fitness/old_avg_fitness) > 1.005)||(avg_fitness/old_avg_fitness) < 1.0);
}

/*
****
initialise_population
Creates and initialise a population
****
*/
initialise_population()
{
                       int i;
                       
                       randomize();
                       for (i=0; i<POPULATION_SIZE; i++)
                           encode(i, random(2^CHROM_LENGTH));
}

/*
****
select
Selects strings for reproduction
****
*/
select(sum_fitness)
double(sum_fitness);
{
                    int i;
                    double r, parsum;
                    
                    parsum = 0;
                    /*spin the roulette*/
                    r = (double)(rand() % (int)sum_fitness);
                    
                    for (i=0; i<POPULATION_SIZE, parsum<=r; i++)
                        parsum += pool[i].fitness;
                    
                    return(--i); /*returns a selected string*/
}

/*
****
crossover
Swaps 2 sub-strings
****
*/
crossover(parent1, parent2, child1, child2)
int parent1;
int parent2;
int child1;
int child2;
{
    int i, site;
    
    if (flip(PCROSS))
        site = random(CHROM_LENGTH);
    else
        site = CHROM_LENGTH;
    for (i=0; i<CHROM_LENGTH; i++)
    {
        if((i<=site) || (site==0))
        {
                     new_pool[child1].string[i] = pool[parent1].string[i];
                     new_pool[child2].string[i] = pool[parent2].string[i];
        }else
        {
             new_pool[child1].string[i] = pool[parent2].string[i];
             new_pool[child2].string[i] = pool[parent1].string[i];
        }
    }
}

/*
****
mutation
Changes the values of string position
****
*/
mutation()
{
          int i,j;
          
          for(i=0; i<POPULATION_SIZE; i++)
          {
                   for(j=0; j<CHROM_LENGTH; j++)
                       if(flip(PMUT))
                          pool[i].string[j] = ~new_pool[i].string[j] & 0x01;
                       else
                          pool[i].string[j] = new_pool[i].string[j]; //& 0x01;
          }
}

/*
****
encode
Code a integer into binary
****
*/
encode(index,value)
int index;
int value;
{
    int i;
    
    for(i=0; i<CHROM_LENGTH; i++)
        pool[index].string[CHROM_LENGTH-1-i] = (value >> i) & 0x01;
}

/*
****
decode
Decode a binary string into an integer
****
*/
decode(index)
int index;
{
    int i, value;
    
    value = 0;
    for(i=0; i<CHROM_LENGTH; i++)
        value += (int)pow(2.0,(double)i)*pool[index].string[CHROM_LENGTH-1-i];
        
    return(value);
}

/*
****
evaluate
Objective function:
          f(x) = [10/(4-x)^2+1]+[20/(15-x)^2+1]
****
*/
evaluate(value)
int value;
{
    return(10/(pow(((double)4-(double)value),2.0)+1)+20/(pow(((double)15-(double)value),2.0)+1));
}

/*
****
flip
Toss a biased coin
****
*/
flip(prob)
double prob;
{
       double i;
       
       i = ((double)rand())/RAND_MAX;
       
       if((prob==1.0) || (i<prob))
           return(1);
       else
           return(0);
}

/*
****
statistics
Print entermediary results
****
*/
statistics()
{
            int i,j;
            printf("\nGeneration: %d\n;Selected Strings\n", generations); 
            
            for(i=0; i<POPULATION_SIZE; i++)
                printf("%d", selected[i]);
                printf("\n");
                printf("\n;X\tf(x)\t New_String\tX'");
                for(i=0; i<POPULATION_SIZE; i++)
                {
                         printf("\n $d\t%u\t;", pool[i].value, pool[i].fitness);
                         
                         for(j=0; j<CHROM_LENGTH;j++)
                             printf("%d", pool[i].string[j]);
                             
                         printf("\t%d", decode(i));
                }
            
            
            system("pause");
         
}                  
                       
        
                     
                  
