/**
* @file	mv_dcll.hpp
* @author	MarshallingVoid	(marshallingvoid@gmail.com)
* @brief	This file contains all the class definitions and data members and member functions required to implement Doubly Circular Linked List. 
* @date	13/11/2022
* @version	1.0
* 
* @copyright	Copyright (c) 2022
*/

#pragma	once

//Headers

#include "mv_list.hpp"

//Constant Literals

#ifndef	SUCCESS
#define	SUCCESS	0
#endif
#ifndef	FAILURE
#define	FAILURE	1
#endif

//typedefs

typedef	int ret_t;

//Node Class Definition

template <typename T_NODE>
class Node
{
private:
T_NODE m_data;
Node<T_NODE>* mp_next;
Node<T_NODE>* mp_prev;
Node( T_NODE data ) : m_data(data), mp_next(this), mp_prev(this)
{ }
~Node() {}
template <typename T_NODE>
friend class MV_DCLL;
};
template <typename T_LIST>
class MV_DCLL : public IList<T_LIST>
{
private:
Node<T_LIST>* mp_head;
Node<T_LIST>* mp_tail;
size_t	m_size;

//List Helper Functions

ret_t GenericInsert(Node<T_LIST>* first, Node<T_LIST>* mid, Node<T_LIST>* last)
{

//Code

mid->mp_next = last;
mid->mp_prev = first;
first->mp_next = mid;
last->mp_prev = mid;
m_size++;
mp_tail = mp_head->mp_prev;
return(SUCCESS);
}
T_LIST GenericRemove(Node<T_LIST>* d_node)
{

//Code

Node<T_LIST>* first = d_node->mp_prev;
Node<T_LIST>* last = d_node->mp_next;
first->mp_next = last;
last->mp_prev = first;
T_LIST to_return_data = d_node->m_data;
delete(d_node);
m_size--;
mp_tail = mp_head->mp_prev;
return(to_return_data);
}
public:
MV_DCLL() 
{

//Code

mp_head = new Node<T_LIST>((T_LIST)0);
mp_tail = mp_head;
m_size = 0;
}
~MV_DCLL()
{

//Code

Node<T_LIST>* prunner = mp_head->mp_next;
for( prunner; prunner != mp_head; )
{
Node<T_LIST>* prunner_next = prunner->mp_next;
delete(prunner);
prunner = prunner_next;
}
delete(mp_head);
}

//List Interface Functions
//List Insertion Functions

ret_t InsertFront(T_LIST new_data)
{

//Code

return( GenericInsert(mp_head, new Node<T_LIST>(new_data), mp_head->mp_next) );
}
ret_t InsertBack(T_LIST new_data)
{

//Code

return( GenericInsert(mp_tail, new Node<T_LIST>(new_data), mp_tail->mp_next) );
}
ret_t InsertAfter(T_LIST new_data, T_LIST e_data)
{

//Code

if( 0 == m_size )
{
std::cerr << "ERROR: No List found." << std::endl;
return(FAILURE);
}
Node<T_LIST>* prunner = mp_head->mp_next;
for( prunner; prunner != mp_head; prunner = prunner->mp_next )
{
if(prunner->m_data == e_data)
break;
}
if( mp_head == prunner )
{
std::cerr << "ERROR: Existing data not found." << std::endl;
return(FAILURE);
}
return( GenericInsert(prunner, new Node<T_LIST>(new_data), prunner->mp_next) );
}
ret_t InsertBefore(T_LIST new_data, T_LIST e_data)
{

//Code

if( 0 == m_size )
{
std::cerr << "ERROR: No List found." << std::endl;
return(FAILURE);
}
Node<T_LIST>* prunner = mp_head->mp_next;
for( prunner; prunner != mp_head; prunner = prunner->mp_next )
{
if(prunner->m_data == e_data)
break;
}
if( mp_head == prunner )
{
std::cerr << "ERROR: Existing data not found." << std::endl;
return(FAILURE);
}
return( GenericInsert(prunner->mp_prev, new Node<T_LIST>(new_data), prunner) );
}
ret_t InsertAt(T_LIST new_data, long index)
{

//Code

if( 0 == m_size )
{
std::cerr << "ERROR: List not found." << std::endl;
return(FAILURE);
}
if( index > m_size )
{
std::cerr << "ERROR: Index out of bound." << std::endl;
}
if( 0 == index )
return( InsertFront(new_data) );
else if( m_size == index )
return( InsertBack(new_data) );
Node<T_LIST>* prunner = mp_head;
for( long le = 0; le < index; ++le )
{
prunner = prunner->mp_next;
}
return(GenericInsert(prunner, new Node<T_LIST>(new_data), prunner->mp_next));
}

//List Removal Functions

T_LIST RemoveFront()
{
if( 0 == m_size )
{
std::cerr << "ERROR: List not found." << std::endl;
return((T_LIST)0);
}
return( GenericRemove(mp_head->mp_next) );
}
T_LIST RemoveBack()
{
if( 0 == m_size )
{
std::cerr << "ERROR: List not found." << std::endl;
return((T_LIST)0);
}
return( GenericRemove(mp_tail) );
}
T_LIST RemoveAfter(T_LIST e_data)
{

//Code

if( 0 == m_size )
{
std::cerr << "ERROR: No List found." << std::endl;
return(FAILURE);
}
Node<T_LIST>* prunner = mp_head->mp_next;
for( prunner; prunner != mp_head; prunner = prunner->mp_next )
{
if(prunner->m_data == e_data)
break;
}
if( mp_head == prunner )
{
std::cerr << "ERROR: Existing data not found." << std::endl;
return(FAILURE);
}
if( mp_tail == prunner )
{
prunner = mp_head;
}
return( GenericRemove(prunner->mp_next) );
}
T_LIST RemoveBefore(T_LIST e_data)
{

//Code

if( 0 == m_size )
{
std::cerr << "ERROR: No List found." << std::endl;
return(FAILURE);
}
Node<T_LIST>* prunner = mp_head->mp_next;
for( prunner; prunner != mp_head; prunner = prunner->mp_next )
{
if(prunner->m_data == e_data)
break;
}
if( mp_head == prunner )
{
std::cerr << "ERROR: Existing data not found." << std::endl;
return(FAILURE);
}
if( mp_head->mp_next == prunner )
{
prunner = mp_head;
}
return( GenericRemove(prunner->mp_prev) );
}
T_LIST RemoveAt(long index)
{

//Code

if( 0 == m_size )
{
std::cerr << "ERROR: List not found." << std::endl;
return(FAILURE);
}
if( index >= m_size )
{
std::cerr << "ERROR: Index out of bound." << std::endl;
}
if( 0 == index )
return( RemoveFront() );
else if( m_size-1 == index )
return( RemoveBack() );
Node<T_LIST>* prunner = mp_head;
for( long le = 0; le < index; ++le )
{
prunner = prunner->mp_next;
}
return( GenericRemove(prunner->mp_next) );
}

//List Data Functions

ret_t ShowList()
{

//Code

std::cout << "Doubly Circular Linked List." << std::endl;
std::cout << "{START}->";
for(Node<T_LIST>* prunner = mp_head->mp_next; 
prunner != mp_head;
prunner = prunner->mp_next)
{
std::cout << "{" << prunner->m_data << "}->";
}
std::cout << "{END}" << std::endl << std::endl;
return(SUCCESS);
}
ret_t ForwardPrint()
{

//Code

return(ShowList());
}
ret_t ReversePrint()
{

//Code

std::cout << "Reverse Doubly Circular Linked List." << std::endl;
std::cout << "{START}->";
for(Node<T_LIST>* prunner = mp_tail; 
prunner != mp_head;
prunner = prunner->mp_prev)
{
std::cout << "{" << prunner->m_data << "}->";
}
std::cout << "{END}" << std::endl << std::endl;
return(SUCCESS);
}
T_LIST Head() const { return(mp_head->mp_next->data); }
T_LIST Tail() const { return(mp_tail->data); }
size_t Size() const { return(m_size); }

//List Manipulation Functions

MV_DCLL<T_LIST>* Merge(MV_DCLL<T_LIST>*& plist)
{

//Code

if( 0 == this->m_size	||
NULL == plist 		||
0 == plist->m_size)
{
std::cerr << "ERROR: List not present to merge." << std::endl;
return(NULL);
}
Node<T_LIST>*	prunner1 = this->mp_head->mp_next;
Node<T_LIST>*	prunner2 = plist->mp_head->mp_next;
MV_DCLL<T_LIST>* plist_new = new MV_DCLL<T_LIST>(); 

//Test Case 1: Both the list is present i.e (Both list have equal no of elements)

while( 	prunner1 != this->mp_head 	&&
prunner2 != plist->mp_head)
{
if( prunner1->m_data <= prunner2->m_data )
{
plist_new->InsertBack(prunner1->m_data);
prunner1 = prunner1->mp_next;
}
else
{
plist_new->InsertBack(prunner2->m_data);
prunner2 = prunner2->mp_next; 
}
}

//Test Case 2: List1.size < List2.size

if( prunner1 == this->mp_head	&&
prunner2 != plist->mp_head )
{
while( prunner2 != plist->mp_head )
{
plist_new->InsertBack(prunner2->m_data);
prunner2 = prunner2->mp_next;
}
}

//Test Case 3: List2.size < List1.size

if( prunner2 == plist->mp_head	&&
prunner1 != this->mp_head )
{
while( prunner1 != this->mp_head )
{
plist_new->InsertBack(prunner1->m_data);
prunner1 = prunner1->mp_next;
}
}
return(plist_new);
}
MV_DCLL<T_LIST>* Append(MV_DCLL<T_LIST>* plist)
{

//Code

}
MV_DCLL<T_LIST>* Concat(MV_DCLL<T_LIST>* plist)
{

//Code

}
MV_DCLL<T_LIST>* Reverse()
{

//Code

}
MV_DCLL<T_LIST>* InplaceReverse()
{

//Code

}
MV_DCLL<T_LIST>* Sort()
{

//Code

}

//Iterator

class Iterator
{
private:
Node<T_LIST>* itr;
MV_DCLL<T_LIST>* list;
public:
Iterator(Node<T_LIST>* itr, MV_DCLL<T_LIST>* list) : itr(itr), list(list) {}
~Iterator() {}
Iterator& operator++() 
{

//Code

itr = itr->mp_next;
/*if( itr == list->mp_head )
itr = list->mp_head->mp_next;*/
return(*this);
}
Iterator& operator--() 
{

//Code

itr = itr->mp_prev;
/*if( itr == list->mp_head )
itr = list->mp_tail;*/
return(*this);
}
Iterator operator++(int value) 
{

//Code

Iterator temp = Iterator(itr, list);
++(*this);
return(temp);
}
Iterator operator--(int value) 
{

//Code

Iterator temp = Iterator(itr, list);
--(*this);
return(temp);
}
Iterator operator+(long value)
{

//Code

Iterator temp = Iterator(itr, list);
for( long le = 0; le < value; ++le )
{
++temp;
}
return( temp );
}
Iterator operator-(long value)
{

//Code

Iterator temp = Iterator(itr, list);
for( long le = 0; le < value; ++le )
{
--temp;
}
return( temp );
}
Iterator& operator+=(long value)
{

//Code

for( long le = 0; le < value; ++le )
{
++(*this);
}
return( *this );
}
Iterator& operator-=(long value)
{

//Code

for( long le = 0; le < value; ++le )
{
--(*this);
}
return( *this );
}
Iterator& operator=(T_LIST value)
{
itr->m_data = value;
return(*this);
}
bool operator==(Iterator& itr)
{
return( this->itr == itr.itr );
}
bool operator!=(Iterator& itr)
{
return( !((*this) == itr) );
}
T_LIST operator*()
{

//Code

return(itr->m_data);
}
};
Iterator begin()
{

//Code

return( Iterator(this->mp_head->mp_next, this) );
}
Iterator end()
{

//Code

return( Iterator(this->mp_head, this) );
}
};
template <typename T_OUT>
std::ostream& operator<<(std::ostream& out, MV_DCLL<T_OUT>* list)
{

//Code

out << "Doubly Circular LinkedList:" << std::endl;
out << "{START}->";
for( auto itr = list->begin(); itr != list->end(); ++itr)
out << "{" << (*itr) << "}->";
out << "{END}" << std::endl;
return(out);
}
