#include<stdio.h>
#include<conio.h>
#include<process.h>

#define stack_size 25

void push(int[],int,int *);
void pop(int[],int *);
void display(int[],int *);

void main()

{int top=-1;
 int stack[stack_size];
 int item,c;
 clrscr();
 do{
 printf("-------------\n");
 printf("STACK PROGRAM\n");
 printf("-------------\n");
 printf("1.Push\n");
 printf("2.Pop\n");
 printf("3.Display\n");
 printf("4.exit\n");
 printf("-------------\n");

 printf("enter your choice-\n");
 scanf("%d",&c);

 switch(c)

 {case 1:printf("enter the item to be added in stack\n");
	 scanf("%d",&item);
	 push(stack,item,&top);
	 break;
  case 2:pop(stack,&top);
	 break;
  case 3:display(stack,&top);
	 break;
  case 4:exit(0);
	 break;
  default:printf("invalid choice\n");}}while(c!=4);
  getch();
   }

void push(int stack[],int item,int *top)

{
 if(*top==stack_size-1)
 {printf("stack overflow\n");}
 else
  {
   stack[++(*top)]=item;}}

void pop(int stack[],int *top)

{if(*top==-1)
 printf("underflow\n");
 else
  {printf("the item to be popped is %d",stack[*top]);
   (*top)--;}}

void display(int stack[],int *top)

{ int i;

 if(*top==-1)
 printf("underflow\n");

 for(i=0;i<=(*top);i++)
 printf("%d ",stack[i]);

 }