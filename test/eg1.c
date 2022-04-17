
#include<stdio.h>
#include<tm_stack.h>
int main()
{
int success;
Stack *stack=createStack(&success);
int x,y,z;
int *p;
x=1;
y=2;
z=3;
pushOnStack(stack,&x,&success);
pushOnStack(stack,&y,&success);
pushOnStack(stack,&z,&success);
while(!isStackEmpty(stack))
{
p=popFromStack(stack,&success);
printf("%d\n",*p);
}


return 0;
}