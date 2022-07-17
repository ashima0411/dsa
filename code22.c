#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NULL 0
typedef struct nodetype
{
    int info;
    struct nodetype *link;
}node;
int main()
{
    node *create();
    int traverse(node*);
    int destroylist(node*);
    int dup_remove(node*);
    node*head;
    head=create();
    printf("sorted linked list with duplicate info values\n");
    traverse(head);
    dup_remove(head);
    printf("sorted list after deleting nodes with duplicate info values\n");
    traverse(head);
    destroylist(head);
    return 0;
}
node* create()
{
    node *ptr,*head=NULL;
    int data;
    char ch='y';
    while(ch=='y'|| ch=='Y')
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
        printf("enter info of new node:");
        scanf("%d",&data);
        ptr->info=data;
        fflush(stdin);
        printf("want to continue:(Y or N)=");
        scanf("%c",&ch);
    }
    ptr->link=NULL;
    return(head);
}
int traverse(node *head)
{
    node* ptr=head;
    while(ptr!=NULL)
    {
        printf("info of node is:%d",ptr->info);
        ptr=ptr->link;
    }
    return 0;
}
int dup_remove(node *head)
{
    node *ptr,*nextnext;
    ptr=head;
    if(ptr==NULL)
    return 0;
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
int destroylist(node *start)
{
    node* ptr=start;
    while(ptr!=NULL)
    {
        ptr=ptr->link;
        free(start);
        start=ptr;
    }
}