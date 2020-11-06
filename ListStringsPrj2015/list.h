//-----------------------------------------------------------------------------
// File list.h
//-----------------------------------------------------------------------------
#ifndef LIST_H_
#define LIST_H_
//-----------------------------------------------------------------------------
#include <string>
//-----------------------------------------------------------------------------
// Pour list, il faut dans TData : copy constructor, operator =, destructor
// Pour bubbleSort, il faut dans TData : <
// Pour find, il faut dans TData : ==
//-----------------------------------------------------------------------------
using std::string;
//-----------------------------------------------------------------------------
namespace StructInfoList {
//-----------------------------------------------------------------------------
class list {
public:
	typedef string value_type;
protected:
	//-------------------------------------------------------------------------
	struct TNode {
			TNode* pPrevious;
			TNode* pNext;
			value_type value;
			TNode();
			~TNode(); 
			TNode(value_type& pvalue);
	};
	//-------------------------------------------------------------------------
public:
	//-------------------------------------------------------------------------
	class iterator {
	public:
	iterator();
	~iterator();
	iterator(const iterator& it);
	iterator(TNode* pNode);
	iterator operator++();
	iterator operator--();
	iterator operator++(int);
	iterator operator--(int);
	bool operator==(iterator it);
	bool operator!=(iterator it);
	value_type& operator*();

	protected:
		TNode* itNode;
		friend class list;
	};

	class const_iterator {
	public:const_iterator();
		~const_iterator();
		const_iterator(const iterator& it);
		const_iterator(const const_iterator& constIt);
		const_iterator(TNode* pNode);
		const_iterator operator++();
		const_iterator operator--();
		//const_iterator operator++(int);
		//const_iterator operator--(int);
		bool operator==(const_iterator constIt) const;
		bool operator!=(const_iterator constIt) const;
		value_type& operator*() const;
		const_iterated:
		TNode* cNode;
		friend class list;
	};

	//-------------------------------------------------------------------------
	// TODO ...

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
	//-------------------------------------------------------------------------
	// TODO ...
	//-------------------------------------------------------------------------
	TNode* last_node;
	int elmt;


};

//-----------------------------------------------------------------------------
} // namespace StructInfoList
//-----------------------------------------------------------------------------
#endif /*LIST_H_*/
