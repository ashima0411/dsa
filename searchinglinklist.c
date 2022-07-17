#include <stdio.h>
#include<stdlib.h>
void create(int);
void search();

struct node{
    int data; 
    struct node *next;
};
struct node *head;
int main()
{
   int choice,item,loc;
   do{
       printf("\n1.create\n 2.search\n 3.Exit\n 4.enter your choice?");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:
           printf("\nEnter the item\n");
           scanf("%d",&item);
           create(item);
           break;
           case 2:
           search();
           case 3:
           exit(0);
           break;
           default:
            printf("\nPlease enter valid choice\n");
       }
   } while(choice != 3);
     return 0;
}
void create(int item){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    if(ptr == NULL){
        printf("\nOVERFLOW\n");
    }
    else{
        ptr -> data=item;
        if(head == NULL){
            head = ptr;
            ptr -> next = head;
        }
        else{
            temp=head;
            while(temp ->next != head){
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=head;
        }
        printf("\nNode inserted\n");
    }
}
void search(){
    struct node *ptr;
    int item, i=0,flag=1;
ptr = head;
if(ptr ==NULL){
    printf("\nenter item which you want to search :\n");
    scanf("%d",&item);
    if(head ->data == item){
        printf("item found at location %d",i+1);
        flag=0;
        return;
    }
    else{
        while(ptr->next != head){
            if(ptr->data == item){
                printf("item found at location %d",i+1);
                flag=0;
                return;
            }
            else{
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }
    }
    if(flag != 0){
        printf("item not found\n");
        return;
    }
}
}