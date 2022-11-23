
/**
 * @file	client.cpp
 * @author	MarshallingVoid	(marshallingvoid@gmail.com)
 * @brief	Client for Doubly Circular Linked List(mv_dcll.hpp) to use and call all the interface function of MV_DCLL 
 * @date	13/11/2022
 * @version	1.0
 * 
 * @copyright	Copyright (c) 2022
 */

//Header

#include	<iostream>
#include	"mv_dcll.hpp"
MV_DCLL<long>* plist = NULL;
MV_DCLL<long>* plist1 = NULL;
MV_DCLL<long>* plist2 = NULL;
MV_DCLL<long>* plist_merge = NULL;
MV_DCLL<long>* plist_concat = NULL;
MV_DCLL<long>* plist_reverse = NULL;
int main(void)
{

//Code

plist = new MV_DCLL<long>();
for( long le = 0; le < 20; ++le )
{
plist->InsertFront( (le+1) * 29 );
}
std::cout << "List after InsertFront:" << std::endl;
plist->ForwardPrint();
plist->ReversePrint();
for( long le = 0; le < 20; ++le )
{
plist->InsertBack( (le+1) * 88 );
}
std::cout << "List after InsertBack:" << std::endl;
plist->ForwardPrint();
plist->ReversePrint();
plist->InsertBefore(1234, 1408);
plist->InsertBefore(5678, 551);
plist->InsertBefore(9875, 528);
plist->InsertBefore(123123, 580);
plist->InsertBefore(13579, 99999);
std::cout << "List after InsertBefore:" << std::endl;
plist->ForwardPrint();
plist->ReversePrint();
plist->InsertAfter(5566, 1234);
plist->InsertAfter(1199, 580);
plist->InsertAfter(9999, 551);
plist->InsertAfter(908012, 123123);
plist->InsertAfter(55227799, 5678);
std::cout << "List after InsertAfter:" << std::endl;
plist->ForwardPrint();
plist->ReversePrint();
plist->InsertAt(9898, 0);
plist->InsertAt(5588, plist->Size() - 1);
plist->InsertAt(337799, 15);
plist->InsertAt(116633, 31);
plist->InsertAt(1238046710829, 26);
std::cout << "List after InsertAt:" << std::endl;
plist->ForwardPrint();
plist->ReversePrint();
plist1 = new MV_DCLL<long>();
plist2 = new MV_DCLL<long>();
for( long le = 0; le < 20; ++le )
{
plist1->InsertBack( (le+1) * 101 );
}
std::cout << "List1 :" << std::endl;
plist1->ForwardPrint();
for( long le = 20; le > 0; --le )
{
plist2->InsertBack( le * 99 );
}
std::cout << "List2 :" << std::endl;
plist2->ForwardPrint();
plist_merge = plist1->Merge(plist2);
std::cout << "Merge List :" << std::endl;
plist_merge->ForwardPrint();
plist_concat = plist1->Concat(plist2);
std::cout << "After Concat :" << std::endl;
std::cout << "List1 :" << std::endl;
plist1->ForwardPrint();
std::cout << "List2 :" << std::endl;
plist2->ForwardPrint();
std::cout << "Concated List :" << std::endl;
plist_concat->ForwardPrint();
plist_reverse = plist_concat->Reverse();
std::cout << "Concated List :" << std::endl;
plist_concat->ForwardPrint();
std::cout << "Reversed List :" << std::endl;
plist_reverse->ForwardPrint();
plist_reverse->InplaceReverse();
std::cout << "After Inplace Reverse List :" << std::endl;
plist_reverse->ForwardPrint();
delete(plist_reverse);
plist_reverse = NULL;
delete(plist_concat);
plist_concat = NULL;
delete(plist_merge);
plist_merge = NULL;
delete(plist1);
plist1 = NULL;
delete(plist2);
plist2 = NULL;
delete(plist);
plist = NULL;
exit(SUCCESS);
}

