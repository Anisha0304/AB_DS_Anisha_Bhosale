
/**
 * @file:	client.cpp
 * @author:	MarshallingVoid	(marshallingvoid@gmail.com) 
 * @brief:	This file contains the use of all the function implement in mv_singly_list.hpp
 * @date:	10/11/2022
 * @version	1.0
 * @copyright	Copyright (c) 2022
 * 
 */

//Headers

#include	<iostream>
#include	"mv_singly_list.hpp"
SinglyLinkedList<long> *psll;
int main(void)
{

//Code

psll = new SinglyLinkedList<long>();
for( long le = 0; le < 10; ++le )
{
psll->InsertFront( (le+1) * 13 );
}
std::cout << "List After insert front: " << std::endl;
psll->ShowList();
for( long le = 0; le < 10; ++le )
{
psll->InsertBack( (le+1) * 62 );
}
std::cout << "List After insert back: " << std::endl;
psll->ShowList();
psll->InsertAfter(1234, 52);
psll->InsertAfter(5678, 620);
psll->InsertAfter(9009, 248);
psll->InsertAfter(8008, 9999);
std::cout << "List After insert after: " << std::endl;
psll->ShowList();
psll->InsertBefore(1001, 1234);
psll->InsertBefore(4422, 248);
psll->InsertBefore(7865, 9009);
psll->InsertBefore(9999, 5678);
std::cout << "List After insert before: " << std::endl;
psll->ShowList();
psll->InsertAt(1331, 10);
psll->InsertAt(1111, 0);
psll->InsertAt(9292, 13);
psll->InsertAt(5555, 15);
std::cout << "List After insert At: " << std::endl;
psll->ShowList();
delete(psll);
psll = NULL;
exit(SUCCESS);
}


