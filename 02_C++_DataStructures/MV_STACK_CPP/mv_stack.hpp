#pragma	once

//Headers
#include "mv_vector.hpp"

//Constant Literals

#ifndef	SUCCESS 
#define	SUCCESS 0
#endif
#ifndef	FAILURE
#define	FAILURE 1
#endif

//Typedefs

typedef	int ret_t;
template<typename T>
class MVStack :private MVVector<T>
{
private:
public:
MVStack()
{

}
~MVStack()
{

}
ret_t Push(T data)
{
return(PushBack(data));
}
T Pop()
{
return(PopBack());
}
T Peek()
{
return((*this)[Size()-1]);
}
long Top()
{
return(Size());
}
T operator[](long index)
{
return(DataAt(index));
}
Iterator begin()
{
MVVector<T>::Iterator itr =static_cast<MVVector<T>*>(this)->begin();
return( itr );
}
Iterator end()
{
MVVector<T>::Iterator itr =static_cast<MVVector<T>*>(this)->end();
return(itr);
}
};	
template<typename T>
std::ostream& operator<<(std::ostream& out,MVStack<T>& stack)
{
out <<"Stack:"<<std::endl;
out <<"{TOP}"<< std::endl;
for(auto itr =stack.end() - 1;
itr !=stack.begin() - 1;
	--itr )
{
out << *itr << std::endl;
}
out <<"{START}"<< std::endl;
return(out);
}
