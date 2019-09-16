#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define psize 20

void push(int[] ,int *, int);
char pop(int[],int *);
int convert(int, int, char);

void main()

{
    int i;
    int top=-1;
    int top1,top2,dch,total;
    int postfix[psize];
    char stack[psize];
    char ch,item1,item2;

    printf("enter the postfix expression-\n");
    scanf("%s",stack);
    i=0;
    while(stack[i]!='\0')
    {
     ch = stack[i];
     switch(ch)
     {
      case '+':
      case '-':
      case '*':
      case '/':
      case '^':item1 = pop(postfix,&top);
	       item2 = pop(postfix,&top);
	       total = convert(item1,item2,ch);
	       push(postfix,&top,total);
	       break;
      default: break;}

     switch(ch)

     {case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':   dch = ch-48;
		  push(postfix,&top,dch);
		  break;
		  default:break;}
		  i++;}
    printf("%d",postfix[0]);
    getch(); }

void push(int postfix[],int *top,int ch)

{if(*top==psize-1)
 {printf("stack overflow");}
 else
  postfix[++(*top)] = ch;}

char pop(int postfix[], int *top)

 {char item;
  if(*top==-1)
   {printf("underflow\n");}
  else
  {item = postfix[(*top)--];}
  return item;}

int convert(int x,int y,char ch)

{
 switch(ch)

 {case '+':return (y+x);
	   break;
  case '-':return (y-x);
	   break;
  case '*':return (y*x);
	   break;
  case '/':return (y/x);
	   break;
  case '^':return pow(y,x);
	   break;

	 }   }


