#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
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

NODE push(NODE head,int item)
{
    NODE x,curr;
    x=getnode();
    x->data=item;
    x->next=NULL;
    if(head==NULL)
    return x;

    else
    {
	curr=head;
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}
	curr->next=x;
    }
    return head;
}

NODE pop(NODE head)
{       NODE temp,prev;
	if(head==NULL)
	{
		printf("LIST IS EMPTY");
	}
	temp=head;
	prev=NULL;
	 while(temp->next!=NULL)
	 {
		prev=temp;
		temp=temp->next;
	 }
	 printf("DELETED ITEM IS: %d\n",temp->data);
	 prev->next=NULL;
	 free(temp);

	 return head;
}

NODE reverse(NODE head)
{
	NODE curr,prev,temp;
	prev=NULL;
	curr=head;
	while(curr!=NULL)
	{
		temp=curr->next;
		curr->next=prev;
		prev=curr;
		curr=temp;
	}
	head=prev;
	return head;
}

NODE disp_stack(NODE head)
{
	NODE temp;
	if(head==NULL)
	printf("List is empty\n");
	else
	{
		temp=head;
		printf("Element in the list:\n");
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
	 head=reverse(head);
	 return head;
}

NODE enqueue(NODE head1,int item)
{
    NODE x,curr;
    x=getnode();
    x->data=item;
    x->next=NULL;
    if(head1==NULL)
    return x;

    else
    {
	curr=head1;
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}
	curr->next=x;
    }
    return head1;
}



NODE dequeue(NODE head1)
{
	NODE temp;
	if(head1==NULL)
	printf("list is empty\n");
	else
	{
		temp=head1;
		printf("item deleted is %d\n",temp->data);
		temp=temp->next;
		free(head1);
	}
	return temp;
}
void disp_queue(NODE head1)
{
	NODE temp;
	if(head1==NULL)
	printf("list is empty\n");
	else
	{
		temp=head1;
		printf("Element in the list :\n");
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

int main() {
    int choice,ele,val;
    NODE head = NULL;
    NODE head1 = NULL;
    clrscr();

    do {
	printf("\n-*-*-*-*-*-*-*-*-*-*-Main Menu-*-*-*-*-*-*-*-*-*-*-\n");
	printf("1.Push into stack\n");
	printf("2.Pop from stack\n");
	printf("3.Display stack elements \n");
	printf("4.Enqueue\n");
	printf("5.Dequeue\n");
	printf("6.Display queue elements\n");
	printf("7.Exit\n");
	printf("---------------------------------\n");
	printf("Enter Choice:  \n");
	printf("---------------------------------\n");
	scanf("%d", &choice);

	switch (choice) {
	    case 1: printf("Enter element to push\n");
		    scanf("%d",&ele);
		    head=push(head,ele);
		    break;

	    case 2: head=pop(head);
		    break;

	    case 3: head=reverse(head);
		    head=disp_stack(head);
		    break;

	    case 4: printf("Enter element to enqueue\n");
		    scanf("%d",&val);
		    head1=enqueue(head1,val);
		    break;

	    case 5: head1=dequeue(head1);
		    break;

	    case 6: disp_queue(head1);
		    break;

	    case 7: exit(0);
		    break;


	    default: printf("Invalid Choice \n");
	}


    } while (choice != 7);

    return 0;
}