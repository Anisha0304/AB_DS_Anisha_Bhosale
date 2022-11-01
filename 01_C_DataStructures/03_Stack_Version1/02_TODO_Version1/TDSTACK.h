#ifndef  _MV_STACK_h
#define _MV_STACK_h
#ifndef SUCCESS 
#define SUCCESS 0
#ifndef FAILURE 
#define FAILURE 1
#endif

//Type Definitions

struct mv_stack;
typedef struct mv_stack mv_stack_t;
typedef struct mv_stack* p_mv_stack_t;
typedef struct mv_stack** pp_mv_stack_t;
typedef 	void*	data_t;
typedef int ret_t;

//Struct Type Definition

struct mv_stack
{
	p_mv_stack_t  pstack;
};
#define SIZE_STACK (sizeof(mv_stack_t))

extern p_mv_stack_t create_stack(void);
extern ret_t mv_stack_pop(p_mv_stack_t pstack);
extern data_t mv_stack_pop(p_mv_stack_t pstack);
extern data_t mv_stack_peek(p_mv_stack_t pstack);
extern void mv_stack_print(pp_mv_stack_t pstack,void (*pPrintDataFunc) (data_t) );
extern ret_t mv_stack_destroy(pp_mv_stack_t ppstack);
#endif
