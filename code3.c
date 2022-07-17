#include<stdio.h>
#include<string.h>
#define NULL 0
typedef struct nodetype
{
	int info;
	struct nodetype *link;
}node;
int main()
{
	node* create();
	void traverse(node*);
	void destroylist(node*);
	void dup_remove(node*);
	node *head;
head=create();
printf("sorted link list with duplicate info values\n");
traverse(head);
dup_remove(head);
printf("\nSorted list after deleting nodes wih duplicate info values");
traverse(head);
destroylist(head);
return 0;
}
node* create()
{
	node *ptr,*head=NULL;
	int data;
	char ch='y';
	while (ch=='y'||ch=='Y')
	{
		if(head==NULL)
		{
			head=(node*)malloc(sizeof(node));
			ptr=head;
		}
		else
		{
		ptr->link=(node*)malloc(sizeof(node));
		ptr=ptr->link;	
		}
		printf("Enter info of new node:");
		scanf("%d",&data);
		ptr->info=data;
		fflush(stdin);
		printf("Want to continue:(Y or N)=");
		scanf("%c",&ch);
		
	}
	ptr->link=NULL;
	return(head);
}
void traverse(node *head)
{
	node* ptr=head;
	while(ptr!=NULL)
	{
		printf("\nInfo of node is \t:%d",ptr->info);
		ptr=ptr->link;
	}
	return;
}
void dup_remove(node *head)
{
	node *ptr, *nextnext;
	ptr=head;
	if(ptr==NULL) return;
	while(ptr->link!=NULL)
	{
		if(ptr->info==ptr->link->info)
		{
			nextnext=ptr->link->link;
			free(ptr->link);
			ptr->link=nextnext;
		}
		else
			{
				ptr=ptr->link;
			
		}
	}
}
void destroylist(node *start)
{
	node* ptr=start;
	while(ptr!=NULL)
	{
		ptr=ptr->link;
		free(start);
		start=ptr;
	}
}