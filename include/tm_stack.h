#ifndef __$__tm_stack_h
#define __$__tm_stack_h123
#include<tm_singly.h>
typedef struct _$_stack
{
singlyLinkedList *list;
}Stack;
Stack* createStack(int *sucess);
void releaseStack(Stack *stack);
void clearStack(Stack *stack);
void pushOnStack(Stack *stack,void *ptr,int *sucess);
void* popFromStack(Stack *stack,int *sucess);
void* peekInStack(Stack *stack,int *sucess);
int isStackEmpty(Stack *stack);
int getSizeOfStack(Stack *stack);
#endif