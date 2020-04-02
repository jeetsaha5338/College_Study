//graph in a file using adjacency matrix. 

#include<stdio.h>
#include<stdlib.h>

int main()
{

	int i,j,v,e,v1,v2,c,tc=0,max,min,x,y,a[100][2],k=1,l,temp;
	FILE *fp;
	fp=fopen("file_graph.txt","r");
	fscanf(fp,"%d %d\n",&v,&e);
	int **p=(int**)malloc(v*sizeof(int*));
	for(i=0;i<v;i++)
	{
		p[i]=(int*)malloc(v*sizeof(int));
	}			
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			p[i][j]=0;
		}
	}
	for(i=0;i<v;i++)
	{
		fscanf(fp,"%d\t%d\t%d\n",&v1,&v2,&c);
		for(j=0;j<v;j++)
		{
			if(i==v1 && j==v2)
			{
				p[v1][v2]=p[v2][v1]=c;
			}
		}
	}
	max=min=p[0][0];
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(p[i][j]>0)
			{
				if(min>p[i][j] || min==0)
				{
					min=p[i][j];
				}
				if(max<p[i][j])
				{
					max=p[i][j];
				}
				for(l=0;l<k;l++)
				{
					if(a[l][0]==p[i][j])
					{
						continue;
					}
					a[++k][0]=p[i][j];
				}
			}
			tc=tc+p[i][j];
			printf("%d\t",p[i][j]);
		}
		printf("\n");
	}
	a[0][0]=min;
	a[++k][0]=max;
	for(l=0;l<k;l++)
	{
		a[l][1]=0;
	}
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			for(l=0;l<k;l++)
			{
				if(p[i][j]==a[l][0])
				{
					a[l][1]=a[l][1]+1;
				}
			}
		}
	}
	printf("Total cost of the graph:%d\n",tc);
	printf("minimum weight:%d\n",min);
	printf("maximum weight:%d\n",max);
	for(l=0;l<k;l++)
	{
		printf("frequency of %d weight is %d\n",a[l][0],a[l][1]);
	}
	//printf("frequency of minimum weight:%d\n",x);
	//printf("frequency of maximum weight:%d\n",y);
	fclose(fp);
	return 0;
}
