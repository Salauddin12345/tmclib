#include<tm_singly.h>
#include<tm_required.h>
#include<stdio.h>
struct abc
{
int x,y;
char m;
};
int main()
{
int s;
struct abc a1,a2,a3;
struct abc *g;
singlyLinkedListIterator *iii;
singlyLinkedList *list=creatSinglyLinkedList(&s);
if(s==false)
{
printf("unable to creat singly Linked list");
return 0;
}
a1.x=10;
a1.y=20;
a1.m='a';
a2.x=100;
a2.y=200;
a2.m='b';
a3.x=1000;
a3.y=2000;
a3.m='c';
addToSinglyLinkedList(list,&a1,&s);
addToSinglyLinkedList(list,&a2,&s);
addToSinglyLinkedList(list,&a3,&s);
iii=getSinglyLinkedListIterator(list);
while(hasMoreElementInSinglyLinkedList(iii))
{
g=(struct abc*)getNextElementFromSinglyLinkedList(iii,&s);
printf("%d %d %c\n",g->x,g->y,g->m);
}
releaseSinglyLinkedListIterator(iii);
return 0;
}