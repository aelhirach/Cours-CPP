//-----------------------------------------------------------------------------
// File algo.h
//-----------------------------------------------------------------------------
#ifndef ALGO_H_
#define ALGO_H_
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
} // namespace StructInfoAlgo
//-----------------------------------------------------------------------------
#endif /*ALGO_H_*/
//-----------------------------------------------------------------------------
