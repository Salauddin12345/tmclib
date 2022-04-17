#include<tm_doubly.h>
#include<tm_required.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student
{
int rollNumber;
char *name;
};
void addStudent(doublyLinkedList *list)
{
int rollNumber,sucess;
char name[22];
struct student *s;
doublyLinkedListIterator *iterator;
struct student *p;
int found,iii;
char m;
int direction=1;
printf("enter roll number:");
scanf("%d",&rollNumber);
fflush(stdin);
if(rollNumber<=0)
{
printf("invalid roll number\n");
return;
}
found=0;
iterator=getDoublyLinkedListIterator(list,direction);
while(hasMoreElementInDoublyLinkedList(iterator))
{
p=(struct student *)getNextElementFromDoublyLinkedList(iterator,&iii);
if(rollNumber==p->rollNumber)
{
found=1;
break;
}
}
if(found==1)
{
printf("that roll number is alloted to %s\n",p->name);
return;
}
printf("enter name:");
fgets(name,22,stdin);
fflush(stdin);
name[strlen(name)-1]='\0';
printf("save(y/n):");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("student not added\n");
return;
}
s=(struct student *)malloc(sizeof(struct student));
if(s==NULL)
{
printf("insufficient space\n");
return;
}
s->name=(char *)malloc(sizeof(char)*(strlen(name)+1));
if(s->name==NULL)
{
free(s);
printf("insufficient memory\n");
return;
}
s->rollNumber=rollNumber;
strcpy(s->name,name);
addToDoublyLinkedList(list,s,&sucess);
if(!sucess)
{
free(s->name);
free(s);
printf("insufficient memory\n");
return;
}
printf("student added,press enter to contiue....");
getchar();
fflush(stdin);
}

void displayListOfStudents(doublyLinkedList *list)
{
struct student *s;
int sucess;
int direction;
doublyLinkedListIterator *iterator;
printf("press 1 to travese top to bottom\npress 2 to traverse bottom to top\nenter your choice:");
scanf("%d",&direction);
fflush(stdin);
iterator=getDoublyLinkedListIterator(list,direction);
while(hasMoreElementInDoublyLinkedList(iterator))
{
s=(struct student *)getNextElementFromDoublyLinkedList(iterator,&sucess);
printf("%d,%s\n",s->rollNumber,s->name);
}
}

void removeStudent(doublyLinkedList *list)
{
int rollNumber,sucess;
int found,pos,iii;
int direction=1;
struct student *p;
char m;
doublyLinkedListIterator *iterator;
printf("enter rollNumber:");
scanf("%d",&rollNumber);
fflush(stdin);
if(rollNumber<=0)
{
printf("invalid input\n");
return;
}
found=0;
pos=0;
iterator=getDoublyLinkedListIterator(list,direction);
while(hasMoreElementInDoublyLinkedList(iterator))
{
p=(struct student *)getNextElementFromDoublyLinkedList(iterator,&iii);
if(p->rollNumber==rollNumber)
{
found=1;
break;
}
pos++;
}
if(found==0)
{
printf("invalid roll Number\n");
return;
}
printf("name:%s\n",p->name);
printf("do you want to delete it (y/n):");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("student not deleted\n");
return;
}
p=(struct student *)removeFromDoublyLinkedList(list,pos,&sucess);
if(!sucess)
{
printf("student not deleted\n");
return;
}
printf("student deleted, press enter to continue....");
getchar();
fflush(stdin);
}

void displaySize(doublyLinkedList *list)
{
int size;
size=getSizeOfDoublyLinkedList(list);
printf("size is :%d\n",size);
}

void clearListOfStudents(doublyLinkedList *list)
{
clearDoublyLinkedList(list);
}

void insertInList(doublyLinkedList *list)
{
int rollNumber,sucess,iii,pos,found;
char name[22];
doublyLinkedListIterator *iterator;
struct student *s;
struct student *p;
char m;
int direction;
printf("enter roll number:");
scanf("%d",&rollNumber);
fflush(stdin);
if(rollNumber<=0)
{
printf("invalid roll number\n");
return;
}
iterator=getDoublyLinkedListIterator(list,direction);
while(hasMoreElementInDoublyLinkedList(iterator))
{
p=(struct student *)getNextElementFromDoublyLinkedList(iterator,&iii);
if(rollNumber==p->rollNumber)
{
found=1;
break;
}
}
if(found==0)
{
printf("invalid rollNumber\n");
return;
}
printf("enter position:");
scanf("%d",&pos);
fflush(stdin);
printf("enter name:");
fgets(name,22,stdin);
fflush(stdin);
name[strlen(name)-1]='\0';
printf("do you want to save it (y/n):");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("student not added\n");
return;
}
s=(struct student *)malloc(sizeof(struct student));
if(s==NULL)
{
printf("insufficient memory\n");
return;
}
s->name=(char *)malloc(sizeof(char)*(strlen(name)+1));
if(s->name==NULL)
{
printf("insufficient memory\n");
free(s);
}
s->rollNumber=rollNumber;
strcpy(s->name,name);
insertInDoublyLinkedList(list,s,pos,&sucess);
if(!sucess)
{
free(s);
free(s->name);
printf("insufficient memory\n");
return;
}
printf("student added,press enter to continue....");
getchar();
}

int main()
{
int ch,sucess,iii;
int direction=1;
doublyLinkedListIterator *iterator;
struct student *s;
doublyLinkedList *list=creatDoublyLinkedList(&sucess);
if(!sucess)
{
printf("insufficient memmory");
return 0;
}
while(1)
{
printf("1.add\n");
printf("2.remove\n");
printf("3.display size\n");
printf("4.list\n");
printf("5.clear\n");
printf("6.insert\n");
printf("7.exit\n");
printf("enter your choice:");
scanf("%d",&ch);
fflush(stdin);
if(ch==1)addStudent(list);
if(ch==2)removeStudent(list);
if(ch==3)displaySize(list);
if(ch==4)displayListOfStudents(list);
if(ch==5)clearListOfStudents(list);
if(ch==6)insertInList(list);
if(ch==7)break;
}
iterator=getDoublyLinkedListIterator(list,direction);
while(hasMoreElementInDoublyLinkedList(iterator))
{
s=(struct student *)getNextElementFromDoublyLinkedList(iterator,&iii);
free(s->name);
free(s);
}
releaseDoublyLinkedList(list);
return 0;
}
