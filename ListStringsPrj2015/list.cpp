//-----------------------------------------------------------------------------
// file list.cpp
//-----------------------------------------------------------------------------
#include "list.h"
//-----------------------------------------------------------------------------
namespace StructInfoList {

	list::TNode::TNode():value(){

	}

	list::TNode::~TNode(){

	}

	list::TNode::TNode(value_type& pvalue){
		value = pvalue;
	}

///////////////////////////////////////////////////////////////////////////////////

	list::iterator::iterator():itNode(0){

	}

	list::iterator::~iterator(){

	}

	list::iterator::iterator(const iterator& it){
		itNode=it.itNode;
	}

	list::iterator::iterator(TNode* pNode){
		itNode=pNode;
	}

	list::iterator list::iterator::operator++() {
		itNode=itNode->pNext;
		return *this;
	}

	list::iterator list::iterator::operator--(){
		itNode=itNode->pPrevious;
		return *this;
	}

	list::iterator list::iterator::operator++(int){
		itNode=itNode->pNext;
		iterator* it = new iterator(itNode->pPrevious);
		return*it;
	}

	list::iterator list::iterator::operator--(int){
		itNode=itNode->pPrevious;
		iterator* it = new iterator(itNode->pNext);
		return*it;
	}

	bool list::iterator::operator==(iterator it){
		if(itNode==it.itNode){
			return true;
		}
		else return false;
	}

	bool list::iterator::operator!=(iterator it){
		if (itNode!=it.itNode){
			return true;
		}
		else return false;
	}

	list::value_type& list::iterator::operator*(){
		return itNode->value;
	}



/////////////////////////////////////////////////////////////////////////////////////////////////////

	list::const_iterator::const_iterator(){
		cNode=0;
	}

	list::const_iterator::~const_iterator(){

	}

	list::const_iterator::const_iterator(const iterator& it){
		cNode = it.itNode;
	}

	list::const_iterator::const_iterator(const const_iterator& constIt){
		cNode = constIt.cNode;
	}

	list::const_iterator::const_iterator(TNode* pNode){
		cNode = pNode;
	}

	list::const_iterator list::const_iterator::operator++(){
		cNode=cNode->pNext;
		return *this;
	}

	list::const_iterator list::const_iterator::operator--(){
		cNode=cNode->pPrevious;
		return *this;
	}

	bool list::const_iterator::operator==(const_iterator constIt) const{
		if(cNode==constIt.cNode){
			return true;
		}
		else return false;
	}

	bool list::const_iterator::operator!=(const_iterator constIt) const{
		if(cNode!=constIt.cNode){
			return true;
		}
		else return false;
	}

		list::value_type& list::const_iterator::operator*() const{
		return cNode->value;
	}


//////////////////////////////////////////////////////////////////////////////////////////////

	list::list():last_node(0){
		elmt=0;
		last_node=new TNode();
		last_node->pPrevious=last_node;
		last_node->pNext=last_node;
	}

	list::~list(){
		while (elmt!=0){
			erase(begin());
		}
	}

	list::list(list& liste):last_node(0){
		elmt=0;
		iterator it1;
		iterator it2;
		last_node=new TNode();
		last_node->pPrevious=last_node;
		last_node->pNext=last_node;
		it2=end();
		for(it1==liste.begin();it1!=liste.end();++it1){
			insert(it2, *it1);
		}
	}

	list::iterator list::begin(){
		list::iterator *it = new list::iterator(last_node->pNext);
		return *it;
	}

	list::iterator list::end(){
		list::iterator *it = new list::iterator(last_node);
		return *it;
	}

	list::const_iterator list::begin() const{
		list::const_iterator *it = new list::const_iterator(last_node->pNext);
		return *it;
	}

	list::const_iterator list::end() const{
		list::const_iterator *it = new list::const_iterator(last_node);
		return *it;
	}

	list::iterator list::insert(iterator& it1, value_type value){
		list::TNode* mNode = new list::TNode(value);
		mNode->pNext = it1.itNode;
		it1--;
		mNode->pPrevious = it1.itNode;
		it1.itNode->pNext=mNode;
		it1++;
		it1++;
		it1.itNode->pPrevious = mNode;
		elmt++;
		return it1;
	}

	list::iterator list::insert(iterator& it1, iterator& it2, iterator& it3){
		while(it2!=it3){
			insert(it1,*it2);
			++it2;
		}
		return it1;
	}

	list::iterator list::erase(iterator it){
		it.itNode->pPrevious->pNext=it.itNode->pNext;
		it.itNode->pNext->pPrevious=it.itNode->pPrevious;
		iterator it2(it.itNode->pNext);
		delete[] &it;
		elmt--;
		return it2;
	}

	list::iterator list::erase(iterator it1, iterator it2){
		while(it1!=it2){
			it1=erase(it1);
		}
		return it2;
	}

	int list::size() const{
		return elmt;
	}

	bool list::empty(){
		if(elmt==0){
			return true;
		}
		else return false;
	}

	list& list::operator=(list& liste){
		iterator it1;
		iterator it2;
		if(this != &liste){
			while (elmt !=0){
				erase(begin());
			}
			elmt = 0;
			it2=end();
			for(it1=liste.begin();it1!=liste.end();++it1){
				insert(it2,*it1);
			}
		}
		return *this;
	}

//-----------------------------------------------------------------------------
} // namespace StructInfoList
//-----------------------------------------------------------------------------
