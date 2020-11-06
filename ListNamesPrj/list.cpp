//-----------------------------------------------------------------------------
// file list.cpp
//-----------------------------------------------------------------------------
#include "list.h"
//-----------------------------------------------------------------------------
namespace StructInfoList
{
//-----------------------------------------------------------------------------
// TODO ... (list::TNode::...)
list::TNode::TNode():data_n()
{
	
}

list::TNode::TNode(ref_type name)
{
	data_n = name;
}

list::TNode::~TNode()
{
}
//-----------------------------------------------------------------------------
// TODO ... (list::iterator::...)
list::iterator::iterator():node_it(0)
{
	//node = 0;
}

list::iterator::iterator(TNode* i_node)
{
	node_it = i_node;
}

list::iterator::iterator(const iterator& i1)
{
	node_it = i1.node_it;
}

list::iterator::~iterator()
{

}

list::iterator list::iterator::operator++()
{
	node_it = node_it->pRight;
	return *this;
}

list::iterator list::iterator::operator--()
{
	node_it = node_it->pLeft;
	return *this;
}

list::iterator list::iterator::operator++(int)
{
	node_it = node_it->pRight;
	iterator * it = new iterator(node_it->pLeft);
	return *it;
}

list::iterator list::iterator::operator--(int)
{
	node_it = node_it->pLeft;
	iterator* it = new iterator(node_it->pRight); 
	return *it;

}

bool list::iterator::operator==(iterator i1)
{
	if(node_it == i1.node_it) {
		return true;
	} else return false;
}

bool list::iterator::operator!=(iterator i1){
	if(node_it == i1.node_it) {
		return false;
	} else return true;
}

TName& list::iterator::operator*()
{
	return node_it->data_n;
}

const TName& list::iterator::operator*() const
{
	return node_it->data_n;
}
//-----------------------------------------------------------------------------
// TODO ... (list::const_iterator::...)
list::const_iterator::const_iterator()
{

}

list::const_iterator::const_iterator(iterator i1)
{
	const_node = i1.node_it;
}

list::const_iterator::const_iterator(const const_iterator& ci1)
{
	const_node = ci1.const_node;
}

list::const_iterator::const_iterator(TNode* c_node)
{
	const_node = c_node;
}
	
list::const_iterator::~const_iterator()
{

}

list::const_iterator list::const_iterator::operator++()
{
	const_node = const_node->pRight;
	return *this;
}

list::const_iterator list::const_iterator::operator--()
{
	const_node = const_node->pLeft;
	return *this;
}

list::const_iterator list::const_iterator::operator++(int)
{
	const_node = const_node->pRight;
	const_iterator * it = new const_iterator(const_node->pLeft);
	return *it;
}

list::const_iterator list::const_iterator::operator--(int)
{
	const_node = const_node->pLeft;
	const_iterator * it = new const_iterator(const_node->pRight);
	return *it;
}

const TName& list::const_iterator::operator*() const{
	return const_node->data_n;
}

bool list::const_iterator::operator==(const_iterator i1) const
{
	if(const_node == i1.const_node) {
		return true;
	} else return false;
}

bool list::const_iterator::operator!=(const_iterator i1) const{
	if(const_node == i1.const_node) {
		return false;
	} else return true;
}
//-----------------------------------------------------------------------------
// TODO ... (list::...)
list::list():end_node(0)
{
	Nelt = 0;
	end_node = new TNode();
	end_node->pLeft = end_node;
	end_node->pRight = end_node;
}

list::~list()
{
	while(Nelt != 0) {
		erase(begin());
	}
}

list::list(list& l1):end_node(0)
{
	Nelt = 0;
	end_node = new TNode();
	end_node->pLeft = end_node;
	end_node->pRight = end_node;
	iterator i1;
	iterator ii = end();
	for(i1 = l1.begin(); i1 != l1.end(); ++i1){
		insert(ii, *i1);
	}
}

int list::size() const
{
	return Nelt;
}

bool list::empty()
{
	if(Nelt == 0) {
		return true;
	} else return false;
}

list& list::operator=(list& l1)
{
	if(this != &l1){
		while(Nelt != 0) {
			erase(begin());
		}
		Nelt = 0;
		iterator i1;
		iterator ii = end();
		for(i1 = l1.begin(); i1 != l1.end(); ++i1){
			insert(ii, *i1);
		}
	}
	return *this;
}

list::iterator list::begin()
{
	list::iterator * it = new list::iterator(end_node->pRight);
	return *it;
}

list::iterator list::end()
{
	list::iterator * it = new list::iterator(end_node);
	return *it;
}

list::iterator list::insert(iterator& i1, TName& data)
{
	list::TNode *  node_i = new list::TNode(data);
	node_i->pRight = i1.node_it;
	--i1;
	node_i->pLeft = i1.node_it;
	i1.node_it->pRight = node_i;
	++i1; ++i1;
	i1.node_it->pLeft = node_i;
	Nelt++;
	return i1;
}

list::iterator list::insert(iterator& i1, iterator& i2, iterator& i3){
	while(i2 != i3){
		insert(i1, *i2);
		++i2;
	}
	return i1;
}

list::const_iterator list::begin() const
{
	list::const_iterator * it = new list::const_iterator(end_node->pRight);
	return *it;
}

list::const_iterator list::end() const
{
	list::const_iterator * it = new list::const_iterator(end_node);
	return * it;
}

list::iterator list::erase(iterator i1)
{
	i1.node_it->pLeft->pRight = i1.node_it->pRight;
	i1.node_it->pRight->pLeft = i1.node_it->pLeft;
	iterator i2(i1.node_it->pRight);
	delete[] &i1;
	Nelt--;
	return i2;
}

list::iterator list::erase(iterator i1, iterator i2)
{
	while(i1 != i2){
		i1 = erase(i1);
	}		
	return i2;
}
//-----------------------------------------------------------------------------
} // namespace StructInfoList
//-----------------------------------------------------------------------------
