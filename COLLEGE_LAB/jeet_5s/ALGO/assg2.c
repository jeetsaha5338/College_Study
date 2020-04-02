//selection sort
#include<stdio.h>
#include<stdlib.h>

void selection(int *a,int n)
{
	int i,j,t,m;
	for(i=0;i<n-1;i++)
	{
		m=i;
		for(j=i+1;j<n;j++)
		{
			if(a[m]>a[j])
			{
				t=a[m];
				a[m]=a[j];
				a[j]=t;
			}
		}
		//m=j;
		//a[j+1]=k;
	}
	for(i=0;i<n;i++)
	{
		printf("\n%d\n",a[i]);
	}
}

int main()
{
	int i,n,j;
	int *a;
	printf("ENTER THE NO. OF NUMBERS:");
	scanf("%d",&n);
	printf("ENTER THE DATA:");
	a= (int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	selection(a,n);
	return 0;
}
