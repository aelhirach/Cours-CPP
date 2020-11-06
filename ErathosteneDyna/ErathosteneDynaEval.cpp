//---------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <inout.h>
#include <math.h>
using namespace std;
//---------------------------------------------------------------------------
const int MAX = 1000000;
struct TListePrem{
  int  nbrMax;
  int* pPrem;
  int  nbrPrem;
};

//---------------------------------------------------------------------------
/// les définitions des fonctions 
void InitialiserTListePrem(TListePrem& plistePrem);
void Erathostene(TListePrem& plistePrem);
void AfficherPremiers(TListePrem& plistePrem);
void DetruireTListePrem(TListePrem& plistePrem);
bool IsPrime(TListePrem &plistePrem, int n);

//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
  TListePrem listePrem;
  bool findPrime;
  int n;
  do {
    InitialiserTListePrem(listePrem);
    /// first test
    listePrem.nbrMax = 0;
    int firstFivisor=1;
    Erathostene(listePrem);
    for(n=0; n <= 10; ++n) {
        findPrime = IsPrime(listePrem, n);
         cout << "MAX= " <<  listePrem.nbrMax << "  n= " << n << "  isPrime="<< findPrime << "  First Divisor = " << firstFivisor <<endl; 
        }
        
    ///////// second test 
    InitialiserTListePrem(listePrem);
     listePrem.nbrMax = 2;
   Erathostene(listePrem);
    for(n=0; n <= 10; ++n) {
        findPrime = IsPrime(listePrem, n);
         cout << "MAX= " <<  listePrem.nbrMax << "  n= " << n << "  isPrime="<< findPrime << "  First Divisor = " << firstFivisor <<endl; 
        }
    InitialiserTListePrem(listePrem);
    
       ///////// third test 
    InitialiserTListePrem(listePrem);
     listePrem.nbrMax = 3;
   Erathostene(listePrem);
    for(n=0; n <= 20; ++n) {
        findPrime = IsPrime(listePrem, n);
         cout << "MAX= " <<  listePrem.nbrMax << "  n= " << n << "  isPrime="<< findPrime << "  First Divisor = " << firstFivisor <<endl; 
        }
    InitialiserTListePrem(listePrem);
    
       ///////// f test 
    InitialiserTListePrem(listePrem);
     listePrem.nbrMax = 4;
   Erathostene(listePrem);
    for(n=0; n <= 20; ++n) {
        findPrime = IsPrime(listePrem, n);
         cout << "MAX= " <<  listePrem.nbrMax << "  n= " << n << "  isPrime="<< findPrime << "  First Divisor = " << firstFivisor <<endl; 
        }
    InitialiserTListePrem(listePrem);

   ///////// x test 
    InitialiserTListePrem(listePrem);
     listePrem.nbrMax = 65535;
   Erathostene(listePrem);
    for(n= 65535; n <=9999997; ++n) {
        findPrime = IsPrime(listePrem, n);
         cout << "MAX= " <<  listePrem.nbrMax << "  n= " << n << "  isPrime="<< findPrime << "  First Divisor = " << firstFivisor <<endl; 
        }
    InitialiserTListePrem(listePrem);
    
   /* DetruireTListePrem(listePrem);*/
    
    
  } while (!Stop());
  return 0;
}
//---------------------------------------------------------------------------
void InitialiserTListePrem(TListePrem& plistePrem) {
         plistePrem.nbrMax = 0;
		plistePrem.nbrPrem = 0;
		plistePrem.pPrem = NULL;
    }
void Erathostene(TListePrem& plistePrem) {
        /// créer le tableau principal 
		int maxValue= (plistePrem.nbrMax);
        int memorySize =  (maxValue / 2)+(maxValue / 2)%2;
        double sqrtMax = sqrt(maxValue);
        /// toutes les cases sont initialisées à false = Non barrées = prmeiers
        bool* array = new bool[memorySize]();

        /// Parcourir le tableau et barré(mettre à true) les multiples des nombres prmeiers (On commence par 3)
        int i,j;
        for (i = 3; i <sqrtMax; i += 2) { 
            if (!array[(i / 2)]) 
                {
                 j=3; 
                 while((i*j<maxValue) && (i*j>0)) 
                    {
                       array[(i*j)/2] = true;
                       j+=2;
                   }
                }
		}
        
	 	// Display prime
		for (i=0; i<memorySize;i++) {
			if (!array[i]) {
    
				plistePrem.nbrPrem++;
			}
    }
        plistePrem.pPrem = new int [plistePrem.nbrPrem];
		plistePrem.pPrem[0] = 2;
		i = 3, j=1;  /// j=0 -> 2
		j=1;  /// j=0 -> 2
		for (i=1; i<memorySize;i++) {
            if (!array[i]) {
                plistePrem.pPrem[j] = (2*i)+1;	
                j++;
            }
		}
		 delete [] array;
    
}

bool IsPrime(TListePrem &plistePrem, int &n) { 
   

    }

void AfficherPremiers(TListePrem& plistePrem){
         cout << "Il y a " << plistePrem.nbrPrem << " nombre premiers inferieurs a " << plistePrem.nbrMax << endl;
         int i; 
		 if (plistePrem.nbrPrem > 30) {
            for (i = 0; i < 10; i++) {
                cout << "Nombre premier n  " << i + 1 <<" :"<< plistePrem. pPrem[i] << endl;
            }
            cout << endl << "...." << endl << endl;

            for (int i = plistePrem.nbrPrem - 10; i < plistePrem.nbrPrem; i++) {
               cout << "Nombre premier n " << i + 1 <<" :"<< plistePrem.pPrem[i] << endl;
            }

        } else {
            for (i = 0; i < plistePrem.nbrPrem; i++) {
                 cout << " Nombre premier n"  << i + 1 <<" :"<<plistePrem.pPrem[i] << endl;
            }
        }
    }
void DetruireTListePrem(TListePrem& plistePrem){
        delete [] plistePrem.pPrem; 
	     plistePrem.nbrMax = 0;
		 plistePrem.nbrPrem = 0;
    }
//---------------------------------------------------------------------------

