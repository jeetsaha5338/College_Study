#include<stdio.h>
void count(int,int,int[][int*]);
int main()
{
	int i,j,r,c;
	int a[5][5];
	printf("enter the no. of row and coloum:");
	scanf("%d%d",&r,&c);
	printf("enter the element of the matrix:\n");
	for(i=0;i<r;i++)
	{ 
		for(j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("given matrix is:\n");
	for(i=0;i<r;i++)
	{ 
		for(j=0;j<c;j++)
		{
			printf("\t%d",a[i][j]);
		}
		printf("\n");
	}
	count(r,c,&a);
	return 0;
}
void count(int p,int q,int b[][*c])
{
	int i,j,m=0,n=0;
	
	for(i=0;i<p;i++)
	{ 
		for(j=0;j<q;j++)
		{
			if(b[i][j]!=0)
				m++;
			else
				n++;
		}
	}
	if(m>=n)
		printf("it is not sparse matrix\n");
	else
	{
		for(i=0;i<p;i++)
		{ 
			for(j=0;j<q;j++)
			{
				if(b[i][j]!=0)
				{
					printf("\nnon-zero element:\t%d\trow:\t%d\tcoloum:\t%d\n",b[i][j],i,j);
				}
			}
		}
	}
}

