//	Header
#include	<stdio.h>
#include	<stdlib.h>

#include	"TDSTACK.h"

struct Demo
{
	long	lnum1;
	char 	ch;
};
#define		SIZE_DEMO		(sizeof(struct Demo))
typedef	struct Demo 	demo_t;
typedef	struct Demo* 	p_demo_t;

p_mv_stack_t	pstack_int = NULL;

p_mv_stack_t 	pstack_demo = NULL;

void print_data_int(data_t data)
{
	// Code
	fprintf(stdout,"%lld", (int) data);
}

void print_data_demo(data_t data)
{
	//	Code
	p_demo_t pdemo = (p_demo_t)data;

	fprintf(stdout, "{%ld | %c}", pdemo->lnum1, pdemo->ch);
	//fprintf(stdout, "%p", pdemo);
}

int main(void)
{
	//	Code

	pstack_int = create_stack();

//STACK FOR INTEGER DATA

mv_stack_push(pstack_int, (data_t) 1);
mv_stack_push(pstack_int, (data_t) 2);
mv_stack_push(pstack_int, (data_t) 3);
mv_stack_push(pstack_int, (data_t) 4);
mv_stack_push(pstack_int, (data_t) 5);
mv_stack_push(pstack_int, (data_t) 6);
mv_stack_push(pstack_int, (data_t) 7);
mv_stack_push(pstack_int, (data_t) 8);
mv_stack_push(pstack_int, (data_t) 9);
mv_stack_push(pstack_int, (data_t) 10);

mv_stack_print(pstack_int, print_data_int);

fprintf(stdout, "popped data:");
print_data_int( mv_stack_pop(pstack_int) );
fprintf(stdout, "\n");
	
fprintf(stdout, "popped data:");
print_data_int( mv_stack_pop(pstack_int) );
fprintf(stdout, "\n");
	
fprintf(stdout, "popped data:");
print_data_int( mv_stack_pop(pstack_int) );
fprintf(stdout, "\n");

mv_stack_print(pstack_int, print_data_int);
mv_stack_destroy(&pstack_int);
mv_stack_print(pstack_int, print_data_int);

pstack_demo = create_stack();

	//	Push Demo Data
	p_demo_t pdemo = (p_demo_t)malloc(SIZE_DEMO);
	pdemo->lnum1 = 1;
	mv_stack_push(pstack_demo, pdemo);

	pdemo = (p_demo_t)malloc(SIZE_DEMO);
	pdemo->lnum1 = 2;
	mv_stack_push(pstack_demo, pdemo);

	pdemo = (p_demo_t)malloc(SIZE_DEMO);
	pdemo->lnum1 = 3;
	mv_stack_push(pstack_demo, pdemo);

	pdemo = (p_demo_t)malloc(SIZE_DEMO);
	pdemo->lnum1 = 4;
	mv_stack_push(pstack_demo, pdemo);

	pdemo = (p_demo_t)malloc(SIZE_DEMO);
	pdemo->lnum1 = 5;
	mv_stack_push(pstack_demo, pdemo);

	pdemo = (p_demo_t)malloc(SIZE_DEMO);
	pdemo->lnum1 = 6;
	mv_stack_push(pstack_demo, pdemo);

	pdemo = (p_demo_t)malloc(SIZE_DEMO);
	pdemo->lnum1 = 7;
	mv_stack_push(pstack_demo, pdemo);

	pdemo = (p_demo_t)malloc(SIZE_DEMO);
	pdemo->lnum1 = 8;
	mv_stack_push(pstack_demo, pdemo);

pdemo = (p_demo_t)malloc(SIZE_DEMO);
	pdemo->lnum1 = 9;
	mv_stack_push(pstack_demo, pdemo);

	pdemo = (p_demo_t)malloc(SIZE_DEMO);
	pdemo->lnum1 = 10;
	mv_stack_push(pstack_demo, pdemo);

	mv_stack_print(pstack_demo, print_data_demo);

	//	Pop Demo Data
	pdemo = mv_stack_pop(pstack_demo);
	fprintf(stdout, "popped data:");
	print_data_demo( pdemo );
	fprintf(stdout, "\n");
	if( pdemo )
	{
		free(pdemo);
		pdemo = NULL;
	};

	pdemo = mv_stack_pop(pstack_demo);
	fprintf(stdout, "popped data:");
	print_data_demo( pdemo );
	fprintf(stdout, "\n");
	if( pdemo )
	{
		free(pdemo);
		pdemo = NULL;
	}
	

	pdemo = mv_stack_pop(pstack_demo);
	fprintf(stdout, "popped data:");
	print_data_demo( pdemo );
	fprintf(stdout, "\n");
	if( pdemo )
	{
		free(pdemo);
		pdemo = NULL;
	}

	pdemo = mv_stack_pop(pstack_demo);
	fprintf(stdout, "popped data:");
	print_data_demo( pdemo );
	fprintf(stdout, "\n");
	if( pdemo )
	{
		free(pdemo);
		pdemo = NULL;
	}

	mv_stack_print(pstack_demo, print_data_demo);

	mv_stack_destroy(&pstack_demo);

	mv_stack_print(pstack_demo, print_data_demo);

	exit(SUCCESS);
}

