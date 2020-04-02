#include<stdio.h>
/*
    il= lower value of i;
    jl= lower value of j;
    iu= upper value of i;
    ju= upper value of j;
*/
int main()
{
    int a[4][4],s[16];
    int i,j,ni=4,nj=4;
    int k,il,jl,iu,ju;
    k=1;
    for(i=0;i<ni;i++)
    {
        for(j=0;j<nj;j++)
        {
            a[i][j]=k++;
            printf("\t%d",a[i][j]);
        }
        printf("\n");
    }
    i=0;j=0;
    il=jl=0;
    iu=ni-1;ju=nj-1;
    k=0;
    while(k!=ni*nj)
    {
        while(i==il && j<=ju)
        {
            printf("%d ",a[i][j]);k++;
            j++;
        }
        j--;i++;il++;
        while(j==ju && i<=iu)
        {
            printf("%d ",a[i][j]);k++;
            i++;
        }
        i--;ju--;j--;
        while(i==iu && j>=jl)
        {
            printf("%d ",a[i][j]);k++;
            j--;
        }
        j++;i--;iu--;
        while(j==jl && i>=il)
        {
            printf("%d ",a[i][j]);k++;
            i--;
        }
        i++;j++;jl++;
    }
    return 0;
}

