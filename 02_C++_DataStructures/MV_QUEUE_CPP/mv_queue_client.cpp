
// Headers

#include <iostream>
#include "mv_queue.hpp"
MVQueue<long>* pqueue;
int main(void)
{
pqueue =new MVQueue<long>(10);
pqueue->PushBack(2);
pqueue->PushBack(4);
pqueue->PushBack(6);
pqueue->PushBack(8);
pqueue->PushBack(10);
pqueue->PushBack(12);
pqueue->PushBack(14);
pqueue->PushBack(16);
pqueue->PushBack(18);
pqueue->PushBack(20);
std::cout<<std::endl<<std::endl;
std::cout<<"Queue After Push Back."<<std::endl;
std::cout<<(*pqueue);
std::cout<<std::endl<<std::endl;
std::cout<<"Popped Data ="<<pqueue->PopFront()<<std::endl;
std::cout<<"Popped Data ="<<pqueue->PopFront()<<std::endl;
std::cout<<"Popped Data = "<<pqueue->PopFront()<<std::endl;
std::cout<< "Popped Data = "<< pqueue->PopFront()<<std::endl;
std::cout<<std::endl<<std::endl;
std::cout<<"Queue After Pop Front."<<std::endl;
std::cout<<(*pqueue);	
pqueue->PushBack(68);
pqueue->PushBack(70);
pqueue->PushBack(77);
std::cout<<std::endl<<std::endl;
std::cout<<"Queue After Push Back."<<std::endl;
std::cout<<(*pqueue);
delete(pqueue);
return(SUCCESS);
}	

