#include<stdio.h>
int main()
{
printf("saisha\n");
    int a[5],i;
    for (i=0;i<=5;i++)
    {
    printf("enter the element in array:");
    scanf("%d",&a[i]);
    }
for(i=0;i<=5;i++)
{
    printf("%d%d,",i,a[i]);
}
return 0;
}
