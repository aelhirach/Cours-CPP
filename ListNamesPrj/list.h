//-----------------------------------------------------------------------------
// File list.h
//-----------------------------------------------------------------------------
#ifndef LIST_H_
#define LIST_H_
//-----------------------------------------------------------------------------
#include "name.h"
//-----------------------------------------------------------------------------
// Pour list, il faut dans TData : copy constructor, operator =, destructor
// Pour bubbleSort, il faut dans TData : <
// Pour find, il faut dans TData : ==
//-----------------------------------------------------------------------------
namespace StructInfoList {
//-----------------------------------------------------------------------------
class list {
protected:
	//-------------------------------------------------------------------------
	struct TNode {
	// TODO ...
	TName data_n;
	TNode* pLeft;
	TNode* pRight;
	TNode();
	TNode(TName& name_n);
	~TNode();
	};
	//-------------------------------------------------------------------------
public:
	//-------------------------------------------------------------------------
	class const_iterator;
	class iterator {
public:
		// TODO ...
		iterator();
		iterator(const iterator& i1);
		~iterator();
		iterator operator++();
		iterator operator--();
		TName& operator*	();
		const TName& operator*() const;
		iterator operator++(int);
		iterator operator--(int);
		bool operator==(iterator i1);
		bool operator!=(iterator i1);
		//const const_iterator 
		iterator(TNode* i_node);
		
protected:
		// TODO ...
		TNode* node_it;
		friend list;
	};

	class const_iterator {
public:
		const_iterator();
		const_iterator(iterator i1);
		const_iterator(const const_iterator& ci1);
		~const_iterator();
		const_iterator operator++();
		const_iterator operator--();
		const_iterator operator++(int);
		const_iterator operator--(int);
		const TName& operator*() const;
		bool operator==(const_iterator i1) const;
		bool operator!=(const_iterator i1) const;
		// TODO ...
		const_iterator(TNode* c_node);
protected:
		// TODO ...
		//Implémentation
		TNode* const_node;
		//Constructeur qui accepte pointeur sur TNode.
		friend list;
		
	};

	// TODO ... (typedefs)
	typedef TName value_type;
	typedef TName& ref_type; //Pas utilisé ici
	typedef TName* point_type; //Pas utilisé ici
	
	//-------------------------------------------------------------------------
	// TODO ... Methode publique
	list();
	~list();
	list(list& l1);
	int size() const;
	bool empty();
	list& operator=(list& l1);
	iterator begin();
	iterator end(); //Sur le fictif qui suit le dernier element
	iterator insert(iterator& i1, TName& data);
	iterator insert(iterator& i1, iterator& i2, iterator& i3);
	const_iterator begin() const;
	const_iterator end() const;
	iterator erase(iterator i1); //Renvoi le suivant
	iterator erase(iterator i1, iterator i2); //Renvoi celui qui suit i2
	//Attention transformer iterator en iterator_const autrement que via methode
	
protected:
	//-------------------------------------------------------------------------
	// TODO ...
	//Fct membre copy
	//Donnée membre
	int Nelt;
	TNode* end_node;
	//-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------
} // namespace StructInfoList
//-----------------------------------------------------------------------------
#endif /*LIST_H_*/