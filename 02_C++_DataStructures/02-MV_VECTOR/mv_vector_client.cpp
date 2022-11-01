#include	<iostream>
#include	"mv_vector.hpp"

//Global Object

MVVector<long>* pvector =NULL;
int main(void)
{
pvector=new MVVector<long>();
for(long le=0;le<10;++le)
{
pvector->PushBack((le+1) * 12);
}
pvector->PushBackV(9,18,27,36,45,54,69,72,81,99,111);
std::cout<<std::endl<<std::endl;
std::cout<<"Vector Using Operator<<:"<<std::endl<<(*pvector);
std::cout<<"Vector Using Operator using pointer<<:"<<std::endl<<pvector;
std::cout<<"Using Forward Traversal"<<std::endl;
pvector->ForwardTraversal();
std::cout<<"Using Reverse Traversal"<<std::endl;
pvector->ReverseTraversal();
std::cout<<std::endl<<std::endl;
std::cout<<"Vector Pop Back:"<<std::endl;
std::cout<<"Popped Data="<<pvector->PopBack()<<std::endl;
std::cout<<"Popped Data= "<<pvector->PopBack()<<std::endl;
std::cout<<"Popped Data="<<pvector->PopBack()<<std::endl;
std::cout<<"Popped Data ="<<pvector->PopBack()<<std::endl;
std::cout<<std::endl<<std::endl;
std::cout<<"Vector Using Operator<<:"<<std::endl<<(*pvector);
delete(pvector);
pvector =NULL;
return(SUCCESS);
}
