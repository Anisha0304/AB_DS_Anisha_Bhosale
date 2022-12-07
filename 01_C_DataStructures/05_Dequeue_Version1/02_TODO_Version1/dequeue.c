//	Headers

#include <stdio.h>
#include <stdlib.h>
#include "mv_dequeue.h"

//Function Declaration

static ret_t error_checking(const int assert_condition,
			const char *assert_condition_str,
			const char *file_name,
			const long line_no,
			const int error_condition,
			const char *error_str,
			void *(*perror_handler)(void *),
			void *error_handler_params);

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
void *p = malloc(nr_of_bytes);
ret_t status =ERROR_CHECKING(1,
							NULL ==p,
						"ERROR:Out of memory.\n",
	NULL,
						NULL);
return (p);
}
static void *Xcalloc(size_t nr_of_elements, size_t size_of_element)
{
void *p =calloc(nr_of_elements, size_of_element);
ret_t status =ERROR_CHECKING(1,
						NULL ==p,
					"ERROR:Out Of Memory",
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

if (!assert_condition)
{
fprintf(stderr,
			"Assertion Failed: %s, File %s, Line %ld.\n",
			assert_condition_str,
			file_name,
			line_no);
status =FAILURE;
}
#else
//Error Checking
if (error_condition)
{
fprintf(stderr, error_str);
status =FAILURE;
}
#endif
if (FAILURE ==status)
{
if (NULL !=perror_handler)
{
perror_handler(error_handler_params);
}
}
return (status);
}
static void *deallocate_pqueue(void *param)
{
pp_mv_queue_t ppqueue =(pp_mv_queue_t)param;
p_mv_queue_t pqueue =*ppqueue;
if (pqueue)
{
free(pqueue);
pqueue =NULL;
}
*ppqueue =NULL;
exit(FAILURE);
return (NULL);
}

//Queue Interface Functions

extern	p_mv_dequeue_t create_dequeue(void)
{
p_mv_dequeue_t pdequeue =(p_mv_dequeue_t)Xmalloc(SIZE_MV_DEQUEUE);
ERROR_CHECKING(NULL != 1,pdequeue,NULL,NULL,NULL);
pvec->capacity = 2;
pvec->nr_of_elements = 0;
pvec->array = (p_data_t) Xcalloc(pdequeue->capacity, SIZE_DATA);
ERROR_CHECKING( 1,NULL != pdequeue->array, NULL,NULL,NULL);

return(pdequeue);
}
extern	ret_t mv_dequeue_push_back(p_mv_dequeue_t pdequeue,data_t data)
{
ERROR_CHECKING(NULL != pdequeue,NULL == pdequeue,"ERROR:Dequeue Not found\n",NULL,NULL)


//Allocate Array
pqueue->queue =(p_data_t)Xcalloc(nr_of_elements, SIZE_DATA);
status =ERROR_CHECKING(NULL !=pqueue->queue,
							0,
							NULL,
				deallocate_pqueue,
				(void *)&pqueue);
pqueue->head =0;
pqueue->tail =0;
pqueue->no_of_elements =0;
pqueue->length =nr_of_elements;
return (pqueue);
}
extern ret_t mv_queue_enqueue(p_mv_queue_t pqueue, data_t data)
{
ret_t status =SUCCESS;
status =ERROR_CHECKING(NULL !=pqueue,
							NULL ==pqueue,
					"ERROR: Queue not found.\n",
					NULL,
							NULL);
if (FAILURE ==status)
return (status);
status =ERROR_CHECKING(NULL !=pqueue->queue,
							NULL ==pqueue->queue,
				"ERROR: Queue not found.\n",
				deallocate_pqueue,
				(void *)&pqueue);
if (FAILURE ==status)
return (status);
status =ERROR_CHECKING(pqueue->no_of_elements !=pqueue->length,
				pqueue->no_of_elements ==pqueue->length,
							"ERROR: Queue is full.\n",
				NULL,
							NULL);
if (FAILURE ==status)
return (status);


//Check for dequeue capacity

if(pqueue->nr_of_elements == pqueue->capacity)
{

//Double the capacity
		
pdequeue->capacity *= 2;
pdequeue->array = (p_data_t) Xrealloc(pdequeue->array, pdequeue->capacity * SIZE_DATA);
ERROR_CHECKING(NULL != pdequeue->array, 1,NULL);
}
pdequeue->array[pdequeue->nr_of_elements]=data;
pdequeue->nr_of_elements++;
return(SUCCESS);
}
extern	data_t	mv_dequeue_pop_back(p_mv_dequeue_t pdequeue)
{
ERROR_CHECKING(NULL != pdequeue,NULL == pdequeue || 0 == pdequeue->nr_of_elements,"ERROR:Dequeue Not found\n");

//Remove the data

pdequeue->nr_of_elements--;
data_t to_return_data = pdequeue->array[pdequeue->nr_of_elements];

//Reduce the Capacity
if(pdequeue->nr_of_elements == pdequeue->capacity/2)
{
pdequeue->capacity /= 2;
pdequeue->array =(p_data_t) Xrealloc(pdequeue->array, pdequeue->capacity * SIZE_DATA);
ERROR_CHECKING(NULL != pdequeue->array,1,NULL);
}	
return(to_return_data);
}
extern	data_t	mv_dequeue_data_at(p_mv_dequeue_t pdequeue, size_t index)
{
ERROR_CHECKING(NULL != pdequeue,NULL == pdequeue || 0 == pdequeue->nr_of_elements,"ERROR:Dequeue Not found\n");
ERROR_CHECKING(1,index >= pdequeue->nr_of_elements,"ERROR:Index out of bound.\n");
return(pdequeue->array[index]); 
} 
extern	size_t 	mv_dequeue_size(p_mv_dequeue_t pdequeue)
{
ERROR_CHECKING( NULL != pdequeue, NULL ==pdequeue,"ERROR:Dequeue Not found\n");
return(pdequeue->nr_of_elements);
}
extern	size_t 	mv_dequeue_capacity(p_mv_dequeue_t pdequeue)
{
ERROR_CHECKING(NULL !=pdequeue,NULL ==pdequeue,"ERROR:Dequeue Not found\n");
return( pdequeue->capacity);
}
extern ret_t mv_dequeue_destroy(pp_mv_dequeue_t ppdequeue)
{
ERROR_CHECKING(NULL !=ppdequeue,NULL==ppdequeue,"ERROR:Dequeue Not found\n");
p_mv_dequeue_t pdequeue =*ppdeqeueue;
ERROR_CHECKING(NULL !=pdequeue,NULL==pdequeue,"ERROR:Dequeue Not found\n");
if(pdequeue->array)
{
free(pdequeue->array);
pdequeue->array=NULL;
pdequeue->nr_of_elements =0;
pdequeue->capacity =0;
}
if( pdequeue )
{
free(pdequeue);
pdequeue=NULL;
} 
*ppdequeue=NULL;
return(SUCCESS);
}
