#ifndef LIST_H
#define LIST_H
#include <string>
using std::string;
namespace StructInfoList {
class list
{
public:
	typedef string value_type;
	//-------------------------------------------------------------------------
protected:
    struct TNode {
			TNode* pPrevious;
			TNode* pNext;
			value_type data;
			TNode();
			~TNode(); 
			TNode(value_type& pValue);
	};

	//-------------------------------------------------------------------------
public:
    class const_iterator;
    /// iterator permet de modifier les éléments dans la list 
    class iterator {
        public:             
                                    iterator();
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
    /// const_iterator ne permet pas de modifier les éléments dans la liste (ce qui est pointé ne peut pas être modifier ) 
    class const_iterator {
        public:
                        const_iterator();
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
	list();
	~list();
	list(list& liste);
	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
	iterator insert(iterator& it, value_type value);
	iterator insert(iterator& it1, iterator& it2, iterator& it3);
	iterator erase (iterator it);
	iterator erase(iterator it1, iterator it2);
	int size() const;
	bool empty();
	list& operator=(list& liste);
    
protected:

	TNode* pEndNode;
	int elementCount;

};
}
#endif // LIST_H
