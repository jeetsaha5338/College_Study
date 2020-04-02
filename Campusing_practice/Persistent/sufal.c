#include<stdio.h>
int m,n,x,y,a[10][10];
void fill(int i,int j)
{
    if(a[i][j-1]==0 && j!=0)
    {
        a[i][j-1]=6;
    }
    if(a[i][j+1]==0 && j!=m-1)
    {
        a[i][j+1]=6;
    }
    if(a[i-1][j]==0 && i!=0)
    {
        a[i-1][j]=6;
    }
    if(a[i+1][j]==0 && i!=n-1)
    {
        a[i+1][j]=6;
    }
}
int check()
{
    int f=0;
    if(a[x][y-1]==5 && y!=0)
        f=1;
    else if(a[x][y+1]==5 && y!=m-1)
        f=1;
    else if(a[x-1][y]==5 && x!=0)
        f=1;
    else if(a[x+1][y]==5 && x!=n-1)
        f=1;
    if(f==1)
    {
        if(shift()==1)
        {
            return check();
        }
        else
            return 1;
    }
    else
        return 0;
}
int shift()
{
    if(a[x][y-1]==0 && y!=0)
    {
        a[x][y-1]=3;
        a[x][y]=0;
        y--;
    }
    else if(a[x][y+1]==0 && y!=m-1)
    {
        a[x][y+1]=3;
        a[x][y]=0;
        y++;
    }
    else if(a[x-1][y]==0 && x!=0)
    {
        a[x-1][y]=3;
        a[x][y]=0;
        x--;
    }
    else if(a[x+1][y]==0 && x!=n-1)
    {
        a[x+1][y]=3;
        a[x][y]=0;
        x++;
    }
    else
        return 0;
    return 1;
}
int boundary()
{
    int f=1;
    if(a[x][y-1]!=1 && y!=0)
    {
        f=0;
    }
    if(a[x][y+1]!=1 && y!=m-1)
    {
        f=0;
    }
    if(a[x-1][y]!=1 && x!=0)
    {
        f=0;
    }
    if(a[x+1][y]!=1 && x!=n-1)
    {
        f=0;
    }
    return f;
}
int main()
{
    int i,j,k=1,c;
    FILE *fp;
    fp=fopen("s_input.txt","r");
    fscanf(fp,"%d\t%d\n",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            fscanf(fp,"%d\t",&a[i][j]);
        }
        fscanf(fp,"\n");
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]==3)
            {
                x=i;y=j;
                break;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("\t%d",a[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    if(boundary()==1)
    {
        printf("\nBoundary Found For '3'\n");
        return 0;
    }
    while(1)
    {
        if(check()==1)
        {
            printf("\n\t%d\n",k);
            return 0;
        }
        /*printf("\nafter checking\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                printf("\t%d",a[i][j]);
            }
            printf("\n");
        }
        printf("\n\n");*/

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(a[i][j]==5)
                {
                    fill(i,j);
                }
            }
        }
        c=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(a[i][j]==6)
                {
                    a[i][j]=5;
                    c++;
                }
            }
        }
        if(c==0)
        {
            printf("\nBoundary Found For '5'\n");
            return 0;
        }
        else
            c=0;
        printf("\nAfter Filling %d Time(s):\n",k);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                printf("\t%d",a[i][j]);
            }
            printf("\n");
        }
        printf("\n\n");
        k++;
    }
}
