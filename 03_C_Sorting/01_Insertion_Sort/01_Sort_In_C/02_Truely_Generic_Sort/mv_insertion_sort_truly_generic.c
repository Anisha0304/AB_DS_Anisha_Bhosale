
/**
 * @file	mv_insertion_sort.c
 * @author	MarshallingVoid	(marshallingvoid@gmail.com)
 * @breif	The interface function definition for Generic Insertion Sort.
 * @date	20/11/2022
 * @version	1.0
 * 
 * @copyright	Copyright (c) 2022
 */


#include <stdio.h>
#include <stdlib.h>
#include "mv_insertion_sort_truly_generic.h"

//Insertion Sort Helper Function

static void assign_value( char* dest, char* src, size_t no_of_bytes )
{

//Code

for( size_t le = 0; le < no_of_bytes; ++le )
{
dest[le] = src[le];
}
}

//Insertion Sort Interface Function

extern ret_t mv_insertion_sort(	data_t* array, 
								long long array_size, 
								size_t element_size,
								COMPAREDATAPROC pcompareproc)
{

//Code

for( long long ole = 1; ole < array_size; ++ole)
{

//Store the key element
//Limitation 1: Type of context is fixed to 8 bytes
//Limitation 2: Allocation of key is of only 8 bytes
//Assignment to key from array index
//data_t key = array[ole];
//Allocate an object with the size of an element

void* key = malloc(element_size);
void* source_addres_from_array = (((char*)array) + ole * element_size);
assign_value( key, source_addres_from_array, element_size);
long long ile = ole-1;	

//while( ile >= 0 && array[ile] > key )

while( ile >= 0 && SUCCESS == pcompareproc((((char*)array) + ile * element_size), key) )
{

//Move the bigger from key element to next index
//fprintf(stdout, "2\n");
			
void* dest = (((char*)array) + (ile+1) * element_size);
void* src = (((char*)array) + ile * element_size);

//array[ile+1] = array[ile]; 

assign_value( dest, src, element_size );
ile--;
}

//Restore the key element in the proper index place
//array[ile+1] = key;

assign_value( (((char*)array) + (ile+1) * element_size), key, element_size );
if( key )
{
free(key);
key = NULL;
}

//fprintf(stdout, "3\n");

}
return(SUCCESS);
}


