#include<stdio.h>
int main()
{
    int n,a[50],a5[10],a7[10],i5=0,i7=0,i=0,j,k;
    printf("Enter Your NUmber:");
    scanf("%d",&n);
    while(n>0)
    {
        a[i++]=n%10;
        n/=10;
    }
    k=i;
    if(k<5)
    {
        printf("\n-1\n");
        return 0;
    }
    for(i=0;i<k/2;i++)
    {
        j=a[i];
        a[i]=a[k-i-1];
        a[k-i-1]=j;
    }
    for(i=0;i<k;i++)
    {
        if((i+1)%7==0)
        {
            a7[i7++]=a[i];
        }
        if((i+1)%5==0)
        {
            a5[i5++]=a[i];
        }
    }
    printf("\nFor 7:");
    for(i=0;i<i7;i++)
        printf("%d ",a7[i]);

    printf("\nFor 5:");
    for(i=0;i<i5;i++)
        printf("%d ",a5[i]);
    return 0;
}
