//Headers

#include <stdio.h>
#include <stdlib.h>
#include "mv_queue.h"

//Function Declaration

static ret_t error_checking(const int assert_condition,const char *assert_condition_str, const char *file_name, const long line_no,
	const int error_condition,const char *error_str,void *(*perror_handler)(void *),void *error_handler_params);

//MACROS

#define QUEUE_DEFAULT_SIZE 512
#define ERROR_CHECKING(assert_condition, error_condition, error_str, error_handler, error_handler_params) ( \
	error_checking(assert_condition,                                                                        \
				   #assert_condition,                                                                       \
				   __FILE__,                                                                                \
				   __LINE__,                                                                                \
				   error_condition,                                                                         \
				   error_str,                                                                               \
				   error_handler,                                                                           \
				   error_handler_params))

//Queue Auxillary Functions
static void *Xmalloc(size_t nr_of_bytes)
{
void *p =malloc(nr_of_bytes);
ret_t status = ERROR_CHECKING(1,
								NULL ==p,
								"ERROR: Out of memory.\n",
								 NULL,
							 NULL);

return (p);
}
static void *Xcalloc(size_t nr_of_elements, size_t size_of_element)
{
void *p =calloc(nr_of_elements,size_of_element);
ret_t status = ERROR_CHECKING(1,
								 NULL ==p,
								  "ERROR: Out Of Memory",
								 NULL,
								 NULL);

return (p);
}
static ret_t error_checking(const int assert_condition,
							const char *assert_condition_str,
							const char *file_name,
							const long line_no,
							const int error_condition,
							const char *error_str,
							void *(*perror_handler)(void *),
							void *error_handler_params)
{
ret_t status =SUCCESS;
#ifdef MV_DEBUG

	//Assertion
	
if(!assert_condition)
{
fprintf(stderr,
			"Assertion Failed: %s,File %s,Line %ld.\n",
				assert_condition_str,
				file_name,
				line_no);
status = FAILURE;
}
#else

//Error Checking
	
if(error_condition)
{
fprintf(stderr,error_str);
status =FAILURE;
}
#endif
if(FAILURE ==status)
{
if(NULL !=perror_handler)
{
perror_handler(error_handler_params);
}
}
return(status);
}
static void *deallocate_pqueue(void *param)
{
pp_mv_queue_t ppqueue =(pp_mv_queue_t)param;
p_mv_queue_t pqueue =*ppqueue;
if(pqueue)
{
free(pqueue);
pqueue =NULL;
}
*ppqueue =NULL;
exit(FAILURE);
return (NULL);
}

//Queue Interface Functions

extern	p_mv_queue_t create_queue(void)
{
p_mv_queue_t pqueue =(p_mv_queue_t)Xmalloc(SIZE_QUEUE);
ERROR_CHECKING(1,NULL !=pqueue,
								 
								  NULL,
								  NULL,

								  NULL);
pqueue->capacity = 2;
pqueue->nr_of_elements = 0;
pqueue->array = (data_t) Xcalloc(pqueue->capacity, SIZE_DATA);
ERROR_CHECKING( 1,NULL != pqueue->array, 
NULL,
NULL,
 NULL);

return(pqueue);
}
extern ret_t mv_queue_push_back(p_mv_queue_t pqueue,data_t data)
{
ERROR_CHECKING(NULL != pqueue,NULL == pqueue,"ERROR:Queue Not found\n",NULL,NULL);
//Check for queue capacity

if(pqueue->nr_of_elements == pqueue->capacity)
{

//Double the capacity
		
pqueue->capacity *= 2;
pqueue->array = (p_mv_queue_t) Xrealloc(pqueue->array, pqueue->capacity * SIZE_DATA);
ERROR_CHECKING(1,NULL != pqueue->array, NULL,NULL,NULL);
}
pqueue->array[pqueue->nr_of_elements]=data;
pqueue->nr_of_elements++;
return(SUCCESS);
}
extern	data_t	mv_queue_pop_back(p_mv_queue_t pqueue)
{
ERROR_CHECKING(NULL != pqueue,NULL == pqueue || 0 == pqueue->nr_of_elements,"ERROR:Queue Not found\n",NULL,NULL);

//Remove the data

pqueue->nr_of_elements--;
data_t to_return_data = pqueue->array[pqueue->nr_of_elements];

//Reduce the Capacity
if(pqueue->nr_of_elements == pqueue->capacity/2)
{
pqueue->capacity /= 2;
 pqueue->array =(p_mv_queue_t) Xrealloc(pqueue->array, pqueue->capacity * SIZE_DATA);
ERROR_CHECKING(1,NULL != pqueue->array,NULL,NULL,NULL);
}	
return(to_return_data);
}
extern	data_t	mv_queue_data_at(p_mv_queue_t pqueue, size_t index)
{
ERROR_CHECKING(NULL != pqueue,NULL == pqueue || 0 == pqueue->nr_of_elements,"ERROR:Queue Not found\n",NULL,NULL);
ERROR_CHECKING(1,index >= pqueue->nr_of_elements,"ERROR:Index out of bound.\n",NULL,NULL);
return(pqueue->array[index]); 
} 
extern	size_t 	mv_vector_size(p_mv_queue_t pqueue)
{
ERROR_CHECKING( NULL != pqueue, NULL ==pqueue,"ERROR:Queue not found\n",NULL,NULL);
return(pqueue->nr_of_elements);
}
extern	size_t 	mv_queue_capacity(p_mv_queue_t pqueue)
{
ERROR_CHECKING(NULL !=pqueue,NULL ==pqueue,"ERROR:Queue Not found\n",NULL,NULL);
return( pqueue->capacity);
}
extern ret_t mv_queue_destroy(pp_mv_queue_t ppqueue)
{
ERROR_CHECKING(NULL !=ppqueue,NULL==ppqueue,"ERROR:Queue Not found\n",NULL,NULL);
p_mv_queue_t pqueue =*ppqueue;
ERROR_CHECKING(NULL !=pqueue,NULL==pqueue,"ERROR:Queue Not found\n",NULL,NULL);
if(pqueue->array)
{
free(pqueue->array);
pqueue->array=NULL;
pqueue->nr_of_elements =0;
pqueue->capacity =0;
}
if( pqueue )
{
free(pqueue);
pqueue=NULL;
} 
*ppqueue=NULL;
return(SUCCESS);
}


