#ifndef __$__tm_queue_h
#define __$__tm_queue_h123
#include<tm_singly.h>
typedef struct _$_queue
{
singlyLinkedList *list;
}Queue;
Queue* creatQueue(int *sucess);
void releaseQueue(Queue *queue);
void clearQueue(Queue *queue);
void addToQueue(Queue *queue,void *ptr,int *sucess);
void* removeFromQueue(Queue *queue,int *sucess);
void* peekInQueue(Queue *queue,int *sucess);
int isQueueEmpty(Queue *queue);
int getSizeOfQueue(Queue *queue);
#endif