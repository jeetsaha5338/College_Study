#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *a,n,m1,m2,i,j=0;
    printf("enter n:");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("enter the elements:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    m1=0;
    for(i=0;i<n;i++)
    {
        if(m1<a[i])
            m1=a[i];
    }
    m2=0;
    for(i=0;i<n;i++)
    {
        if(a[i]!=m1 && a[i]>m2)
            m2=a[i];
        if(a[i]==m1)
            j++;
    }
    if(j==n)
    {
        printf("NOT EXIST");
        return 0;
    }
    printf("\n%d",m2);
    return 0;
}

