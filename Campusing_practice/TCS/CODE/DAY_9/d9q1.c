#include<stdio.h>
int main()
{
    int n,i,j,k,a[10],temp;
    printf("enter no.");
    scanf("%d",&n);
    k=n;
    i=0;
    while(k>0)
    {
        a[i++]=k%10;
        k/=10;
    }
    k=i;
    for(i=0;i<k;i++)
    {
        for(j=0;j<k-i-1;j++)
        {
            if(a[j]<a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("\nleargest number:");
    for(i=0;i<k;i++)
        printf("%d ",a[i]);

    printf("\n2nd leargest number:");
    for(i=k-1;i>0;i--)
    {
        if(a[i]!=a[i-1])
        {
            temp=a[i];
            a[i]=a[i-1];
            a[i-1]=temp;
            break;
        }
    }
    for(i=0;i<k;i++)
        printf("%d ",a[i]);
    return 0;
}
