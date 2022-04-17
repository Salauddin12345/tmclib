#ifndef __$__tm_queue_c
#define __$__tm_queue_c123
#include<stdio.h>
#include<stdlib.h>
#include<tm_required.h>
#include<tm_queue.h>
Queue* createQueue(int *sucess)
{
Queue *queue;
int xyz;
if(sucess) *sucess=false;
queue=(Queue *)malloc(sizeof(Queue));
if(queue==NULL) return NULL;
queue->list=creatSinglyLinkedList(&xyz);
if(!xyz)
{
free(queue);
return NULL;
}
if(sucess)*sucess=true;
return queue;
}
void releaseQueue(Queue *queue)
{ 
releaseSinglyLinkedList(queue->list);
free(queue);
}
void clearQueue(Queue *queue)
{ 
clearSinglyLinkedList(queue->list);
}
void addToQueue(Queue *queue,void *ptr,int *sucess)
{ 
if(sucess) *sucess=false;
if(queue==NULL) return;
addToSinglyLinkedList(queue->list,ptr,sucess);
}
void* peekInQueue(Queue *queue,int *sucess)
{ 
if(sucess)*sucess=false;
if(queue==NULL) return NULL;
return getElementFromSinglyLinkedList(queue->list,0,sucess);
}
void* removeFromQueue(Queue *queue,int *sucess)
{ 
if(sucess)*sucess=false;
if(queue==NULL) return NULL;
return removeFromSinglyLinkedList(queue->list,0,sucess);
} 
int isQueueEmpty(Queue *queue)
{ 
if(queue==NULL) return true;
return getSizeOfSinglyLinkedList(queue->list)==0;
} 
int getSizeOfQueue(Queue *queue)
{
if(queue==NULL) return 0;
return getSizeOfSinglyLinkedList(queue->list);
}
#endif