#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h> 
struct node
{  
    int data;  
    struct node *previous;  
    struct node *next;  
};        
struct node *head, *tail = NULL;   
void addnode(int data) 
{   
    struct node *newnode = (struct node*)malloc(sizeof(struct node));  
    newnode->data = data;   
    if(head == NULL) 
    {   
        head = tail = newnode;   
        head->previous = NULL;   
        tail->next = NULL;  
    }  
    else 
    {    
        tail->next = newnode;   
        newnode->previous = tail;  
        tail = newnode;  
        tail->next = NULL;  
    }  
}   
void searchnode(int value) 
{  
    int i = 1;  
    bool flag = false;   
    struct node *current = head;  
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    while(current != NULL) 
    {  
        if(current->data == value) 
        {  
            flag = true;  
            break;  
        }  
        current = current->next;  
        i++;  
    }  
    if(flag)  
         printf("Node is present in the list at the position : %d\n", i);  
    else  
         printf("Node is not present in the list\n");  
}    
int main()  
{   
    printf("ashima\n");
    addnode(1);  
    addnode(5);  
    addnode(4);  
    addnode(2);  
    addnode(3);  
    searchnode(4);  
   searchnode(3); 
   searchnode(0);
   return 0;  
}