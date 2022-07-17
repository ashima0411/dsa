#include<stdio.h>

int main()
{
int a[20] ,i,n,loc, item; 
int lsearch (int a[], int n, int item);

printf ("Enter number of Elements (<=20)--");
scanf ("%d",&n);
for (i=0; i<n; i++)
{
printf ("Enter element a[%d]--",i);
scanf ("%d",&a[i]);

}
printf ("Enter item to search=");
scanf ("%d",&item);
loc = lsearch (a,n,item);
if(loc==-1)

printf("Item does not exist in array");
else
printf("Item %d\t exist at index = %d",item,loc);
getch();
}
int lsearch(int a[],int n,int item)
{
int loc=-1,i=1;
while(i<n && a[i]!=item)
i=i+1;
if(a[i]==item)
loc=i;
return(loc);
}