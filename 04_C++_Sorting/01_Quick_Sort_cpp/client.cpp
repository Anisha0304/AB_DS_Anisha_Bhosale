
//Headers

#include <iostream>
#include <ctime>
#include "quick_sort.hpp"
#include "mv_array.hpp"
int main(void)
{
MVArray<long long, 99999>	arr;
long long size = 99999;
for( long le = 0; le < size; ++le )
{
arr[le] = 1 + rand() % 10;//9999999;
}

/*std::cout << "Array Before Quick Sort: ";
for( long le = 0; le < size; ++le )
{
std::cout << arr[le] << " ";
}
std::cout << std::endl;*/
QuickSort(arr, 0, size-1, [](long long value1, long long value2){
return( value1 <= value2 );
});
std::cout << "Array After Quick Sort: ";
for( long le = 0; le < size; ++le )
{
std::cout << arr[le] << " ";
}
}
std::cout << std::endl;
return(SUCCESS);


