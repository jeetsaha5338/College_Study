#include<stdio.h>
int main()
{
    int i,j,count=0,n,l,k=1;
    printf("Enter the N:");
    scanf("%d",&n);
    while(1)
    {
        j=0;
        l=k;
        while(l!=1)
        {
            if(l%2==0)
                l/=2;
            else if(l%3==0)
                l/=3;
            else if(l%5==0)
                l/=5;
            else
            {
                j=1;
                break;
            }
        }
        if(j==0)
        {
            count++;
            if(count==n)
            {
                printf("%d",k);
                break;
            }
        }
        k++;
    }
}
