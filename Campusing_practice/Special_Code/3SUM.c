#include<stdio.h>
int ar[6]={-6,-1,0,1,2,-1},l=6,t=0;
int main()
{
    fun(0,1,2);
    return 0;
}
void fun(int a,int i,int k)
{
    if(a<=l-3)//l-3=3
    {
        if(i<=l-2)
        {
            if(ar[a]+ar[i]+ar[k]==t)
                printf("\t%d+%d+%d=%d\n",ar[a],ar[i],ar[k],t);
        }
        if(i==l-2)
            fun(a+1,a+2,a+3);
        if(k==l-1)
            fun(a,i+1,i+2);
        else
            fun(a,i,k+1);
    }
}
