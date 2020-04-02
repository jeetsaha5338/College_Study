#include<stdio.h>
int main()
{
    int i,j,f,k=0,n,in[10],out[10];
    printf("Enter N:");
    scanf("%d",&n);
    printf("Enter Array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&in[i]);
    }
    printf("\nInput[]:");
    for(i=0;i<n;i++)
    {
        printf("%d ",in[i]);
    }
    for(i=0;i<n;i++)
    {
        f=0;
        for(j=0;j<k;j++)
        {
            if(out[j]==in[i])
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            out[k++]=in[i];
        }
    }
    printf("\nOutput[]:");
    for(i=0;i<k;i++)
        printf("%d ",out[i]);

    return 0;
}
