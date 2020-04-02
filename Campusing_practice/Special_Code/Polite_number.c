#include<stdio.h>
int main()
{
        int n,i,j,s=0,k;
        printf("Enter The Number:");
        scanf("%d",&n);
        for(i=1;i<n;i++)
        {
            s=0;
            for(j=i;j<n;j++)
            {
                s=s+j;
                if(s==n)
                {
                    for(k=i;k<=j;k++)
                    {
                       printf(" %d,",k);
                    }
                    printf("\n");
                    break;
                }
                else if(s>n)
                {
                    break;
                }
            }
        }
        return 0;
}
