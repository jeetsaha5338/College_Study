#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,x;
	int a[50];
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=-1;
	}
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(x!=-1)
		{
			if(x>n)
			{
				printf("ERROR");
				exit(0);
			}
			else
			{
				a[x]=x;
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
