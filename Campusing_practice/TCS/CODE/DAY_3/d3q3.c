#include<stdio.h>
int main()
{
    int n,i,j=0,f=0,k,a=1,b=1,c,t=2;
    printf("enter n:");
    scanf("%d",&n);
    if(n%2==0)
    {
        k=2;
        while(1)
        {
            for(i=2;i<=k/2;i++)
            {
                if(k%i==0)
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                j++;
                if(j==n/2)
                {
                    printf("%d",k);
                    break;
                }
            }
            f=0;
            k++;
        }
    }
    else
    {
        k=n/2+1;
        if(k<3)
            printf("1");
        else
        {
            while(t!=k)
            {
                c=a+b;
                a=b;
                b=c;
                t++;
            }
            printf("%d",c);
        }

    }
    return 0;
}
