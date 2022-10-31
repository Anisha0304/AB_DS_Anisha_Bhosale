//Headers
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <string.h>
#include "TDND_Array.h"

//Function Declaration

void error_checking( const int assert_condition, 
				const char* assert_condition_str,
				const char* file_name,
				const int line_no,
				const int error_condition,
				const char* error_str);

//Macros

#define ERROR_CHECKING(	assert_condition, error_condition, error_str){											\
												error_checking( assert_condition,		\
											#assert_condition, 		\
												__FILE__,				\
												__LINE__,				\
												error_condition,		\
												error_str);				\
}

//Array Helper Function

static void* xmalloc(size_t no_of_bytes)
{
void* p =malloc(no_of_bytes);
ERROR_CHECKING( 1, NULL == p, "ERROR: Out Of Memory.\n" );
return(p);
}
static void* xcalloc(size_t no_of_elements, size_t no_of_bytes)
{
void* p =calloc(no_of_elements, no_of_bytes);
ERROR_CHECKING( 1, NULL == p, "ERROR: Out Of Memory.\n" );
return(p);
}
static	void* Xrealloc(void* p, size_t nr_of_bytes)
{

//Code

void* rp = realloc(p, nr_of_bytes);
ERROR_CHECKING( 1, NULL == p, "ERROR: Out Of Memory.\n" );
return(rp);
}
void error_checking( const int assert_condition, 
				const char* assert_condition_str,
				const char* file_name,
				const int line_no,
				const int error_condition,
				const char* error_str)
{

//Code

#ifdef DEBUG

//Check Assertion

if( !assert_condition )
{
fprintf(stderr, "Assertion failed : %s, File %s, Line No %d\n", assert_condition_str, file_name, line_no);
}
#else	

//Error Checking

if( error_condition )
{
if( NULL != error_str )
{
fprintf(stderr, error_str);
exit(FAILURE);
}
}
#endif
}

//Array Interface Function

extern	p_array_t create_array(size_t no_of_dimensions, ...)
{
p_array_t parray =(p_array_t) xmalloc(SIZE_ARRAY);

//Step 1:Initialize The No Of Dimensions For Array

parray->no_of_dimensions =no_of_dimensions;

//Step 2:Allocate An Array To Store The Size Of Every Dimension
	 	
//Initialize Size Of Each Dimension

parray->pdimension =(long*) xcalloc(no_of_dimensions, sizeof(long));

//Step 3:Get The Size Of Every Dimension From Variadic Input Parameters 
	 			
//Storing All The Sizes Of Each Dimension

va_list arg;
va_start(arg, no_of_dimensions);
for( long le = 0; le < no_of_dimensions; ++le)
{
parray->pdimension[le] =va_arg(arg, long);
}
va_end(arg);

//Step 4:Calculate The Total No Of Elements For The Data Array By Multiplying Sizes Of Each 
				
//Allocating Memory To Array

size_t no_of_elements =parray->pdimension[0];

//Calculating No Of Elements

for(long le = 1; le < no_of_dimensions; ++le)
no_of_elements *= parray->pdimension[le];

//Step 5:Allocate The Data Array.
	 
parray->ptr =(data_t*) xcalloc( no_of_elements, sizeof(void*));

//Step 6: Initialize All The Bytes Of Allocated Array To '0'.
	
memset(parray->ptr, 0, no_of_elements * sizeof(void*));
parray->to_jump_dimension =(size_t*) xcalloc( no_of_dimensions, sizeof(size_t));
parray->to_jump_dimension[no_of_dimensions - 1] =1;
for(long le = no_of_dimensions-2; le >= 0; --le)
{
parray->to_jump_dimension[le] =parray->pdimension[le+1] * parray->to_jump_dimension[le+1];
}
return(parray);
}
extern	ret_t array_set_data(p_array_t parray, data_t data, ...)
{

//Code

long* indices =NULL;

//Error Checking

#ifdef MY_DEBUG
assert(NULL != parray);
#else
if(NULL == parray)
{
fprintf(stderr, "Error: No array found.\n");
return(FAILURE);
}
#endif

//Allocate Array To Store Indices
	
indices =(long*) xcalloc(parray->no_of_dimensions, sizeof(long));

//Get Indices From Input Parameters
	
va_list arg;
va_start(arg, data);
for(long le = 0; le < parray->no_of_dimensions; ++le)
{
long index =va_arg(arg, long);
#ifdef	MY_DEBUG
assert( index >= 0 	&& index < parray->pdimension[le] );
#else
if(index < 0	||	index >= parray->pdimension[le])
{
fprintf(stderr, "ERROR: Index Out Of Bound.\n");
va_end(arg);
free(indices);
return(FAILURE);
}
#endif
indices[le] =index;
}
va_end(arg);

//Calculate The Final Index

size_t final_index =0;
for(long le = 0; le < parray->no_of_dimensions; ++le)
{
final_index = final_index + parray->to_jump_dimension[le] * indices[le];
}

//Set The Value 

parray->ptr[final_index] =data;

//Free The Indices Array

free(indices);
return(SUCCESS);
}

extern	data_t	array_get_data(p_array_t parray, ...)
{

//Code

long*	indices =NULL;
#ifdef	MY_DEBUG
assert(NULL != parray);
#else
if(NULL == parray)
{
fprintf(stderr, "ERROR: No array found.\n");
return(NULL);
}
#endif

//Allocate array for indices

indices =(long*) xcalloc(parray->no_of_dimensions, sizeof(long));

//Assign indices value

va_list arg;
va_start(arg, parray);
for(long le = 0; le < parray->no_of_dimensions; ++le)
{
long index =va_arg(arg, long);
#ifdef MY_DEBUG
assert(index >= 0 && index < parray->pdimension[le]);
#else
if(index < 0 || index >= parray->pdimension[le])
{
fprintf(stderr, "ERROR: Index out of bound.\n");
va_end(arg);
free(indices);
return(NULL);
}
#endif
indices[le] =index;
}
va_end(arg);

//Calculate Final Index

size_t final_index =0;
for(long le = 0; le < parray->no_of_dimensions; ++le)
{
final_index =final_index + parray->to_jump_dimension[le] * indices[le];
}

//Get The Value

data_t to_return_data = parray->ptr[final_index];

//Free Indices;

free(indices);

//Return Data

return(to_return_data);
}
extern	long	array_get_size_of_dimension(p_array_t parray, long index)
{

//Code

#ifdef MY_DEBUG
assert(NULL != parray);
assert(index < parray->no_of_dimensions)
#else
if(NULL == parray)
{
fprintf(stderr, "ERROR: No array found to destroy.\n");
return(0);
}
if(index >= parray->no_of_dimensions)
{
fprintf(stderr, "ERROR: Dimension does not exists.\n");
return(0);
}
#endif
return(parray->pdimension[index]);
}
extern	ret_t 	array_destroy(pp_array_t pparray)
{

//Code

p_array_t parray = *pparray;
#ifdef MY_DEBUG
assert(NULL != parray);
#else
if(NULL == parray)
{
fprintf(stderr, "ERROR: No array found to destroy.\n");
return(FAILURE);
}
#endif

//Free The To Jump Dimension

if(parray->to_jump_dimension)
{
free(parray->to_jump_dimension);
parray->to_jump_dimension =NULL;
}

//Free The Data Array

if(parray->ptr)
{
free(parray->ptr);
parray->ptr =NULL;
}

//Free The Size Of Each Dimension Array

if(parray->pdimension)
{
free(parray->pdimension);
parray->pdimension =NULL;
}

//Free The Struct Object

if(parray)
{
free(parray);
parray =NULL;
}

//Assign NULL To The Client Side Pointer

*pparray =NULL;
return(SUCCESS);
}
