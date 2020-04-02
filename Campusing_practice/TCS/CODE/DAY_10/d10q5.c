#include<stdio.h>
int main()
{
    int a[10]={1,1,2,2,2,3,4,4,5,5};
    int p,i,c=1,j;
    p=a[0];
    for(i=1;i<10;i++)
    {
        if(a[i]==p)
        {
            p=a[i];
            c++;
        }
        else if(c==1)
        {
            printf("%d",p);
            return 0;
        }
        else
        {
            c=1;
            p=a[i];
        }
    }
    if(c==1)
    {
        printf("%d",p);
    }
    return 0;
}
