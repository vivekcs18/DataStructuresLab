#include<stdio.h>
#include<conio.h>
#include<process.h>

#define q_size 5

void enqueue(int[],int,int *,int *);
void dequeue(int[],int *,int *);
void display(int[],int *,int *);

void main()

{ int q[q_size];
  int f=-1;
  int r=-1;
  int item,c;
  clrscr();
  do{
  printf("----------------------\n");
  printf("CIRCULAR QUEUE PROGRAM\n");
  printf("----------------------\n");
  printf("1.Enqueue\n");
  printf("2.Dequeue\n");
  printf("3.Display\n");
  printf("4.exit\n");
  printf("\n-------------\n");

  printf("\nenter your choice-\n");
  scanf("%d",&c);

  switch(c)

 {case 1:printf("enter element to be inserted\n");
	 scanf("%d",&item);
	 enqueue(q,item,&f,&r);
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

void enqueue(int q[], int item, int *f, int *r)

{if((*r+1)%q_size==(*f))
 printf("queue full\n");
 else
 {if(*f==-1)
  *f=0;
  *r=(*r+1)%q_size;
  q[*r]=item;}}

void dequeue(int q[],int *f, int *r)

{if(*f==-1)
 printf("queue is empty\n");
 else
 {printf("element 1deleted = %d ",q[*f]);
  if(*f==*r)
  {*r=-1;
   *f=-1;}
  else
  *f=(*f+1)%q_size;}}


void display(int q[], int *f, int *r)

{ int i;

 if(*f==-1)
 {printf("queue is empty\n");
  return; }
  printf("elements in queue-\n");

  for(i=*f;i!=*r;i=(i+1)%q_size)
  {printf(" %d ",q[i]);}

  printf(" %d ",q[i]);}