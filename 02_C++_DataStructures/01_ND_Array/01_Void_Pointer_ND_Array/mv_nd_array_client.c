//Header
#include <iostream>
#include "mv_nd_array.hpp"

//Comstant Literals

#define MAX 5
MVArray* parray_4d=NULL;
int main(void)
{
	parray_4D =new MVArray(4,MAX,MAX,MAX,MAX);

//Write Data To Array

long long count=1;
for(long index1=0;index1<parray_4D->GetDimensionSize(0);++index1)
{
for(long index2=0;index2<parray_4D->GetDimensionSize(1);++index2)
{
for(long index3=0;index3<parray_4D->GetDimensionSize(1);++index3)
{
for(long index4=0;index4<parray_4D->GetDimensionSize(1);++index4)
{	
parray_4D->SetData((data_t)count++,index1,index2,index3,index4);
}
}
}	
}
for(long index1=0;index1<parray_4D->GetDimensionSize(0);++index1)
{
for(long index2=0;index2<parray_4D->GetDimensionSize(1);++index2)
{
for(long index3=0;index3<parray_4D->GetDimensionSize(1);++index3)
{
for(long index4=0;index4<parray_4D->GetDimensionSize(1);++index4)
{	
std::cout << "parray_4D["
<< index1
<< "]"
<< "["
<< index2
<< "]"
<< "["
<< index3
<< "]"
<< "["
<< index4
<< "]"
<< "="
<< (long long)parray_4D->GetData(index1,index2,index3,index4)
<< std::endl;
}
}
}
}
delete(parray_4D);
return(0);
}









