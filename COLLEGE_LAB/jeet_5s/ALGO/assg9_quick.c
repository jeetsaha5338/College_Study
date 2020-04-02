//quick sort
#include<stdio.h>
#include<stdlib.h>
int *a;
int partition(int,int);
void quick_sort(int,int);
void swap(int,int);
int main()
{
	int i,j,n,t,k;
	printf("enter the value of n\n");
	scanf("%d",&n);
	printf("enter the elements of an array\n");
	a= (int*)malloc(n*sizeof(int));	
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quick_sort(0,n-1);
	printf("sorted array:");
	for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
	printf("\n");
	return 0;
}

void quick_sort(int lb, int ub)
{
	int q;
	if(lb<ub)
	{
		q=partition(lb,ub);
		quick_sort(lb,q-1);
		quick_sort(q+1,ub);
	}
}

int partition(int lb,int ub)
{
	int x,i,j;
	x=a[ub];
	i=lb-1;
	for(j=lb;j<ub;j++)
	{
		if(a[j]<=x)
		{
			i=i+1;
			swap(i,j);
		}
	}
	swap(i+1,ub);
	return i+1;
}
void swap(int i,int j)
{
	int t;
	t=a[i];
	a[i]=a[j];
	a[j]=t;
}
