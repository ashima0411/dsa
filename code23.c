#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct
{
    int s[MAX];
    int top;
}
stack;
int main()
{
    printf("ashima\n");
    stack s1;
    int choice,item;
    char ch;
    int create_stack(stack*);
    int push(stack*,int);
    int pop(stack*);
    int peek(stack*);
    int isempty(stack*);
    int display(stack*);
    create_stack(&s1);
    while(1)
    {
        printf("\nchoice 1.Push\t 2.Pop\t 3.Peek\t 4.Display\t 5.Exit");
        printf("\nEnter your choice(1-5)->");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
            printf("enter element to push=");
            scanf("%d",&item);
            push(&s1,item);
            break;
            case 2:
            if(isempty(&s1)==1)
            printf("underflow: stack Empty");
            else
            {
                item=pop(&s1);
                printf("Element popped=%d\t",item);
            }
            break;
            case 3:
            if(isempty(&s1)==1)
            printf("underflow:stack empty");
            else
            {
                item=peek(&s1);
                printf("element at the top=%d\t",item);
            }
            break;
            case 4:
            display(&s1);
            break;
            case 5:
            exit(0);
        }
    }
}
int create_stack(stack* sp)
{
    sp->top=-1;
}
int isempty(stack* sp)
{
    return(sp->top==-1);
}
int push(stack* sp,int item)
{
    if(sp->top==MAX-1)
    printf("overflow:stack is full");
    else
    {
        sp->top++;
        sp->s[sp->top]=item;
    }
}
int pop(stack* sp)
{
    int item;
    item=sp->s[sp->top];
    sp->top--;
    return(item);
}
int peek(stack* sp)
{
    int item;
    item=sp->s[sp->top];
    return(item);
}
int display(stack* sp)
{
    int i;
    printf("\n contents of stack=");
    for(i=0;i<=sp->top;i++)
    printf("%d\t",sp->s[i]);
}