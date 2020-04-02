//BFS
#include<stdio.h>
#include<stdlib.h>
#define chng 114
#define max 100
#define NIL -999
#define INF 999
int d[max],g[max],pi[max];
int a[max],f=0,r=0;//for Q
char color[max];
int **adj,v,e;//for adjacent

//op Q
void EQ(int i)
{
	a[f++]=i;
}
int DQ()
{
	return a[r++];
}
//end Q
void BFS(int s)
{
	int u,v;
	color[s]='G';
	d[s]=0;
	pi[s]=NIL;
	EQ(s);
	while(f!=r)
	{
		u=DQ();
		for(v=0;v<e;v++)
		{
			if(adj[u][v]==1)
			{
				if(color[v]=='W')
				{
					color[v]='G';
					d[v]=d[u]+1;
					pi[v]=u;
					EQ(v);
				}
			}
		}
		color[u]='B';
	}
}

//adj create
void adjacent()
{
	int i,j,v1,v2;
	char x,y;
	FILE *fp;
	fp=fopen("file_graph.txt","r");
	fscanf(fp,"%d\t%d\n",&v,&e);
	adj=(int**)malloc(v*sizeof(int*));
	for(i=0;i<v;i++)
	{
		adj[i]=(int*)malloc(e*sizeof(int));
	}
	for(i=0;i<v;i++)
	{
		for(j=0;j<e;j++)
		{
			adj[i][j]=0;
		}
	}
	for(i=0;i<e;i++)
	{
		fscanf(fp,"%c\t%c\n",&x,&y);
		v1=x-chng;
		v2=y-chng;
		adj[v1][v2]=1;
		adj[v2][v1]=1;
	}   
	fclose(fp);
}

//end adj

int main()
{
	int v1,i,j;
	char c;
	adjacent();
	/*for(i=0;i<v;i++)
	{
		for(j=0;j<e;j++)
		{
			printf("\t%d",adj[i][j]);
		}
		printf("\n");
	}*/
	//initialization
	for(i=0;i<max;i++)
	{
		color[i]='W';
	}
	for(i=0;i<max;i++)
	{
		d[i]=INF;
	}
	for(i=0;i<max;i++)
	{
		pi[i]=NIL;
	}//end
	FILE *fp;
	fp=fopen("g_v.txt","r");
	fscanf(fp,"%d",&v1);
	for(i=0;i<v1;i++)
	{
		fscanf(fp,"%c",&c);
		g[i]=c-chng;
	}
	BFS(g[0]);
	printf("\tC\tP\n\n");
	for(i=0;i<v;i++)
	{
		printf("\t%c",g[i]+chng);
		printf("\t%c\n",pi[i]+chng);
	}
	fclose(fp);
	return 0;
}
