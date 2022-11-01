//Headers
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ND_Array.h"
#define NO_OF_ELEMENTS 6
#define NO_OF_1D_ARRAY 6
#define NO_OF_2D_ARRAY 6
#define NO_OF_3D_ARRAY 5
#define NO_OF_4D_ARRAY 5
#define NO_OF_5D_ARRAY 4
#define NO_OF_6D_ARRAY 4
#define NO_OF_7D_ARRAY 3
#define NO_OF_8D_ARRAY 3
#define NO_OF_9D_ARRAY 3
#define NO_OF_10D_ARRAY 3
#define NO_OF_11D_ARRAY 3
#define MAX 6
p_array_t my_4Darray=NULL;
p_array_t my_8Darray=NULL;
p_array_t my_12Darray=NULL;
int main(void)
{

                           //4 Dimension Array
my_4Darray=create_array(4,MAX,MAX,MAX,MAX);
assert(NULL !=my_4Darray);

//Values to 4D array

size_t count =0;
for( long index1 = 0; index1 < array_get_size_of_dimension(my_4Darray, 0); ++index1 )
for( long index2 = 0; index2 < array_get_size_of_dimension(my_4Darray, 1); ++index2 )
for( long index3 = 0; index3 < array_get_size_of_dimension(my_4Darray, 2); ++index3)
for( long index4 = 0; index4 < array_get_size_of_dimension(my_4Darray, 3); ++index4)
array_set_data(my_4Darray,(data_t)(++count),index1,index2,index3,index4);
fprintf(stdout,"\n*************************************************************************\n");
fprintf(stdout," First Element of 4D array = %lld\n", (long long)array_get_data(my_4Darray, 0, 0, 0, 0) );
fprintf(stdout," Last Element of 4D array = %lld\n", (long long)array_get_data(my_4Darray, 5, 5, 5, 5) );
fprintf(stdout,"\n*************************************************************************\n\n\n\n\n");array_destroy(&my_4Darray);

                                 //8 Dimension Array

my_8Darray = create_array(8,4,4,4,4,4,4,4,4);
assert (NULL !=my_8Darray);

//Values to 8D array

count=0;
for(long index1=0;index1<array_get_size_of_dimension(my_8Darray,0); ++index1)
for(long index2=0;index2<array_get_size_of_dimension(my_8Darray,1); ++index2)
for(long index3=0;index3<array_get_size_of_dimension(my_8Darray,2); ++index3)
for(long index4=0;index4<array_get_size_of_dimension(my_8Darray,3); ++index4)
for(long index5=0;index5<array_get_size_of_dimension(my_8Darray,4); ++index5)
for(long index6=0;index6<array_get_size_of_dimension(my_8Darray,5); ++index6)
for(long index7=0;index7<array_get_size_of_dimension(my_8Darray,6); ++index7)
for(long index8=0;index8<array_get_size_of_dimension(my_8Darray,7); ++index8)
array_set_data( my_8Darray, (data_t)(++count), index1, index2,index3, index4, index5, index6, index7, index8);
fprintf(stdout,"\n*************************************************************************\n");
fprintf(stdout,"\n8D Array:\n");
fprintf(stdout," First Element of 8D array = %lld\n", (long long)array_get_data(my_8Darray, 0, 0, 0, 0, 0, 0, 0, 0) );
fprintf(stdout," Last Element of 8D array = %lld\n", (long long)array_get_data(my_8Darray, 3, 3, 3, 3, 3, 3, 3, 3) );
fprintf(stdout,"\n*************************************************************************\n\n\n\n\n");array_destroy(&my_8Darray);


                               //12 Dimension Array

my_12Darray= create_array(12,NO_OF_11D_ARRAY, NO_OF_10D_ARRAY,NO_OF_9D_ARRAY, NO_OF_8D_ARRAY,NO_OF_7D_ARRAY, NO_OF_6D_ARRAY,NO_OF_5D_ARRAY, NO_OF_4D_ARRAY,NO_OF_3D_ARRAY, NO_OF_2D_ARRAY,NO_OF_1D_ARRAY, NO_OF_ELEMENTS);
assert( NULL != my_12Darray);

//Values to 12D array
count=0;
for (long index1=0; index1<array_get_size_of_dimension(my_12Darray,0); ++index1)
for(long index2=0;index2<array_get_size_of_dimension(my_12Darray,1); ++index2)
for(long index3=0;index3<array_get_size_of_dimension(my_12Darray,2); ++index3)
for(long index4=0;index4<array_get_size_of_dimension(my_12Darray,3); ++index4)
for(long index5=0;index5<array_get_size_of_dimension(my_12Darray,4); ++index5)
for(long index6=0;index6<array_get_size_of_dimension(my_12Darray,5); ++index6)
for(long index7=0;index7<array_get_size_of_dimension(my_12Darray,6); ++index7)
for(long index8=0;index8<array_get_size_of_dimension(my_12Darray,7); ++index8)
for(long index9=0;index9<array_get_size_of_dimension(my_12Darray,8); ++index9)
for(long index10=0;index10<array_get_size_of_dimension(my_12Darray,9); ++index10)
for(long index11=0;index11<array_get_size_of_dimension(my_12Darray,10); ++index11)
for(long index12=0;index12<array_get_size_of_dimension(my_12Darray,11); ++index12)
array_set_data(my_12Darray,(data_t)(++count), index1, index2, index3, index4, index5, index6, index7, index8, index9, index10, index11, index12);

// Read Value

fprintf(stdout, "\n*************************************************************************\n");
fprintf(stdout," First Element of 12D array = %lld\n", (long long)array_get_data(my_12Darray, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0) );
fprintf(stdout," Last Element of 12D array = %lld\n", (long long)array_get_data(my_12Darray, NO_OF_11D_ARRAY-1, NO_OF_10D_ARRAY-1, NO_OF_9D_ARRAY-1, NO_OF_8D_ARRAY-1, NO_OF_7D_ARRAY-1, NO_OF_6D_ARRAY-1, NO_OF_5D_ARRAY-1, NO_OF_4D_ARRAY-1, NO_OF_3D_ARRAY-1, NO_OF_2D_ARRAY-1, NO_OF_1D_ARRAY-1, NO_OF_ELEMENTS-1));
fprintf(stdout, "\n*************************************************************************\n\n\n\n\n");
//Destroy Array

array_destroy(&my_12Darray);
exit(SUCCESS);
}