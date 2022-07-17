#include<stdio.h>
#include<conio.h>
#include <process.h>
#include<ctype.h>
#include <string.h>
char post_fix[20];
int j=0;
char stack[15];
int top=-1;

main()
{
    char ch;
    void pop();
    void push(char);
    char exp_infix[20];
    int i=0;
clrscr();
printf("\n enter infix expression and terminate it with ')' \n");
gets(exp_infix);
push('(');
while (top>=0)
{
    ch=exp_infix[i];
    switch(ch)
{
    case '(':
    push(ch);
    i++;
    break;
    case ')':
    while(stack[top] !='(')
    {
        pop(); 
    }
    pop();
    i++;
    break;
    case '+':
    case ('-'):
    while(stack[top]=='-' ||stack[top]=='+' ||stack[top]=='*' ||stack[top]=='/'||stack[top]=='^')
    {pop();}
    push(ch);
    i++;
    break;
    case'*':
    case '/':
    while ((stack[top]=='*')||(stack[top]=='/')||(stack[top]=='^')    )
    {pop();}
    push(ch);
    i++;
}
}
}
printf("postfix expression is =\t%s",post_fix);
printf("\n-------End of program-----\n");
getch();

void push(char item)
{
    top++;
    stack[top]=item;
}
void pop()
{
    if (top==-1)
    printf("stack is empty");
    else{
        if(stack[top]!='(')
        {post_fix[j]=stack[top];j++;}
    }
}