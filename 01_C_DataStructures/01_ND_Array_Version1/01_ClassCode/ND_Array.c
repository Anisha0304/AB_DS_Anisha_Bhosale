//Header
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <string.h>
#include "ND_Array.h"

//Array Helper Function

static void* xmalloc(size_t no_of_bytes)
{
	void* p= malloc(no_of_bytes);
	if(NULL==p)
{
	fprintf(stderr, "ERROR:Out Of Memory\n");
	exit(FAILURE);

}
return(p);
}
static void*	xcalloc(size_t no_of_elements, size_t no_of_bytes)
{
	void* p=calloc(no_of_elements,no_of_bytes);
	if(NULL==p)
	{
		fprintf(stderr, "ERROR:Out Of Memory\n");
		exit(FAILURE);

	}
	return(p);
}

//Array Interface Function

extern p_array_t create_array(size_t no_of_dimensions, ...)
{
 //Test Case
 
 #ifdef MY_DEBUG
 assert(0 !=no_of_dimensions);      //for developer
 #else	
 if(0 == no_of_dimensions)          //for client
{
	fprintf(stderr, "0 dimension array not possible. \n");
	return(NULL);
}
#endif
p_array_t parray = (p_array_t) xmalloc(SIZE_ARRAY);
/*
* Step 1: Initialize the no of dimensions for array
*/
parray->no_of_dimensions=no_of_dimensions;
/*
* Step 2: Allocate an array to store the size of every dimension with 'no_of_dimension' as no of elements.
*/
//Initialize size of each dimension

parray->pdimensions = (long*) xcalloc( no_of_dimensions, sizeof(long) );
/*
* Step3:Get the size of every dimension from variadic input parameters and store it in the allocated array from step 2.
*/
//Storing all the sizes of each dimension

va_list arg;
va_start(arg, no_of_dimensions);
for(long le=0;le<no_of_dimensions;++le)
{
parray->pdimensions[le] = va_arg(arg, long);	
}
va_end(arg);
/*
* Step 4: Calculate the total no of elements for the data array by multiplying sizes of each dimension.
*/
//Allocating memory to array

size_t no_of_elements = parray->pdimensions[0];

//Calculating no of elements

for(long le=1;le<no_of_dimensions;++le)
no_of_elements *= parray->pdimensions[le];
/*
* Step 5: Allocate the data array.
*/
parray->ptr=(data_t*) xcalloc(no_of_elements,sizeof(void*));
/*
* Step6:Initialize all the bytes of allocated array to '0'.
*/
memset(parray->ptr, 0, no_of_elements * sizeof(void*));
parray->to_jump_dimensions = (size_t*) xcalloc( no_of_dimensions, sizeof(size_t) );
parray->to_jump_dimensions[ no_of_dimensions - 1 ] = 1;
for(long le = no_of_dimensions-2;le>=0;--le)
{
	parray->to_jump_dimensions[le]=parray->pdimensions[le+1]*parray->to_jump_dimensions[le+1];
	}
return(parray);
}
extern ret_t array_set_data(p_array_t parray,data_t data, ...)
{
	long* indices=NULL;

	//ERROR CHECKING

#ifdef MY_DEBUG
assert(NULL !=parray);
#else
if(NULL == parray)
{
fprintf(stderr, "Error: No array found.\n");
return(FAILURE);
}
#endif

//Allocate array to store indices

indices =(long*) xcalloc(parray->no_of_dimensions,sizeof(long));

//Get indices from input parameters

va_list arg;
va_start(arg,data);
for(long le=0; le<parray->no_of_dimensions;++le)
{
	long index=va_arg(arg,long);
#ifdef MY_DEBUG
assert(index >=0 && index < parray->pdimension[le]);
#else
if(index < 0 || index >=parray->pdimensions[le])
{
fprintf(stderr,"ERROR:Index Out Of Bound.\n");
va_end(arg);
free(indices);
return(FAILURE);
}
#endif
indices[le]=index;
}
va_end(arg);

//Calculate the final index

size_t final_index=0;
for(long le=0; le< parray->no_of_dimensions;++le)
{
	final_index=final_index+parray->to_jump_dimensions[le]* indices[le];
}

//Set The Value 

parray->ptr[final_index]=data;

//Free the indices array

free(indices);
return(SUCCESS);
}
extern data_t array_get_data(p_array_t parray,...)
{
	long* indices =NULL;
#ifdef MY_DEBUG
assert(NULL !=parray);
#else
if(NULL == parray)
{
	fprintf(stderr,"ERROR:No array found .\n");
	return(NULL);
}
#endif	

//Allocate array for indices

indices =(long*) xcalloc( parray->no_of_dimensions,sizeof(long));

//Assign indices value

va_list arg;
va_start(arg,parray);
for( long le = 0; le < parray->no_of_dimensions; ++le )
{
	long index =va_arg(arg,long);
#ifdef MY_DEBUG
assert(index >=0 && index< parray->pdimension[le]);
#else	
if(index <0 || index >=parray->pdimensions[le])
{
fprintf(stderr, "ERROR: Index Out Of bound.\n");
va_end(arg);
free(indices);
return(NULL);
}
#endif
indices[le]=index;
}
va_end(arg);

//Calculate final index

size_t final_index=0;
for(long le =0;le <parray->no_of_dimensions;++le)
{
	final_index=final_index+parray->to_jump_dimensions[le]*indices[le];
}

//Get the values

data_t to_return_data=parray->ptr[final_index];

//Free indices;

free(indices);

//Return Data

return(to_return_data);
}
extern long array_get_size_of_dimension(p_array_t parray,long index)
{
	#ifdef MY_DEBUG
	assert(NULL !=parray);
	assert(index < parray->no_of_dimensions)
	#else
	if(NULL == parray)
	{
		fprintf(stderr,"ERROR:No array found to destroy.\n");
		return(0);
	}
	if(index >=parray->no_of_dimensions)
	{
		fprintf(stderr,"ERROR:Dimension does not exists.\n");
		return(0);
	}
	#endif
	return(parray->pdimensions[index]);
}
extern	ret_t 	array_destroy(pp_array_t pparray)
{
	p_array_t parray = *pparray;

	#ifdef MY_DEBUG
	assert(NULL !=parrray);
	#else
	if(NULL ==parray)
	{
		fprintf(stderr,"ERROR:No array found to destroy.\n");
		return(FAILURE);
	}
	#endif

	//Free the to jump dimension

	if(parray->to_jump_dimensions)
	{
		free(parray->to_jump_dimensions);
		parray->to_jump_dimensions=NULL;
	}

	//Free the data array

	if(parray->ptr)
	{
		free(parray->ptr);
		parray->ptr=NULL;
	}

	//Free the size of each dimension array

	if(parray->pdimensions)
	{
		free(parray->pdimensions);
		parray->pdimensions=NULL;
	}

	//Free the struct object

	if(parray)
		{
			free(parray);
			parray=NULL;
		}

		//Assign NULL to the client side pointer

		*pparray=NULL;
		return(SUCCESS);
	}


