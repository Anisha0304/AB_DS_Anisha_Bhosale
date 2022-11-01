#pragma	once
#include <cstdarg>
#include "mv_base_iterator.hpp"

//Constant Literals

#ifndef	SUCCESS 
#define	SUCCESS	0
#endif
#ifndef	FAILURE
#define	FAILURE 1
#endif
#ifndef	DEFAULT_SIZE
#define	DEFAULT_SIZE	32 
#endif

//Type Declarations

template<typename T>
class MVVector;

typedef	int ret_t;

//Global Function Declarations

template<typename T>
std::ostream& operator<<(std::ostream& out,MVVector<T>& vec);
template<typename T>
std::ostream& operator<<(std::ostream& out,MVVector<T>*& vec);

//Type Definition 
template<typename T>
class MVVector
{
private:
T*	m_data_array;
size_t	m_no_of_elements;
size_t	m_capacity;

//Vector Helper Functions

bool IsArray() const
{
if(m_data_array)
return(true);
return(false);
}
public:
	
//Vector Interface Functions

//Default Constructor

MVVector()
{
this->m_capacity =DEFAULT_SIZE;
this->m_no_of_elements =0;
this->m_data_array =NULL;
m_data_array =(T*) realloc(m_data_array,DEFAULT_SIZE * sizeof(T));
if(NULL ==m_data_array)
{
std::cerr <<"ERROR:Out Of Memory." << std::endl;
exit(FAILURE);
}
memset(m_data_array, 0,DEFAULT_SIZE * sizeof(T));
}
~MVVector()
{
if(m_data_array)
{
free(m_data_array);
m_data_array =NULL;
}
}

//Push Back

ret_t PushBack(T data)
{
if(!IsArray())
{
std::cerr <<"ERROR:Vector Not Found."<< std::endl;
return(FAILURE);
}
m_data_array[m_no_of_elements]=data;
m_no_of_elements++;
if(m_no_of_elements ==m_capacity)
{
m_capacity =m_capacity * 2;
m_data_array =(T*) realloc(m_data_array, m_capacity * sizeof(T));
}
return(SUCCESS);
}
ret_t operator+(T data)
{
return(PushBack(data));
}

//Variadic Push Back

ret_t PushBackV(long no_of_values, ...)
{
va_list args;
va_start(args, no_of_values);
for(long le =0;le < no_of_values;++le)
{
(*this) + va_arg(args, T);
}
va_end(args);
return(SUCCESS);
}

//Pop Back

T PopBack()
{
if(!IsArray()	||	
0 == m_no_of_elements)
{
std::cerr <<"ERROR:Vector Not Found."<< std::endl;
return((T)0);
}
m_no_of_elements--;
T to_return_data =m_data_array[m_no_of_elements];
if(m_no_of_elements <=m_capacity/2 &&
			0 !=m_no_of_elements)
{
m_capacity /=2;
m_data_array =(T*) realloc(m_data_array, m_capacity * sizeof(T)); 
}
return(to_return_data);
}

//Retrive Data

T DataAt(long index) const
{
if( !IsArray()	||
			0 ==m_no_of_elements)
{
std::cerr <<"ERROR:Vector not found" << std::endl;
return((T)0);
}
if(index >= m_no_of_elements)
{
std::cerr <<"ERROR:Index out of bound." << std::endl;
return((T)0);
}
return(m_data_array[index]);
}

//Getter Of Size
	
size_t Size() const
{
return(m_no_of_elements);
}

//Getter Of Capacity

size_t Capacity() const
{
return(m_capacity);
}
T operator[](long index) const
{
return(DataAt(index));
}
ret_t Replace(long index, T data)
{

}
ret_t Insert(long index, T data)
{
}
T Remove(long index)
{
}

//Inner Iterator Class

class Iterator :public mv_base_iterator<T>
{
private:
T*	m_data_ptr;
public:
Iterator(T* data_ptr)
{
this->m_data_ptr =data_ptr;
}
~Iterator()
{
this->m_data_ptr =NULL;
}

//Per Increment & Post Increment

//Pre Increment

Iterator& operator++()
{
this->m_data_ptr++;
return(*this);
}

//Post Increment
Iterator operator++(int value)
{
Iterator itr = *this;
	++*this;
return(itr);
}

//Pre Decrement

Iterator& operator--()
{
m_data_ptr--;
return(*this);
}

//Post Decrement

Iterator operator--(int value)
{
Iterator itr = *this;
			--*this;
return(itr);
}
Iterator operator+(int value)
{
Iterator itr =Iterator(m_data_ptr + value);
return(itr);
}
Iterator operator-(int value)
{
Iterator itr =Iterator(m_data_ptr - value);
return(itr);
}
Iterator& operator+=(int value)
{
this->m_data_ptr +=value;
return(*this);
}
Iterator& operator-=(int value)
{
this->m_data_ptr -=value;
return(*this);
}
bool operator!=(Iterator& itr)
{
return( !((*this) ==itr));
//return( this->m_data_ptr != itr->m_data_ptr );
}
bool operator==(Iterator& itr)
{
return(this->m_data_ptr ==itr.m_data_ptr);
}
T operator*()
{
return(*m_data_ptr);
}
};
Iterator begin()
{
return(Iterator(m_data_array));
}
Iterator end()
{
return(Iterator(&m_data_array[m_no_of_elements]));
}
void ForwardTraversal()
{
std::cout << (*this);
}
void ReverseTraversal()
{
std::cout << this;
}
};

template<typename T>
std::ostream& operator<<(std::ostream& out, MVVector<T>& vec)
{
for(auto itr = vec.begin();
	     itr != vec.end();
	     ++itr )
{
std::cout << *itr << std::endl;
}
return(out);
}
template<typename T>
std::ostream& operator<<(std::ostream& out, MVVector<T>*& vec)
{
for(auto itr = vec->end()-1;
	     itr != vec->begin()-1;
	     itr-- )
{
std::cout << *itr << std::endl;
}
return(out);
}
template<typename T>
std::ostream& operator<<(std::ostream& out, MVVector<T>*&& vec)
{
for(auto itr = vec->end()-1;
	     itr != vec->begin()-1;
	     itr--)
{
std::cout << *itr << std::endl;
}
return(out);
}