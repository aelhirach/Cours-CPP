//-----------------------------------------------------------------------------
// file algo.cpp
//-----------------------------------------------------------------------------
#include <cstring>
#include "algo.h"

//-----------------------------------------------------------------------------
using namespace StructInfoList;
using namespace std;
//-----------------------------------------------------------------------------
inline void swap(TName& d1, TName& d2) {
	TName temp(d1);
	d1=d2;
	d2=temp;
}
//-----------------------------------------------------------------------------
namespace StructInfoAlgo {
//-----------------------------------------------------------------------------
// TODO ...

//ALGO
list::iterator find(list::iterator i1, list::iterator i2, TName e){
	while(i1!=i2){
		if (*i1 == e){
			return i1;
		}else i1++;
	}
	return i2;
}
list::iterator find_if(list::iterator i1, list::iterator i2, const Predicate& g){
	while(i1!=i2){
		if(g(*i1)){
			return i1;
		}else i1++;
	}
	return i2;
}
list::iterator reverse(list::iterator i1, list::iterator i2){
	i2--;
	while(i1 != i2){
		swap(*i1,*i2);
		if(++i1 != i2){
			i2--;
		}else break;
	}
	return i2;
}

list::iterator bubbelSort(list::iterator i1, list::iterator i2, Compare f){
	list::iterator i1bis(i1);
	list::iterator i2bis(i2);
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
