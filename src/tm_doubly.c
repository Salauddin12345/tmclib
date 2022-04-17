#ifndef __tm__$_tm_doubly_c
#define __tm__$_tm_doubly_c234
#include<stdio.h>
#include<tm_required.h>
#include<tm_doubly.h>
#include<stdlib.h>

doublyLinkedList* creatDoublyLinkedList(int *sucess)
{
doublyLinkedList *dll;
if(sucess)*sucess=false;
dll=(doublyLinkedList*)malloc(sizeof(doublyLinkedList));
if(dll==NULL) return NULL;
if(sucess)*sucess=true;
dll->start=NULL;
dll->end=NULL;
dll->count=0;
return dll;
}

void addToDoublyLinkedList(doublyLinkedList *dll,void *ptr,int *sucess)
{
struct _$_DLL_Node *t;
if(sucess)*sucess=false;
if(dll==NULL)return;
t=(struct _$_DLL_Node *)malloc(sizeof(struct _$_DLL_Node));
if(t==NULL)return;
t->ptr=ptr;
t->next=NULL;
t->prev=NULL;
if(dll->start==NULL)
{
dll->start=dll->end=t;
}
else
{
dll->end->next=t;
t->prev=dll->end;
dll->end=t;
}
dll->count++;
if(sucess)*sucess=true;
}

void* getElementFromDoublyLinkedList(doublyLinkedList *dll,int index,int *sucess)
{
struct _$_DLL_Node *t;
int x;
void *ptr=NULL;
if(sucess)*sucess=false;
if(dll==NULL)return NULL;
if(index<0 || index >=dll->count)return NULL;
for(x=0,t=dll->start;x<index;t=t->next,x++);
ptr=t->ptr;
if(sucess)*sucess=true;
return ptr;
}

void releaseDoublyLinkedList(doublyLinkedList *dll)
{
clearDoublyLinkedList(dll);
free(dll);
}

doublyLinkedListIterator* getDoublyLinkedListIterator(doublyLinkedList *dll,int direction)
{
doublyLinkedListIterator *iterator;
if(dll==NULL)return NULL;
if(direction!=1 && direction!=2)return NULL;
iterator=(doublyLinkedListIterator*)malloc(sizeof(doublyLinkedListIterator));
iterator->direction=direction;
if(direction==1)
{
iterator->node=dll->start;
}
else
{
iterator->node=dll->end;
}
return iterator;
}
int hasMoreElementInDoublyLinkedList(doublyLinkedListIterator *iterator)
{
if(iterator==NULL)return false;
return iterator->node!=NULL;
}
void* getNextElementFromDoublyLinkedList(doublyLinkedListIterator *iterator,int *sucess)
{
void *ptr;
if(sucess)*sucess=false;
if(iterator==NULL)return NULL;
if(iterator->node==NULL)return NULL;
ptr=iterator->node->ptr;
if(iterator->direction==1)iterator->node=iterator->node->next;
else iterator->node=iterator->node->prev;
return ptr;
}
void releaseDoublyLinkedListIterator(doublyLinkedListIterator *iterator)
{
if(iterator==NULL)return NULL;
free(iterator);
}
void clearDoublyLinkedList(doublyLinkedList *dll)
{
struct _$_DLL_Node *t;
if(dll==NULL)return;
while(dll->start!=NULL)
{
t=dll->start;
dll->start=dll->start->next;
free(t);
}
}

int getSizeOfDoublyLinkedList(doublyLinkedList *dll)
{
if(dll==NULL)return 0;
return dll->count;
}
void insertInDoublyLinkedList(doublyLinkedList *dll,void *ptr,int index,int *sucess)
{
struct _$_DLL_Node *t,*p1;
int x;
if(sucess)*sucess=false;
if(dll==NULL)return;
if(index<0 || index>dll->count)return;
t=(struct _$_DLL_Node *)malloc(sizeof(struct _$_DLL_Node));
if(t==NULL)return;
t->ptr=ptr;
t->next=NULL;
t->prev=NULL;
for(x=0,p1=dll->start;x<index;p1=p1->next,x++);
if(p1==NULL)
{
if(dll->start==NULL)
{
dll->start=dll->end=t;
}
else
{
dll->end->next=t;
t->prev=dll->end;
dll->end=t;
}
dll->count++;
if(sucess)*sucess=true;
return;
}
if(p1==dll->start)
{
t->next=dll->start;
dll->start->prev=t;
dll->start=t;
dll->count++;
if(sucess)*sucess=true;
return;
}
t->next=p1;
t->prev=p1->prev;
p1->prev->next=t;
p1->prev=t;
dll->count++;
if(sucess)*sucess=true;
}
void* removeFromDoublyLinkedList(doublyLinkedList *dll,int index,int *sucess)
{
struct _$_DLL_Node *p1;
int x;
void *ptr;
if(sucess)*sucess=false;
if(dll==NULL)return NULL;
if(index<0 || index>=dll->count)return NULL;
x=0;
p1=dll->start;
while(x<index)
{
p1=p1->next;
x++;
}
ptr=p1->ptr;
if(p1==dll->start && p1==dll->end)
{
dll->start=dll->end=NULL;
}
else if(p1==dll->start)
{
dll->start=dll->start->next;
}else if(p1==dll->end)
{
dll->end=dll->end->prev;
dll->end->next=NULL;
}
else
{
p1->prev->next=p1->next;
p1->next->prev=p1->prev;
}
free(p1);
dll->count--;
if(sucess)*sucess=true;
return ptr;
} 
#endif
