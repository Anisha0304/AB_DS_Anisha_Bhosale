#include <stdio.h> 
#include <stdlib.h>
#include "TDSTACK.h" 
#define SIZE 20  
int array[SIZE];                      //Declaration Of Array Type Variable.  
int top1 =-1;  
int top2 =SIZE;  
   
//Function To Push Data Into Stack1  

void push1(int data)  
{  

//Checking The Overflow Condition  

if(top1 < top2 - 1)  
{  
top1++;  
array[top1] = data;  
}  
else  
{  
printf("Stack is full");  
}  
}  

//Function To Push Data Into Stack2  

void push2(int data)  
{  
// checking overflow condition    
if (top1 < top2 - 1)  
{  
top2--;  
array[top2] =data;   
}  
else  
{  
printf("Stack is full..\n");  
}  
}  
   
//Function To Pop Data From The Stack1  

void pop1()  
{  

//Checking The Underflow Condition   
 
if(top1 >= 0)  
{  
int popped_element = array[top1];  
top1--;  
printf("%d is being popped from Stack 1\n", popped_element);  
}  
else  
{  
printf("Stack is Empty \n");  
}  
}  

//Function To Remove The Element From The Stack2  

void pop2()  
{  

//Checking Underflow Condition    

if(top2 < SIZE)  
{  
int popped_element = array[top2];  
top2--;  
printf("%d is being popped from Stack 1\n", popped_element);  
}  
else  
{  
printf("Stack is Empty!\n");  
}  
}  
   
//Functions To Print The Values Of Stack1  

void display_stack1()  
{  
int i;  
for(i = top1; i >= 0; --i)  
{  
printf("%d ", array[i]);  
}  
printf("\n");  
}  

//Function To Print The Values Of Stack2  

void display_stack2()  
{  
int i;  
for(i = top2; i < SIZE; ++i)  
{  
printf ("%d ", array[i]);  
}  
printf ("\n");  
}  
int main()  
{  
int ar[SIZE];  
int i;  
int num_of_ele;  
printf("We can push a total of 20 values\n");  

//Number Of Elements Pushed In Stack 1 is 10  
//Number Of Elements Pushed In Stack 2 is 10  
// Loop To Insert The Elements Into Stack1    

for(i = 1; i <= 10; ++i)  
{  
push1(i);  
printf("Value Pushed in Stack 1 is %d\n", i);  
}  

// Loop To Insert The Elements Into Stack2.    

for(i = 11; i <= 20; ++i)  
{  
push2(i);  
printf("Value Pushed in Stack 2 is %d\n", i);  
}  
   
//Print Both Stacks  

display_stack1();  
display_stack2();  
   
//Pushing On Stack Full  
  
printf("Pushing Value in Stack 1 is %d\n", 11);  
push1 (11);  
   
//Popping All Elements from Stack 1  
num_of_ele = top1 + 1;  
while (num_of_ele)  
{  
pop1 ();  
--num_of_ele;  
}  
   
//Trying To Pop The Element From The Empty Stack  

pop1();  
return 0;  
}  