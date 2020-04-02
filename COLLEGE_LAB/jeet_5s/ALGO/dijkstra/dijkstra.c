#include<stdio.h>
#define max 100
#define inf 999
#define nil 999
int v,e,ne=1,v1,v2,u1,u2;
int cost[max][max],visited[max],min,dist[max],pi[max];
void dij()
{
    int i,j;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            if(cost[i][j]==0)
                cost[i][j]=inf;
        }
    }
    for(i=0;i<v;i++)
    {
        dist[i]=inf;
        pi[i]=nil;
    }
    visited[0]=1;
    dist[0]=0;
    while(ne<v)
    {
        min=inf;
        for(i=0;i<v;i++)
        {
            for(j=0;j<v;j++)
            {
                if(cost[i][j]<min && visited[i]!=0)
                {
                    min=cost[i][j];
                    v1=u1=i;
                    v2=u2=j;
                }
            }
        }
        if(visited[u1]==0 || visited[u2]==0)
        {
            ne++;
            if(dist[v2]>dist[v1]+cost[v1][v2])
            {
                dist[v2]=dist[v1]+cost[v1][v2];
                pi[v2]=v1;
            }
            visited[v2]=1;
        }
        cost[v1][v2]=inf;
    }
}
void adjacency()
{
    int i,j,a,b,c;
    FILE *fp;
    fp=fopen("graph3.txt","r");
    fscanf(fp,"%d\t%d\n",&v,&e);
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            cost[i][j]=0;
        }
    }
    for(i=0;i<e;i++)
    {
        fscanf(fp,"%d\t%d\t%d\n",&a,&b,&c);
        cost[a][b]=c;
    }
    fclose(fp);
}
int main()
{
    int i;
    adjacency();
    dij();
    for(i=0;i<v;i++)
        printf("\nDistance From 0 to %d is: %d & Parent is: %d",i,dist[i],pi[i]);
    return 0;
}
