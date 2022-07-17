#include <stdio.h>
#include <stdlib.h>
#define NULL ((void *)0)

typedef struct nodetype
{
     int info;
   struct nodetype *link;
}node;

int main()
{
    printf("swati\n");
    node* create();
    int traverse(node*);
    node* search(node*,int);
    int instloc(node*,int,node);
    int item,data;
    node *head,*loc,*ptr;
    head = create();
    printf("linked list before insertion:\n");
    traverse(head);
    printf("\n Enter item to search from linked list : ");
    scanf("%d",&item);
    loc = search(head,item);
    printf("\n Enter info. to be inserted after searched item = ");
    scanf("%d",&data);
    instloc(&head, data, loc);
    printf("linked list after insertion \n");
    traverse(head);
    printf("\n ----End of program----\n");
    ptr=head;
    while(ptr != NULL)
    {
        ptr = ptr->link;
        free(head);
        head=ptr;
    }
    return 0;
}
node* create(){
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
        else{
            ptr->link=(node*)malloc(sizeof(node));
            ptr=ptr->link;
        }
        printf("Enter info. of new node =");
        scanf("%d",&data);
        ptr->info=data;
        fflush(stdin);
        printf("want to continue:(Y or N)=");
        scanf("%c",&ch);
    }
    ptr->link=NULL;
    return (head);
}
int traverse(node *head){
    node* ptr=head;
    while(ptr!=NULL)
    {
        printf("\n info of node is \t%d",ptr->info);
        ptr=ptr->link;
    }
    return 0;
}
node* search(node *head, int item)
{
    node *loc,*ptr;
    loc = NULL;
    ptr=head;
    while((ptr!= NULL) && (item != ptr->info))
    ptr=ptr->link;
    if(item==ptr->info)
    loc=ptr;
    return(loc);
}
int instloc(node** head,int item,node *loc)
{
    node* new;
    new=(node*)malloc(sizeof(node));
    new->info=item;
    if(loc==NULL)
    {
        new->link=*head;
        *head=new;
    }
    else
    {
        new->link=loc->link;
        loc->link=new;
    }
}