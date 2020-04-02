#include<stdio.h>
int main()
{
    int n1,n2,i,j,flag,p=0,f=0;
    int *prime,*fibo;
    printf("Enter N1 & N2:");
    scanf("%d%d",&n1,&n2);
    prime=(int*)malloc((n2-n1)*sizeof(int));
    fibo=(int*)malloc((n2-n1)*sizeof(int));
    for(i=n1;i<=n2;i++)
    {
        flag=0;
        for(j=2;j<=i/2;j++)
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            prime[p++]=i;
        }
    }
    int a=0,b=1,c;
    c=a+b;
    while(c<=n2)
    {
        if(c>=n1)
        {
            fibo[f++]=c;
        }
        a=b;
        b=c;
        c=a+b;
    }
    for(i=0;i<p;i++)
    {
        flag=0;
        for(j=0;j<f;j++)
        {
            if(prime[i]==fibo[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            printf("%d ",prime[i]);
    }
    return 0;
}
