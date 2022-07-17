#include<stdio.h>
#include<conio.h>
#define NULL 0
typedef struct nodetype
{
    int info;
    struct nodetype *link;
    }node;
     main()
     {
         node * create();
         void traverse(node*);
         node* search(node*,int);
         void instloc(node**,int,node*);
         int item,data;
         node*head,*loc,*ptr;
         clrscr();
         head= create();
         printf("linked list before insertion:\n");
         traverse(head);
         printf("\n enter item to search from linked list:");
         scanf("%d",&item);
         loc=search(head,item);
         printf("\n enter info to be inserted after searched item=");
         scanf("%d",&data);
         instloc(&head,data,loc);
         printf("linked list after insertion\n");
         traverse(head);
         printf("\n----End of program----\n");
         ptr=head;
         while(ptr!=NULL)
         {
             ptr=ptr->link;
             free(head);
             head=ptr;
         }            
         getch();
           }
node*create()
{
    node *ptr,*head=NULL;
    char ch='y';
    int data;
    while (ch=='y'||ch=='Y')
}
if(head==NULL)
{
    head=(node*)malloc(sizeof(node));
    ptr=ptr
}