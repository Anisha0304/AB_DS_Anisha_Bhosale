#ifndef _ND_ARRAY_H
#define _ND_ARRAY_H
#define SUCCESS 0
#define FAILURE 1

//Type Definition

struct array;
typedef struct array array_t;
typedef struct array* p_array_t;
typedef struct array** pp_array_t;
typedef void* data_t;
typedef int ret_t;
 
//Structure Type Definition

struct array
{
	data_t* ptr;   //actual array
	long* pdimensions;  //array for storing size of each dimension
	size_t no_of_dimensions;  //total no of dimensions
	size_t* to_jump_dimensions;
};
#define		SIZE_ARRAY		(sizeof(array_t))
extern p_array_t create_array(size_t no_of_dimensions,...);
extern ret_t array_set_data(p_array_t parray,data_t data, ...);
extern data_t array_get_data(p_array_t parray,...);
extern long array_get_size_of_dimension(p_array_t parray,long index);
extern ret_t array_destroy(pp_array_t pparray);
#endif   /* _ND_ARRAY_N */