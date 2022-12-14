/**
 * @file	client.cpp
 * @author	Anisha Bhosale	(anishabhosale003@gmail.com)
 * @brief	This file contains all the client side function calling(usage) of  Merge Sort.
 * @date	03/12/2022
 * @version	1.0
 * 
 * @copyright	Copyright (c) 2022
 */

#include <iostream>
#include <ctime>
#include "mv_merge_sort.hpp"
int main(void)
{

//Code

srand(time(0));
long long no_of_elements =999;//1 + rand() % 100;
long* array =new long[no_of_elements];
for(long long le =0;le <no_of_elements;++le)
{
array[le] =1 +rand() %200;
}
std::cout <<"Array Before Sort:"<<std::endl;
std::cout <<"START, ";
for(long long le =0;le <no_of_elements;++le)
std::cout <<array[le] << ", ";
std::cout <<"END"<<std::endl <<std::endl;
clock_t start =clock();
	
/*MergeSort(array,no_of_elements,[](long a,long b) {
return(a > b);
});*/
	
MergeSort(array,no_of_elements,[](long a,long b){
if(a % 2 ==0 &&
b % 2 ==0)
return(a <b);
return(false);
});
clock_t end =clock();
std::cout <<"Array After Sort:"<<std::endl;
std::cout <<"START, ";
for(long long le =0;le <no_of_elements;++le)
std::cout <<array[le]<< ", ";
std::cout <<"END"<<std::endl <<std::endl;
std::cout <<"Time Required to sort"<< no_of_elements << " = " <<((double) end - start) / CLOCKS_PER_SEC <<"sec"<<std::endl;
delete [] array;
return(0);
}

