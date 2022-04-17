#ifndef __$__tm_stack_c
#define __$__tm_stack_c123
#include<stdio.h>
#include<stdlib.h>
#include<tm_required.h>
#include<tm_stack.h>
Stack* createStack(int *sucess)
{
Stack *stack;
int xyz;
if(sucess) *sucess=false;
stack=(Stack *)malloc(sizeof(Stack));
if(stack==NULL) return NULL;
stack->list=creatSinglyLinkedList(&xyz);
if(!xyz)
{
free(stack);
return NULL;
}
if(sucess)*sucess=true;
return stack;
}
void releaseStack(Stack *stack)
{ 
clearStack(stack);
releaseSinglyLinkedList(stack->list);
free(stack);
}
void clearStack(Stack *stack)
{ 
clearSinglyLinkedList(stack->list);
}
void pushOnStack(Stack *stack,void *ptr,int *sucess)
{ 
if(sucess) *sucess=false;
if(stack==NULL) return;
insertInSinglyLinkedList(stack->list,ptr,0,sucess);
}
void* peekInStack(Stack *stack,int *sucess)
{ 
if(sucess)*sucess=false;
if(stack==NULL) return NULL;
return getElementFromSinglyLinkedList(stack->list,0,sucess);
}
void* popFromStack(Stack *stack,int *sucess)
{ 
if(sucess)*sucess=false;
if(stack==NULL) return NULL;
return removeFromSinglyLinkedList(stack->list,0,sucess);
} 
int isStackEmpty(Stack *stack)
{ 
if(stack==NULL) return true;
return getSizeOfSinglyLinkedList(stack->list)==0;
} 
int getSizeOfStack(Stack *stack)
{
if(stack==NULL) return 0;
return getSizeOfSinglyLinkedList(stack->list);
}
#endif