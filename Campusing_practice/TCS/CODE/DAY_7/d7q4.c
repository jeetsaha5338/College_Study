#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,k,n1=6,n2=9;
    int a1[6]={1,3,4,5,7,15};
    int a2[9]={2,3,5,6,9,12,15,20,25};
    i=0;j=0;
    while(i!=n1 && j!=n2)
    {
        if(a1[i]<a2[j])
            printf("%d ",a1[i++]);
        else if(a1[i]>a2[j])
            printf("%d ",a2[j++]);
        else{ i++;j++;}
    }
    if(i==n1)
    {
        for(k=j;k<n2;k++)
        {
            printf("%d ",a2[k]);
        }
    }
    else if(j==n2)
    {
        for(k=i;k<n1;k++)
        {
            printf("%d ",a1[k]);
        }
    }
    return 0;
}
