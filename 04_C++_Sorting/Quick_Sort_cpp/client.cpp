//Headers
#include <iostream>
#include <ctime>
#include "quick_sort.hpp"
#include "mv_array.hpp"
#include "mv_dcll.hpp"
int main(void)
{
MVArray<long long, 100>	arr;
long long size = 100;
for( long le = 0; le < size; ++le )
{
arr[le] = 1 + rand() % 9999;
}
std::cout << "Array Before Quick Sort: ";
for( long le = 0; le < size; ++le )
{
std::cout << arr[le] << " ";
}
std::cout << std::endl;
QuickSort(arr, 0, size-1, [](long long value1, long long value2){
return( value1 <= value2 );
});
std::cout << std::endl;
std::cout << "Array After Quick Sort: ";
for( long le = 0; le < size; ++le )
{
std::cout << arr[le] << " ";
}
std::cout << std::endl;
MV_DCLL<long long>	list;
for( long le = 0; le < size; ++le )
{
list.InsertBack(1 + rand() % 9999);
}
std::cout << std::endl;
std::cout << std::endl;
std::cout << "List Before Quick Sort: ";
std::cout << list << std::endl;
QuickSort(list, 0, list.Size()-1, [](long long value1, long long value2) {
return( value1 <= value2 );
});
std::cout << std::endl;
std::cout << "List After Quick Sort: ";
std::cout << list << std::endl;
return(SUCCESS);
}

