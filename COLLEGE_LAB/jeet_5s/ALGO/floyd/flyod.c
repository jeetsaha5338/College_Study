#include<stdio.h>
int d[20][20],p[20][20];
FILE *fp1,*fp2;
#define INFINITY 99
#define NIL -9
void disp(int[20][20],int[20][20],int ,const char*,const char*,int );
void path(int ,int );
int main()
{
	int i,v,j,k;
	char msg[30];
	fp1=fopen("output_F.txt","w");
	fprintf(fp1,"\t\t\tFLOYD-WARSGALL\n\n");
	fp2=fopen("input_F.txt","r");
	fscanf(fp2,"%d\n",&v);
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
			fscanf(fp2,"%d\t",&d[i][j]);
		}
		fscanf(fp2,"\n");
	}
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
			if(i==j||d[i][j]==INFINITY)
				p[i][j]=NIL;
			else
				p[i][j]=i;
		}
	}
	disp(d,p,v,"Distance matrix: ","Predecessor matrix: ",0);
	for(k=1;k<=v;k++)
	{
		for(i=1;i<=v;i++)
		{
			for(j=1;j<=v;j++)
			{
				if(d[i][k]+d[k][j]<d[i][j])
				{
					d[i][j]=d[i][k]+d[k][j];
					p[i][j]=p[k][j];
				}
			}
		}
        disp(d,p,v,"Distance matrix: ","Predecessor matrix: ",k);
	}
	fprintf(fp1,"\n\n\nPath between all pair of vertices");
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
			if(i!=j)
			{
				fprintf(fp1,"\n\nPath between %d to %d:--",i,j);
				path(i,j);
			}
		}
		fprintf(fp1,"\n");
	}
	printf("\nCheck the 'output_F.txt' file\n");
}


void path(int i,int j)
{
	if(i==j)
		fprintf(fp1,"\t%d",i);
	else if(p[i][j]==NIL)
		fprintf(fp1,"no. path between %d and %d",i,j);
	else
	{
		path(i,p[i][j]);
		fprintf(fp1,"\t%d",j);
	}
}

void disp(int a[20][20],int b[20][20],int n,const char* msg1,const char* msg2,int k)
{
	int i,j;
	fprintf(fp1,"\n%s%d\t\t%s%d\n",msg1,k,msg2,k);
	for(i=1;i<=n;i++)
	{
		fprintf(fp1,"\n");
		for(j=1;j<=n;j++)
		{
			fprintf(fp1,"%4d",a[i][j]);
		}
		fprintf(fp1,"\t\t");
		for(j=1;j<=n;j++)
		{
			fprintf(fp1,"%4d",b[i][j]);
		}
	}
}


