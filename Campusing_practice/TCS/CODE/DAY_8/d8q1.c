#include<stdio.h>
int main()
{
    int n,i,j,sum,f,k,c=0;
    printf("Enter the Number:");
    scanf("%d",&n);
    for(i=n/2+1;i>=1;i--)
    {
        sum=i;
        f=0;
        for(j=i-1;j>=1;j--)
        {
            sum+=j;
            if(sum==n)
            {
                f=1;
                break;
            }
            else if(sum>n)
                break;
        }
        if(f==1)
        {
            for(k=i;k>=j;k--)
                printf("%d ",k);
            printf("\n");
            c++;
        }
    }
    printf("%d",c);
    return 0;
}
