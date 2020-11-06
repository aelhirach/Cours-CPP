
/*
 ============================================================================
 Name        : ErathosteneDynaIsPrimeEval.c
 Author      : JM Mattens
 Version     :
 Copyright   :
 Description :
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* typedef short int bool; */
typedef unsigned char bool;
#define false 0
#define true 1

#define MAX 2147483647       /* (2^31-1) */

struct TListePrem {
    int nbrMax;
    int* pPrem;
    int nbrPrem;
};

void InitialiserTListePrem(struct TListePrem * plistePrem){
		plistePrem->nbrMax = 0;
		plistePrem->nbrPrem = 0;
		plistePrem->pPrem = NULL;
	}

void Erathostene(struct TListePrem *plistePrem){
		/// créer le tableau principal 
		int maxValue= (plistePrem->nbrMax);
        int memorySize = (maxValue/2)+(maxValue%2);
        /// toutes les cases sont initialisées à 0 = Non barrées = prmeiers
		bool* array=(bool*)calloc(memorySize, sizeof(bool));
        /// Parcourir le tableau et barré(mettre à true) les multiples des nombres prmeiers (On commence par 3)
        register int i,j;
        for (i = 3; i < sqrt(maxValue); i += 2) {
           if (!array[(i / 2)]) {/// i/2 = 1-2-3-4-5-6-7-8-9-10  
                 j = (i * i) / 2; /// 4-12-24-...
                 while (j <memorySize) {
                 array[j] = true; 
                 j += i; /// les multiples impaires  exemple : 3*3 - 3*5 - 3*7 -3*9 .... <
                   }
		   }
		}
        
		i = 0;
		while (i <memorySize) {
			if (!array[i]) {
				plistePrem->nbrPrem++;
			}
			i++;
		}
		
		plistePrem->pPrem = calloc(plistePrem->nbrPrem, sizeof(int));
		plistePrem->pPrem[0] = 2;	
		
		j=1;  /// j=0 -> 2
		for (i=1; i<memorySize;i++) {
            if (!array[i]) {
                plistePrem->pPrem[j] = (2*i)+1;	
                j++;
            }
		}
		 free(array);
}

/*int f(int tab[], int nbVal , int val) {
    

        if (tab==NULL) return -1;
        else if ((val>tab[nbVal-1])) return -1;
        else if ((nbVal==1) || (val<tab[0])) return 0;
        else {
        bool trouve; int id; int ifin; int im; 
        trouve = false;  
        id = 0; 
        ifin = nbVal; 
        while(!trouve && ((ifin - id) > 1)){
        im = (id + ifin)/2;  
        trouve = (tab[im] == val);  
        if(tab[im] > val) ifin = im;  
        else id = im;  
      }
    
       if (tab[id] == val) return(id); 
       else return (id+1);
  
    }
}*/	   
void AfficherPremiers(struct TListePrem *plistePrem){
	     printf("Il y a %d nombre premiers inferieurs a %d\n", plistePrem->nbrPrem, plistePrem->nbrMax);
		 register int i; 
		 if (plistePrem->nbrPrem > 20) {
            for (i = 0; i < 10; i++) {
                printf("Nombre premier n %6d : %6d\n", i + 1, plistePrem->pPrem[i]);
            }

            printf("\n...\n\n");

            for (int i = plistePrem->nbrPrem - 10; i < plistePrem->nbrPrem; i++) {
               printf("Nombre premier n %6d : %6d\n", i + 1,  plistePrem->pPrem[i]);
            }

        } else {
            for (i = 0; i < plistePrem->nbrPrem; i++) {
                printf("Nombre premier n %6d : %6d\n", i + 1, plistePrem->pPrem[i]);
            }
        }
		 } 
void DetruireTListePrem(struct TListePrem *plistePrem)
		{
		 free(plistePrem->pPrem);
	     plistePrem->nbrMax = 0;
		 plistePrem->nbrPrem = 0;
		 }
int IsPrime(struct TListePrem *plistePrem, int n) {
    if(n<=plistePrem->nbrMax) 
       { int index = FindInSortedIntArray(plistePrem->pPrem,plistePrem->nbrPrem,n);
         if(n==plistePrem->pPrem[index])
         return true;
         else return false;
       }
        else  {
        bool isPrime=true;
        int j=0;
        while (j<=sqrt(n)) {
            printf("j=%d  pPrem[j]=%d  n=%d  ",j, plistePrem->pPrem[j],n);
            getchar();
            if((n%plistePrem->pPrem[j])==0)
                {  
                    isPrime=false;
                    printf("isPrime=%d",isPrime);
                    break;
                 }
                j++;

               }
               
        /*if (sqrt(n)>plistePrem->nbrPrem && isPrime)
             { 
                 for(int i=plistePrem->pPrem[plistePrem->nbrPrem-1];i<sqrt(n);i+=2)
                     {if (n%i==0) 
                     isPrime=false; }
             }*/
         return false;
       }
    
}
int FindInSortedIntArray(int tab[], int nbVal , int val) {
        
        if (tab==NULL) return -1;
        else if ((val>tab[nbVal-1])) return -1;
        else if ((nbVal==1) || (val<tab[0])) return 0;
        else {
        bool trouve; int id; int ifin; int im; 
        trouve = false;  
        id = 0; 
        ifin = nbVal; 
        while(!trouve && ((ifin - id) > 1)){
        im = (id + ifin)/2;  
        trouve = (tab[im] == val);  
        if(tab[im] > val) ifin = im;  
        else id = im;  
      }
    
       if (tab[id] == val) return(id); 
       else return (id+1);
  
    }
}

int main(int argc, char* argv[])
{
    clock_t ct1, ct2;
    struct TListePrem listePrem1;
    struct TListePrem listePrem2;
    struct TListePrem listePrem3;
    int* t1 = NULL;
    int t2[] = { 1 };
    int t3[] = { 1, 3 };
    int t4[] = { 1, 3, 5 };  
    int t5[] = { 1, 3, 5 ,7,11,13,15,17,19 };
    int cpt;
    int n;
    int findPrime;
    printf("Recherche 5 dans t1 -> %d\n", FindInSortedIntArray(t1, 0, 5));
    printf("Recherche 0 dans t2 -> %d\n", FindInSortedIntArray(t2, 1, 0));
    printf("Recherche 1 dans t2 -> %d\n", FindInSortedIntArray(t2, 1, 1));
    printf("Recherche 2 dans t2 -> %d\n", FindInSortedIntArray(t2, 1, 2));
    printf("Recherche 0 dans t3 -> %d\n", FindInSortedIntArray(t3, 2, 0));
    printf("Recherche 1 dans t3 -> %d\n", FindInSortedIntArray(t3, 2, 1));
    printf("Recherche 2 dans t3 -> %d\n", FindInSortedIntArray(t3, 2, 2));
    printf("Recherche 3 dans t3 -> %d\n", FindInSortedIntArray(t3, 2, 3));
    printf("Recherche 4 dans t3 -> %d\n", FindInSortedIntArray(t3, 2, 4));
    printf("Recherche 0 dans t4 -> %d\n", FindInSortedIntArray(t4, 3, 0));
    printf("Recherche 1 dans t4 -> %d\n", FindInSortedIntArray(t4, 3, 1));
    printf("Recherche 2 dans t4 -> %d\n", FindInSortedIntArray(t4, 3, 2));
    printf("Recherche 3 dans t4 -> %d\n", FindInSortedIntArray(t4, 3, 3));
    printf("Recherche 4 dans t4 -> %d\n", FindInSortedIntArray(t4, 3, 4));
    printf("Recherche 5 dans t4 -> %d\n", FindInSortedIntArray(t4, 3, 5));
    printf("Recherche 6 dans t4 -> %d\n", FindInSortedIntArray(t4, 3, 6));

    ct1 = clock();
    InitialiserTListePrem(&listePrem1);
    listePrem1.nbrMax = 0;
    Erathostene(&listePrem1);
    ct2 = clock();
    printf("\nDuree Erathostene(0): %.2f\n", (double)(ct2 - ct1) / CLOCKS_PER_SEC);
    AfficherPremiers(&listePrem1);
    ct1 = clock();
    InitialiserTListePrem(&listePrem2);
    listePrem2.nbrMax = 32767;
    Erathostene(&listePrem2);
    ct2 = clock();
    printf("\nDuree Erathostene(32767): %.2f\n", (double)(ct2 - ct1) / CLOCKS_PER_SEC);
    AfficherPremiers(&listePrem2);
    ct1 = clock();
    InitialiserTListePrem(&listePrem3);
    listePrem3.nbrMax = 2147483647;
    Erathostene(&listePrem3);
    ct2 = clock();
    printf("\nDuree Erathostene(2147483647): %.2f\n", (double)(ct2 - ct1) / CLOCKS_PER_SEC);
    AfficherPremiers(&listePrem3);
    puts("\nIsPrime pour n = 0..100000000 avec Erathostene(0) ...");
    ct1 = clock();
    cpt = 0;
    for(n = 0; n < 100000000; ++n) {
        findPrime = IsPrime(&listePrem1, n);
        //printf("n:%10d isPrime:%2d\n", n, findPrime);
        if(!((findPrime && n == listePrem3.pPrem[cpt++]) || (!findPrime && n != listePrem3.pPrem[cpt]))) {
            printf("Erreur pour %10d\n", n);
        }
    }
    ct2 = clock();
    printf("%10d premiers trouves\n", cpt);
    printf("Duree des calculs et verifications: %.2f\n", (double)(ct2 - ct1) / CLOCKS_PER_SEC);

    puts("\nIsPrime pour n = 0..0..100000000  avec Erathostene(32767) ...");
    ct1 = clock();
    cpt = 0;
    for(n = 0; n < 100000000 ; ++n) {
        findPrime = IsPrime(&listePrem2, n);
        //printf("n:%10d isPrime:%2d\n", n, findPrime);
        if(!((findPrime && n == listePrem3.pPrem[cpt++]) || (!findPrime && n != listePrem3.pPrem[cpt]))) {
            printf("Erreur pour %10d\n", n);
        }
    }
    ct2 = clock();
    printf("%10d premiers trouves\n", cpt);
    printf("Duree des calculs et verifications: %.2f\n", (double)(ct2 - ct1) / CLOCKS_PER_SEC);
    puts("\nIsPrime pour n = 0..0..100000000  avec Erathostene(2147483647) ...");
    ct1 = clock();
    cpt = 0;
    for(n = 0; n < 100000000 ; ++n) {
        findPrime = IsPrime(&listePrem3, n);
        //printf("n:%10d isPrime:%2d\n", n, findPrime);
        if(!((findPrime && n == listePrem3.pPrem[cpt++]) || (!findPrime && n != listePrem3.pPrem[cpt]))) {
            printf("Erreur pour %10d\n", n);
        }
    }
    ct2 = clock();
    printf("%10d premiers trouves\n", cpt);
    printf("Duree des calculs et verifications: %.2f\n", (double)(ct2 - ct1) / CLOCKS_PER_SEC);

    DetruireTListePrem(&listePrem1);
    DetruireTListePrem(&listePrem2);
    DetruireTListePrem(&listePrem3);

    return EXIT_SUCCESS;
}

/*  TODO ... */

