#include<stdio.h>
#include<stdlib.h>
int main(int c,char **v)
{
    int i,k=0,n,a[11]={2,3,5,7,11,13,15,17,19,23,29};
    if(c!=2)
    {
        printf("ERORR");
        exit(1);
    }
    for(i=0;v[1][i]!='\0';i++)
    {
        if(v[1][i]<48 || v[1][i]>57)
        {
            printf("ERORR");
            exit(1);
        }
    }
    n=atoi(v[1]);
    while(n>1)
    {
        if(n%a[k]==0)
        {
            printf("%d ",a[k]);
            n/=a[k];
        }
        else if(k==11)
            break;
        else
            k++;
    }
    return 0;
}
