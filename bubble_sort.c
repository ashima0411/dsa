#include<stdio.h>
int main()
{
    printf("ashima\n");
    int a[20],n,i;
    int bubblesort(int[],int);
    printf("enter number of elements(<=20)=");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter element a[%d]=",i);
        scanf("%d",&a[i]);
    }
    bubblesort(a,n);
    printf("sorted elements---");
    for(i=0;i<n;i++)
    printf("%d \t",a[i]);
    return 0;
}
int bubblesort(int a[],int n)
{
    int temp,i,j;
    for(i=1;i<=n-1;i++)
    {
        for(j=0;j<=n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
