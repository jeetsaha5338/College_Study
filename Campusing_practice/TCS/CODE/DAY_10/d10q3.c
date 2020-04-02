#include<stdio.h>
int c;
int chck(int sum,int ai,int *a,int count)
{
    int i;
    sum-=ai;
    if(sum==0)
    {
        count++;
        if(c>count)
            c=count;
        return;
    }
    else if(sum>0)
    {
        for(i=0;i<4;i++)
        {
            chck(sum,a[i],a,count+1);
        }
    }
    else
        return;
}
int main()
{
    int a[4]={1,5,7,10};
    int i,n;
    printf("Enter N:");
    scanf("%d",&n);
    c=n;
    for(i=0;i<4;i++)
    {
        chck(n,a[i],a,0);
    }
    printf("total=%d\n",c);
    return 0;
}
