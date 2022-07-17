#include<stdio.h>
int main()
{
    printf("ashima\n");
    int n,i,a[20];
    int selectionsort(int a[],int n);
    int display(int a[],int n);
    printf("enter total number of elements in array(<20)-->");
    scanf("%d",&n);
    printf("input array elements to be sorted\n");
    for(i=0;i<n;i++)
    {
        printf("enter element a[%d]-->",i);
        scanf("%d",&a[i]);
    }
    printf("array element before sorting are---");
    display(a,n);
    selectionsort(a,n);
    printf("\narray element after sorting are--");
    display(a,n);
    return 0;
}
int selectionsort(int a[],int n)
{
    int i,j;
    int loc,temp;
    for(i=0;i<n-1;i++)
    {
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[loc])
            loc=j;
        }
        temp=a[i];
        a[i]=a[loc];
        a[loc]=temp;
    }
}
int display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}
