#ifndef __tm__$_tm_doubly_h
#define __tm__$_tm_doubly_h234
struct _$_DLL_Node
{
void *ptr;
struct _$_DLL_Node *next;
struct _$_DLL_Node *prev;
};

typedef struct _$_doublyLinkedList
{
struct _$_DLL_Node *start;
struct _$_DLL_Node *end;
int count;
}doublyLinkedList;

typedef struct __$_doublyLinkedListIterator
{
struct _$_DLL_Node *node;
int direction;
}doublyLinkedListIterator;

doublyLinkedList* creatDoublyLinkedList(int *sucess);
void addToDoublyLinkedList(doublyLinkedList *sll,void *ptr,int *sucess);
doublyLinkedListIterator* getDoublyLinkedListIterator(doublyLinkedList *sll,int direction);
int hasMoreElementInDoublyLinkedList(doublyLinkedListIterator *iterator);
void* getNextElementFromDoublyLinkedList(doublyLinkedListIterator *iterator,int *sucess);
void releaseDoublyLinkedListIterator(doublyLinkedListIterator *iterator);
void* getElementFromDoublyLinkedList(doublyLinkedList *sll,int index,int *sucess);
void releaseDoublyLinkedList(doublyLinkedList *sll);
void clearDoublyLinkedList(doublyLinkedList *sll);
int getSizeOfDoublyLinkedList(doublyLinkedList *sll);
void insertInDoublyLinkedList(doublyLinkedList *sll,void *ptr,int index,int *sucess);
void* removeFromDoublyLinkedList(doublyLinkedList *sll,int index,int *sucess);
#endif
