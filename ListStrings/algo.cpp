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

list::iterator find(list::iterator it1, list::iterator it2, list::value_type val) {}
list::iterator find_if(list::iterator it1, list::iterator it2, const Predicate &p){}
list::iterator reverse(list::iterator it1, list::iterator it2){}
list::iterator bubbleSort(list::iterator it1, list::iterator it2, Compare c){}
} // namespace StructInfoAlgo
//-----------------------------------------------------------------------------
