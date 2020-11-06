//-----------------------------------------------------------------------------
// File algo.h
//-----------------------------------------------------------------------------
#ifndef ALGO_H_
#define ALGO_H
#include <iostream>     // std::cout, std::ios
#include <sstream>      // std::ostringstream
using namespace std;
//-----------------------------------------------------------------------------
namespace StructInfoAlgo {
//-----------------------------------------------------------------------------
template<class T> static inline void swap(T& d1, T& d2);
//-----------------------------------------------------------------------------
// TODO ... Déclarations des prototypes (find, find_if, reverse, bubbelSort)

template<class InputIterator, class T>
InputIterator find(InputIterator it1, InputIterator it2, T val);
template<class InputIterator,class predicate>
InputIterator find_if(InputIterator i1, InputIterator i2, const predicate& p);
template<class InputIterator>
InputIterator reverse(InputIterator it1, InputIterator it2);
template<class InputIterator, class Compare>
InputIterator bubbelSort(InputIterator i1, InputIterator i2, Compare c);
template<class InputIterator>
string seqToString(InputIterator iterB,InputIterator iterE);

template<class InputIterator1, class InputIterator2, class Compare>
int seqCompare(InputIterator1 iterB1,InputIterator1 iterE1,InputIterator2 iterB2, InputIterator2 iterE2,Compare c);

//-----------------------------------------------------------------------------
template<class T> static inline void swap(T& d1, T& d2) {
	T temp(d1);
	d1=d2;
	d2=temp;
}
//-----------------------------------------------------------------------------
// TODO ... Définitions des patrons de fonctions (find, find_if, reverse, bubbelSort)

template<class InputIterator, class T>
InputIterator find(InputIterator iterB, InputIterator iterE, T value){
        while (iterB !=iterE) {
                 if (*iterB==value) 
                     return iterB; 
                else  ++iterB;
            }
         return iterE;
}

template<class InputIterator, class predicate>
InputIterator find_if(InputIterator iterB, InputIterator iterE, const predicate &p){
      while(iterB!=iterE){
		if(p(*iterB)){
			return iterB;
		}
		else iterB++;
        }
       return iterE;
    }

template<class InputIterator>
InputIterator reverse(InputIterator iterB, InputIterator iterE){
    iterE--;
	while(iterB!=iterE){
		swap(*iterB,*iterE);
		if(++iterB != iterE){
			iterE--;
		}
		else break;
	}
	return iterE;
    }

template<class InputIterator, class Compare>
InputIterator bubbelSort(InputIterator iterB, InputIterator iterE, Compare c){
	InputIterator iterOne(iterB);
    InputIterator iterTwo(iterB); ++iterTwo;
     while (iterTwo != iterE) {
           while (iterTwo != iterE) {
                        if  (c(*iterOne,*(iterTwo)) >0)  swap(*iterOne,*iterTwo);
                        ++iterOne; ++iterTwo;
                        }
          --iterE;
          iterOne = iterTwo=iterE; iterOne--;
            while(iterTwo!=iterB){
                        if  (c(*iterOne,*(iterTwo)) >0)  swap(*iterOne,*iterTwo);
                        --iterOne; --iterTwo;
                        }
            ++iterB;
             iterOne = iterTwo=iterB; iterTwo++;
           }
           return  iterE;
}
//-----------------------------------------------------------------------------
template<class InputIterator>
string seqToString(InputIterator iterB,InputIterator iterE) {
    ostringstream oss("");
    oss << '(';
    while(iterB != iterE) {
          oss << *iterB; 
        iterB++;
        if  (iterB != iterE)
            oss << ',';
            
        }
          oss << ')';
    return oss.str(); 
    } 
template<class InputIterator1, class InputIterator2, class Compare>
int seqCompare(InputIterator1 iterB1,InputIterator1 iterE1,InputIterator2 iterB2, InputIterator2 iterE2,Compare c) {
    int result =0;
    while (iterB1 != iterE1 && iterB2 != iterE2){
         result = c(*iterB1,*iterB2); 
         if (result !=0) break; 
         iterB1++;
         iterB2++;
        }
    if ((iterB1 != iterE1) && (iterB2 == iterE2)) return 1; 
    else if ((iterB1 == iterE1) && (iterB2 != iterE2)) return -1; 
    else return result; 
    }
} // namespace StructInfoAlgo
//-----------------------------------------------------------------------------







#endif /*ALGO_H_*/
//-----------------------------------------------------------------------------
