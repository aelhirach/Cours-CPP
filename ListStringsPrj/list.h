//-----------------------------------------------------------------------------
// File list.h
//-----------------------------------------------------------------------------
#ifndef LIST_H_
#define LIST_H_
//-----------------------------------------------------------------------------
#include <string>
/* Type TValue must be defined by the programmer for use with TList          */

//--------------------------------  ---------------------------------------------
// Pour list, il faut dans TData : copy constructor, operator =, destructor
// Pour bubbleSort, il faut dans TData : <
// Pour find, il faut dans TData : ==
//-----------------------------------------------------------------------------
using namespace std; 
//-----------------------------------------------------------------------------
namespace StructInfoList {
//-----------------------------------------------------------------------------
class list {
public : 
        typedef string value_type;

protected:
	// stucture TNode-------------------------------------------------------------------------
   struct TNode {
             TNode * pPrevious;
             TNode * pNext;
            value_type data;
            TNode();
            ~TNode();
            TNode(value_type& _data);
	};
public:
            class const_iterator;
            //// Class iterator /////////////////////////////////////////////////////
            class iterator
                {
                    public:
                                    iterator(TNode* p);
                                    iterator(const iterator& _iter);
                                    ~iterator ();
                                    iterator& operator=(iterator _iter);
                                    iterator& operator++(); // ++it
                                    iterator operator++(int); // it++ : un paramètre bidon de type int pour différencier le post et et le pré incrémentation
                                    iterator& operator--(); // ++it
                                    iterator operator--(int); // it++ : un paramètre bidon de type int pour différencier le post et et le pré décrémentation
                                    bool operator==(const iterator& _iter);
                                    bool operator!=(const iterator& _iter);// return !((*this)==_iter);}
                                    value_type& operator*();
                                    iterator* operator->();

                                    
                    protected:
                                    TNode* p;
                                    
                };
       	//// Class const_iterator /////////////////////////////////////////////////////
            class const_iterator 
                {
                public:
                        const_iterator(TNode* p);
                        const_iterator(const const_iterator& _iter);
                        const_iterator(const iterator& _iter);
                        ~const_iterator ();
                        const_iterator& operator=(iterator _iter);
                        const_iterator& operator++(); // ++it
                        const_iterator operator++(int); // it++ : un paramètre bidon de type int pour différencier le post et et le pré incrémentation
                        bool operator==(const const_iterator& _iter);
                        bool operator!=(const const_iterator& _iter);// return !((*this)==other);}
                        const value_type& operator*() const;
                        const_iterator const * operator->() const;
                protected:
                        TNode* p;
            
               };
           //// constrictor destroctor  /////////////////////////////////////////////////////
             list();
             list(const list& _list);
             ~list ();
		   //// definition des méthodes /////////////////////////////////////////////////////
            iterator begin();
            iterator end();
            bool empty();
            unsigned int size();
protected:
		    iterator _pEndNode;
	         unsigned int _elementCount;  /// entier positif
	};
    

//-----------------------------------------------------------------------------
} // namespace StructInfoList
//-----------------------------------------------------------------------------
#endif /*LIST_H_*/
