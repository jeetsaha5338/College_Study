#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[7]={1,2,7,6,3,4,8};
    int i,j,s1=0,s2=0,n=7;
    for(i=1;i<=n+1;i++)
    {
        s1+=i;
    }
    for(i=0;i<n;i++)
        s2+=a[i];
    printf("result:%d",s1-s2);
    return 0;
}
