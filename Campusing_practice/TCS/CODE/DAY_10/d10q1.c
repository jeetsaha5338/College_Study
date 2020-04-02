#include<stdio.h>
int main()
{
    int i,j,k,l,n,sum,flag;
    int a[10]={2,3,5,7,11,13,17,19,23,29};
    printf("Enter N:");
    scanf("%d",&n);
    k=10;
    flag=0;
    for(i=0;i<k-1;i++)
    {
        sum=a[i];
        if(sum>=n)
            break;
        else
        {
            for(j=i+1;j<k;j++)
            {
                sum+=a[j];
                if(sum==n)
                {
                    for(l=i;l<=j;l++)
                    {
                        printf("%d ",a[l]);
                    }
                    printf("\n");
                    flag=1;
                    break;
                }
                else if(sum>n)
                    break;
            }
        }
    }
    if(flag==0)
        printf("Not Possible\n");
    return 0;
}
