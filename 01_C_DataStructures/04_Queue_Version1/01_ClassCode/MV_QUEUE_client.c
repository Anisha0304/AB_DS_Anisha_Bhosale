//Headers
#include <stdio.h>
#include <stdlib.h>
#include "mv_queue.h"
p_mv_queue_t pqueue = NULL;
void print_data(data_t data)
{
long long lnum =(int)data;
fprintf(stdout,"{%lld}-",lnum);
}
void delete_data(data_t data)
{
long long lnum =(int)data;
fprintf(stdout, "deleting : %lld\n", lnum);
}
int main(void)
{
pqueue =create_default_queue();
mv_queue_enqueue(pqueue, (data_t)100);
mv_queue_enqueue(pqueue, (data_t)150);
mv_queue_enqueue(pqueue, (data_t)200);
mv_queue_enqueue(pqueue, (data_t)250);
mv_queue_enqueue(pqueue, (data_t)300);
mv_queue_enqueue(pqueue, (data_t)350);
mv_queue_enqueue(pqueue, (data_t)400);
mv_queue_enqueue(pqueue, (data_t)450);
mv_queue_enqueue(pqueue, (data_t)500);
mv_queue_enqueue(pqueue, (data_t)550);
mv_queue_print_data(pqueue, print_data);
fprintf(stdout,"Dequeue done data:");
print_data(mv_queue_dequeue(pqueue));
fprintf(stdout,"\n");
fprintf(stdout,"Dequeue donr data:");
print_data(mv_queue_dequeue(pqueue));
fprintf(stdout,"\n");
fprintf(stdout,"Dequeue done data:");
print_data(mv_queue_dequeue(pqueue));
fprintf(stdout,"\n");
fprintf(stdout,"Dequeue done data:");
print_data(mv_queue_dequeue(pqueue));
fprintf(stdout,"\n");
mv_queue_print_data(pqueue,print_data);
mv_queue_destroy(&pqueue,delete_data);
exit(SUCCESS);
}
