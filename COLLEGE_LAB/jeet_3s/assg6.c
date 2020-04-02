#include<stdio.h>
int main()
{
	int i,j,m,n,p;
	int a[10][10];
	printf("enter the value of m & n:",m,n);
	scanf("%d%d",&m,&n);
	printf("enter the elements of the array:");
	for(i=0;i<m;i++)
	{ 
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("enter the finding value:",p);
	scanf("%d",&p);
	for(i=0;i<m;i++)
	{ 
		for(j=0;j<n;j++)
			printf("%2d\t",a[i][j]);
		printf("\n\n");
	}
	for(i=0;i<m;i++)
	{ 
		for(j=0;j<n;j++)
		{
			if(a[i][j]==p)
			{
				printf("the position is:%d %d\n",i,j);
			}
		}
	}
	return 0;
}
