//Headers
#include <stdio.h>
#include <stdlib.h>
#include "mv_dequeue.h"
p_mv_queue_t pqueue =NULL;
void print_data(data_t data)
{
long long lnum =(int)data;
fprintf(stdout, "{%lld}-",lnum);
}
void delete_data(data_t data)
{
long long lnum =(int)data;
fprintf(stdout, "deleting : %lld\n", lnum);
}
int main(void)
{
pqueue =create_default_queue();
mv_queue_push_back(pqueue, (data_t)9);
mv_queue_push_back(pqueue, (data_t)18);
mv_queue_push_back(pqueue, (data_t)27);
mv_queue_push_back(pqueue, (data_t)36);
mv_queue_push_back(pqueue, (data_t)45);
mv_queue_push_back(pqueue, (data_t)54);
mv_queue_push_back(pqueue, (data_t)63);
mv_queue_push_back(pqueue, (data_t)72);
mv_queue_push_back(pqueue, (data_t)81);
mv_queue_push_back(pqueue, (data_t)90);
mv_queue_print_data(pqueue, print_data);
fprintf(stdout, "Dequeue done data:");
print_data(mv_queue_pop_back(pqueue));
fprintf(stdout, "\n");
fprintf(stdout, "Dequeue done data:");
print_data(mv_queue_pop_back(pqueue));
fprintf(stdout, "\n");
fprintf(stdout, "Dequeue done data:");
print_data(mv_queue_pop_back(pqueue));
fprintf(stdout, "\n");
fprintf(stdout, "Dequeue done data:");
print_data(mv_queue_pop_back(pqueue));
fprintf(stdout, "\n");
mv_queue_print_data(pqueue, print_data);
mv_queue_destroy(&pqueue, delete_data);
exit(SUCCESS);
}