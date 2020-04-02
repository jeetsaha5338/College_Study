#include<stdio.h>
#include<stdlib.h>
int main()
{
    int s,i,j,n,t;
    printf("Enter N & T:");
    scanf("%d%d",&n,&t);
    int *a;
    a=(int*)malloc(n*sizeof(int));
    printf("Ur Series Is:");
    for(i=0;i<n-1;i++)
    {
        a[i]=0;
        //printf(" 0");
    }
    a[i]=1;
    for(i=0;i<n;i++)
    {
        printf(" %d",a[i]);
    }
    for(;i<t;i++)
    {
        s=0;
        for(j=0;j<n;j++)
            s+=a[j];
        printf(" %d",s);
        for(j=0;j<n-1;j++)
            a[j]=a[j+1];
        a[j]=s;
    }
    //printf(" 1");
    return 0;
}
