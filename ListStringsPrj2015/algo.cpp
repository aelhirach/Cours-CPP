//-----------------------------------------------------------------------------
// file algo.cpp
//-----------------------------------------------------------------------------
#include "algo.h"
//-----------------------------------------------------------------------------
using namespace StructInfoList;
//-----------------------------------------------------------------------------
inline void swap(string& d1, string& d2) {
	string temp(d1);
	d1=d2;
	d2=temp;
}
//-----------------------------------------------------------------------------
namespace StructInfoAlgo {
//-----------------------------------------------------------------------------
// TODO ...

list::iterator find(list::iterator it1, list::iterator it2, list::value_type val){
	while(it1!=it2){
		if(*it1 == val){
			return it1;
		}
		else it1++;
	}
	return it2;
}

list::iterator find_if(list::iterator it1, list::iterator it2, const Predicate &p){
	while(it1!=it2){
		if(p(*it1)){
			return it1;
		}
		else it1++;
	}
	return it2;
}


list::iterator reverse(list::iterator it1, list::iterator it2){
	it2--;
	while(it1!=it2){
		swap(*it1,*it2);
		if(++it1 != it2){
			it2--;
		}
		else break;
	}
	return it2;
}

list::iterator bubbleSort(list::iterator it1, list::iterator it2, Compare c){
	list::iterator copit1(it1);
	list::iterator copit2(it2);
	copit2=++copit1;
	copit1--;
	while(it1 != it2){
		for(;copit2 != it2; ++copit2){
			if(c(*copit1, *copit2)>0){
				swap(*copit1, *copit2);
			}
			++copit1;
		}
		--it2;
		--copit1;
		--copit2;
		if(it1 == it2) break;
		for(; copit2 != it1; --copit1){
			if(c(*copit1, *copit2)>0){
				swap(*copit1, *copit2);
			}
			--copit2;
		}
		++it1;
		++copit1;
		++copit2;
	}
	return it2;

}


//-----------------------------------------------------------------------------
} // namespace StructInfoAlgo
//-----------------------------------------------------------------------------
