#include<stdio.h>
char buff[100];
int power(int m,int m1)
{
    int i,f=1;
    for(i=1;i<=m1;i++)
    {
        f=f*m;
    }
    return f;
}
void send_code()
{
    int data[20];
    int r=0,i,d,j,k,n,s,f,m;
    printf("\nEnter Data Size:");
    scanf("%d",&d);//d=4
    int a[10];//a[i]={1,0,1,1}
    printf("\nEnter Data Elements:");
    for(i=1;i<=d;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<20;i++)
    {
        data[i]=0;
    }
    do{r++;}while(power(2,r)<(d+r+1));//r=3
    n=d+r;
    j=d;
    k=0;
    for(i=1;i<=n;i++)
    {
        if(i==(power(2,k)))
        {
            data[i]=2;
            k++;
        }
        else
        {
            data[i]=a[j];
            j--;
        }
    }
    printf("\nINIT_ARRY:\n");
    for(i=1;i<=n;i++)
    {
        printf(" %d",data[i]);
    }
    for(i=0;i<r;i++)
    {
        f=power(2,i);//1,2,4
        k=f;
        s=0;
        j=0;
        while(k<=n)
        {
            m=k+(j%f);
            s=s+data[m];
            j++;
            if(j%f==0)
            {
                k=k+2*f;
            }
        }
        m=s%2;
        data[f]=m;
    }
    printf("\nDATA:\n");
    for(i=1;i<=n;i++)
    {
        if(data[i]==1)
            buff[i-1]='1';
        else
            buff[i-1]='0';
        printf(" %d",data[i]);
    }
}
void recv_code()
{
    int data[20];
    int r=0,i,j,k,n,s,f,m,l;
    for(i=0;buff[i]!='\0';i++)
    {
        if(buff[i]=='0')
            data[i+1]=0;
        else
            data[i+1]=1;
    }
    n=i;
    printf("\nGET_ARRY:\n");
    for(i=1;i<=n;i++)
    {
        printf(" %d",data[i]);
    }
    do{r++;}while(power(2,r)<(n+1));
    m=0;
    l=0;
    for(i=0;i<r;i++)
    {
        f=power(2,i);
        k=f;
        s=0;
        j=0;
        while(k<=n)
        {
            m=k+(j%f);
            s=s+data[m];
            j++;
            if(j%f==0)
            {
                k=k+2*f;
            }
        }
        l+=(s%2);
    }
    if(l==0)
        printf("\nRIGHT\n");
    else
        printf("\nWRONG\n");
}
int main()
{
    int i;
    for(i=0;i<100;i++)
    {
        buff[i]='\0';
    }
    send_code();
    printf("\nBUFFER:%s\n",buff);
    recv_code();
    return 0;
}
