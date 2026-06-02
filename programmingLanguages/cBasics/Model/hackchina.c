#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//						Code by .??.
//						DarkThorn@163.com
//						http://blog.donews.com/6lines

#define MAXPOP 200
#define MAXSTR 64

#define DEFPOPSIZ 50	//default pop size, value domain:	[2,200]
#define DEFCHRLEN 22	//default chrom length:				[2,63]
#define DEFMAXGEN 100	//default max generation:			[1,65535]
#define DEFPC 0.25	//default crossover probability:		[0.0,1.0]
#define DEFPM 0.01f	//default mutation probability:			[0.0,1.0]

typedef struct population
{
	unsigned chrom[MAXSTR];
	float x,fitness;				//x: value of chrom
	unsigned parent1,parent2,xsite;
}POP;


	unsigned nPopSize,nMutation,nCross,nXcross,nRndIdx;
	float fPc,fPm,fSumFit,fAvgFit,fRand[MAXPOP];
	double coef;


	POP *pOldPop,*pNewPop,*pPop;
	unsigned nChromLen,nGen,nMaxGen,nMaxPop,nMinPop,nTxt;
	float fMaxFit,fMinFit;

	void InitData();

	int Flip(float probabiliby);
	float Random();		//generate a pseudorandom integer from 0 to 1
	void ResetRandom();	//reset pseudorandom integer array fRand

	float ObjFunc(float vx);
	float DeCode(unsigned * pChrom);

	void StatPop(POP * pop);
	void InitPop();		//initialize population
	void InitReport();   //initial info report

	unsigned Select();
	int Mutation(unsigned chromval);
	int CrossOver(unsigned * parent1,unsigned * parent2,int popidx);
	void UpdateGen();

	void Report(int gen);


int main()
{
	float oldmaxfit;
	int oldmaxpp;
	unsigned i;

	InitData();
	InitPop();
	InitReport();
	pPop=pNewPop;
	pNewPop=pOldPop;
	StatPop(pNewPop);
	Report(nGen);
	pNewPop=pPop;
	do
	{
		nGen++;
		oldmaxfit=fMaxFit;
		oldmaxpp=nMaxPop;
		UpdateGen();
		StatPop(pNewPop);
		if(fMaxFit<oldmaxfit)
		{
			for(i=0;i<nChromLen;i++)
				pNewPop[nMinPop].chrom[i]=pOldPop[oldmaxpp].chrom[i];
			pNewPop[nMinPop].x=pOldPop[oldmaxpp].x;
			pNewPop[nMinPop].fitness=pOldPop[oldmaxpp].fitness;
			StatPop(pNewPop);
		}
		Report(nGen);
		pPop=pOldPop;
		pOldPop=pNewPop;
		pNewPop=pPop;
	}while(nGen<nMaxGen);
	if(pOldPop)
		free(pOldPop);
	if(pNewPop)
		free(pNewPop);
}



void InitData()
{
	unsigned i;
	if(pOldPop)
		free(pOldPop);
	if(pNewPop)
		free(pNewPop);
	printf("Please Input Population Size(2-200)(Default:%u):",DEFPOPSIZ);
	scanf("%u",&nPopSize);
	printf("Please Input Chromosome Length(2-63)(Default:%u):",DEFCHRLEN);
	scanf("%u",&nChromLen);
	printf("Please Input Max Generation(1-65535)(Default:%u):",DEFMAXGEN);
	scanf("%u",&nMaxGen);
	printf("Please Input Crossover Probability(0.0-1.0)(Default:%f):",DEFPC);
	scanf("%f",&fPc);
	printf("Please Input Mutation Probability(0.0-1.0)(Default:%f):",DEFPM);
	scanf("%f",&fPm);
	nGen=0;
	nCross=0;
	nMutation=0;
	nTxt=0;
	coef=pow(2.00,nChromLen)-1.0;
	srand((unsigned)time(NULL));
	ResetRandom();

	if(!(pOldPop=(POP *)malloc(nPopSize*sizeof(POP))))
	{
		printf("Allocate Memory Failed !");
		exit(1);
	}
	if(!(pNewPop=(POP *)malloc(nPopSize*sizeof(POP))))
	{
		printf("Allocate Memory Failed !");
		exit(1);
	}

	for(i=0;i<nPopSize;i++)
	{
		pOldPop[i].chrom[0]='\0';
		pNewPop[i].chrom[0]='\0';
	}
}

void ResetRandom()
{
	unsigned i;
	//srand((unsigned)time(NULL));
	for(i=0;i<nChromLen;i++)
		fRand[i]=(float)(rand()/(float)RAND_MAX);
	nRndIdx=0;
}

float Random()
{
	nRndIdx++;
	if(nRndIdx>=nChromLen)
	{
		nRndIdx=0;
		ResetRandom();
	}
	return fRand[nRndIdx];
}

int Flip(float probability)
{
	float tmp;
	//srand((unsigned)time(NULL));
	tmp=(float)(rand()/(float)RAND_MAX);
	if(tmp<=probability)
		return 1;
	return 0;
}

float ObjFunc(float vx)
{
	double y;
	//y=sin(2.0*3.1415926*vx);
	//return (float)(y*y);

	y=vx*sin(10*3.1415926*vx)+1.0;
	return (float)y;
}

float DeCode(unsigned * pChrom)
{
	int i;
	double t1,t2;
	t1=0.0;
	t2=1.0;
	for(i=nChromLen-1;i>=0;i--)
	{
		if(pChrom[i])
			t1+=t2;
		t2*=2.0;
	}
	//t1/=coef;
	t1=-1.0+t1*3.0/coef;
	return (float)t1;
}

void StatPop(POP * pop)
{
	unsigned i;
	fSumFit=pop[0].fitness;
	fMinFit=pop[0].fitness;
	fMaxFit=pop[0].fitness;
	nMaxPop=0;
	nMinPop=0;
	for(i=1;i<nPopSize;i++)
	{
		fSumFit+=pop[i].fitness;
		if(pop[i].fitness>fMaxFit)
		{
			fMaxFit=pop[i].fitness;
			nMaxPop=i;
		}
		if(pop[i].fitness<fMinFit)
		{
			fMinFit=pop[i].fitness;
			nMinPop=i;
		}
	}
	fAvgFit=fSumFit/(float)nPopSize;
}

void InitPop()
{
	unsigned i,j;
	//srand((unsigned)time(NULL));
	for(i=0;i<nPopSize;i++)
	{
		for(j=0;j<nChromLen;j++)
			pOldPop[i].chrom[j]=(int)(2.0/(float)RAND_MAX*rand());
		pOldPop[i].chrom[j]='\0';
		pOldPop[i].x=(float)DeCode(pOldPop[i].chrom);
		pOldPop[i].fitness=ObjFunc(pOldPop[i].x);
		pOldPop[i].parent1=0;
		pOldPop[i].parent2=0;
		pOldPop[i].xsite=0;
	}
	StatPop(pOldPop);
}

void InitReport()
{
	FILE *fp;

	printf("                        Simple Genetic Algorithm - SGA\n");
	printf("________________________________________________________________________________\n");
	printf("    SGA Parameters:\n");
	printf("Population Size(nPopSize) = %u\n",nPopSize);
	printf("Chromosome Length(nChromLen) = %u\n",nChromLen);
	printf("Maximum of Generation(nMaxGen) = %u\n",nMaxGen);
	printf("Crossover Probability(fPc) = %f\n",fPc);
	printf("Mutation Probability(fPm) = %f\n",fPm);
	printf("________________________________________________________________________________\n");
	printf("Initial Population Average Fitness = %f\n",fAvgFit);
	printf("Initial Population Max Fitness = %f\n",fMaxFit);
	printf("Initial Population Min Fitness = %f\n",fMinFit);
	printf("Initial Population Sum Fitness = %f\n",fSumFit);
	printf("________________________________________________________________________________\n");

	if((fp=fopen("SGAReport.txt","w"))==NULL)
	{
		printf("Cannot Open File for Report!");
		exit(2);
	}

	fprintf(fp,"                    Simple Genetic Algorithm - SGA\n");
	fprintf(fp,"________________________________________________________________________________\n");
	fprintf(fp,"    SGA Parameters:\n");
	fprintf(fp,"Population Size(nPopSize) = %u\n",nPopSize);
	fprintf(fp,"Chromosome Length(nChromLen) = %u\n",nChromLen);
	fprintf(fp,"Maximum of Generation(nMaxGen) = %u\n",nMaxGen);
	fprintf(fp,"Crossover Probability(fPc) = %f\n",fPc);
	fprintf(fp,"Mutation Probability(fPm) = %f\n",fPm);
	fprintf(fp,"________________________________________________________________________________\n");
	fprintf(fp,"Initial Population Average Fitness = %f\n",fAvgFit);
	fprintf(fp,"Initial Population Max Fitness = %f\n",fMaxFit);
	fprintf(fp,"Initial Population Min Fitness = %f\n",fMinFit);
	fprintf(fp,"Initial Population Sum Fitness = %f\n",fSumFit);
	fprintf(fp,"________________________________________________________________________________\n");

	fclose(fp);

}

unsigned Select()
{
	double tmprnd,tmpsum;
	unsigned i;
	tmpsum=0.0;
	i=0;
	tmprnd=Random()*fSumFit;
	do
	{
		tmpsum+=pOldPop[i].fitness;
		i++;
	}while((tmpsum<tmprnd)&&(i<nPopSize));
	return i-1;
}

int Mutation(unsigned chromval)
{
	int mutate;
	mutate=Flip(fPm);
	if(mutate)
	{
		nMutation++;
		if(chromval)
			chromval=0;
		else
			chromval=1;
	}
	if(chromval)
		return 1;
	else
		return 0;
}

int CrossOver(unsigned * parent1,unsigned * parent2,int popidx)
{
	unsigned i;
	//srand((unsigned)time(NULL));
	if(Flip(fPc))
	{
		nXcross=(int)((float)(nChromLen-1)/(float)RAND_MAX*rand());
		nCross++;
	}
	else
		nXcross=nChromLen;
	if(nXcross!=nChromLen)
	{
		for(i=0;i<nXcross;i++)
		{
			pNewPop[popidx].chrom[i]=Mutation(parent1[i]);
			pNewPop[popidx+1].chrom[i]=Mutation(parent2[i]);
		}
		for(i=nXcross;i<nChromLen;i++)
		{
			pNewPop[popidx].chrom[i]=Mutation(parent2[i]);
			pNewPop[popidx+1].chrom[i]=Mutation(parent1[i]);
		}
	}
	else
		for(i=0;i<nChromLen;i++)
		{
			pNewPop[popidx].chrom[i]=Mutation(parent1[i]);
			pNewPop[popidx+1].chrom[i]=Mutation(parent2[i]);
		}
	return 1;
}

void UpdateGen()
{
	unsigned i,mate1,mate2;
	i=0;
	do
	{
		mate1=Select();
		mate2=Select();
		CrossOver(pOldPop[mate1].chrom,pOldPop[mate2].chrom,i);
		pNewPop[i].x=(float)DeCode(pNewPop[i].chrom);
		pNewPop[i].fitness=ObjFunc(pNewPop[i].x);
		pNewPop[i].parent1=mate1;
		pNewPop[i].parent2=mate2;
		pNewPop[i].xsite=nXcross;
		pNewPop[i+1].x=(float)DeCode(pNewPop[i+1].chrom);
		pNewPop[i+1].fitness=ObjFunc(pNewPop[i+1].x);
		pNewPop[i+1].parent1=mate1;
		pNewPop[i+1].parent2=mate2;
		pNewPop[i+1].xsite=nXcross;
		i=i+2;
	}while(i<nPopSize);
}

void Report(int gen)
{
	unsigned i,j;
	FILE *fp;
	if((fp=fopen("SGAReport.txt","a"))==NULL)
	{
		printf("Cannot Open File for Report!");
		exit(2);
	}
	printf("    Population Report:\n");
	printf("Generation: %d\n",gen);
	printf("Indiv  Parents   xsite    x        Fitness     String\n");

	fprintf(fp,"    Population Report:\n");
	fprintf(fp,"Generation: %d\n",gen);
	fprintf(fp,"Indiv  Parents   xsite    x        Fitness     String\n");

	for(i=0;i<nPopSize;i++)
	{
		printf("%3u>: (%3u,%3u)   %2u %10.4f %10.4f     ",
			i,pNewPop[i].parent1,pNewPop[i].parent2,
			pNewPop[i].xsite,pNewPop[i].x,pNewPop[i].fitness);
		fprintf(fp,"%3u>: (%3u,%3u)   %2u %10.4f %10.4f     ",
			i,pNewPop[i].parent1,pNewPop[i].parent2,
			pNewPop[i].xsite,pNewPop[i].x,pNewPop[i].fitness);
		for(j=0;j<nChromLen;j++)
		{
			printf("%d",pNewPop[i].chrom[j]);
			fprintf(fp,"%d",pNewPop[i].chrom[j]);
		}
		printf("\n");
		fprintf(fp,"\n");
	}

	printf("________________________________________________________________________________\n");
	printf("    Result:\n");
	printf("Generation Calculated(nGen) = %u\n",nGen);
	printf("Average Fitness = %8.4f\n",fAvgFit);
	printf("Chromosome Value with Max Fitness = (%2u,%f)\n",nMaxPop,pNewPop[nMaxPop].x);
	printf("Max Fitness = %f\n",fMaxFit);
	printf("Chromosome Value with Min Fitness = (%2u,%f)\n",nMinPop,pNewPop[nMinPop].x);
	printf("Min Fitness = %f\n",fMinFit);
	printf("Crossover Num = %u\n",nCross);
	printf("Mutate Num = %u\n",nMutation);
	printf("________________________________________________________________________________\n");

	fprintf(fp,"________________________________________________________________________________\n");
	fprintf(fp,"    Result:\n");
	fprintf(fp,"Generation Calculated(nGen) = %u\n",nGen);
	fprintf(fp,"Average Fitness = %8.4f\n",fAvgFit);
	fprintf(fp,"Chromosome Value with Max Fitness = (%2u,%f)\n",nMaxPop,pNewPop[nMaxPop].x);
	fprintf(fp,"Max Fitness = %f\n",fMaxFit);
	fprintf(fp,"Chromosome Value with Min Fitness = (%2u,%f)\n",nMinPop,pNewPop[nMinPop].x);
	fprintf(fp,"Min Fitness = %f\n",fMinFit);
	fprintf(fp,"Crossover Num = %u\n",nCross);
	fprintf(fp,"Mutate Num = %u\n",nMutation);
	fprintf(fp,"________________________________________________________________________________\n");

	//fclose(fp);
	system("pause");
}
