#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node *NODE;

NODE getnode() {
    NODE p;
    p = (NODE) malloc(sizeof(struct node));
    if (p != NULL) return p;
    else {
	printf("No Memory \n");
	return NULL;}
}

NODE push(NODE head,int new_data)
{
    NODE new_node = getnode();  
  
    new_node->data = new_data;  
  
    new_node->next = head;  
    new_node->prev = NULL;

    if (head!= NULL)
	head->prev = new_node;

    head= new_node;

    return head;
}

NODE insertbefore(NODE first,int item)

{NODE t,c,p;
 if(first==NULL)
 {printf("list is empty\n");
  return first;}
 c=first;
 while(c!=NULL)
 {if(item==c->data)
   break;
  c=c->next;}
 if(c==NULL)
 {printf("key not found\n");
  return first;}
 if(c==first)
 {printf("enter the item to be inserted towards left\n");
  t=getnode();
  scanf("%d",&t->data);
  t->next=first;
  first->prev=t;
  t->prev=NULL;
  first=t;
  return first;}
 p=c->prev;
 printf("enter the item to be inserted towards left\n");
 t=getnode();
 scanf("%d",&t->data);
 p->next=t;
 t->prev=p;
 c->prev=t;
 t->next=c;
 return first;}

NODE deletepos(NODE first,int item)

{NODE p,c,temp;
 if(first==NULL)
  {printf("list is empty\n");
   return first;}
 c=first;
 while(c!=NULL)
 {if(item==c->data)
   break;
  c=c->next;}
 if(c==NULL)
 {printf("item not found\n");
  return first;}
 p=c->prev;
 if(p==NULL)
 {first=c->next;
  c->next->prev=NULL;
  return first;}
 temp=c->next;
 p->next=temp;
 temp->prev=p;
 return first;}


void disp(NODE node1)

{ NODE last;
    printf("\nTraversal in forward direction \n");
    while (node1!= NULL) {
	printf(" %d ", node1->data);
	last = node1;
	node1 = node1->next;
    }

    printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
	printf(" %d ", last->data);
	last = last->prev;
    }
}



void main() {
    int choice,ele1,posi,ele;
    NODE head = NULL;
    clrscr();

    do {
	printf("\n-*-*-*-*-*-*-*-*-*-*-Main Menu-*-*-*-*-*-*-*-*-*-*-\n");
	printf("1.insert\n");
	printf("2.insert before\n");
	printf("3.delete a specific node\n");
	printf("4.Display\n");
	printf("5.Exit\n");
	printf("---------------------------------\n");
	printf("Enter Choice:  \n");
	printf("---------------------------------\n");
	scanf("%d", &choice);

	switch (choice) {
	    case 1: printf("Enter element to push\n");
		    scanf("%d",&ele);
		    head=push(head,ele);
		    break;


	    case 2: printf("Enter element before which item is to be inserted\n");
		    scanf("%d",&ele1);
		    head=insertbefore(head,ele1);
		    break;

	    case 3: printf(" element to be deleted\n");
		    scanf("%d",&posi);
		    head=deletepos(head,posi);
		    break;

	    case 4: disp(head);
		    break;

	    case 5: exit(0);
		    break;


	    default: printf("Invalid Choice \n");
	}


    } while (choice != 5);


}