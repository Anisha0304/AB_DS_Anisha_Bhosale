/**
 * @file:mv_insertion_sort.hpp
 * @author:Anisha Bhosale (anishabhosale003@gmail.com)
 * @brief:This file hold the definition for sort algorithm i.e generic insertion sort
 * @date:02/12/2022
 * @version:1.0
 * 
 * @copyright:Copyrights(c) 2022
 */

#pragma once
template<typename T>
extern void InsertionSort(T* array,long size)
{

//Code
//loop(i =1 to A.length-1)

for(long ole =1;ole <size;++ole)
{

//key =A[i]

T key =array[ole];

//j =i-1

long ile =ole-1;

//loop(j >=0 && key<A[j])

while(ile >=0 && key<array[ile])
{

//move the element ahead by 1 place
//A[j+1] =A[j]

array[ile+1] =array[ile];
--ile;
}

//Insert the key at the appropriate position

array[ile+1] =key;
}
}

/**
 * This Insertion Sort is Data Generic AS WELL AS Data Structure Generic
 */

template<typename T_ITR>
extern void InsertionSort(T_ITR first,T_ITR last)
{

//Code
//loop(i =1 to A.length-1)

for(T_ITR itr =first + 1;itr !=last;++itr)
{

//key =A[i]

auto key =*itr;

//j =i-1

T_ITR ritr =itr-1;

//loop(j >=0 && key <A[j])

while(ritr !=first-1 && key <*ritr)
{

//move the element ahead by 1 place
//A[j+1] = A[j]
            
(ritr+1) =*ritr;
ritr--;
}

//Insert the key at the appropriate position

(ritr+1) =key;
}
}


/**
 *This Insertion Sort is Data Generic AS WELL AS Data Structure Generic
*/

template<typename T_ITR,class Compare>
extern void InsertionSort(T_ITR first,T_ITR last,Compare compare)
{

//Code
//loop(i =1 to A.length-1)

for(T_ITR itr =first + 1;itr !=last;++itr)
{

//key =A[i]

auto key =*itr;

//j =i-1

T_ITR ritr =itr-1;

//loop(j >=0 && key<A[j])

while(ritr !=first-1 && compare(key,*ritr))
{

//move the element ahead by 1 place
//A[j+1] =A[j]

(ritr+1) =*ritr;
ritr--;
}

//Insert the key at the appropriate position

(ritr+1) =key;
}
}
