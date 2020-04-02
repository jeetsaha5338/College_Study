#include<stdio.h>
int flag;
void check(int sum, int ai,int *a,int n)
{
    int i
    sum-=ai;
    if(sum==0)
    {
        flag=1;
        return;
    }
    else if(sum>0)
    {
        for(i=0;i<n;i++)
        {
            check(sum,a[i],a,n);
        }
    }
    else
        return;
}
int main()
{
    int i,j,n,a[10],sum;
    printf("enter sum:");
    scanf("%d",&sum);
    printf("enter n:");
    scanf("%d",&n);
    printf("Enter Values:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    flag=0;
    for(i=0;i<n;i++)
    {
        check(sum,a[i],a,n);
    }
    if(flag==0)
        printf("\nNO");
    else
        printf("\nYES");
    return 0;

}
