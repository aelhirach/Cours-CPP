//-----------------------------------------------------------------------------
// File list.h
//-----------------------------------------------------------------------------
#ifndef LIST_H_
#define LIST_H_
//-----------------------------------------------------------------------------
// Pour list, il faut dans TData : copy constructor, operator =, destructor
// Pour bubbleSort, il faut dans TData : <
// Pour find, il faut dans TData : ==
//-----------------------------------------------------------------------------
namespace StructInfoList {
//-----------------------------------------------------------------------------
template<class TData> class list {
protected:
	//-------------------------------------------------------------------------
	struct TNode {
		// TODO ...
        	TNode* pPrevious;
			TNode* pNext;
			TData data;
			TNode(): data(){}
			~TNode() {}
			TNode(TData& pData) {data=pData;}
	};
	//-------------------------------------------------------------------------
    public:
// TODO ... (typedefs)
	typedef TData value_type;
	typedef TData& reference;
	typedef const TData& const_reference;
    typedef  TData* pointer;
    typedef const TData* const_pointer;
	//-------------------------------------------------------------------------
	class const_iterator; // !!!
	class iterator {
public:
// TODO ... (déclarations + définitions inline)
     iterator():  pNode(0){}
        iterator(TNode* p): pNode(p){ }
        iterator(const iterator& _iter): pNode(_iter.pNode){}
        ~iterator(){}
   
     inline iterator operator++() {
             pNode = pNode->pNext;  
            return *this;
            }// ++it
  inline iterator operator--(){
             pNode = pNode->pPrevious; 
            return *this;
            } // --it
   
    inline iterator operator++(int){
        pNode = pNode->pNext;
        iterator * iter = new iterator(pNode->pPrevious);
        return *iter;
    }
    inline iterator operator--(int){
        pNode = pNode->pPrevious;
        iterator* iter = new iterator(pNode->pNext);
        return *iter;
    }
     bool operator==(const iterator& _iter){ return pNode == _iter.pNode; }
   bool operator!=(const iterator& _iter){ return pNode != _iter.pNode;}// return !((*this)==_iter);}
    inline  reference operator*(){return pNode->data;}
    inline const_reference operator*() const{return pNode->data;}
    inline pointer operator->(){return &(pNode->data);}
    inline const pointer operator->() const{return &(pNode->data);}

protected:
	TNode* pNode;
	friend class list;
	};

	class const_iterator { // !!!
public:


        const_iterator():  pNode(0){}
        const_iterator(TNode* p): pNode(p){ }
        const_iterator(iterator iter){pNode = iter.pNode;}
        const_iterator(const const_iterator& _iter): pNode(_iter.pNode){}
        ~const_iterator(){}
   
     inline const_iterator operator++() {
             pNode = pNode->pNext;  
            return *this;
            }// ++it
  inline const_iterator operator--(){
             pNode = pNode->pPrevious; 
            return *this;
            } // --it
   
    inline const_iterator operator++(int){
        pNode = pNode->pNext;
        const_iterator * iter = new const_iterator(pNode->pPrevious);
        return *iter;
    }
    inline const_iterator operator--(int){
        pNode = pNode->pPrevious;
        const_iterator* it = new const_iterator(pNode->pNext);
        return *it;
    }
     bool operator==(const const_iterator& _iter){ return pNode == _iter.pNode; }
     bool operator!=(const const_iterator& _iter){ return pNode != _iter.pNode;}// return !((*this)==_iter);}
    inline  const_reference operator*() const{return pNode->data;}
    inline const_pointer operator->() const{return &(pNode->data);}
protected:
    TNode* pNode;
    friend list;
	// TODO ...
	};

	// TODO ... (typedefs)


	//-------------------------------------------------------------------------
// TODO ... (déclarations)
    list();
	~list();
	list(list& _list);
    iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
	iterator insert(iterator iter, TData& data);
	template<class InputIterator> iterator insert(iterator iter, InputIterator iterB, InputIterator iterE);
    iterator erase(iterator iter);
	iterator erase(iterator iterB, iterator iterE);
	inline int size() const;
	inline bool empty();
	list& operator=(list& _list);

protected:
	//-------------------------------------------------------------------------
	// TODO ...

    int elementCount;
	TNode* pEndNode;

	//-------------------------------------------------------------------------
};
//-----------------------------------------------------------------------------
// TODO ... (template<class TData> inline list<TData>::TNode::...)

  template<class TData>
    list<TData>::list() {
            elementCount=0;
            pEndNode=new TNode();
            pEndNode->pPrevious=pEndNode;
            pEndNode->pNext=pEndNode;
                }

template<class TData>
list<TData>::~list()
{
	while(elementCount != 0) {
		erase(begin());
	}
}

template<class TData>
list<TData>::list(list& liste):pEndNode(0)
{
	elementCount = 0;
	pEndNode = new TNode();
	pEndNode->pPrevious = pEndNode;
	pEndNode->pNext = pEndNode;
	iterator iterB;
	iterator iterE = end();
	for(iterB = liste.begin(); iterE != liste.end(); ++iterB){
		insert(iterE, *iterB);
	}
}

template<class TData>
inline int list<TData>::size() const {return elementCount;}

template<class TData>
inline bool list<TData>::empty(){return (elementCount == 0);}

template<class TData>
list<TData>& list<TData>::operator=(list& _list)
{
 if (this != &_list){
                erase(begin(),end());
                iterator iter(pEndNode);
                iterator iterB =_list.begin();
                iterator iterE =_list.end();
                insert(iter, iterB,iterE);
           }
            return *this;
}

template<class TData>
typename list<TData>::iterator list<TData>::begin()
{
	iterator * iter = new iterator(pEndNode->pNext);
	return *iter;
}

template<class TData>
typename list<TData>::iterator list<TData>::end()
{
	iterator * iter = new iterator(pEndNode);
	return *iter;
}

template<class TData>
typename list<TData>::iterator list<TData>::insert(iterator iter, TData& _data)
{
	TNode* pNewNode = new TNode(_data); /// créer un nouveau noeud 
                pNewNode->pNext = iter.pNode; ///  le next de nouveau neud c'est iter
                iter--;// pointer sur iter previous 
                pNewNode->pPrevious = iter.pNode; /// le previous de nouveau noeud c'est iter--
                iter.pNode->pNext=pNewNode; 
                iter++;
                iter++;
                iter.pNode->pPrevious = pNewNode;
                elementCount++;
                return iter;
}

template<class TData>
template<class InputIterator>
typename list<TData>::iterator list<TData>::insert(iterator iter, InputIterator iterB, InputIterator iterE){
        // insérer une séquence d'éléments iter2 -> iter3 devant iter1
		  while (iterB!=iterE) {
                insert(iter,*iterB);
                ++iterB;
              }
          // envoyer le dernier élement devant lequel on a inséré
          return iter;
        }

template<class TData>
typename list<TData>::const_iterator list<TData>::begin() const
{
	const_iterator * iter = new const_iterator(pEndNode->pNext);
	return *iter;
}

template<class TData>
typename list<TData>::const_iterator list<TData>::end() const
{
	const_iterator * iter = new const_iterator(pEndNode);
	return * iter;
}

template<class TData>
typename list<TData>::iterator list<TData>::erase(iterator iter)
{
	iter.pNode->pPrevious->pNext= iter.pNode->pNext;
    iter.pNode->pNext->pPrevious=iter.pNode->pPrevious;
	iterator iterNext(iter.pNode->pNext);
	delete[] &iter;
	elementCount--;
	return iterNext;
}

template<class TData>
typename list<TData>::iterator  list<TData>::erase(iterator iterB, iterator iterE) {
         while (iterB!=iterE){

                    iterB= erase(iterB);
            }
            return iterE;
        } 
//-----------------------------------------------------------------------------
// TODO ... (template<class TData> inline list<TData>::iterator::...)
//-----------------------------------------------------------------------------
// TODO ... (template<class TData> inline list<TData>::const_iterator::...)
//-----------------------------------------------------------------------------
// TODO ... (template<class TData> inline list<TData>::...)
//      et  (template<class TData> list<TData>::...)
//-----------------------------------------------------------------------------
} // namespace StructInfoList
//-----------------------------------------------------------------------------

#endif /*LIST_H_*/
