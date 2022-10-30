//Headers
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "MV_VECTOR.h"
p_mv_vector_t pvector =NULL;
void print_data(p_mv_vector_t pvector)
{
	fprintf(stdout,"\n{START}-");
	for(long le=0;le<mv_vector_size(pvector); ++le)
	{
		fprintf(stdout, "{%lld}-",(int)mv_vector_data_at(pvector,le));
	}
	fprintf(stdout, "{END}\n");
}
int main(void)
{
	pvector=create_vector();
	mv_vector_push_back(pvector,(data_t)10);
	mv_vector_push_back(pvector,(data_t)20);
	mv_vector_push_back(pvector,(data_t)30);
	mv_vector_push_back(pvector,(data_t)40);
	print_data(pvector);
	printf("pvector size= %llu\n",mv_vector_size(pvector));
	printf("pvector capacity =%llu\n",mv_vector_capacity(pvector));
	mv_vector_push_back(pvector, (data_t)50);
    mv_vector_push_back(pvector,(data_t)60);
	mv_vector_push_back(pvector,(data_t)70);
	mv_vector_push_back(pvector,(data_t)80);
mv_vector_push_back(pvector,(data_t)90);
mv_vector_push_back(pvector,(data_t)100);
print_data(pvector);
printf("pvector size = %llu\n", mv_vector_size(pvector));
printf("pvector Capacity = %llu\n", mv_vector_capacity(pvector));
mv_vector_pop_back(pvector);
mv_vector_pop_back(pvector);
mv_vector_pop_back(pvector);
print_data(pvector);
printf("pvector size = %llu\n", mv_vector_size(pvector));
printf("pvector Capacity = %llu\n", mv_vector_capacity(pvector));
mv_vector_destroy(&pvector);
exit(0);
}


