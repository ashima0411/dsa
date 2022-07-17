#include<stdio.h>
#include<stdlib.h>
struct node
{
    int co,ex;
    struct node* next;
};
struct node* create(struct node* head,int co, int ex)
{
struct node *temp,*flag;
if(head==NULL)
{
    temp=(struct node*)malloc(sizeof(struct node));
    temp->co=co;
    temp->ex=ex;
    temp->next=NULL;
    head=temp;
}
else
{
    temp=head;
    while(temp->next!=NULL)
    temp=temp->next;
    flag=(struct node*)malloc(sizeof(struct node));
    flag->co=co;
    flag->ex=ex;
    flag->next=NULL;
    temp->next=flag;
}
return head;
}
struct node* polyadd(struct node *pt1, struct node *pt2, struct node *sum)
{
    struct node *poly1=pt1, *poly2=pt2, *res;
    if(poly1!=NULL && poly2==NULL)
    {
        sum=poly1;
        return sum;
    }
    else if(poly1==NULL && poly2!=NULL)
    {
        sum=poly2;
        return sum;
    }
    while(poly1!=NULL && poly2!=NULL)
    {
        if(sum==NULL)
        {
            sum=(struct node*)malloc(sizeof(struct node));
            res=sum;
        }
        else
        {
            res->next=(struct node*)malloc(sizeof(struct node));
            res=res->next;
        }
        if(poly1->ex>poly2->ex)
        {
            res->co=poly1->co;
            res->ex=poly1->ex;
            poly1=poly1->next;
        }
        else if(poly1->ex<poly2->ex)
        {
            res->co=poly2->co;
            res->ex=poly2->ex;
            poly2=poly2->next;
        }
        else if(poly1->ex==poly2->ex)
        {
            res->co=poly1->co+poly1->co;
            res->ex=poly1->ex;
            poly1=poly1->next;
            poly2=poly2->next;
        }
    }
    while(poly1!=NULL)
    {
        res->next=(struct node *)malloc(sizeof(struct node));
        res=res->next;
        res->co=poly1->co;
        res->ex=poly1->ex;
        poly1=poly1->next;
    }
    while(poly2!=NULL)
    {
        res->next=(struct node *)malloc(sizeof(struct node));
        res=res->next;
        res->co=poly2->co;
        res->ex=poly2->ex;
        poly2=poly2->next;
    }
    res->next=NULL;
    return sum;
}
int display(struct node* head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d^%d+",temp->co,temp->ex);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    printf("ashima\n");
    struct node *pt1=NULL, *pt2=NULL, *sum=NULL;
    int ch,co,ex;
    int i=1;
    while(i)
    {
        printf("1. Add to poly1\n");
        printf("2. Add to poly2\n");
        printf("3. Perform Addition\n");
        printf("4. Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter co-efficient\n");
            scanf("%d",&co);
            printf("enter exponent\n");
            scanf("%d",&ex);
            pt1=create(pt1,co,ex);
            break;
            case 2:
            printf("Enter co-efficient\n");
            scanf("%d",&co);
            printf("enter exponent\n");
            scanf("%d",&ex);
            pt2=create(pt2,co,ex);
            break;
            case 3:
            sum=polyadd(pt1,pt2,sum);
            printf("\npolynomial 1\n");
            display(pt1);
             printf("\npolynomial 2\n");
            display(pt2);
            printf("\nSum:\n");
            display(sum);
            break;
            case 4:
            i=0;
            break;
            default:
            printf("wrong choice! re enter\n");
            break;
        }
    }
}
