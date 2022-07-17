#include<stdio.h>
#include<stdlib.h>
typedef struct nodetype
{
    int info;
    struct nodetype *link;
}
node;
int main()
{
    printf("ashima\n");
    node* create();
    int traverse(node*);
    int instsort(node**,int);
    node *head,*ptr;
    int item;
    head=create();
    printf("linked list before insertion");
    traverse(head);
    printf("enter info to be inserted into new node:");
    scanf("%d",&item);
    instsort(&head,item);
    printf("linked list after insertion");
    traverse(head);
    printf("----End of program----");
    ptr=head;
    while(ptr!=NULL)
    {
        ptr=ptr->link;
        free(head);
        head=ptr;
    }
    return 0;
}
node* create()
{
    node *ptr,*head=NULL;
    char ch='y';
    int data;
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
        printf("enter into of new node:");
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
        printf("info of node is %d",ptr->info);
        ptr=ptr->link;
    }
    return 0;
}
int instsort(node** head,int item)
{
    node *new,*ptr,*prevptr;
    new=(node*)malloc(sizeof(node));
    new->info=item;
    new->link=NULL;
    if(*head==NULL)
    {
        *head=new;
        return 0;
    }
    ptr=*head;
    prevptr=NULL;
    while((ptr!=NULL)&&(item>ptr->info))
    {
        prevptr=ptr;
        ptr=ptr->link;
    }
    if(prevptr==NULL)
    {
        new->link=*head;
        *head=new;
    }
    else
    {
        new->link=ptr;
        prevptr->link=new;
    }
}