#ifndef __tm__$_tm_singly_h
#define __tm__$_tm_singly_h234
struct _$_SLL_Node
{
void *ptr;
struct _$_SLL_Node *next;
};

typedef struct _$_singlyLinkedList
{
struct _$_SLL_Node *start;
struct _$_SLL_Node *end;
int count;
}singlyLinkedList;

typedef struct __$_singlyLinkedListIterator
{
struct _$_SLL_Node *node;
}singlyLinkedListIterator;

singlyLinkedList* creatSinglyLinkedList(int *sucess);
void addToSinglyLinkedList(singlyLinkedList *sll,void *ptr,int *sucess);
singlyLinkedListIterator* getSinglyLinkedListIterator(singlyLinkedList *sll);
int hasMoreElementInSinglyLinkedList(singlyLinkedListIterator *iterator);
void* getNextElementFromSinglyLinkedList(singlyLinkedListIterator *iterator,int *sucess);
void releaseSinglyLinkedListIterator(singlyLinkedListIterator *iterator);
void* getElementFromSinglyLinkedList(singlyLinkedList *sll,int index,int *sucess);
void releaseSinglyLinkedList(singlyLinkedList *sll);
void clearSinglyLinkedList(singlyLinkedList *sll);
int getSizeOfSinglyLinkedList(singlyLinkedList *sll);
void insertInSinglyLinkedList(singlyLinkedList *sll,void *ptr,int index,int *sucess);
void* removeFromSinglyLinkedList(singlyLinkedList *sll,int index,int *sucess);
#endif
