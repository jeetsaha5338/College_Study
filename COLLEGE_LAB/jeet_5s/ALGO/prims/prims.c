#include<stdio.h>
#define max 100
#define inf 999
int v,e,ne=1,v1,v2,u1,u2;
int cost[max][max],visited[max],min,mincost=0;
void prims()
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
    visited[0]=1;
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
            printf("\nEdge no. %d (b/w %d & %d) cost is: %d and parent is: %d",ne++,u1,u2,min,v1);
            mincost=mincost+min;
            visited[v2]=1;
        }
        cost[v1][v2]=cost[v2][v1]=inf;
    }
}
void adjacency()
{
    int i,j,a,b,c;
    FILE *fp;
    fp=fopen("graph2.txt","r");
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
        cost[a][b]=cost[b][a]=c;
    }
    fclose(fp);
}
int main()
{
    adjacency();
    prims();
    printf("\nMinimum Cost: %d",mincost);
    return 0;
}
