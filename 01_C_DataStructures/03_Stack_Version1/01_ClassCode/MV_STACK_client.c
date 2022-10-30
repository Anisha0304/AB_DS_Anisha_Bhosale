//Header

#include <stdio.h>
#include <stdlib.h>
#include "MV_STACK.h"
struct Demo
{
	long lnum1;
	char ch;
};
#define SIZE_DEMO (sizeof(struct Demo))
typedef struct Demo demo_t;
typedef struct Demo* p_demo_t;
p_mv_stack_t pstack_int =NULL;
p_mv_stack_t pstack_demo =NULL;
void print_data_int(data_t data)
{
	fprintf(stdout,"%lld",(int) data);
}
void print_data_demo(data_t data)
{
	p_demo_t pdemo=(p_demo_t)data;
	fprintf(stdout, "{%ld | %c}",pdemo->lnum1,pdemo->ch);
	//fprintf(stdout,"%p",pdemo);
}
int main(void)
{
	pstack_int =create_stack();

	                    //STACK FOR INTEGER DATA

mv_stack_push(pstack_int, (data_t) 10);
mv_stack_push(pstack_int, (data_t) 20);
mv_stack_push(pstack_int, (data_t) 30);
mv_stack_push(pstack_int, (data_t) 40);
mv_stack_push(pstack_int, (data_t) 50);
mv_stack_push(pstack_int, (data_t) 60);

//Stack Print;

mv_stack_print(pstack_int,print_data_int);
fprintf(stdout,"popped data:");
print_data_int(mv_stack_pop(pstack_int));
fprintf(stdout,"\n");
fprintf(stdout,"popped data:");
print_data_int(mv_stack_pop(pstack_int));
fprintf(stdout,"\n");
fprintf(stdout,"popped data:");
print_data_int(mv_stack_pop(pstack_int));
fprintf(stdout,"\n");
mv_stack_print(pstack_int,print_data_int);
mv_stack_destroy(&pstack_int);
mv_stack_print(pstack_int,print_data_int);

                      //STACK FOR USER DEFINED STRUCT DEMO

pstack_demo =create_stack();

//Push Demo Data

p_demo_t pdemo=(p_demo_t)malloc(SIZE_DEMO);
pdemo->lnum1=100;
pdemo->ch='A';
mv_stack_push(pstack_demo,pdemo);
pdemo=(p_demo_t)malloc(SIZE_DEMO);
pdemo->lnum1=150;
pdemo->ch='N';
mv_stack_push(pstack_demo,pdemo);
pdemo=(p_demo_t)malloc(SIZE_DEMO);
pdemo->lnum1=200;
pdemo->ch='I';
mv_stack_push(pstack_demo,pdemo);
pdemo=(p_demo_t)malloc(SIZE_DEMO);
pdemo->lnum1=250;
pdemo->ch='S';
mv_stack_push(pstack_demo,pdemo);
pdemo=(p_demo_t)malloc(SIZE_DEMO);
pdemo->lnum1=300;
pdemo->ch='H';
mv_stack_push(pstack_demo,pdemo);
pdemo=(p_demo_t)malloc(SIZE_DEMO);
pdemo->lnum1=350;
pdemo->ch='A';
mv_stack_push(pstack_demo,pdemo);
pdemo=(p_demo_t)malloc(SIZE_DEMO);
pdemo->lnum1=400;
pdemo->ch='V';
mv_stack_push(pstack_demo,pdemo);
pdemo=(p_demo_t)malloc(SIZE_DEMO);
pdemo->lnum1=450;
pdemo->ch='B';
mv_stack_push(pstack_demo,pdemo);

//Print Demo Data

mv_stack_print(pstack_demo,print_data_demo);

//Pop Demo Data

pdemo=mv_stack_pop(pstack_demo);
fprintf(stdout,"popped data:");
print_data_demo(pdemo);
fprintf(stdout,"\n");
if(pdemo)
{
	free(pdemo);
	pdemo = NULL;
};
pdemo=mv_stack_pop(pstack_demo);
fprintf(stdout,"popped data:");
print_data_demo(pdemo);
fprintf(stdout,"\n");
if(pdemo)
{
	free(pdemo);
	pdemo = NULL;
		}
pdemo=mv_stack_pop(pstack_demo);
fprintf(stdout,"popped data:");
print_data_demo(pdemo);
fprintf(stdout,"\n");
if(pdemo)
{
	free(pdemo);
	pdemo = NULL;
		}
pdemo=mv_stack_pop(pstack_demo);
fprintf(stdout,"popped data:");
print_data_demo(pdemo);
fprintf(stdout,"\n");
if(pdemo)
{
	free(pdemo);
	pdemo = NULL;
		}	
mv_stack_print(pstack_demo,print_data_demo);
mv_stack_destroy(&pstack_demo);
mv_stack_print(pstack_demo,print_data_demo);
exit(SUCCESS);
}



