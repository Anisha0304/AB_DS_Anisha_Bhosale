#ifndef	 _mv_vector_h
#define	 _mv_vector_h

//Constant Literals 

#ifndef  SUCCESS
#define	 SUCCESS 0
#endif

#ifndef FAILURE
#define	FAILURE 1
#endif

//Type Definitions

struct mv_vector;
typedef	 struct mv_vector 	mv_vector_t;
typedef	 struct mv_vector*	p_mv_vector_t;
typedef	 struct mv_vector**	pp_mv_vector_t;
typedef	void*	data_t;
typedef data_t*	p_data_t;
#define SIZE_DATA	(sizeof(data_t))
typedef	int ret_t;
struct mv_vector
{
p_data_t	array;
size_t	nr_of_elements;
size_t	capacity;	
};
#define SIZE_MV_VECTOR	(sizeof(mv_vector_t))

//Vector Interface Functions

extern p_mv_vector_t create_vector(void);
extern ret_t mv_vector_push_back(p_mv_vector_t, data_t);
extern data_t mv_vector_pop_back(p_mv_vector_t);
extern data_t mv_vector_data_at(p_mv_vector_t, size_t);
extern size_t mv_vector_size(p_mv_vector_t);
extern size_t mv_vector_capacity(p_mv_vector_t);
extern ret_t mv_vector_destroy(pp_mv_vector_t);
#endif		