#include<stdio.h>
int main()
{
    int a[9]={2,12,4,7,5,6,10,3,18};
    int n=9,x=16,i,j,sum,k,f;
    for(i=0;i<n;i++)
    {
        sum=a[i];
        f=0;
        for(j=i+1;j<n;j++)
        {
            sum+=a[j];
            if(sum==x)
            {
                f=1;
                break;
            }
            else if(sum>x)
            {
                break;
            }
        }
        if(f==1)
        {
            for(k=i;k<=j;k++)
                printf("%d ",a[k]);
            printf("\n");
        }
    }
    return 0;
}
