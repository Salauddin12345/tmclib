#include<stdio.h>
#include<stdlib.h>
#include<tm_stack.h>
struct Node
{
int num;
struct Node *left;
struct Node *right;
};
struct Node *root;
void insertInTree(int num)
{
struct Node *t,*j;
if(root==NULL)
{
t=(struct Node *)malloc(sizeof(struct Node));
t->num=num;
t->left=t->right=NULL;
root=t;
printf("data added\n");
return;
}
j=root;
while(1)
{
if(num==j->num)break;
if(num<j->num)
{
if(j->left==NULL)
{
t=(struct Node *)malloc(sizeof(struct Node));
t->num=num;
t->left=t->right=NULL;
j->left=t;
printf("data added\n");
break;
}
else
{
j=j->left;
}
}
else
{
if(j->right==NULL)
{
t=(struct Node *)malloc(sizeof(struct Node));
t->num=num;
t->left=t->right=NULL;
j->right=t;
printf("data added\n");
break;
}
else
{
j=j->right;
}
}
}
}
void inOrderTraversal()
{
struct Node *t,*node;
int success;
Stack *stack=createStack(&success);
for(t=root;t!=NULL;t=t->left)pushOnStack(stack,t,&success);
while(!isStackEmpty(stack))
{
node=(struct Node *)popFromStack(stack,&success);
printf("%d\n",node->num);
for(t=node->right;t!=NULL;t=t->left)pushOnStack(stack,t,&success);
}
}
void removeFromTree(int num)
{
struct Node *t,*j;
struct Node *k,*rr;
struct Node **p2p;
t=root;
while(t!=NULL)
{
if(num==t->num)break;
j=t;
if(num<t->num)t=t->left;
else t=t->right;
}
if(t==NULL)
{
printf("invalid number %d\n",num);
return;
}
if(t==root)
{
p2p=&root;
}
else
{
if(t==j->left)
{
p2p=&(j->left);
}
else
{
p2p=&(j->right);
}
}
if(t->left==NULL && t->right==NULL)
{
*p2p=NULL;
free(t);
printf("data deleted\n");
return;
}
if(t->right!=NULL)
{
for(k=t->right;k->left!=NULL;k=k->left)rr=k;
k->left=t->left;
if(t->right!=k)
{
rr->left=k->right;
k->right=t->right;
}
}
else
{
for(k=t->left;k->right!=NULL;k=k->right)rr=k;
k->right=t->right;
if(t->right!=k)
{
rr->right=k->left;
k->left=t->left;
}
}
*p2p=k;
free(t);
printf("student deleted\n");
}
int main()
{
int ch,num;
root=NULL;
while(1)
{
printf("1.insert In Tree\n");
printf("2.in-order traversal\n");
printf("3.remove From Tree\n");
printf("4.exit\n");
printf("enter your choice:");
scanf("%d",&ch);
fflush(stdin);
if(ch==1)
{
printf("enter number to add in tree:");
scanf("%d",&num);
fflush(stdin);
insertInTree(num);
}
if(ch==2)inOrderTraversal();
if(ch==3)
{
printf("enter number to delete form tree:");
scanf("%d",&num);
fflush(stdin);
removeFromTree(num);
}
if(ch==4)break;
}
return 0;
}