#include<stdio.h>
#include<stdlib.h>
int chk(int n)
{
    int i,f=1;
    if(n==1)
    {
        return 0;
    }
    for(i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            f=0;
            break;
        }
    }
    return f;
}
int main()
{
    int i,j,n,count=0;
    printf("Enter The N:");
    scanf("%d",&n);
    count+=chk(n);
    n/=10;
    while(n>0)
    {
        n/=10;
        count+=chk(n);
    }
    printf("%d",count);

}
