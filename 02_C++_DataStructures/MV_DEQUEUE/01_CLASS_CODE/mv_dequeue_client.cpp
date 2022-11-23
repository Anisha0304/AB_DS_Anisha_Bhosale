//	Headers
#include <iostream>
#include "mv_dequeue.hpp"
MVDeQueue<long>* pdequeue =NULL;
int main(void)
{
pdequeue =new MVDeQueue<long>();
std::cout <<"Dequeue Push Back:" << std::endl;
for(int le =0;le<6;++le)
{
pdequeue->PushBack((le+1)*12);
}
std::cout << (*pdequeue);
std::cout <<"Dequeue Push Front:" << std::endl;
for(int le =0; le<6;++le)
{
pdequeue->PushFront((le+1)*17);
}
std::cout << (*pdequeue);
std::cout <<"Popped Back Data" << pdequeue->PopBack() << std::endl;
std::cout <<"Popped Back Data" << pdequeue->PopBack() << std::endl;
std::cout <<"Popped Back Data" << pdequeue->PopBack() << std::endl;
std::cout <<"Popped Back Data" << pdequeue->PopBack() << std::endl;
std::cout <<"Popped Front Data" << pdequeue->PopFront() << std::endl;
std::cout <<"Popped Front Data" << pdequeue->PopFront() << std::endl;
std::cout <<"Popped Front Data" << pdequeue->PopFront() << std::endl;
std::cout <<"Popped Front Data" << pdequeue->PopFront() << std::endl;
delete(pdequeue);
return(SUCCESS);
}

