#include<stdio.h>
#define max 100
#define inf 999
int v,e,ne=1,v1,v2,u1,u2;
int cost[max][max],visited[max],min,mincost=0,pi[max],tree[max];
int find(int i)
{
    while(pi[i])
    {
        i=pi[i];
    }
    return i;
}
int uni(int i, int j)
{
    if(i!=j)
    {
        pi[j]=i;
        return 1;
    }
    return 0;
}
void krushkal()
{
    int i,j;
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            if(cost[i][j]==0)
                cost[i][j]=inf;
        }
    }
    for(i=1;i<=v;i++)
    {
        pi[i]=0;
        tree[i]=0;
    }
    while(ne<v)
    {
        min=inf;
        for(i=1;i<=v;i++)
        {
            for(j=1;j<=v;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    u1=i;
                    u2=j;
                }
            }
        }
        v1=find(u1);
        v2=find(u2);
        if(uni(v1,v2))
        {
            printf("\nEdge no. %d (b/w %d & %d) cost is: %d",ne++,u1,u2,min);
            mincost=mincost+min;
            tree[u2]=v1;
        }
        cost[u1][u2]=cost[u2][u1]=inf;
    }
}
void adjacency()
{
    int i,j,a,b,c;
    FILE *fp;
    fp=fopen("graph4.txt","r");
    fscanf(fp,"%d\t%d\n",&v,&e);
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            cost[i][j]=0;
        }
    }
    for(i=1;i<=e;i++)
    {
        fscanf(fp,"%d\t%d\t%d\n",&a,&b,&c);
        cost[a][b]=cost[b][a]=c;
    }
    fclose(fp);
}
int main()
{
    int i;
    adjacency();
    krushkal();
    printf("\nMinimum Cost: %d",mincost);
    printf("\nThe Graph Is:");
    for(i=1;i<=v;i++)
        printf("\n(vertex)%d--->%d(root)",i,tree[i]);
    return 0;
}
