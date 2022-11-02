#pragma once 

//Constant Literals

#ifndef SUCCESS
#define SUCCESS 0
#endif 
#ifndef FAILURE
#define FAILURE 1
#endif

//Type Definitions

class MVArray;        //Class Type Declaration
typedef void* data_t;
typedef int ret_t;

//Class Type Definition

class MVArray
{
	private:
	data_t* data_array;
	size_t* dimension_array;
	size_t no_of_dimensions;
	size_t* to_jump_dimension_array;
	public:

	//Parameterize Constructor

	MVArray(size_t no_of_dimensions,...);

	//Destuctor

	~MVArray();

//Setter Member Functions

ret_t SetData(data_t, ...);

//Getter Member Functions

data_t	GetData(...);

//Get Size Of Dimension

size_t GetDimensionSize(size_t index) const;
};


