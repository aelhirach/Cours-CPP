//-----------------------------------------------------------------------------
// File algo.h
//-----------------------------------------------------------------------------
#ifndef ALGO_H_
#define ALGO_H_
//-----------------------------------------------------------------------------
#include "list.h"
//-----------------------------------------------------------------------------
using namespace StructInfoList;
//-----------------------------------------------------------------------------
namespace StructInfoAlgo {
//-----------------------------------------------------------------------------
typedef int (*Compare)(const string&, const string&);
//---------------------------------------------------------------------------
class Predicate {
public:
//	Predicate() {};
	virtual bool operator()(const string& name) const = 0;
};
//-----------------------------------------------------------------------------
// TODO ... (find, find_if, reverse, bubbelSort) 

list::iterator find(list::iterator it1, list::iterator it2, list::value_type val);
list::iterator find_if(list::iterator it1, list::iterator it2, const Predicate &p);
list::iterator reverse(list::iterator it1, list::iterator it2);
list::iterator bubbleSort(list::iterator it1, list::iterator it2, Compare c);


//-----------------------------------------------------------------------------
} // namespace StructInfoAlgo
//-----------------------------------------------------------------------------
#endif /*ALGO_H_*/
//-----------------------------------------------------------------------------
