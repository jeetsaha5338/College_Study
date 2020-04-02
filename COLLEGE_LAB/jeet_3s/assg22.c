#include<stdio.h>
int main()
{
	int i,j,r,c,m=0,n=0;
	int *
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
	for(i=0;i<r;i++)
	{ 
		for(j=0;j<c;j++)
		{
			if(a[i][j]!=0)
				m++;
			else
				n++;
		}
	}
	if(n>=(2/3*r*c))
		printf("it is not sparse matrix\n");
	else
	{
		for(i=0;i<r;i++)
		{ 
			for(j=0;j<c;j++)
			{
				if(a[i][j]!=0)
				{
					printf("\nnon-zero element:\t%d\trow:\t%d\tcoloum:\t%d\n",a[i][j],i,j);
				}
			}
		}
	}
	return 0;
}
			
