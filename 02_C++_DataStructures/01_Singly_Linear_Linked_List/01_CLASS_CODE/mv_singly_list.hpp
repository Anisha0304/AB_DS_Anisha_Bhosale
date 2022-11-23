/**
 * @file:	mv_singly_list.hpp
 * @author:	MarshallingVoid	(marshallingvoid@gmail.com) 
 * @brief:	This file contains the implementation of <class SinglyLinkedList> and its Interface<public> and Helper<private> function using cpp.
 * @date:	10/11/2022
 * @version	1.0
 * @copyright	Copyright (c) 2022
 * 
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

//Typedef

#ifndef	RET_T
#define	RET_T
typedef	int 	ret_t;
#endif

//Struct Node Definition

template<typename T_NODE>
class Node
{
private:
T_NODE	m_data;
Node*	mp_next;
Node( T_NODE data ) : m_data(data) 
{ 

//Code

mp_next = NULL;
}
template<typename T_NODE>
friend class SinglyLinkedList;
};

//Class SinglyLinkedList Definition

template<typename T_SLL>
class SinglyLinkedList : public IList<T_SLL>
{
private:
Node<T_SLL>*		mp_head;
Node<T_SLL>*		mp_tail;
size_t		size;
ret_t GenericInsert( Node<T_SLL>* first, Node<T_SLL>* mid, Node<T_SLL>* last )
{

//Code

mid->mp_next = last;
first->mp_next = mid;
size++;
if( NULL == mid->mp_next )
mp_tail = mid;
return(SUCCESS);
}
public:
SinglyLinkedList()
{

//Code

mp_head = new Node<T_SLL>(0);	//	Sentinel
mp_tail = mp_head;
size = 0;
}
~SinglyLinkedList()
{

//Code

}

//List Insertion Functions

ret_t	InsertFront(T_SLL data)
{

//Code

return( GenericInsert(mp_head, new Node<T_SLL>(data), mp_head->mp_next) );
}
ret_t	InsertBack(T_SLL data)
{

//Code

return( GenericInsert(mp_tail, new Node<T_SLL>(data), mp_tail->mp_next) );
}
ret_t	InsertAfter(T_SLL new_data, T_SLL e_data)
{

//Code

if( 0 == size )
return(FAILURE);
Node<T_SLL>*	prunner = mp_head->mp_next;
while( NULL != prunner )
{
if( prunner->m_data == e_data )
break;
prunner = prunner->mp_next;
}
if( NULL == prunner )
{
std::cerr << "ERROR: " << e_data << " not found in the list." << std::endl;
return(FAILURE);
}
return( GenericInsert( prunner, new Node<T_SLL>(new_data), prunner->mp_next ) );
}
ret_t	InsertBefore(T_SLL new_data, T_SLL e_data)
{

//Code

if( 0 == size )
return(FAILURE);
Node<T_SLL>* prunner = mp_head;
while( NULL != prunner->mp_next )
{
if( e_data == prunner->mp_next->m_data )
break;
prunner = prunner->mp_next;
}
if(NULL == prunner->mp_next)
return(FAILURE);
return( GenericInsert(prunner, new Node<T_SLL>(new_data), prunner->mp_next) );
}
ret_t	InsertAt(T_SLL new_data, long index)
{

//Code

if( 0 == size || index > size)
return(FAILURE);
if( 0 == index )
return( InsertFront(new_data) );
else if( size == index )
return( InsertBack(new_data) );
Node<T_SLL>* prunner = mp_head;
for( long le = 0; le < index; ++le)
prunner = prunner->mp_next;
return( GenericInsert(prunner, new Node<T_SLL>(new_data), prunner->mp_next) ); 
}

//List Removal Functions

T_SLL	RemoveFront() 
{ 

//Code

return(NULL); 
}
T_SLL	RemoveBack() { return(NULL); }
T_SLL	RemoveAfter(T_SLL e_data) { return(NULL); }
T_SLL 	RemoveBefore(T_SLL e_data) { return(NULL); }
T_SLL	RemoveAt(long index) { return(NULL); }

//Data Print Function

void ShowList()
{

//Code

Node<T_SLL>* prunner = mp_head->mp_next;
std::cout << "Singly List:" << std::endl;
std::cout << "{START}->";
for( prunner; NULL != prunner; prunner = prunner->mp_next)
{
std::cout << "{" << prunner->m_data << "}->";
}
std::cout << "{END}" << std::endl << std::endl;
}
};
