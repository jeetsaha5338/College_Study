#include<stdio.h>
int main()
{
    int n,i,j,a[10][10],k=1;
    int s1=0,s2=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=k++;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\t%d",a[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
                s1+=a[i][j];
            if(i+j==n-1)
                s2+=a[i][j];
        }
    }
    printf("Principle:%d, Secondary:%d",s1,s2);
    return 0;
}
