//-----------------------------------------------------------------------------
// File algo.h
//-----------------------------------------------------------------------------
#ifndef ALGO_H_
#define ALGO_H_
//-----------------------------------------------------------------------------
#include "name.h"
#include "list.h"
//-----------------------------------------------------------------------------
using namespace StructInfoList;
//-----------------------------------------------------------------------------
namespace StructInfoAlgo {
//-----------------------------------------------------------------------------
typedef int (*Compare)(const TName&, const TName&);
//---------------------------------------------------------------------------
class Predicate {
public:
	virtual bool operator()(const TName& name) const = 0;
};

//-----------------------------------------------------------------------------
// TODO ... (find, find_if, reverse, bubbelSort) 
list::iterator find(list::iterator i1, list::iterator i2, TName e);
list::iterator find_if(list::iterator i1, list::iterator i2, const Predicate& g);
list::iterator reverse(list::iterator i1, list::iterator i2);
list::iterator bubbelSort(list::iterator i1, list::iterator i2, Compare f);
//-----------------------------------------------------------------------------
} // namespace StructInfoAlgo
//-----------------------------------------------------------------------------
#endif /*ALGO_H_*/
//-----------------------------------------------------------------------------
