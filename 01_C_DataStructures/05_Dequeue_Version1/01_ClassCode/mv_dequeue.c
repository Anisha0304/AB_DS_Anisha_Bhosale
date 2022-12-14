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
extern p_mv_queue_t create_default_queue(void)
{
p_mv_queue_t pqueue =(p_mv_queue_t)Xmalloc(SIZE_QUEUE);
ret_t status =ERROR_CHECKING(NULL !=pqueue,
								  0,
							NULL,
						 NULL,
						 NULL);
if (FAILURE ==status)
{
exit(FAILURE);
}

//Allocate Array
	
pqueue->queue =(p_data_t)Xcalloc(QUEUE_DEFAULT_SIZE, SIZE_DATA);
status =ERROR_CHECKING(NULL !=pqueue->queue,
							0,
						NULL,
							deallocate_pqueue,
					(void *)&pqueue);

pqueue->head =0;
pqueue->tail =0;
pqueue->no_of_elements =0;
pqueue->length =QUEUE_DEFAULT_SIZE;
return (pqueue);
}
extern p_mv_queue_t create_custom_queue(size_t nr_of_elements)
{
p_mv_queue_t pqueue =(p_mv_queue_t)Xmalloc(SIZE_QUEUE);
ret_t status =ERROR_CHECKING(NULL !=pqueue,
								  0,
								 NULL,
								  NULL,
								  NULL);

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

//Insert Data

pqueue->queue[pqueue->tail] =data;
pqueue->tail++;
if (pqueue->tail ==pqueue->length)
{
pqueue->tail =0;
}
pqueue->no_of_elements++;
return (SUCCESS);
}
extern data_t mv_queue_dequeue(p_mv_queue_t pqueue)
{
ret_t status =SUCCESS;
status =ERROR_CHECKING(NULL !=pqueue,
							NULL ==pqueue,
				"ERROR: Queue not found.\n",
							NULL,
						NULL);
if (FAILURE ==status)
return (NULL);
status =ERROR_CHECKING(NULL !=pqueue->queue,
							NULL ==pqueue->queue,
					"ERROR: Queue not found.\n",
							deallocate_pqueue,
							(void *)&pqueue);
if (FAILURE ==status)
return (NULL);
status =ERROR_CHECKING(0 !=pqueue->no_of_elements,
							0 ==pqueue->no_of_elements,
				"ERROR: No Data to delete",
							NULL,
				NULL);
if (FAILURE ==status)
return (NULL);
data_t to_return_data =pqueue->queue[pqueue->head];
pqueue->head++;
if (pqueue->head ==pqueue->length)
{
pqueue->head =0;
}
pqueue->no_of_elements--;
return (to_return_data);
}
extern ret_t mv_queue_print_data(p_mv_queue_t pqueue, PRINTDATAPROC pprintfunc)
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
status =ERROR_CHECKING(NULL !=pprintfunc,
							NULL ==pprintfunc,
					"ERROR: Print Callback must be provided.\n",
							NULL,
					NULL);
if (FAILURE ==status)
return (status);
fprintf(stdout, "\nQUEUE:\n");
fprintf(stdout, "\n{START}-");
for (long le =pqueue->head; le !=pqueue->tail; ++le)
{
if (le ==pqueue->length)
{
le =0;
}
pprintfunc(pqueue->queue[le]);
}
fprintf(stdout, "{END}\n");
return (status);
}
extern size_t mv_queue_length(p_mv_queue_t pqueue)
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
return (pqueue->length);
}
extern ret_t mv_queue_destroy(pp_mv_queue_t ppqueue, DELETEDATAPROC pdeletefunc)
{
ret_t status =SUCCESS;
status =ERROR_CHECKING(NULL !=ppqueue,
							NULL ==ppqueue,
					"ERROR: Queue not found.\n",
							NULL,
						NULL);

if (FAILURE ==status)
return (status);
p_mv_queue_t pqueue =*ppqueue;
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
status =ERROR_CHECKING(NULL !=pdeletefunc,
							NULL ==pdeletefunc,
					"ERROR: Delete Callback must be provided.\n",
							NULL,
							NULL);
if (FAILURE ==status)
return (status);
fprintf(stdout, "\nDestroying QUEUE:\n");
fprintf(stdout, "\n{START}\n");
for (long le =pqueue->head; le !=pqueue->tail; ++le)
{
if (le ==pqueue->length)
{
le =0;
}
pdeletefunc(pqueue->queue[le]);
}
fprintf(stdout, "{END}\n");
if (pqueue->queue)
{
free(pqueue->queue);
pqueue->queue =NULL;
}
if (pqueue)
{
free(pqueue);
pqueue =NULL;
}
*ppqueue =NULL;
return (status);
}
