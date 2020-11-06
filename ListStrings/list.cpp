#include "list.h"
//-----------------------------------------------------------------------------
namespace StructInfoList {
    
//-----------------------------------------------------------------------------
// TODO ... (list::TNode::...)
// Creates a new node with previous, next and element all set to null. This implementation creates a new empty Node. 
list::TNode::TNode() {
    }
list::TNode::~TNode() {
    }
list::TNode::TNode(value_type& _data){
		data = _data;
	}
 // TODO ... (list::list()...)   
    list::list(){}
	list::~list(){}
    list::list(list& liste) {}
	list::iterator list::begin() {}
	list::iterator list::end(){ }
	list::const_iterator list::begin() const { }
	list::const_iterator list::end() const{ }
	list::iterator list::insert(iterator& it, value_type value){ }
	list::iterator list::insert(iterator& it1, iterator& it2, iterator& it3){ }
	list::iterator list::erase (iterator it){}
	list::iterator list::erase(iterator it1, iterator it2){ }
	int list::size() const{}
	bool list::empty(){}
	list& list::operator=(list& liste){ }
    
    // TODO ... (list::iterator()...)   
        list::iterator::iterator(){}
        list::iterator::iterator(TNode* p){}
        list::iterator::iterator(const iterator& _iter){}
        list::iterator::~iterator(){}
        list::iterator& list::iterator::operator=(iterator _iter){}
        list::iterator& list::iterator::operator++() {}// ++it
        list:: iterator list::iterator::operator++(int){} // it++ : un paramètre bidon de type int pour différencier le post et et le pré incrémentation
        list::iterator& list::iterator::operator--(){} // ++it
        list::iterator list::iterator::operator--(int){} // it++ : un paramètre bidon de type int pour différencier le post et et le pré décrémentation
        bool list::iterator::operator==(const iterator& _iter){}
        bool list::iterator::operator!=(const iterator& _iter){}// return !((*this)==_iter);}
        list::value_type& list::iterator::operator*(){}
        list::iterator* list::iterator::operator->(){}
        
        // TODO ... (list::const_iterator()...)   
         list::const_iterator::const_iterator(){}
         list::const_iterator::const_iterator(TNode* p){}
         list::const_iterator::const_iterator(const const_iterator& _iter){}
         list::const_iterator::const_iterator(const iterator& _iter){}
         list::const_iterator::~const_iterator(){}
         list::const_iterator& list::const_iterator::operator=(iterator _iter){}
         list::const_iterator& list::const_iterator::operator++(){} // ++it
         list::const_iterator list::const_iterator::operator++(int){} // it++ : un paramètre bidon de type int pour différencier le post et et le pré incrémentation
         bool list::const_iterator::operator==(const const_iterator& _iter){}
         bool list::const_iterator::operator!=(const const_iterator& _iter){}// return !((*this)==other);}
         const list::value_type& list::const_iterator::operator*() const{}
         list::const_iterator const * list::const_iterator::operator->() const {}
    
}