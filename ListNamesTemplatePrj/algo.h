	//-----------------------------------------------------------------------------
	// File algo.h
	//-----------------------------------------------------------------------------
	#ifndef ALGO_H_
	#define ALGO_H_
	//-----------------------------------------------------------------------------
	namespace StructInfoAlgo {
	//-----------------------------------------------------------------------------
	template<class T> static inline void swap(T& d1, T& d2);
	//---------------------------------------------------------------------------

	/*template<class T> class Predicate {
	public:
		virtual bool operator()(const T& name) const = 0;
	};*/

	// TODO ... Déclarations des prototypes (find, find_if, reverse, bubbelSort)
	template<class ItUniDir, class T>
	ItUniDir find(ItUniDir i1, ItUniDir i2, T e);
	template<class ItUniDir,class predicate>
	ItUniDir find_if(ItUniDir i1, ItUniDir i2, const predicate& g);
	template<class ItBiDir>
	ItBiDir reverse(ItBiDir i1, ItBiDir i2);
	template<class ItBiDir, class Compare>
	ItBiDir bubbelSort(ItBiDir i1, ItBiDir i2, Compare f);
	//-----------------------------------------------------------------------------
	template<class T> static inline void swap(T& d1, T& d2) {
		T temp(d1);
		d1=d2;
		d2=temp;
	}
	//-----------------------------------------------------------------------------
	// TODO ... Définitions des patrons de fonctions (find, find_if, reverse, bubbelSort)
	template<class ItUniDir, class T>
	ItUniDir find(ItUniDir i1, ItUniDir i2, T e){
		while(i1!=i2){
			if (*i1 == e){
				return i1;
			}else i1++;
		}
		return i2;
	}

	template<class ItUniDir, class predicate>
	ItUniDir find_if(ItUniDir i1, ItUniDir i2, const predicate& g){
		while(i1!=i2){
			if(g(*i1)){
				return i1;
			}else i1++;
		}
		return i2;
	}

	template<class ItBiDir>
	ItBiDir reverse(ItBiDir i1, ItBiDir i2){
		while(i1 != i2){
			swap(*i1,*i2);
			if(++i1 != i2){
				i2--;
			}else break;
		}
		return i2;
	}

	template<class ItBiDir, class Compare>
	ItBiDir bubbelSort(ItBiDir i1, ItBiDir i2, Compare f){
		ItBiDir i1bis(i1);
		ItBiDir i2bis(i2);
		i2bis = ++i1bis;
		i1bis--;
		while(i1 != i2){
			for(; i2bis != i2; ++i2bis){
				if(f(*i1bis, *i2bis)>0){
					swap(*i1bis, *i2bis);
				}
				++i1bis;
			}
			--i2;
			--i2bis;
			--i1bis;
			
			if(i1 == i2) break;
			
			for(; i2bis != i1; --i1bis){
				if(f(*i1bis, *i2bis)>0){
					swap(*i1bis, *i2bis);
				}
				--i2bis;
			}
			++i1;
			++i2bis;
			++i1bis;
		}
		return i2;
	}

	//-----------------------------------------------------------------------------
	} // namespace StructInfoAlgo
	//-----------------------------------------------------------------------------
	#endif /*ALGO_H_*/
	//-----------------------------------------------------------------------------
