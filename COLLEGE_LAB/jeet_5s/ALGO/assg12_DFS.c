//DFS
#include<stdio.h>
#include<stdlib.h>
#define chng 117
#define max 100
#define NIL -999
int di[max],df[max],g[max],pi[max];
char color[max];
int **adj,v,e,time=0;//for adjacent

void DFS_VISIT(int u)
{
	int v1;
	time++;
	di[u]=time;
	color[u]='G';
	for(v1=0;v1<e;v1++)
	{
		if(adj[u][v1]==1)
		{
			if(color[v1]=='W')
			{
				pi[v1]=u;
				DFS_VISIT(v1);
			}
		}
	}
	color[u]='B';
	time++;
	df[u]=time;
}
				
void DFS()
{
	int u;
	for(u=0;u<v;u++)
	{
		color[u]='W';
		pi[u]=NIL;
		di[u]=0;
		df[u]=0;
	}
	for(u=0;u<v;u++)
	{
		if(color[u]=='W')
		{
			DFS_VISIT(u);
		}
	}
}
//adj create
void adjacent()
{
	int i,j,v1,v2;
	char x,y,c;
	FILE *fp;
	fp=fopen("File.txt","r");
	fscanf(fp,"%d\t%d\t",&v,&e);
	for(i=0;i<v;i++)
	{
		fscanf(fp,"%c",&c);
		g[i]=c-chng;
	}
	fscanf(fp,"\n");
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
	int i,j;
	adjacent();
	DFS();
	printf("\tC\tP\n\n");

	
	for(i=0;i<v;i++)
	{
		
		printf("\t%c",g[i]+chng);
		printf("\t%c----",pi[i]+chng);
		printf("\t%d,",di[i]);
		printf("\t%d\n",df[i]);
	}
	return 0;
}
