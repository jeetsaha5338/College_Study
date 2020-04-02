#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *a,*b,n,d,i,j;
    printf("Enter N & D:");
    scanf("%d %d",&n,&d);
    a=(int*)malloc(sizeof(int)*n);
    b=(int*)malloc(sizeof(int)*d);
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    for(i=0;i<d;i++)
    {
        b[i]=a[i];
    }
    for(i=d;i<n;i++)
    {
        a[i-d]=a[i];
    }
    for(i=n-d;i<n;i++)
    {
        a[i]=b[i-(n-d)];
    }
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
