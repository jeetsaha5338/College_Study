#include<stdio.h>
void swap(int *p,int *q)
{
    int *t=*p;
    *p=*q;
    *q=t;
    return;
}
int main()
{
    int a[9]={5,4,9,1,-8,0,7,6,-5},i,j,n=9,l,u;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
                swap(&a[j],&a[j+1]);
        }
    }
    for(i=0;i<n;i++)
        printf("\t%d",a[i]);
    printf("\n");
    l=0;u=n-1;
    while(l<=u)
    {
        printf("\t%d",a[l]);
        if(l!=u)
            printf("\t%d",a[u]);
        l++;
        u--;
    }
    return 0;
}
