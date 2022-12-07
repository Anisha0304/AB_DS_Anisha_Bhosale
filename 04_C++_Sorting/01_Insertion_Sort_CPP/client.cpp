/**
 * @file	client.cpp
 * @author	Anisha Bhosale	(anishabhosale003@gmail.com)
 * @brief	This file contains all the client side function calling(usage) of  Insertion Sort.
 * @date	02/12/2022
 * @version	1.0
 * 
 * @copyright	Copyright (c) 2022
 */

#include <iostream>
#include <ctime>
#include "mv_insertion_sort.hpp"
#include "mv_array.hpp"
int main(void)
{

//Code

srand(time(0));
long no_of_elements =10;
MVArray<long,10>array;
for(long le =0;le<no_of_elements;++le)
{
array[le] =rand() % 100;
}
std::cout<<"Before Insertion Sort"<<std::endl;
std::cout<< "START, ";
for(long le =0;le<no_of_elements;++le)
{
std::cout <<array[le]<<", ";
}
std::cout<<"END"<<std::endl<<std::endl;
std::cout<<"Before Insertion Sort using Iterator"<<std::endl;
std::cout<<"START, ";
for(auto itr =array.begin();itr !=array.end();++itr)
{
std::cout << *itr<< ", ";
}
std::cout<<"END"<<std::endl<<std::endl;

//Insertion Sort With Iterator Genericness

InsertionSort(array.begin(), array.end());
std::cout<<"After Insertion Sort using Iterator"<<std::endl;
std::cout<< "START, ";
for(auto itr = array.begin(); itr != array.end();++itr)
{
std::cout<<*itr<< ", ";
}
std::cout<<"END"<< std::endl<<std::endl;

//Insertion Sort With Iterator Genericness and Lambda Expression

InsertionSort(array.begin() + 5,array.end(),[](long a, long b){
return(a > b);
});
std::cout<<"After Insertion Sort using Iterator and Lambda Expression"<< std::endl;
std::cout<<"START, ";
for(auto itr =array.begin();itr !=array.end();++itr)
{
std::cout << *itr << ", ";
}
std::cout<<"END"<<std::endl <<std::endl;
return(0);
}
