#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<process.h>
struct node
{
	int info;
	struct node *lchild;
	struct node *rchild;
}*root;



void find(int item,struct node **par,struct node **loc)
{
	struct node *ptr,*ptrsave;

	if(root==NULL)  /*tree empty*/
	{
		*loc=NULL;
		*par=NULL;
		return;
	}
	if(item==root->info) /*item is at root*/
	{
		*loc=root;
		*par=NULL;
		return;
	}
	/*Initialize ptr and ptrsave*/
	if(item<root->info)
		ptr=root->lchild;
	else
		ptr=root->rchild;
	ptrsave=root;

	while(ptr!=NULL)
	{
		if(item==ptr->info)
		{       *loc=ptr;
			*par=ptrsave;
			return;
		}
		ptrsave=ptr;
		if(item<ptr->info)
			ptr=ptr->lchild;
		else
			ptr=ptr->rchild;
	 }/*End of while */
	 *loc=NULL;   /*item not found*/
	 *par=ptrsave;
}/*End of find()*/

void insert(int item)
{       struct node *tmp,*parent,*location;
	find(item,&parent,&location);
	if(location!=NULL)
	{
		printf("Item already present");
		return;
	}

	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=item;
	tmp->lchild=NULL;
	tmp->rchild=NULL;

	if(parent==NULL)
		root=tmp;
	else
		if(item<parent->info)
			parent->lchild=tmp;
		else
			parent->rchild=tmp;
}/*End of insert()*/

int preorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return 0;
	}
	if(ptr!=NULL)
	{
		printf("%d  ",ptr->info);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}/*End of preorder()*/

void inorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		printf("%d  ",ptr->info);
		inorder(ptr->rchild);
	}
}/*End of inorder()*/

void postorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	if(ptr!=NULL)
	{
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d  ",ptr->info);
	}
}/*End of postorder()*/

void display(struct node *ptr,int level)
{
	int i;
	if ( ptr!=NULL )
	{
		display(ptr->rchild, level+1);
		printf("\n");
		for (i = 0; i < level; i++)
			printf("    ");
		printf("%d", ptr->info);
		display(ptr->lchild, level+1);
	}/*End of if*/
}/*End of display()*/
void main()
{
	int choice,num;
	root=NULL;
	while(1)
	{
		printf("\n");
		printf("1.Construct\n");
		printf("2.Inorder Traversal\n");
		printf("3.Preorder Traversal\n");
		printf("4.Postorder Traversal\n");
		printf("5.Display\n");
		printf("6.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			printf("Enter the number to be inserted : ");
			scanf("%d",&num);
			insert(num);
			break;

		 case 2:
			inorder(root);
			break;
		 case 3:
			preorder(root);
			break;
		 case 4:
			postorder(root);
			break;
		 case 5:
			display(root,1);
			break;
		 case 6:exit(0);
			break;
		 default:
			printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */
}getch();/*End of main()*/
