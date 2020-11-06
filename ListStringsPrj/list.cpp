//-----------------------------------------------------------------------------
// file list.cpp
//-----------------------------------------------------------------------------
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
    
   
//-----------------------------------------------------------------------------
// TODO ... (list::iterator::...)
    list::iterator::iterator(TNode* _p) : p(_p) {}
    list::iterator::iterator (const iterator& _iter) : p(_iter.p) {}// copie constructor
    list::iterator::~iterator() { }
    list::iterator& list::iterator::operator=(iterator _iter) { 
 //std::swap(p, it.p); return *this; 
  if (this != &_iter)  
      {  
         // Free the existing resource.  
         delete[] _data;  
  
         _length = _iter._length;  
         _data = new int[_length];  
         std::copy(_iter._data, _iter._data + _length, _data);  
      }  
      return *this;  
 
 } // je peux utiliser comme j'ai fait au niveau  du projet graphe eviter m1=m1 
    list::iterator& list::iterator::operator++() // ++it
    { 
        p = p->pNext;  
        return *this;
     }
   list::iterator list::iterator::operator++(int) //  it++ : un paramètre bidon de type int pour différencier le post et et le pré incrémentation
    { 
        iterator previous = p;
            p = p->pNext; //++*this;
        return previous;
    }
    /// decrémentation
    list::iterator&  list::iterator::operator--()  // --it
    { 
        p = p->pPrevious; 
        return *this;
     }
    list::iterator list::iterator::operator--(int)  // it--
    { 
        iterator next = p;
            p = p->pPrevious; 
        return next;
    }
    bool list::iterator operator==(const iterator& other) { return p == other.p; }
    bool list::iterator operator!=(const iterator& other) { return p != other.p; }// return !((*this)==other);}
    value_type&  list::iterator operator*() { return p->data;}


//-----------------------------------------------------------------------------
// TODO ... (list::const_iterator::...)
//-----------------------------------------------------------------------------


// TODO ... (list::...)

list::list() {
        /// créer le noeud garde-fou 
        list::TNode* node = new TNode();/// ceci inisialise les pointeurs et les données à 0  
        _pEndNode=node;
       _elementCount=0;
}
list::~list() {
       delete _pEndNode; 
}

 list::iterator list::begin() {
         if (this->empty()) return  this->_pEndNode;
        /// premier inclut
        else return  _pEndNode->pNext;
    }
     
     }
 list::iterator list::iterator::end() {}
  bool empty() {}


//-----------------------------------------------------------------------------
} // namespace StructInfoList
//-----------------------------------------------------------------------------
