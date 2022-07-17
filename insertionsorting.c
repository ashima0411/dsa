#include<stdio.h>
int main()
{
    printf("ashima\n");
    int n,i,a[20];
    int insertionsort(int a[], int n);
    int display(int a[],int n);
    printf("enter total number of elements in array(<20)-->");
    scanf("%d",&n);
    printf("input array elements to be sorted\n");
    for(i=0;i<n;i++)
    {
        printf("enter element a[%d]-->",i);
        scanf("%d",&a[i]);
    }
    printf("array element before sorting are--");
    display(a,n);
    insertionsort(a,n);
    printf("\narray element after sorting are--");
    display(a,n);
    return 0;
}
int insertionsort(int a[], int n)
{
    int i,j,target;
    for(i=1;i<n;i++)
    {
        target=a[i];
        j=i-1;
        while((j>=0)&&(target<=a[j]))
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=target;
    }
}
int display(int a[],int n)
{
    int i;
    {
        for(i=0;i<n;i++)
            {
               printf("%d",a[i]);
            }
    }
}
