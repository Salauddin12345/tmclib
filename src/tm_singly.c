#ifndef __tm__$_tm_singly_c
#define __tm__$_tm_singly_c234
#include<stdio.h>
#include<tm_required.h>
#include<tm_singly.h>
#include<stdlib.h>

singlyLinkedList* creatSinglyLinkedList(int *sucess)
{
singlyLinkedList *sll;
if(sucess)*sucess=false;
sll=(singlyLinkedList*)malloc(sizeof(singlyLinkedList));
if(sll==NULL) return NULL;
if(sucess)*sucess=true;
sll->start=NULL;
sll->end=NULL;
sll->count=0;
return sll;
}

void addToSinglyLinkedList(singlyLinkedList *sll,void *ptr,int *sucess)
{
struct _$_SLL_Node *t;
if(sucess)*sucess=false;
if(sll==NULL)return;
t=(struct _$_SLL_Node *)malloc(sizeof(struct _$_SLL_Node));
if(t==NULL)return;
t->ptr=ptr;
t->next=NULL;
if(sll->start==NULL)
{
sll->start=sll->end=t;
sll->end=t;
}
else
{
sll->end->next=t;
sll->end=t;
}
sll->count++;
if(sucess)*sucess=true;
}

void* getElementFromSinglyLinkedList(singlyLinkedList *sll,int index,int *sucess)
{
struct _$_SLL_Node *t;
int x;
void *ptr=NULL;
if(sucess)*sucess=false;
if(sll==NULL)return NULL;
if(index<0 || index >=sll->count)return NULL;
for(x=0,t=sll->start;x<index;t=t->next,x++);
ptr=t->ptr;
if(sucess)*sucess=true;
return ptr;
}

void releaseSinglyLinkedList(singlyLinkedList *sll)
{
clearSinglyLinkedList(sll);
free(sll);
}

singlyLinkedListIterator* getSinglyLinkedListIterator(singlyLinkedList *sll)
{
singlyLinkedListIterator *iterator;
if(sll==NULL)return NULL;
iterator=(singlyLinkedListIterator*)malloc(sizeof(singlyLinkedListIterator));
iterator->node=sll->start;
return iterator;
}
int hasMoreElementInSinglyLinkedList(singlyLinkedListIterator *iterator)
{
if(iterator==NULL)return false;
return iterator->node!=NULL;
}
void* getNextElementFromSinglyLinkedList(singlyLinkedListIterator *iterator,int *sucess)
{
void *ptr;
if(sucess)*sucess=false;
if(iterator==NULL)return NULL;
if(iterator->node==NULL)return NULL;
ptr=iterator->node->ptr;
iterator->node=iterator->node->next;
return ptr;
}
void releaseSinglyLinkedListIterator(singlyLinkedListIterator *iterator)
{
if(iterator==NULL)return NULL;
free(iterator);
}
void clearSinglyLinkedList(singlyLinkedList *sll)
{
struct _$_SLL_Node *t;
if(sll==NULL)return;
while(sll->start!=NULL)
{
t=sll->start;
sll->start=sll->start->next;
free(t);
}
}

int getSizeOfSinglyLinkedList(singlyLinkedList *sll)
{
if(sll==NULL)return 0;
return sll->count;
}
void insertInSinglyLinkedList(singlyLinkedList *sll,void *ptr,int index,int *sucess)
{
struct _$_SLL_Node *t,*p1,*p2;
int x;
if(sucess)*sucess=false;
if(sll==NULL)return;
if(index<0 || index>sll->count)return;
t=(struct _$_SLL_Node *)malloc(sizeof(struct _$_SLL_Node));
if(t==NULL)return;
t->ptr=ptr;
t->next=NULL;
for(x=0,p1=sll->start;x<index;p1=p1->next,x++)p2=p1;
if(p1==NULL)
{
if(sll->start==NULL)
{
sll->start=sll->end=t;
}
else
{
sll->end->next=t;
sll->end=t;
}
sll->count++;
if(sucess)*sucess=true;
return;
}
if(p1==sll->start)
{
t->next=sll->start;
sll->start=t;
sll->count++;
if(sucess)*sucess=true;
return;
}
t->next=p1;
p2->next=t;
sll->count++;
if(sucess)*sucess=true;
}
void* removeFromSinglyLinkedList(singlyLinkedList *sll,int index,int *sucess)
{
struct _$_SLL_Node *p1,*p2;
int x;
void *ptr;
if(sucess)*sucess=false;
if(sll==NULL)return NULL;
if(index<0 || index>=sll->count)return NULL;
x=0;
p1=sll->start;
while(x<index)
{
p2=p1;
p1=p1->next;
x++;
}
ptr=p1->ptr;
if(p1==sll->start && p1==sll->end)
{
sll->start=sll->end=NULL;
}
else if(p1==sll->start)
{
sll->start=sll->start->next;
}else if(p1==sll->end)
{
sll->end=p2;
sll->end->next=p2;
}
else
{
p2->next=p1->next;
}
free(p1);
sll->count--;
if(sucess)*sucess=true;
return ptr;
} 
#endif
