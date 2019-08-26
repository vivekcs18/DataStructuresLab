#include<stdio.h>
#include<conio.h>
#include<process.h>

#define q_size 3

void enqueue(int[],int,int *);
void dequeue(int[],int *,int *);
void display(int[],int *,int *);

void main()

{ int q[q_size];
  int f=0;
  int r=-1;
  int item,c;
  clrscr();
  do{
  printf("-------------\n");
  printf("QUEUE PROGRAM\n");
  printf("-------------\n");
  printf("1.Enqueue\n");
  printf("2.Dequeue\n");
  printf("3.Display\n");
  printf("4.exit\n");
  printf("-------------\n");

  printf("enter your choice-\n");
  scanf("%d",&c);

  switch(c)

 {case 1:printf("enter the item to be added in queue\n");
	 scanf("%d",&item);
	 enqueue(q,item,&r);
	 break;
  case 2:dequeue(q,&f,&r);
	 break;
  case 3:display(q,&f,&r);
	 break;
  case 4:exit(0);
	 break;
  default:printf("invalid choice\n");}}while(c!=4);
  getch();
   }

void enqueue(int q[],int item, int *r)

{
 if((*r)==q_size-1)
 {printf("Queue is full\n");}
 else
  {q[++(*r)]=item;}}

void dequeue(int q[],int *f,int *r)

{if((*f)>(*r))
 printf("queue is empty\n");
 else
  {printf("the element deleted is %d",q[(*f)]);
   (*f)++;}}

void display(int q[], int *f, int *r)

{ int i;

 if((*f)>(*r))
 printf("nothing to display\n");

 for(i=(*f);i<=(*r);i++)
 printf("%d ",q[i]);



		       }